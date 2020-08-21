#pragma once

#include "RE/Memory/IMemoryStoreBase/IMemoryStore/ScrapHeap.h"


namespace RE
{
	namespace CompactingStore
	{
		class Store;
	}


	class BSSmallBlockAllocator;
	class IMemoryHeap;


	class MemoryManager
	{
	public:
		struct ThreadScrapHeap
		{
		public:
			// members
			ScrapHeap		 heap;			// 00
			ThreadScrapHeap* next;			// 90
			std::uint32_t	 owningThread;	// 98
			std::uint32_t	 pad;			// 9C
		};
		static_assert(sizeof(ThreadScrapHeap) == 0xA0);


		static MemoryManager* GetSingleton();

		void*	   Allocate(std::size_t a_size, std::int32_t a_alignment, bool a_alignmentRequired);
		void	   Deallocate(void* a_mem, bool a_alignmentRequired);
		ScrapHeap* GetThreadScrapHeap();
		void*	   Reallocate(void* a_oldMem, std::size_t a_newSize, std::int32_t a_alignment, bool a_aligned);


		// members
		bool					initialized{ false };					 // 000
		std::uint16_t			numHeaps{ 0 };							 // 002
		std::uint16_t			numPhysicalHeaps{ 0 };					 // 004
		IMemoryHeap**			heaps{ nullptr };						 // 008
		bool*					allowOtherContextAllocs{ nullptr };		 // 010
		IMemoryHeap*			heapsByContext[127]{ nullptr };			 // 018
		ThreadScrapHeap*		threadScrapHeap{ nullptr };				 // 410
		IMemoryHeap**			physicalHeaps{ nullptr };				 // 418
		IMemoryHeap*			bigAllocHeap{ nullptr };				 // 420
		IMemoryHeap*			emergencyHeap{ nullptr };				 // 428
		BSSmallBlockAllocator*	smallBlockAllocator{ nullptr };			 // 430
		CompactingStore::Store* compactingStore{ nullptr };				 // 438
		IMemoryHeap*			externalHavokAllocator{ nullptr };		 // 440
		bool					specialHeaps{ false };					 // 448
		bool					allowPoolUse{ true };					 // 449
		std::uint32_t			sysAllocBytes{ 0 };						 // 44C
		std::uint32_t			mallocBytes{ 0 };						 // 450
		std::uint32_t			alignmentForPools{ 4 };					 // 450
		std::uint32_t			mainThreadMemoryProblemPassSignal{ 0 };	 // 458
		std::size_t				failedAllocationSize{ 0 };				 // 460
		std::uint32_t			numMemoryProblemPassesRun{ 0 };			 // 468
		std::size_t				timeOfLastMemoryProblemPass{ 0 };		 // 470
		IMemoryHeap*			defaultHeap{ nullptr };					 // 478
	};
	static_assert(sizeof(MemoryManager) == 0x480);


	inline void* malloc(std::size_t a_size)
	{
		auto heap = MemoryManager::GetSingleton();
		return heap ?
					 heap->Allocate(a_size, 0, false) :
					 nullptr;
	}


	template <class T>
	inline T* malloc(std::size_t a_size)
	{
		return static_cast<T*>(malloc(a_size));
	}


	template <class T>
	inline T* malloc()
	{
		return malloc<T>(sizeof(T));
	}


	inline void* aligned_alloc(std::size_t a_alignment, std::size_t a_size)
	{
		auto heap = MemoryManager::GetSingleton();
		return heap ?
					 heap->Allocate(a_size, static_cast<std::int32_t>(a_alignment), true) :
					 nullptr;
	}


	template <class T>
	inline T* aligned_alloc(std::size_t a_alignment, std::size_t a_size)
	{
		return static_cast<T*>(aligned_alloc(a_alignment, a_size));
	}


	template <class T>
	inline T* aligned_alloc()
	{
		return aligned_alloc<T>(alignof(T), sizeof(T));
	}


	inline void* calloc(std::size_t a_num, std::size_t a_size)
	{
		return malloc(a_num * a_size);
	}


	template <class T>
	inline T* calloc(std::size_t a_num, std::size_t a_size)
	{
		return static_cast<T*>(calloc(a_num, a_size));
	}


	template <class T>
	inline T* calloc(std::size_t a_num)
	{
		return calloc<T>(a_num, sizeof(T));
	}


	inline void* realloc(void* a_ptr, std::size_t a_newSize)
	{
		auto heap = MemoryManager::GetSingleton();
		return heap ?
					 heap->Reallocate(a_ptr, a_newSize, 0, false) :
					 nullptr;
	}


	template <class T>
	inline T* realloc(void* a_ptr, std::size_t a_newSize)
	{
		return static_cast<T*>(realloc(a_ptr, a_newSize));
	}


	inline void* aligned_realloc(void* a_ptr, std::size_t a_newSize, std::size_t a_alignment)
	{
		auto heap = MemoryManager::GetSingleton();
		return heap ?
					 heap->Reallocate(a_ptr, a_newSize, static_cast<std::int32_t>(a_alignment), true) :
					 nullptr;
	}


	template <class T>
	inline T* aligned_realloc(void* a_ptr, std::size_t a_newSize, std::size_t a_alignment)
	{
		return static_cast<T*>(aligned_realloc(a_ptr, a_newSize, a_alignment));
	}


	inline void free(void* a_ptr)
	{
		auto heap = MemoryManager::GetSingleton();
		if (heap) {
			heap->Deallocate(a_ptr, false);
		}
	}


	inline void aligned_free(void* a_ptr)
	{
		auto heap = MemoryManager::GetSingleton();
		if (heap) {
			heap->Deallocate(a_ptr, true);
		}
	}
}


#define TES_HEAP_REDEFINE_NEW()                                                                                         \
	[[nodiscard]] inline void* operator new(std::size_t a_count)                                                        \
	{                                                                                                                   \
		const auto mem = RE::malloc(a_count);                                                                           \
		if (mem) {                                                                                                      \
			return mem;                                                                                                 \
		} else {                                                                                                        \
			stl::report_and_fail("out of memory"sv);                                                                    \
		}                                                                                                               \
	}                                                                                                                   \
                                                                                                                        \
	[[nodiscard]] inline void* operator new[](std::size_t a_count)                                                      \
	{                                                                                                                   \
		const auto mem = RE::malloc(a_count);                                                                           \
		if (mem) {                                                                                                      \
			return mem;                                                                                                 \
		} else {                                                                                                        \
			stl::report_and_fail("out of memory"sv);                                                                    \
		}                                                                                                               \
	}                                                                                                                   \
                                                                                                                        \
	[[nodiscard]] constexpr void* operator new(std::size_t, void* a_ptr) noexcept { return a_ptr; }                     \
	[[nodiscard]] constexpr void* operator new[](std::size_t, void* a_ptr) noexcept { return a_ptr; }                   \
	[[nodiscard]] constexpr void* operator new(std::size_t, std::align_val_t, void* a_ptr) noexcept { return a_ptr; }   \
	[[nodiscard]] constexpr void* operator new[](std::size_t, std::align_val_t, void* a_ptr) noexcept { return a_ptr; } \
                                                                                                                        \
	inline void operator delete(void* a_ptr) { RE::free(a_ptr); }                                                       \
	inline void operator delete[](void* a_ptr) { RE::free(a_ptr); }                                                     \
	inline void operator delete(void* a_ptr, std::align_val_t) { RE::aligned_free(a_ptr); }                             \
	inline void operator delete[](void* a_ptr, std::align_val_t) { RE::aligned_free(a_ptr); }                           \
	inline void operator delete(void* a_ptr, std::size_t) { RE::free(a_ptr); }                                          \
	inline void operator delete[](void* a_ptr, std::size_t) { RE::free(a_ptr); }                                        \
	inline void operator delete(void* a_ptr, std::size_t, std::align_val_t) { RE::aligned_free(a_ptr); }                \
	inline void operator delete[](void* a_ptr, std::size_t, std::align_val_t) { RE::aligned_free(a_ptr); }


namespace RE
{
	// this class is an implementation detail of operator new[]/delete[]
	template <class T>
	class SimpleArray
	{
	public:
		using value_type = T;
		using size_type = std::size_t;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const iterator;

		struct Head
		{
		public:
			// memebrs
			size_type size;	 // 00
		};

		struct Data
		{
		public:
			// members
			value_type entries[1];	// 00
		};

		constexpr SimpleArray() noexcept = default;

		explicit SimpleArray(size_type a_count) { resize(a_count); }

		~SimpleArray() { clear(); }

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] constexpr reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < size());
			return _data->entries[a_pos];
		}

		[[nodiscard]] constexpr const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < size());
			return _data->entries[a_pos];
		}

		[[nodiscard]] constexpr reference		front() noexcept { return operator[](0); }
		[[nodiscard]] constexpr const_reference front() const noexcept { return operator[](0); }

		[[nodiscard]] constexpr reference		back() noexcept { return operator[](size() - 1); }
		[[nodiscard]] constexpr const_reference back() const { return operator[](size() - 1); }

		[[nodiscard]] constexpr pointer		  data() { return _data ? _data->entries : nullptr; }
		[[nodiscard]] constexpr const_pointer data() const noexcept { return _data ? _data->entries : nullptr; }

		[[nodiscard]] constexpr iterator	   begin() noexcept { return _data ? _data->entries : nullptr; }
		[[nodiscard]] constexpr const_iterator begin() const noexcept { return _data ? _data->entries : nullptr; }
		[[nodiscard]] constexpr const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] constexpr iterator	   end() noexcept { return _data ? _data->entries + size() : nullptr; }
		[[nodiscard]] constexpr const_iterator end() const noexcept { return _data ? _data->entries + size() : nullptr; }
		[[nodiscard]] constexpr const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] bool empty() const noexcept { return size() == 0; }

		[[nodiscard]] size_type size() const noexcept { return _data ? get_head()->size : 0; }

		void clear()
		{
			if (_data) {
				for (auto& elem : *this) {
					elem.~value_type();
				}
				free(get_head());
				_data = nullptr;
			}
		}

		void resize(size_type a_count)
		{
			auto oldSize = resize_impl(a_count);

			if (oldSize < a_count) {
				for (size_type i = oldSize; i < a_count; ++i) {
					new (std::addressof(_data->entries[i])) value_type{};
				}
			}
		}

		void resize(size_type a_count, const value_type& a_value)
		{
			auto oldSize = resize_impl(a_count);

			if (oldSize < a_count) {
				for (size_type i = oldSize; i < a_count; ++i) {
					new (std::addressof(_data->entries[i])) value_type{ a_value };
				}
			}
		}

	protected:
		[[nodiscard]] Head* get_head() const noexcept
		{
			assert(_data != nullptr);
			return reinterpret_cast<Head*>(_data) - 1;
		}

		[[nodiscard]] size_type resize_impl(size_type a_newSize)
		{
			auto oldSize = size();
			if (a_newSize == oldSize) {
				return oldSize;
			} else if (a_newSize == 0) {
				clear();
				return oldSize;
			}

			auto newHead = malloc<Head>(sizeof(Head) + (sizeof(value_type) * a_newSize));
			newHead->size = a_newSize;
			auto newData = reinterpret_cast<Data*>(newHead + 1);
			if (_data) {
				size_type toCopy;
				if (a_newSize < oldSize) {
					for (size_type i = a_newSize; i < oldSize; ++i) {
						_data->entries[i].~value_type();
					}
					toCopy = a_newSize;
				} else {
					toCopy = oldSize;
				}
				std::memcpy(newData->entries, data(), toCopy * sizeof(size_type));
				free(get_head());
			}
			_data = newData;

			return oldSize;
		}

		// members
		Data* _data{ nullptr };	 // 0
	};
	static_assert(sizeof(SimpleArray<void*>) == 0x8);
}
