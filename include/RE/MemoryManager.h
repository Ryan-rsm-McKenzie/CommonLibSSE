#pragma once

#include <cstring>
#include <memory>
#include <new>
#include <type_traits>

#include "RE/ScrapHeap.h"


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
			UInt32			 owningThread;	// 98
			UInt32			 pad;			// 9C
		};
		STATIC_ASSERT(sizeof(ThreadScrapHeap) == 0xA0);


		static MemoryManager* GetSingleton();

		void*	   Allocate(std::size_t a_size, SInt32 a_alignment, bool a_aligned);
		void	   Deallocate(void* a_ptr, bool a_aligned);
		ScrapHeap* GetThreadScrapHeap();
		void*	   Reallocate(void* a_ptr, std::size_t a_newSize, SInt32 a_alignment, bool a_aligned);


		// members
		bool					initialized;						// 000
		UInt8					pad001;								// 001
		UInt16					numHeaps;							// 002
		UInt16					numPhysicalHeaps;					// 004
		UInt16					pad006;								// 006
		IMemoryHeap**			heaps;								// 008
		bool*					allowOtherContextAllocs;			// 010
		IMemoryHeap*			heapsByContext[127];				// 018
		ThreadScrapHeap*		threadScrapHeap;					// 410
		IMemoryHeap**			physicalHeaps;						// 418
		IMemoryHeap*			bigAllocHeap;						// 420
		IMemoryHeap*			emergencyHeap;						// 428
		BSSmallBlockAllocator*	smallBlockAllocator;				// 430
		CompactingStore::Store* compactingStore;					// 438
		IMemoryHeap*			externalHavokAllocator;				// 440
		bool					specialHeaps;						// 448
		bool					allowPoolUse;						// 449
		UInt16					pad44A;								// 44A
		UInt32					sysAllocBytes;						// 44C
		UInt32					mallocBytes;						// 450
		UInt32					alignmentForPools;					// 450
		UInt32					mainThreadMemoryProblemPassSignal;	// 458
		UInt32					pad45C;								// 45C
		std::size_t				failedAllocationSize;				// 460
		UInt32					numMemoryProblemPassesRun;			// 468
		UInt32					pad46C;								// 46C
		std::size_t				timeOfLastMemoryProblemPass;		// 470
		IMemoryHeap*			defaultHeap;						// 478
	};
	STATIC_ASSERT(sizeof(MemoryManager) == 0x480);


	inline void* malloc(std::size_t a_size)
	{
		auto heap = MemoryManager::GetSingleton();
		if (!heap) {
			throw std::bad_alloc();
		}

		auto mem = heap->Allocate(a_size, 0, false);
		if (!mem) {
			throw std::bad_alloc();
		}

		return mem;
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
		if (!heap) {
			throw std::bad_alloc();
		}

		auto mem = heap->Allocate(a_size, static_cast<SInt32>(a_alignment), true);
		if (!mem) {
			throw std::bad_alloc();
		}

		return mem;
	}


	template <class T>
	inline T* aligned_alloc(std::size_t a_alignment, std::size_t a_size)
	{
		return static_cast<T*>(aligned_alloc(static_cast<SInt32>(a_alignment), a_size));
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
		if (!heap) {
			throw std::bad_alloc();
		}

		auto mem = heap->Reallocate(a_ptr, a_newSize, 0, false);
		if (!mem) {
			throw std::bad_alloc();
		}

		return mem;
	}


	template <class T>
	inline T* realloc(void* a_ptr, std::size_t a_newSize)
	{
		return static_cast<T*>(realloc(a_ptr, a_newSize));
	}


	inline void* aligned_realloc(void* a_ptr, std::size_t a_newSize, std::size_t a_alignment)
	{
		auto heap = MemoryManager::GetSingleton();
		if (!heap) {
			throw std::bad_alloc();
		}

		auto mem = heap->Reallocate(a_ptr, a_newSize, static_cast<SInt32>(a_alignment), true);
		if (!mem) {
			throw std::bad_alloc();
		}

		return mem;
	}


	template <class T>
	inline T* aligned_realloc(void* a_ptr, std::size_t a_newSize, std::size_t a_alignment)
	{
		return static_cast<T*>(aligned_realloc(a_ptr, a_newSize, a_alignment));
	}


	inline void free(void* a_ptr)
	{
		if (a_ptr) {
			auto heap = MemoryManager::GetSingleton();
			if (heap) {
				heap->Deallocate(a_ptr, false);
			}
		}
	}


	inline void aligned_free(void* a_ptr)
	{
		if (a_ptr) {
			auto heap = MemoryManager::GetSingleton();
			if (heap) {
				heap->Deallocate(a_ptr, true);
			}
		}
	}
}


#define TES_HEAP_REDEFINE_NEW()                                                                                     \
	inline void* operator new(std::size_t a_count) { return RE::malloc(a_count); }                                  \
	inline void* operator new[](std::size_t a_count) { return RE::malloc(a_count); }                                \
	inline void* operator new([[maybe_unused]] std::size_t a_count, void* a_plcmnt) noexcept { return a_plcmnt; }   \
	inline void* operator new[]([[maybe_unused]] std::size_t a_count, void* a_plcmnt) noexcept { return a_plcmnt; } \
	inline void	 operator delete(void* a_ptr) noexcept                                                              \
	{                                                                                                               \
		try {                                                                                                       \
			RE::free(a_ptr);                                                                                        \
		} catch (...) {                                                                                             \
		}                                                                                                           \
	}                                                                                                               \
	inline void operator delete[](void* a_ptr) noexcept                                                             \
	{                                                                                                               \
		try {                                                                                                       \
			RE::free(a_ptr);                                                                                        \
		} catch (...) {                                                                                             \
		}                                                                                                           \
	}                                                                                                               \
	inline void operator delete([[maybe_unused]] void* a_ptr, [[maybe_unused]] void* a_plcmnt) noexcept { return; } \
	inline void operator delete[]([[maybe_unused]] void* a_ptr, [[maybe_unused]] void* a_plcmnt) noexcept { return; }


namespace RE
{
	// this class is an implementation detail of operator new[]/delete[]
	template <class T>
	class SimpleArray
	{
	public:
		using value_type = T;
		using size_type = std::size_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const iterator;


		struct Head
		{
			size_type size;
		};


		struct Data
		{
			value_type entries[1];
		};


		SimpleArray() :
			_data(0)
		{}


		explicit SimpleArray(size_type a_count) :
			_data(nullptr)
		{
			resize(a_count);
		}


		~SimpleArray()
		{
			clear();
		}


		TES_HEAP_REDEFINE_NEW();


		reference operator[](size_type a_pos)
		{
			assert(a_pos < size());
			return _data->entries[a_pos];
		}


		const_reference operator[](size_type a_pos) const
		{
			assert(a_pos < size());
			return _data->entries[a_pos];
		}


		reference front()
		{
			return operator[](0);
		}


		const_reference front() const
		{
			return operator[](0);
		}


		reference back()
		{
			return operator[](size() - 1);
		}


		const_reference back() const
		{
			return operator[](size() - 1);
		}


		T* data()
		{
			return _data ? _data->entries : nullptr;
		}


		const T* data() const
		{
			return _data ? _data->entries : nullptr;
		}


		iterator begin()
		{
			return _data ? std::addressof(_data->entries[0]) : nullptr;
		}


		const_iterator begin() const
		{
			return _data ? std::addressof(_data->entries[0]) : nullptr;
		}


		const_iterator cbegin() const
		{
			return begin();
		}


		iterator end()
		{
			return _data ? std::addressof(_data->entries[size()]) : nullptr;
		}


		const_iterator end() const
		{
			return _data ? std::addressof(_data->entries[size()]) : nullptr;
		}


		const_iterator cend() const
		{
			return end();
		}


		[[nodiscard]] bool empty() const
		{
			return size() == 0;
		}


		size_type size() const
		{
			return _data ? get_head()->size : 0;
		}


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
		Head* get_head() const
		{
			assert(_data != nullptr);
			return reinterpret_cast<Head*>(_data) - 1;
		}


		size_type resize_impl(size_type a_newSize)
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
		Data* _data;  // 0
	};
	STATIC_ASSERT(sizeof(SimpleArray<void*>) == 0x8);
}
