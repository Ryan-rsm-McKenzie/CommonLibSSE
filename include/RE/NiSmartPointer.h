#pragma once


namespace RE
{
#define NiSmartPointer(className)					\
	class className;								\
	typedef NiPointer<className> className##Ptr;


	template <class Ty>
	class NiPointer
	{
	public:
		typedef Ty*			pointer;
		typedef const Ty*	const_pointer;
		typedef Ty&			reference;
		typedef const Ty&	const_reference;


		// constructor and destractor
		NiPointer(pointer a_objPtr = (pointer)0)
		{
			_object = a_objPtr;
			if (_object) {
				_object->IncRefCount();
			}
		}


		NiPointer(const NiPointer& a_ptr)
		{
			_object = a_ptr._object;
			if (_object) {
				_object->IncRefCount();
			}
		}


		NiPointer(const NiPointer&& a_ptr)
		{
			_object = a_ptr._object;
			a_ptr._object = 0;
		}


		~NiPointer()
		{
			if (_object) {
				_object->DecRefCount();
			}
		}


		// type conversions
		operator pointer() const
		{
			return _object;
		}


		reference operator*()
		{
			return *_object;
		}


		pointer operator->()
		{
			return _object;
		}


		// assignment
		NiPointer& operator=(pointer a_objPtr)
		{
			if (_object) {
				_object->DecRefCount();
			}
			_object = a_objPtr;
			if (_object) {
				_object->IncRefCount();
			}
			return *this;
		}


		NiPointer& operator=(const NiPointer& a_rhs)
		{
			if (_object) {
				_object->DecRefCount();
			}
			_object = a_rhs.pObject;
			if (_object) {
				_object->IncRefCount();
			}
			return *this;
		}


		NiPointer& operator=(NiPointer&& a_rhs)
		{
			_object = a_rhs._object;
			a_rhs._object = 0;
			return *this;
		}


		// comparisons
		bool operator==(const pointer a_objPtr) const
		{
			return (_object == a_objPtr);
		}


		bool operator!=(const pointer a_objPtr) const
		{
			return (_object != a_objPtr);
		}


		bool operator==(const NiPointer& a_rhs) const
		{
			return (_object == a_rhs._object);
		}


		bool operator!=(const NiPointer& a_rhs) const
		{
			return (_object != a_rhs._object);
		}

	protected:
		pointer _object;	// 0
	};
	using TestNiPointer = NiPointer<uint32_t>;
	STATIC_ASSERT(sizeof(TestNiPointer) == 0x8);
}
