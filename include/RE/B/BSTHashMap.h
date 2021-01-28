#pragma once

#include "RE/B/BSTTuple.h"
#include "RE/C/CRC.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	namespace detail
	{
		static constexpr std::uint8_t BSTScatterTableSentinel[] = { 0xDEu, 0xADu, 0xBEu, 0xEFu };
	}

	// scatter table with chaining
	template <
		class Hash,
		class KeyEqual,
		class Traits,
		template <std::size_t, std::size_t> class Allocator>
	class BSTScatterTable
	{
	public:
		using traits_type = Traits;
		using key_type = typename Traits::key_type;
		using mapped_type = typename Traits::mapped_type;
		using value_type = typename Traits::value_type;
		using size_type = std::uint32_t;
		using difference_type = std::int32_t;
		using hasher = Hash;
		using key_equal = KeyEqual;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

		static_assert(std::is_invocable_r_v<size_type, const hasher&, const key_type&>);
		static_assert(std::is_invocable_r_v<bool, const key_equal&, const key_type&, const key_type&>);

	private:
		struct entry_type
		{
			entry_type() = default;
			entry_type(const entry_type&) = delete;

			entry_type(entry_type&& a_rhs)	//
				noexcept(std::is_nothrow_move_constructible_v<value_type>&&
						std::is_nothrow_destructible_v<value_type>)
			{
				if (a_rhs.has_value()) {
					const auto rnext = a_rhs.next;
					emplace(std::move(a_rhs).steal(), rnext);
				}
			}

			~entry_type() noexcept { destroy(); };

			entry_type& operator=(const entry_type&) = delete;

			entry_type& operator=(entry_type&& a_rhs)  //
				noexcept(std::is_nothrow_move_constructible_v<value_type>&&
						std::is_nothrow_destructible_v<value_type>)
			{
				if (this != std::addressof(a_rhs)) {
					destroy();
					if (a_rhs.has_value()) {
						const auto rnext = a_rhs.next;
						emplace(std::move(a_rhs).steal(), rnext);
					}
				}
				return *this;
			}

			[[nodiscard]] bool has_value() const noexcept { return next != nullptr; }

			void destroy()	//
				noexcept(std::is_nothrow_destructible_v<value_type>)
			{
				if (has_value()) {
					std::destroy_at(std::addressof(value));
					next = nullptr;
				}
				assert(!has_value());
			}

			template <class Arg>
			void emplace(Arg&& a_value, const entry_type* a_next)  //
				noexcept(std::is_nothrow_constructible_v<value_type, Arg>)
			{
				static_assert(std::same_as<std::decay_t<Arg>, value_type>);
				destroy();
				std::construct_at(std::addressof(value), std::forward<Arg>(a_value));
				next = const_cast<entry_type*>(a_next);
				assert(has_value());
			}

			[[nodiscard]] value_type steal() &&	 //
				noexcept(std::is_nothrow_move_constructible_v<value_type>&&
						std::is_nothrow_destructible_v<value_type>)
			{
				assert(has_value());
				value_type val = std::move(value);
				destroy();
				assert(!has_value());
				return val;
			}

			union
			{
				value_type value;
				std::byte  buffer[sizeof(value_type)]{ static_cast<std::byte>(0) };
			};
			entry_type* next{ nullptr };
		};

		template <class U>
		class iterator_base :
			public boost::stl_interfaces::iterator_interface<
				iterator_base<U>,
				std::forward_iterator_tag,
				U>
		{
		private:
			using super =
				boost::stl_interfaces::iterator_interface<
					iterator_base<U>,
					std::forward_iterator_tag,
					U>;

		public:
			using difference_type = typename super::difference_type;
			using value_type = typename super::value_type;
			using pointer = typename super::pointer;
			using reference = typename super::reference;
			using iterator_category = typename super::iterator_category;

			iterator_base() = default;

			template <class V>
			iterator_base(const iterator_base<V>& a_rhs) noexcept  //
				requires(std::convertible_to<typename iterator_base<V>::reference, reference>) :
				_first(a_rhs._first),
				_last(a_rhs._last)
			{}

			~iterator_base() = default;

			template <class V>
			iterator_base& operator=(const iterator_base<V>& a_rhs) noexcept  //
				requires(std::convertible_to<typename iterator_base<V>::reference, reference>)
			{
				assert(_last == a_rhs._last);
				_first = a_rhs._first;
				_last = a_rhs._last;
				return *this;
			}

			[[nodiscard]] reference operator*() const noexcept
			{
				assert(iterable());
				assert(_first->has_value());
				return _first->value;
			}

			template <class V>
			[[nodiscard]] bool operator==(const iterator_base<V>& a_rhs) const noexcept
			{
				assert(_last == a_rhs._last);
				return _first == a_rhs._first;
			}

			iterator_base& operator++() noexcept
			{
				seek();
				return *this;
			}

			using super::operator++;

		protected:
			friend class BSTScatterTable;

			iterator_base(entry_type* a_first, entry_type* a_last) noexcept :
				_first(a_first),
				_last(a_last)
			{
				assert(!!_first == !!_last);  // both or neither have values
				assert(_first <= _last);
				if (iterable() && !_first->has_value()) {
					seek();
				}
			}

			[[nodiscard]] entry_type* get_entry() const noexcept { return _first; }

		private:
			template <class>
			friend class iterator_base;

			[[nodiscard]] bool iterable() const noexcept { return _first && _last && _first != _last; }

			void seek() noexcept
			{
				assert(iterable());
				do {
					++_first;
				} while (_first != _last && !_first->has_value());
			}

			entry_type* _first{ nullptr };
			entry_type* _last{ nullptr };
		};

	public:
		using allocator_type = Allocator<sizeof(entry_type), alignof(entry_type)>;
		using iterator = iterator_base<value_type>;
		using const_iterator = iterator_base<const value_type>;

		BSTScatterTable() = default;

		BSTScatterTable(const BSTScatterTable& a_rhs) { insert(a_rhs.begin(), a_rhs.end()); }

		BSTScatterTable(BSTScatterTable&& a_rhs) noexcept  //
			requires(std::same_as<typename allocator_type::propagate_on_container_move_assignment, std::true_type>) :
			_capacity(std::exchange(a_rhs._capacity, 0)),
			_free(std::exchange(a_rhs._free, 0)),
			_good(std::exchange(a_rhs._good, 0)),
			_sentinel(a_rhs._sentinel),
			_allocator(std::move(a_rhs._allocator))
		{
			assert(a_rhs.empty());
		}

		~BSTScatterTable() { free_resources(); }

		BSTScatterTable& operator=(const BSTScatterTable& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				clear();
				insert(a_rhs.begin(), a_rhs.end());
			}
			return *this;
		}

		BSTScatterTable& operator=(BSTScatterTable&& a_rhs)	 //
			requires(std::same_as<typename allocator_type::propagate_on_container_move_assignment, std::true_type>)
		{
			if (this != std::addressof(a_rhs)) {
				free_resources();

				_capacity = std::exchange(a_rhs._capacity, 0);
				_free = std::exchange(a_rhs._free, 0);
				_good = std::exchange(a_rhs._good, 0);
				_sentinel = a_rhs._sentinel;
				_allocator = std::move(a_rhs._allocator);

				assert(a_rhs.empty());
			}
			return *this;
		}

		[[nodiscard]] iterator		 begin() noexcept { return make_iterator<iterator>(get_entries()); }
		[[nodiscard]] const_iterator begin() const noexcept { return make_iterator<const_iterator>(get_entries()); }
		[[nodiscard]] const_iterator cbegin() const noexcept { return make_iterator<const_iterator>(get_entries()); }

		[[nodiscard]] iterator		 end() noexcept { return make_iterator<iterator>(); }
		[[nodiscard]] const_iterator end() const noexcept { return make_iterator<const_iterator>(); }
		[[nodiscard]] const_iterator cend() const noexcept { return make_iterator<const_iterator>(); }

		[[nodiscard]] bool		empty() const noexcept { return size() == 0; }
		[[nodiscard]] size_type size() const noexcept { return _capacity - _free; }

		void clear()
		{
			if (size() > 0) {
				const auto entries = get_entries();
				assert(entries != nullptr);
				for (size_type i = 0; i < _capacity; ++i) {
					entries[i].destroy();
				}
				_free = _capacity;
				_good = 0;
			}

			assert(empty());
		}

		std::pair<iterator, bool> insert(const value_type& a_value) { return do_insert(a_value); }
		std::pair<iterator, bool> insert(value_type&& a_value) { return do_insert(std::move(a_value)); }

		template <std::input_iterator InputIt>
		void insert(InputIt a_first, InputIt a_last)  //
			requires(std::convertible_to<std::iter_reference_t<InputIt>, const_reference>)
		{
			reserve(size() + static_cast<size_type>(std::distance(a_first, a_last)));
			for (; a_first != a_last; ++a_first) {
				insert(*std::move(a_first));
			}
		}

		template <class... Args>
		std::pair<iterator, bool> emplace(Args&&... a_args)	 //
			requires(std::constructible_from<value_type, Args...>)
		{
			return insert(value_type(std::forward<Args>(a_args)...));
		}

		iterator erase(const_iterator a_pos) { return do_erase(a_pos); }
		iterator erase(iterator a_pos) { return do_erase(a_pos); }

		size_type erase(const key_type& a_key)
		{
			const auto pos = find(a_key);
			const auto result = pos != end() ? erase(pos) : pos;
			return result != end() ? 1 : 0;
		}

		[[nodiscard]] iterator		 find(const key_type& a_key) { return do_find<iterator>(a_key); }
		[[nodiscard]] const_iterator find(const key_type& a_key) const { return do_find<const_iterator>(a_key); }

		[[nodiscard]] bool contains(const key_type& a_key) const { return find(a_key) != end(); }

		void reserve(size_type a_count)
		{
			if (a_count <= _capacity) {
				return;
			}

			const auto oldCap = _capacity;
			const auto oldEntries = get_entries();

			const auto [newCap, newEntries] = [&]() {
				constexpr std::uint64_t min = allocator_type::min_size();
				static_assert(min > 0 && std::has_single_bit(min));
				const auto cap = std::max(std::bit_ceil<std::uint64_t>(a_count), min);
				assert(cap >= min);
				if (cap > 1u << 31) {
					stl::report_and_fail("a buffer grew too large"sv);
				}

				const auto entries = allocate(static_cast<size_type>(cap));
				if (!entries) {
					stl::report_and_fail("failed to handle an allocation"sv);
				}

				return std::make_pair(static_cast<size_type>(cap), entries);
			}();

			const auto setCap = [&](size_type a_newCap) {
				_capacity = a_newCap;
				_free = _capacity;
				_good = 0;
			};

			if (newEntries == oldEntries) {
				std::uninitialized_default_construct_n(oldEntries + oldCap, newCap - oldCap);
				std::vector<value_type> todo;
				todo.reserve(size());
				for (size_type i = 0; i < oldCap; ++i) {
					auto& entry = oldEntries[i];
					if (entry.has_value()) {
						todo.emplace_back(std::move(entry).steal());
					}
				}
				setCap(newCap);
				insert(
					std::make_move_iterator(todo.begin()),
					std::make_move_iterator(todo.end()));
			} else {
				// in with the new
				std::uninitialized_default_construct_n(newEntries, newCap);
				setCap(newCap);
				set_entries(newEntries);

				if (oldEntries) {  // out with the old
					for (size_type i = 0; i < oldCap; ++i) {
						auto& entry = oldEntries[i];
						if (entry.has_value()) {
							insert(std::move(entry).steal());
						}
					}
					std::destroy_n(oldEntries, oldCap);
					deallocate(oldEntries);
				}
			}
		}

	private:
		[[nodiscard]] static const key_type& unwrap_key(const value_type& a_value) noexcept
		{
			return traits_type::unwrap_key(a_value);
		}

		[[nodiscard]] entry_type* allocate(size_type a_count)
		{
			return static_cast<entry_type*>(_allocator.allocate_bytes(sizeof(entry_type) * a_count));
		}

		void deallocate(entry_type* a_entry) { _allocator.deallocate_bytes(a_entry); }

		[[nodiscard]] iterator do_erase(const_iterator a_pos)
		{
			assert(a_pos != end());
			const auto entry = a_pos.get_entry();
			assert(entry != nullptr);
			assert(entry->has_value());

			if (entry->next == _sentinel) {	 // end of chain
				if (auto prev = &get_entry_for(unwrap_key(entry->value)); prev != entry) {
					while (prev->next != entry) {
						prev = prev->next;
					}
					prev->next = const_cast<entry_type*>(_sentinel);  // detach from chain
				}

				entry->destroy();
			} else {  // move next into current
				*entry = std::move(*entry->next);
			}

			++_free;
			return make_iterator<iterator>(entry + 1);
		}

		template <class Iter>
		[[nodiscard]] Iter do_find(const key_type& a_key) const	 //
			noexcept(noexcept(hash_function(a_key)) && noexcept(key_eq(a_key, a_key)))
		{
			if (empty()) {
				return make_iterator<Iter>();
			}

			auto entry = &get_entry_for(a_key);
			if (entry->has_value()) {
				do {  // follow chain
					if (key_eq(unwrap_key(entry->value), a_key)) {
						return make_iterator<Iter>(entry);
					} else {
						entry = entry->next;
					}
				} while (entry != _sentinel);
			}

			return make_iterator<Iter>();
		}

		template <class P>
		[[nodiscard]] std::pair<iterator, bool> do_insert(P&& a_value)	//
			requires(std::same_as<std::decay_t<P>, value_type>)
		{
			if (const auto it = find(unwrap_key(a_value)); it != end()) {  // already exists
				return std::make_pair(it, false);
			}

			if (_free == 0) {  // no free entries
				reserve(_capacity + 1);
				assert(_free > 0);
			}

			const stl::scope_exit decrement{ [&]() noexcept { --_free; } };
			const auto			  entry = &get_entry_for(unwrap_key(a_value));
			if (entry->has_value()) {  // slot is taken, resolve conflict
				const auto free = &get_free_entry();
				const auto wouldve = &get_entry_for(unwrap_key(entry->value));
				if (wouldve == entry) {	 // hash collision
					free->emplace(std::forward<P>(a_value), std::exchange(entry->next, free));
					return std::make_pair(make_iterator<iterator>(free), true);
				} else {  // how did we get here?
					auto prev = wouldve;
					while (prev->next != entry) {
						prev = prev->next;
					}

					// evict current value and detach from chain
					*free = std::move(*entry);
					prev->next = free;
					entry->emplace(std::forward<P>(a_value), _sentinel);

					return std::make_pair(make_iterator<iterator>(entry), true);
				}
			} else {  // its free realestate
				entry->emplace(std::forward<P>(a_value), _sentinel);
				return std::make_pair(make_iterator<iterator>(entry), true);
			}
		}

		void free_resources()
		{
			if (_capacity > 0) {
				assert(get_entries() != nullptr);
				std::destroy_n(get_entries(), _capacity);
				deallocate(get_entries());
				set_entries(nullptr);
				_capacity = 0;
				_free = 0;
				_good = 0;
			}

			assert(get_entries() == nullptr);
			assert(_capacity == 0);
			assert(_free == 0);
		}

		[[nodiscard]] entry_type& get_entry_for(const key_type& a_key) const  //
			noexcept(noexcept(hash_function(a_key)))
		{
			assert(get_entries() != nullptr);
			assert(std::has_single_bit(_capacity));

			const auto hash = hash_function(a_key);
			const auto idx = hash & (_capacity - 1);  // quick modulo
			return get_entries()[idx];
		}

		[[nodiscard]] entry_type* get_entries() const noexcept { return static_cast<entry_type*>(_allocator.get_entries()); }

		[[nodiscard]] entry_type& get_free_entry() noexcept
		{
			assert(_free > 0);
			assert(get_entries() != nullptr);
			assert(std::has_single_bit(_capacity));
			assert([&]() noexcept {
				const auto begin = get_entries();
				const auto end = get_entries() + _capacity;
				return std::find_if(
						   begin,
						   end,
						   [](const auto& a_entry) noexcept {
							   return !a_entry.has_value();
						   }) != end;
			}());

			const auto entries = get_entries();
			while (entries[_good].has_value()) {
				_good = (_good + 1) & (_capacity - 1);	// wrap around w/ quick modulo
			}
			return entries[_good];
		}

		[[nodiscard]] size_type hash_function(const key_type& a_key) const	//
			noexcept(std::is_nothrow_constructible_v<hasher>&&
					std::is_nothrow_invocable_v<const hasher&, const key_type&>)
		{
			return static_cast<size_type>(hasher()(a_key));
		}

		[[nodiscard]] bool key_eq(const key_type& a_lhs, const key_type& a_rhs) const  //
			noexcept(std::is_nothrow_constructible_v<key_equal>&&
					std::is_nothrow_invocable_v<const key_equal&, const key_type&, const key_type&>)
		{
			return static_cast<bool>(key_equal()(a_lhs, a_rhs));
		}

		template <class Iter>
		[[nodiscard]] Iter make_iterator() const noexcept
		{
			return Iter(get_entries() + _capacity, get_entries() + _capacity);
		}

		template <class Iter>
		[[nodiscard]] Iter make_iterator(entry_type* a_first) const noexcept
		{
			return Iter(a_first, get_entries() + _capacity);
		}

		void set_entries(entry_type* a_entries) noexcept { _allocator.set_entries(a_entries); }

		// members
		std::uint64_t	  _pad00{ 0 };																		  // 00
		std::uint32_t	  _pad08{ 0 };																		  // 08
		size_type		  _capacity{ 0 };																	  // 0C - total # of slots, always a power of 2
		size_type		  _free{ 0 };																		  // 10 - # of free slots
		size_type		  _good{ 0 };																		  // 14 - last free index
		const entry_type* _sentinel{ reinterpret_cast<const entry_type*>(detail::BSTScatterTableSentinel) };  // 18 - signals end of chain
		allocator_type	  _allocator;																		  // 20
	};

	template <class Key, class T>
	class BSTScatterTableTraits
	{
	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = RE::BSTTuple<const key_type, mapped_type>;

		[[nodiscard]] static const key_type& unwrap_key(const value_type& a_value) noexcept { return a_value.first; }
	};

	template <class Key>
	class BSTSetTraits
	{
	public:
		using key_type = Key;
		using mapped_type = void;
		using value_type = key_type;

		[[nodiscard]] static const key_type& unwrap_key(const value_type& a_value) noexcept { return a_value; }
	};

	template <std::size_t S, std::size_t A>
	struct BSTScatterTableHeapAllocator
	{
	public:
		using size_type = std::uint32_t;
		using propagate_on_container_move_assignment = std::true_type;

		BSTScatterTableHeapAllocator() = default;
		BSTScatterTableHeapAllocator(const BSTScatterTableHeapAllocator&) = delete;

		BSTScatterTableHeapAllocator(BSTScatterTableHeapAllocator&& a_rhs) noexcept :
			_entries(std::exchange(a_rhs._entries, nullptr))
		{}

		~BSTScatterTableHeapAllocator() = default;
		BSTScatterTableHeapAllocator& operator=(const BSTScatterTableHeapAllocator&) = delete;

		BSTScatterTableHeapAllocator& operator=(BSTScatterTableHeapAllocator&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				assert(_entries == nullptr);
				_entries = std::exchange(a_rhs._entries, nullptr);
			}
			return *this;
		}

		[[nodiscard]] static constexpr size_type min_size() noexcept { return 1u << 3; }

		[[nodiscard]] void* allocate_bytes(std::size_t a_bytes)
		{
			assert(a_bytes % S == 0);
			return malloc(a_bytes);
		}

		void deallocate_bytes(void* a_ptr) { free(a_ptr); }

		[[nodiscard]] void* get_entries() const noexcept { return _entries; }
		void				set_entries(void* a_entries) noexcept { _entries = static_cast<std::byte*>(a_entries); }

	private:
		// members
		std::uint64_t _pad00{ 0 };			// 00 (20)
		std::byte*	  _entries{ nullptr };	// 08 (28)
	};

	template <std::uint32_t N>
	struct BSTStaticHashMapBase
	{
	public:
		static_assert(N > 0 && std::has_single_bit(N));

		template <std::size_t S, std::size_t A>
		struct Allocator
		{
		public:
			using size_type = std::uint32_t;
			using propagate_on_container_move_assignment = std::false_type;

			Allocator() = default;
			Allocator(const Allocator&) = delete;
			Allocator(Allocator&&) = delete;
			~Allocator() = default;
			Allocator& operator=(const Allocator&) = delete;
			Allocator& operator=(Allocator&&) = delete;

			[[nodiscard]] static constexpr size_type min_size() noexcept { return N; }

			[[nodiscard]] void* allocate_bytes(std::size_t a_bytes)
			{
				assert(a_bytes % S == 0);
				return a_bytes <= N * S ? _buffer : nullptr;
			}

			void deallocate_bytes([[maybe_unused]] void* a_ptr) { assert(a_ptr == _buffer); }

			[[nodiscard]] void* get_entries() const noexcept { return _entries; }

			void set_entries(void* a_entries) noexcept
			{
				assert(a_entries == _buffer || a_entries == nullptr);
				_entries = static_cast<std::byte*>(a_entries);
			}

		private:
			alignas(A) std::byte _buffer[N * S]{ static_cast<std::byte>(0) };  // 00 (20)
			std::byte* _entries{ nullptr };									   // ??
		};
	};

	template <std::size_t S, std::size_t A>
	class BSTScatterTableScrapAllocator
	{
	public:
		using size_type = std::uint32_t;
		using propagate_on_container_move_assignment = std::false_type;

		BSTScatterTableScrapAllocator() = default;
		BSTScatterTableScrapAllocator(const BSTScatterTableScrapAllocator&) = delete;
		BSTScatterTableScrapAllocator(BSTScatterTableScrapAllocator&&) = delete;
		~BSTScatterTableScrapAllocator() = default;
		BSTScatterTableScrapAllocator& operator=(const BSTScatterTableScrapAllocator&) = delete;
		BSTScatterTableScrapAllocator& operator=(BSTScatterTableScrapAllocator&&) = delete;

		[[nodiscard]] static constexpr size_type min_size() noexcept { return 1u << 3; }

		[[nodiscard]] void* allocate_bytes(std::size_t a_bytes)
		{
			assert(_allocator != nullptr);
			assert(a_bytes % S == 0);
			return _allocator->Allocate(a_bytes, 0x10);
		}

		void deallocate_bytes(void* a_ptr)
		{
			assert(_allocator != nullptr);
			_allocator->Deallocate(a_ptr);
		}

		[[nodiscard]] void* get_entries() const noexcept { return _entries; }
		void				set_entries(void* a_entries) noexcept { _entries = static_cast<std::byte*>(a_entries); }

	private:
		// members
		ScrapHeap* _allocator{ MemoryManager::GetSingleton().GetThreadScrapHeap() };  // 00 (20)
		std::byte* _entries{ nullptr };												  // 08 (28)
	};

	template <
		class Key,
		class T,
		class Hash = BSCRC32<Key>,
		class KeyEq = std::equal_to<Key>>
	using BSTHashMap =
		BSTScatterTable<
			Hash,
			KeyEq,
			BSTScatterTableTraits<Key, T>,
			BSTScatterTableHeapAllocator>;

	template <
		class Key,
		class Hash = BSCRC32<Key>,
		class KeyEq = std::equal_to<Key>>
	using BSTSet =
		BSTScatterTable<
			Hash,
			KeyEq,
			BSTSetTraits<Key>,
			BSTScatterTableHeapAllocator>;

	template <
		class Key,
		class T,
		std::uint32_t N,
		class Hash = BSCRC32<Key>,
		class KeyEq = std::equal_to<Key>>
	using BSTStaticHashMap =
		BSTScatterTable<
			Hash,
			KeyEq,
			BSTScatterTableTraits<Key, T>,
			typename BSTStaticHashMapBase<N>::Allocator>;

	template <
		class Key,
		class T,
		class Hash = BSCRC32<Key>,
		class KeyEq = std::equal_to<Key>>
	using BSTScrapHashMap =
		BSTScatterTable<
			Hash,
			KeyEq,
			BSTScatterTableTraits<Key, T>,
			BSTScatterTableScrapAllocator>;

	using UnkKey = std::uintptr_t;
	using UnkValue = std::uintptr_t;
}
