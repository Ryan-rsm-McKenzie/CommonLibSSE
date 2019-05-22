#pragma once

#include <algorithm>  // min
#include <cassert>  // assert
#include <cmath>  // ceil
#include <cstring>  // memcpy

#include "RE/hkContainerAllocators.h"  // hkContainerHeapAllocator


namespace RE
{
	template <class T>
	class hkArrayBase
	{
	public:
		using value_type = T;
		using size_type = SInt32;
		using reference = value_type&;
		using const_reference = const value_type&;


		reference operator[](size_type a_pos)
		{
			assert(a_pos >= 0 && a_pos < size());
			return _data[a_pos];
		}


		const_reference operator[](size_type a_pos) const
		{
			assert(a_pos >= 0 && a_pos < size());
			return _data[a_pos];
		}


		size_type size() const noexcept
		{
			return _size;
		}


		void reserve(size_type a_newCap)
		{
			assert(a_newCap <= kCapacityMask);
			if (a_newCap <= capacity()) {
				return;
			}

			auto allocator = hkContainerHeapAllocator::GetSingleton();
			size_type newSize = a_newCap * sizeof(T);
			T* newMem = static_cast<T*>(allocator->BufAlloc(newSize));
			if (_data) {
				size_type oldSize = size() * sizeof(T);
				std::memcpy(newMem, _data, oldSize);
				if ((_capacityAndFlags & kDontDeallocFlag) == 0) {
					allocator->BufFree(_data, oldSize);
				}
			}

			_data = newMem;
			_capacityAndFlags &= ~kCapacityMask;
			_capacityAndFlags |= a_newCap & kCapacityMask;
		}


		size_type capacity() const noexcept
		{
			return _capacityAndFlags & kCapacityMask;
		}


		void push_back(const T& a_value)
		{
			if (size() == capacity()) {
				reserve(static_cast<size_type>(std::ceil(size() * GROWTH_FACTOR)));
			}
			_data[_size++] = a_value;
		}


		void resize(size_type a_count)
		{
			assert(a_count > 0 && a_count <= kCapacityMask);
			if (a_count == size()) {
				return;
			}

			if (a_count < size()) {	// if shrink
				for (size_type i = a_count; i < size(); ++i) {
					_data[i].~T();
				}
			}

			auto allocator = hkContainerHeapAllocator::GetSingleton();
			size_type newSize = a_count * sizeof(T);
			T* newMem = static_cast<T*>(allocator->BufAlloc(newSize));
			if (_data) {
				size_type oldSize = size() * sizeof(T);
				std::memcpy(newMem, _data, std::min(oldSize, newSize));
				if ((_capacityAndFlags & kDontDeallocFlag) == 0) {
					allocator->BufFree(_data, oldSize);
				}
			}

			if (a_count > size()) {	// if grow
				for (size_type i = size(); i < a_count; ++i) {
					new(&newMem[i]) T{};
				}
			}

			_data = newMem;
			_size = a_count;
			_capacityAndFlags &= ~kCapacityMask;
			_capacityAndFlags |= a_count & kCapacityMask;
		}





		enum : UInt32
		{
			kCapacityMask = 0x3FFFFFFF,
			kFlagMask = 0xC0000000,
			kDontDeallocFlag = (UInt32)1 << 31
		};


		static constexpr float GROWTH_FACTOR = 1.5;	// NOT PART OF NATIVE TYPE


		T*		_data;				// 00
		SInt32	_size;				// 08
		SInt32	_capacityAndFlags;	// 0C
	};
	STATIC_ASSERT(sizeof(hkArrayBase<void*>) == 0x10);


	template <class T, class Allocator = void>
	class hkArray : public hkArrayBase<T>
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkArray<void*>) == 0x10);


	template <class T, std::size_t N, class Allocator = void>
	class hkInplaceArray : public hkArray<T, Allocator>
	{
	public:
		T storage[N];	// 10
	};
}
