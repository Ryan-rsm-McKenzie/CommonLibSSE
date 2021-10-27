#pragma once

namespace RE
{
	template <class T, class Allocator, class SizePolicy>
	struct GArrayDataBase
	{
	public:
		using ValueType = T;
		using AllocatorType = Allocator;
		using SizePolicyType = SizePolicy;
		using SelfType = GArrayDataBase<T, Allocator, SizePolicy>;

		GArrayDataBase() :
			data(nullptr),
			size(0),
			policy()
		{}

		GArrayDataBase(const SizePolicy& a_policy) :
			data(nullptr),
			size(0),
			policy(a_policy)
		{}

		~GArrayDataBase()
		{
			Allocator::DestructArray(data, size);
			Allocator::Free(data);
		}

		UPInt GetCapacity() const
		{
			return policy.GetCapacity();
		}

		void ClearAndRelease()
		{
			Allocator::DestructArray(data, size);
			Allocator::Free(data);
			data = nullptr;
			size = 0;
			policy.SetCapacity(0);
		}

		void Reserve(const void* a_heapAddr, UPInt a_newCapacity)
		{
			if (policy.NeverShrinking() && a_newCapacity < GetCapacity())
				return;

			if (a_newCapacity < policy.GetMinCapacity())
				a_newCapacity = policy.GetMinCapacity();

			if (a_newCapacity == 0) {
				if (data) {
					Allocator::Free(data);
					data = nullptr;
				}
				policy.SetCapacity(0);
			} else {
				UPInt gran = policy.GetGranularity();
				UPInt newCapacity = (a_newCapacity + gran - 1) / gran * gran;
				if (data) {
					if (Allocator::IsMovable()) {
						data = (T*)Allocator::Realloc(data, sizeof(T) * newCapacity);
					} else {
						T* newData = (T*)Allocator::Alloc(a_heapAddr, sizeof(T) * newCapacity);
						for (UPInt i = 0; i < size; ++i) {
							Allocator::Construct(&newData[i], data[i]);
							Allocator::Destruct(&data[i]);
						}
						Allocator::Free(data);
						data = newData;
					}
				} else {
					data = (T*)Allocator::Alloc(a_heapAddr, sizeof(T) * newCapacity);
				}
				policy.SetCapacity(newCapacity);
			}
		}

		void ResizeNoConstruct(const void* a_heapAddr, UPInt a_newSize)
		{
			UPInt oldSize = size;

			if (a_newSize < oldSize) {
				Allocator::DestructArray(data + a_newSize, oldSize - a_newSize);
				if (a_newSize < (policy.GetCapacity() >> 1)) {
					Reserve(a_heapAddr, a_newSize);
				}
			} else if (a_newSize >= policy.GetCapacity()) {
				Reserve(a_heapAddr, a_newSize + (a_newSize >> 2));
			}
			size = a_newSize;
		}

		// members
		T*         data;    // 00
		UPInt      size;    // 08
		SizePolicy policy;  // 10
	};
}
