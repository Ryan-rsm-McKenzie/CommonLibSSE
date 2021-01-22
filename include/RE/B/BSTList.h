#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	// forward list
	template <class T>
	class BSSimpleList
	{
	public:
		using value_type = T;
		using size_type = std::uint32_t;
		using reference = value_type&;
		using const_reference = const value_type&;

		struct Node
		{
		public:
			inline Node() :
				item{},
				next(nullptr)
			{}

			inline Node(value_type a_value, Node* a_next) :
				item(a_value),
				next(a_next)
			{}

			inline Node(const Node& a_rhs) :
				item(a_rhs.item),
				next(a_rhs.next)
			{}

			inline Node(Node&& a_rhs) :
				item(std::move(a_rhs.item)),
				next(std::move(a_rhs.next))
			{
				a_rhs.next = nullptr;
			}

			inline Node(const value_type& a_value) :
				item(a_value),
				next(nullptr)
			{}

			inline Node(value_type&& a_value) :
				item(std::move(a_value)),
				next(nullptr)
			{}

			~Node() = default;

			inline Node& operator=(const Node& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					item = a_rhs.item;
					next = a_rhs.next;
				}
				return *this;
			}

			inline Node& operator=(Node&& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					item = std::move(a_rhs.item);

					next = std::move(a_rhs.next);
					a_rhs.next = nullptr;
				}
				return *this;
			}

			TES_HEAP_REDEFINE_NEW();

			// members
			value_type		item;  // 00
			observer<Node*> next;  // ??
		};

		template <class U>
		class iterator_base
		{
		public:
			using difference_type = std::ptrdiff_t;
			using value_type = U;
			using pointer = U*;
			using reference = U&;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator_base() noexcept :
				_cur(nullptr)
			{}

			constexpr iterator_base(const iterator_base& a_rhs) noexcept :
				_cur(a_rhs._cur)
			{}

			constexpr iterator_base(iterator_base&& a_rhs) noexcept :
				_cur(std::move(a_rhs._cur))
			{
				a_rhs._cur = nullptr;
			}

			constexpr iterator_base(Node* a_node) noexcept :
				_cur(a_node)
			{}

			inline ~iterator_base() noexcept { _cur = nullptr; }

			constexpr iterator_base& operator=(const iterator_base& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_cur = a_rhs._cur;
				}
				return *this;
			}

			constexpr iterator_base& operator=(iterator_base&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_cur = std::move(a_rhs._cur);
					a_rhs._cur = nullptr;
				}
				return *this;
			}

			[[nodiscard]] constexpr reference operator*() const noexcept { return _cur->item; }
			[[nodiscard]] constexpr pointer	  operator->() const noexcept { return std::addressof(_cur->item); }

			[[nodiscard]] constexpr bool operator==(const iterator_base& a_rhs) const noexcept { return _cur == a_rhs._cur; }
			[[nodiscard]] constexpr bool operator!=(const iterator_base& a_rhs) const noexcept { return !(*this == a_rhs); }

			// prefix
			constexpr iterator_base& operator++() noexcept
			{
				assert(_cur);
				_cur = _cur->next;
				return *this;
			}

			// postfix
			[[nodiscard]] constexpr iterator_base operator++(int) noexcept
			{
				iterator_base tmp(*this);
				++(*this);
				return tmp;
			}

		protected:
			friend class BSSimpleList<T>;

			[[nodiscard]] constexpr Node*		get_current() noexcept { return _cur; }
			[[nodiscard]] constexpr const Node* get_current() const noexcept { return _cur; }

			[[nodiscard]] constexpr bool comes_before(const iterator_base& a_rhs) const noexcept
			{
				for (auto iter = _cur; iter; iter = iter->next) {
					if (iter == a_rhs._cur) {
						return true;
					}
				}
				return false;
			}

		private:
			observer<Node*> _cur;
		};

		using iterator = iterator_base<value_type>;
		using const_iterator = iterator_base<const value_type>;

		inline BSSimpleList() :
			_listHead()
		{}

		inline BSSimpleList(const BSSimpleList& a_rhs) :
			_listHead()
		{
			copy_from(a_rhs);
		}

		inline BSSimpleList(BSSimpleList&& a_rhs) :
			_listHead(std::move(a_rhs._listHead))
		{}

		inline ~BSSimpleList()
		{
			clear();
		}

		inline BSSimpleList& operator=(const BSSimpleList& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				clear();
				copy_from(a_rhs);
			}
			return *this;
		}

		inline BSSimpleList& operator=(BSSimpleList&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				clear();
				_listHead = std::move(a_rhs._listHead);
			}
			return *this;
		}

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] inline reference front()
		{
			assert(!empty());
			return *begin();
		}

		[[nodiscard]] inline const_reference front() const
		{
			assert(!empty());
			return *begin();
		}

		[[nodiscard]] inline iterator		begin() { return empty() ? end() : iterator(get_head()); }
		[[nodiscard]] inline const_iterator begin() const { return empty() ? end() : const_iterator(get_head()); }
		[[nodiscard]] inline const_iterator cbegin() const { return begin(); }

		[[nodiscard]] constexpr iterator	   end() noexcept { return iterator(nullptr); }
		[[nodiscard]] constexpr const_iterator end() const noexcept { return const_iterator(nullptr); }
		[[nodiscard]] constexpr const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] inline bool empty() const { return !_listHead.next && !_listHead.item; }

		inline void clear()
		{
			erase_after_impl(get_head(), nullptr);
			if (static_cast<bool>(_listHead.item)) {
				std::destroy_at(std::addressof(_listHead.item));
			}
		}

		inline iterator insert_after(const_iterator a_pos, const_reference a_value)
		{
			auto node = new Node(a_value);
			return insert_after_impl(
				a_pos.get_current(),
				std::make_pair(node, node));
		}

		inline iterator insert_after(const_iterator a_pos, value_type&& a_value)
		{
			auto node = new Node(std::move(a_value));
			return insert_after_impl(
				a_pos.get_current(),
				std::make_pair(node, node));
		}

		inline iterator insert_after(const_iterator a_pos, size_type a_count, const_reference a_value)
		{
			if (a_count <= 0) {
				return a_pos;
			}

			return insert_after_impl(
				a_pos.get_current(),
				alloc_copies(a_count, a_value));
		}

		inline iterator erase_after(const_iterator a_pos)
		{
			if (a_pos == cend()) {
				return end();
			}

			auto node = a_pos.get_current();
			erase_after_impl(node, node->next);
			return node->next;
		}

		inline iterator erase_after(const_iterator a_first, const_iterator a_last)
		{
			assert(a_first.comes_before(a_last));

			auto head = a_first.get_current();
			auto tail = a_last.get_current();

			erase_after_impl(head, tail);
			return tail;
		}

		inline void push_front(const_reference a_value) { emplace_front_impl(a_value); }
		inline void push_front(value_type&& a_value) { emplace_front_impl(std::move(a_value)); }

		template <class... Args>
		inline reference emplace_front(Args&&... a_args)
		{
			emplace_front_impl(std::forward<Args>(a_args)...);
			return front();
		}

		inline void pop_front()
		{
			assert(!empty());

			std::destroy_at(std::addressof(_listHead.item));
			auto node = _listHead.next;
			if (node) {
				_listHead.next = node->next;
				std::construct_at(std::addressof(_listHead.item), std::move(node->item));
				delete node;
			}
		}

		inline void resize(size_type a_count) { resize(a_count, value_type{}); }
		inline void resize(size_type a_count, const value_type& a_value) { resize_impl(a_count, a_value); }

	protected:
		[[nodiscard]] constexpr Node*		get_head() noexcept { return std::addressof(_listHead); }
		[[nodiscard]] constexpr const Node* get_head() const noexcept { return std::addressof(_listHead); }

		[[nodiscard]] inline std::pair<Node*, Node*> alloc_copies(size_type a_count, const_reference a_value)
		{
			assert(a_count > 0);

			auto head = new Node(a_value);
			auto tail = head;
			for (size_type i = 1; i < a_count; ++i) {
				tail->next = new Node(a_value);
				tail = tail->next;
			}

			return std::make_pair(head, tail);
		}

		inline void copy_from(const BSSimpleList& a_rhs)
		{
			auto lhs = get_head();
			auto rhs = a_rhs.get_head();

			lhs->item = rhs->item;
			while (rhs->next) {
				rhs = rhs->next;
				lhs->next = new Node(rhs->item);
				lhs = lhs->next;
			}
		}

		[[nodiscard]] inline Node* insert_after_impl(Node* a_pos, std::pair<Node*, Node*> a_values)
		{
			auto [head, tail] = a_values;

			assert(a_pos);
			assert(head && tail);

			tail->next = a_pos->next;
			a_pos->next = head;
			return tail;
		}

		inline void erase_after_impl(Node* a_head, Node* a_tail)
		{
			if (a_head && a_head != a_tail) {
				auto iter = a_head->next;
				auto tmp = iter;
				while (iter != a_tail) {
					tmp = iter;
					iter = iter->next;
					delete tmp;
				}
				a_head->next = a_tail;
			}
		}

		template <class... Args>
		inline void emplace_front_impl(Args&&... a_args)
		{
			if (static_cast<bool>(_listHead.item)) {
				auto node = new Node(std::move(_listHead));
				_listHead.next = node;
			}

			std::destroy_at(std::addressof(_listHead.item));
			std::construct_at(std::addressof(_listHead.item), std::forward<Args>(a_args)...);
		}

		inline void resize_impl(size_type a_count, const_reference a_value)
		{
			if (a_count <= 0) {
				clear();
			}

			auto	  iter = begin();
			auto	  last = end();
			size_type elems = 1;
			while (iter != last && elems != a_count) {
				++iter;
				++elems;
			}

			if (elems < a_count) {
				// need to grow
				insert_after(iter, a_count - elems, a_value);
			} else if (iter != last) {
				// need to shrink
				erase_after(iter, last);
			} else {
				// already required size
			}
		}

		// members
		Node _listHead;	 // 00

		// T				_item;	// 00
		// BSSimpleList<T>* _next;	// ??
	};
}
