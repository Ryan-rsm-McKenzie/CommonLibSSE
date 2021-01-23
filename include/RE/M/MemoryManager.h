#pragma once

#include "RE/S/ScrapHeap.h"

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

		[[nodiscard]] static MemoryManager* GetSingleton()
		{
			using func_t = decltype(&MemoryManager::GetSingleton);
			REL::Relocation<func_t> func{ REL::ID(11045) };
			return func();
		}

		[[nodiscard]] void* Allocate(std::size_t a_size, std::int32_t a_alignment, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Allocate);
			REL::Relocation<func_t> func{ REL::ID(66859) };
			return func(this, a_size, a_alignment, a_alignmentRequired);
		}

		void Deallocate(void* a_mem, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Deallocate);
			REL::Relocation<func_t> func{ REL::ID(66861) };
			return func(this, a_mem, a_alignmentRequired);
		}

		[[nodiscard]] ScrapHeap* GetThreadScrapHeap()
		{
			using func_t = decltype(&MemoryManager::GetThreadScrapHeap);
			REL::Relocation<func_t> func{ REL::ID(66841) };
			return func(this);
		}

		[[nodiscard]] void* Reallocate(void* a_oldMem, std::size_t a_newSize, std::int32_t a_alignment, bool a_aligned)
		{
			using func_t = decltype(&MemoryManager::Reallocate);
			REL::Relocation<func_t> func{ REL::ID(66860) };
			return func(this, a_oldMem, a_newSize, a_alignment, a_aligned);
		}

		void RegisterMemoryManager()
		{
			using func_t = decltype(&MemoryManager::RegisterMemoryManager);
			REL::Relocation<func_t> func{ REL::ID(35199) };
			return func(this);
		}

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
		using difference_type = std::ptrdiff_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using iterator = value_type*;
		using const_iterator = const value_type*;

		constexpr SimpleArray() noexcept = default;

		explicit SimpleArray(size_type a_count) { resize(a_count); }

		~SimpleArray()
		{
			static_assert(!std::is_trivially_destructible_v<value_type>, "there's no allocation overhead for trivially destructible types");
			clear();
		}

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < size());
			return _data[a_pos];
		}

		[[nodiscard]] const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < size());
			return _data[a_pos];
		}

		[[nodiscard]] reference		  front() noexcept { return operator[](0); }
		[[nodiscard]] const_reference front() const noexcept { return operator[](0); }

		[[nodiscard]] reference		  back() noexcept { return operator[](size() - 1); }
		[[nodiscard]] const_reference back() const noexcept { return operator[](size() - 1); }

		[[nodiscard]] pointer		data() noexcept { return _data; }
		[[nodiscard]] const_pointer data() const noexcept { return _data; }

		[[nodiscard]] iterator		 begin() noexcept { return _data; }
		[[nodiscard]] const_iterator begin() const noexcept { return _data; }
		[[nodiscard]] const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] iterator		 end() noexcept { return _data ? _data + size() : nullptr; }
		[[nodiscard]] const_iterator end() const noexcept { return _data ? _data + size() : nullptr; }
		[[nodiscard]] const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] bool empty() const noexcept { return size() == 0; }

		[[nodiscard]] size_type size() const noexcept { return _data ? *static_cast<const std::size_t*>(get_head()) : 0; }

		void clear()
		{
			if (_data) {
				std::destroy_n(data(), size());
				free(get_head());
				_data = nullptr;
			}
		}

		void resize(size_type a_count)
		{
			const auto oldSize = size();
			if (oldSize == a_count) {
				return;
			}

			const auto newData = [=]() {
				auto bytes = sizeof(value_type) * a_count;
				if constexpr (alignof(value_type) > alignof(std::size_t)) {
					bytes += sizeof(value_type);
				} else {
					bytes += sizeof(std::size_t);
				}

				const auto data = malloc<std::size_t>(bytes);
				*data = a_count;

				if constexpr (alignof(value_type) > alignof(std::size_t)) {
					return reinterpret_cast<pointer>(data) + 1;
				} else {
					return reinterpret_cast<pointer>(data + 1);
				}
			}();

			if (a_count < oldSize) {  // shrink
				std::uninitialized_move_n(data(), a_count, newData);
			} else {  // grow
				std::uninitialized_move_n(data(), oldSize, newData);
				std::uninitialized_default_construct_n(newData + oldSize, a_count - oldSize);
			}

			clear();
			_data = newData;
		}

	protected:
		[[nodiscard]] void* get_head() noexcept
		{
			assert(_data != nullptr);
			if constexpr (alignof(value_type) > alignof(std::size_t)) {
				return _data - 1;
			} else {
				return reinterpret_cast<std::size_t*>(_data) - 1;
			}
		}

		[[nodiscard]] const void* get_head() const noexcept
		{
			assert(_data != nullptr);
			if constexpr (alignof(value_type) > alignof(std::size_t)) {
				return _data - 1;
			} else {
				return reinterpret_cast<const std::size_t*>(_data) - 1;
			}
		}

		// members
		pointer _data{ nullptr };  // 0
	};
}
