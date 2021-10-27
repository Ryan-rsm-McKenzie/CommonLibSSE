#pragma once

#include "RE/G/GArrayDataBase.h"

namespace RE
{
	template <class T, class Allocator, class SizePolicy>
	struct GArrayData : GArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
		using ValueType = T;
		using AllocatorType = Allocator;
		using SizePolicyType = SizePolicy;
		using BaseType = GArrayDataBase<T, Allocator, SizePolicy>;
		using SelfType = GArrayData<T, Allocator, SizePolicy>;

		GArrayData() :
			BaseType()
		{}

		GArrayData(std::int32_t a_size) :
			BaseType()
		{
			Resize(a_size);
		}

		GArrayData(const SelfType& a_arrayData) :
			BaseType(a_arrayData.policy)
		{
			Append(a_arrayData.data, a_arrayData.size);
		}

		void Reserve(UPInt a_newCapacity)
		{
			BaseType::Reserve(this, a_newCapacity);
		}

		void Resize(UPInt a_newSize)
		{
			UPInt oldSize = this->size;
			BaseType::ResizeNoConstruct(this, a_newSize);
			if (a_newSize > oldSize) {
				Allocator::ConstructArray(this->data + oldSize, a_newSize - oldSize);
			}
		}

		void PushBack(const ValueType& a_val)
		{
			BaseType::ResizeNoConstruct(this, this->size + 1);
			Allocator::Construct(this->data + this->size - 1, a_val);
		}

		template <class S>
		void PushBackAlt(const S& a_val)
		{
			BaseType::ResizeNoConstruct(this, this->size + 1);
			Allocator::ConstructAlt(this->data + this->size - 1, a_val);
		}

		void Append(const ValueType a_other[], UPInt a_count)
		{
			if (a_count) {
				UPInt oldSize = this->size;
				BaseType::ResizeNoConstruct(this, this->size + a_count);
				Allocator::ConstructArray(this->data + oldSize, a_count, a_other);
			}
		}
	};
}
