#pragma once

#include "RE/NiTCollection.h"  // NiTMallocInterface
#include "RE/TESMemoryManager.h"  // calloc, free


namespace RE
{
	template <class T, class Allocator = NiTMallocInterface<T>>
	class NiTArray
	{
	public:
		NiTArray();
		virtual ~NiTArray();	// 00

		// sparse array, can have nullptr entries that should be skipped
		// iterate from 0 to m_emptyRunStart - 1

		inline std::size_t GetSize() const
		{
			return _emptyRunStart;
		}


		inline std::size_t GetEffectiveSize() const
		{
			return _size;
		}


		inline std::size_t GetAllocatedSize() const
		{
			return _arrayBufLen;
		}


		inline T& GetAt(std::size_t index)
		{
			return _data[index];
		}


		inline const T& GetAt(std::size_t index) const
		{
			return _data[index];
		}

		// members
		T*		_data;			// 08
		UInt16	_arrayBufLen;	// 10 - max elements storable in _data
		UInt16	_emptyRunStart;	// 12 - index of beginning of empty slot run
		UInt16	_size;			// 14 - number of filled slots
		UInt16	_growSize;		// 16 - number of slots to grow _data by
	};
	STATIC_ASSERT(sizeof(NiTArray<void*>) == 0x18);


	template <class T>
	class NiTObjectArray : public NiTArray<T, NiTNewInterface<T>>
	{
	public:
		NiTObjectArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1);
	};
	STATIC_ASSERT(sizeof(NiTObjectArray<void*>) == 0x18);


	template <class T>
	class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T>>
	{
	public:
		NiTPrimitiveArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1);
	};
	STATIC_ASSERT(sizeof(NiTPrimitiveArray<void*>) == 0x18);


	// 18
	template <class T, class Allocator = NiTMallocInterface<T >>
	class NiTLargeArray
	{
	public:
		NiTLargeArray();
		virtual ~NiTLargeArray();


		// fast, doesn't search for empty slots
		void Append(T a_item)
		{
			if (_emptyRunStart == _arrayBufLen) {
				// need to expand the array
				Resize(_arrayBufLen + 1);
			}

			_data[_emptyRunStart] = a_item;
			_emptyRunStart++;
			_size++;
		}


		void Resize(UInt32 a_size)
		{
			// not reclaiming memory yet
			if (a_size <= _size) return;

			// obey min grow size
			UInt32	growSize = a_size - _size;
			if (growSize < _growSize) {
				growSize = _growSize;
			}

			a_size = _arrayBufLen + growSize;

			// create new array
			auto newData = calloc<T>(a_size);

			for (UInt32 i = 0; i < a_size; i++) {
				new (&newData[i]) T;
				newData[i] = 0;
			}

			// copy over data, compacting as we go
			UInt32	iter = 0;

			for (UInt32 i = 0; i < _emptyRunStart; i++) {
				if (_data[i]) {
					newData[iter] = _data[i];
					iter++;
				}
			}

			// update pointers
			T* oldData = _data;
			UInt32 oldDataLen = _emptyRunStart;

			_data = newData;
			_arrayBufLen = a_size;
			_emptyRunStart = _size;

			// delete old array
			if (oldData) {
				for (UInt32 i = 0; i < oldDataLen; i++) {
					if (oldData[i]) {
						oldData[i].~T();
					}
				}
				free(oldData);
			}
		}


		T*		_data;			// 08
		UInt32	_arrayBufLen;	// 10 - max elements storable in m_data
		UInt32	_emptyRunStart;	// 14 - index of beginning of empty slot run
		UInt32	_size;			// 18 - number of filled slots
		UInt32	_growSize;		// 1C - number of slots to grow m_data by
	};
	STATIC_ASSERT(sizeof(NiTLargeArray<void*>) == 0x20);


	template <class T>
	class NiTLargePrimitiveArray : public NiTLargeArray<T, NiTMallocInterface<T>>
	{
	public:
		NiTLargePrimitiveArray(UInt32 a_maxSize = 0, UInt32 a_growBy = 1);
	};
	STATIC_ASSERT(sizeof(NiTLargePrimitiveArray<void*>) == 0x20);
}
