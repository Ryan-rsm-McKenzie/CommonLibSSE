#pragma once

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	template <class Ty>
	struct BSTSmartPointerIntrusiveRefCount
	{
		typedef Ty* pointer;


		static void Attach(pointer a_ptr)
		{
			a_ptr->IncRefCount();
		}


		static void Detach(pointer a_ptr)
		{
			if (a_ptr->DecRefCount() == 0) {
				delete a_ptr;
			}
		}
	};


	template <class Ty, template <class> class RefManager = BSTSmartPointerIntrusiveRefCount>
	class BSTSmartPointer
	{
	public:
		typedef Ty				value_type;
		typedef Ty*				pointer;
		typedef const Ty*		const_pointer;
		typedef RefManager<Ty>	reference_manager;


		BSTSmartPointer() :
			_ptr(0)
		{}


		BSTSmartPointer(const BSTSmartPointer& a_ptr) :
			_ptr(0)
		{
			Attach((const_pointer)a_ptr);
		}


		BSTSmartPointer(BSTSmartPointer&& a_ptr)
		{
			_ptr = a_ptr._ptr;
			a_ptr._ptr = 0;
		}


		BSTSmartPointer(const_pointer a_ptr) :
			_ptr(0)
		{
			Attach(a_ptr);
		}


		~BSTSmartPointer()
		{
			Release();
		}


		operator pointer()
		{
			return _ptr;
		}


		operator const_pointer() const
		{
			return _ptr;
		}


		operator bool() const
		{
			return _ptr != 0;
		}


		pointer operator->()
		{
			return _ptr;
		}


		const_pointer operator->() const
		{
			return _ptr;
		}


		value_type& operator*()
		{
			return *_ptr;
		}


		const value_type& operator*() const
		{
			return *_ptr;
		}


		BSTSmartPointer& operator=(const pointer a_ptr)
		{
			Release();
			Attach(a_ptr);
			return *this;
		}


		BSTSmartPointer& operator=(const BSTSmartPointer& a_ptr)
		{
			Release();
			Attach((const_pointer)a_ptr);
			return *this;
		}


		BSTSmartPointer& operator=(BSTSmartPointer&& a_ptr)
		{
			Release();
			_ptr = a_ptr._ptr;
			a_ptr._ptr = 0;
			return *this;
		}


		pointer Get()
		{
			return _ptr;
		}


		const_pointer Get() const
		{
			return _ptr;
		}


		void Attach(const_pointer a_ptr)
		{
			_ptr = const_cast<pointer>(a_ptr);
			if (_ptr) {
				reference_manager::Attach(_ptr);
			}
		}


		void Release()
		{
			if (_ptr) {
				reference_manager::Detach(_ptr);
				_ptr = 0;
			}
		}

	protected:
		// members
		pointer _ptr;	// 0
	};
	STATIC_ASSERT(sizeof(BSTSmartPointer<void*>) == 0x8);


#define BSSmartPointer(className)						\
	class className;									\
	typedef BSTSmartPointer<className> className##Ptr;
}
