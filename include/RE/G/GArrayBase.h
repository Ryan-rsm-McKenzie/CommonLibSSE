#pragma once

#include "GMemory.h"

namespace RE
{
	class GMemoryHeap;

	template <class T>
	class GArrayBase
	{
	public:
		using ValueType = T::ValueType;
		using AllocatorType = T::AllocatorType;
		using SizePolicyType = T::SizePolicyType;
		using SelfType = GArrayBase<T>;

		struct iterator
		{
		public:
			iterator() :
				array(nullptr),
				curIndex(-1)
			{}

			iterator(SelfType* a_arr, SPInt a_idx = 0) :
				array(a_arr),
				curIndex(a_idx)
			{}

			bool operator==(const iterator& a_it) const
			{
				return array == a_it.array && curIndex == a_it.curIndex;
			}

			bool operator!=(const iterator& a_it) const
			{
				return array != a_it.array || curIndex != a_it.curIndex;
			}

			iterator& operator++()
			{
				if (array) {
					if (curIndex < static_cast<SPInt>(array->GetSize())) {
						++curIndex;
					}
				}
				return *this;
			}

			iterator operator++(std::int32_t)
			{
				iterator it(*this);
						 operator++();
				return it;
			}

			iterator& operator--()
			{
				if (array) {
					if (curIndex >= 0) {
						--curIndex;
					}
				}
				return *this;
			}

			iterator operator--(std::int32_t)
			{
				iterator it(*this);
						 operator--();
				return it;
			}

			iterator operator+(std::int32_t a_delta) const
			{
				return iterator(array, curIndex + a_delta);
			}

			iterator operator-(std::int32_t a_delta) const
			{
				return iterator(array, curIndex - a_delta);
			}

			SPInt operator-(const iterator& a_right) const
			{
				assert(array == a_right.array);
				return curIndex - a_right.curIndex;
			}

			ValueType& operator*() const
			{
				assert(array);
				return (*array)[curIndex];
			}

			ValueType* operator->() const
			{
				assert(array);
				return &(*array)[curIndex];
			}

			ValueType* GetPtr() const
			{
				assert(array);
				return &(*array)[curIndex];
			}

			bool IsFinished() const
			{
				return !array || curIndex < 0 || curIndex >= static_cast<std::int32_t>(array->GetSize());
			}

			void Remove()
			{
				if (!IsFinished()) {
					array->RemoveAt(curIndex);
				}
			}

			SPInt GetIndex() const
			{
				return curIndex;
			}

		private:
			SelfType* array;
			SPInt     curIndex;
		};

		struct const_iterator
		{
		public:
			const_iterator() :
				array(nullptr),
				curIndex(-1)
			{}

			const_iterator(const SelfType* a_arr, SPInt a_idx = 0) :
				array(a_arr),
				curIndex(a_idx)
			{}

			bool operator==(const const_iterator& a_it) const
			{
				return array == a_it.array && curIndex == a_it.curIndex;
			}

			bool operator!=(const const_iterator& a_it) const
			{
				return array != a_it.array || curIndex != a_it.curIndex;
			}

			const_iterator& operator++()
			{
				if (array) {
					if (curIndex < static_cast<std::int32_t>(array->GetSize())) {
						++curIndex;
					}
				}
				return *this;
			}

			const_iterator operator++(std::int32_t)
			{
				const_iterator it(*this);
							   operator++();
				return it;
			}

			const_iterator& operator--()
			{
				if (array) {
					if (curIndex >= 0)
						--curIndex;
				}
				return *this;
			}

			const_iterator operator--(std::int32_t)
			{
				const_iterator it(*this);
							   operator--();
				return it;
			}

			const_iterator operator+(std::int32_t a_delta) const
			{
				return const_iterator(array, curIndex + a_delta);
			}

			const_iterator operator-(std::int32_t a_delta) const
			{
				return const_iterator(array, curIndex - a_delta);
			}

			SPInt operator-(const const_iterator& a_right) const
			{
				assert(array == a_right.array);
				return curIndex - a_right.curIndex;
			}

			const ValueType& operator*() const
			{
				assert(array);
				return (*array)[curIndex];
			}

			const ValueType* operator->() const
			{
				assert(array);
				return &(*array)[curIndex];
			}

			const ValueType* GetPtr() const
			{
				assert(array);
				return &(*array)[curIndex];
			}

			bool IsFinished() const
			{
				return !array || curIndex < 0 || curIndex >= static_cast<std::int32_t>(array->GetSize());
			}

			SPInt GetIndex() const
			{
				return curIndex;
			}

		private:
			const SelfType* array;
			SPInt           curIndex;
		};

		GFC_MEMORY_REDEFINE_NEW(GArrayBase, AllocatorType::StatId);

		GArrayBase() :
			data()
		{}

		GArrayBase(std::int32_t a_size) :
			data(a_size)
		{}

		GArrayBase(const SelfType& a_array) :
			data(a_array.data)
		{}

		GArrayBase(GMemoryHeap* a_heap) :
			data(a_heap)
		{}

		GArrayBase(GMemoryHeap* a_heap, std::int32_t a_size) :
			data(a_heap, a_size)
		{}

		GArrayBase(const ValueType& a_defaultVal) :
			data(a_defaultVal)
		{}

		GArrayBase(const ValueType& a_defaultVal, std::int32_t a_size) :
			data(a_defaultVal, a_size)
		{}

		SizePolicyType* GetSizePolicy() const
		{
			return data.policy;
		}

		void SetSizePolicy(const SizePolicyType& a_policy)
		{
			data.policy = a_policy;
		}

		bool NeverShrinking() const
		{
			return data.policy.NeverShrinking();
		}

		UPInt GetSize() const
		{
			return data.size;
		}

		UPInt GetCapacity() const
		{
			return data.GetCapacity();
		}

		UPInt GetNumBytes() const
		{
			return data.GetCapacity() * sizeof(ValueType);
		}

		void ClearAndRelease()
		{
			data.ClearAndRelease();
		}

		void Clear()
		{
			data.Resize(0);
		}

		void Resize(UPInt a_newSize)
		{
			data.Resize(a_newSize);
		}

		void Reserve(UPInt a_newCapacity)
		{
			if (a_newCapacity > data.GetCapacity()) {
				data.Reserve(a_newCapacity);
			}
		}

		ValueType& At(UPInt a_index)
		{
			assert(a_index < data.size);
			return data.data[a_index];
		}

		const ValueType& At(UPInt a_index) const
		{
			assert(a_index < data.size);
			return data.data[a_index];
		}

		ValueType ValueAt(UPInt a_index) const
		{
			assert(a_index < data.size);
			return data.data[a_index];
		}

		ValueType& operator[](UPInt a_index)
		{
			assert(a_index < data.size);
			return data.data[a_index];
		}

		const ValueType& operator[](UPInt a_index) const
		{
			assert(a_index < data.size);
			return data.data[a_index];
		}

		void PushBack(const ValueType& a_val)
		{
			data.PushBack(a_val);
		}

		template <class S>
		void PushBackAlt(const S& a_val)
		{
			data.PushBackAlt(a_val);
		}

		void PopBack()
		{
			assert(data.size > 0);
			data.Resize(data.size - 1);
		}

		ValueType& Front()
		{
			return At(0);
		}

		const ValueType& Front() const
		{
			return At(0);
		}

		ValueType& Back()
		{
			return At(data.size - 1);
		}

		const ValueType& Back() const
		{
			return At(data.size - 1);
		}

		const SelfType& operator=(const SelfType& a_array)
		{
			Resize(a_array.GetSize());
			for (UPInt i = 0; i < data.size; i++) {
				*(data.data + i) = a_array[i];
			}
			return *this;
		}

		void RemoveMultipleAt(UPInt a_index, UPInt a_num)
		{
			assert(a_index + a_num <= data.size);

			if (data.size == a_num) {
				Clear();
			} else {
				AllocatorType::DestructArray(data.data + a_index, a_num);
				AllocatorType::CopyArrayForward(
					data.data + a_index,
					data.data + a_index + a_num,
					data.size + a_num - a_index);
				data.size -= a_num;
			}
		}

		void RemoveAt(UPInt a_index)
		{
			assert(a_index < data.size);

			if (data.size == 1) {
				Clear();
			} else {
				AllocatorType::Destruct(data.data + a_index);
				AllocatorType::CopyArrayForward(
					data.data + a_index,
					data.data + a_index + 1,
					data.size - 1 - a_index);
				--data.size;
			}
		}

		void InsertAt(UPInt a_index, const ValueType& a_val = ValueType())
		{
			assert(a_index <= data.size);

			data.Resize(data.size + 1);
			if (a_index < data.size - 1) {
				AllocatorType::CopyArrayBackward(
					data.data + a_index + 1,
					data.data + a_index,
					data.size - 1 - a_index);
			}
			AllocatorType::Construct(data.data + a_index, a_val);
		}

		void InsertMultipleAt(UPInt a_index, UPInt a_num, const ValueType& a_val = ValueType())
		{
			assert(a_index <= data.size);

			data.Resize(data.size + a_num);
			if (a_index < data.size - a_num) {
				AllocatorType::CopyArrayBackward(
					data.data + a_index + a_num,
					data.data + a_index,
					data.size - a_num - a_index);
			}

			for (UPInt i = 0; i < a_num; ++i) {
				AllocatorType::Construct(data.data + a_index + i, a_val);
			}
		}

		void Append(const SelfType& a_other)
		{
			Append(a_other.data.data, a_other.GetSize());
		}

		void Append(const ValueType a_other[], UPInt a_count)
		{
			data.Append(a_other, a_count);
		}

		iterator begin()
		{
			return iterator(this);
		}

		iterator end()
		{
			return iterator(this, static_cast<SPInt>(GetSize()));
		}

		iterator Last()
		{
			return iterator(this, static_cast<SPInt>(GetSize() - 1));
		}

		const_iterator begin() const
		{
			return const_iterator(this);
		}

		const_iterator end() const
		{
			return const_iterator(this, static_cast<SPInt>(GetSize()));
		}

		const_iterator Last() const
		{
			return const_iterator(this, static_cast<SPInt>(GetSize() - 1));
		}

		// members
		T data;  // 00
	};
}
