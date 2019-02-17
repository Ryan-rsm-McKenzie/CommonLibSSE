#pragma once


namespace RE
{
	template<class C>
	class GPtr
	{
	public:
		GPtr() :
			_object(0)
		{}


		GPtr(C& a_obj)
		{
			_object = &a_obj;
		}


		GPtr(C* a_obj)
		{
			if (a_obj) {
				a_obj->AddRef();
			}
			_object = a_obj;
		}


		GPtr(const GPtr<C>& a_src)
		{
			if (a_src._object) {
				a_src._object->AddRef();
			}
			_object = a_src._object;
		}


		template<class R>
		GPtr(GPtr<R>& a_src)
		{
			if (a_src) {
				a_src->AddRef();
			}
			_object = a_src;
		}


		~GPtr()
		{
			if (_object) {
				_object->Release();
			}
		}


		bool operator==(const GPtr& a_rhs) const
		{
			return _object == a_rhs._object;
		}


		bool operator!=(const GPtr& a_rhs) const
		{
			return _object != a_rhs._object;
		}


		bool operator==(const C* a_rhs) const
		{
			return _object == a_rhs;
		}


		bool operator!=(const C* a_rhs) const
		{
			return _object != a_rhs;
		}


		bool operator==(C* a_rhs) const
		{
			return _object == a_rhs;
		}


		bool operator!=(C* a_rhs) const
		{
			return _object != a_rhs;
		}


		bool operator<(const GPtr & a_rhs) const
		{
			return _object < a_rhs._object;
		}


		template<class R>
		const GPtr<C>& operator=(const GPtr<R>& a_src)
		{
			if (a_src) {
				a_src->AddRef();
			}
			if (_object) {
				_object->Release();
			}
			_object = a_src;
			return *this;
		}


		const GPtr<C> & operator = (const GPtr<C> & src)
		{
			if (src) src->AddRef();
			if (_object) _object->Release();
			_object = src;
			return *this;
		}

		const GPtr<C>& operator=(C* a_src)
		{
			if (a_src) {
				a_src->AddRef();
			}
			if (_object) {
				_object->Release();
			}
			_object = a_src;
			return *this;
		}


		const GPtr<C>& operator=(C& a_src)
		{
			if (_object) {
				_object->Release();
			}
			_object = &a_src;
			return *this;
		}


		template<class R>
		GPtr<C>& SetPtr(const GPtr<R>& a_src)
		{
			if (a_src) {
				a_src->AddRef();
			}
			if (_object) {
				_object->Release();
			}
			_object = a_src;
			return *this;
		}


		GPtr<C>& SetPtr(const GPtr<C>& a_src)
		{
			if (a_src) {
				a_src->AddRef();
			}
			if (_object) {
				_object->Release();
			}
			_object = a_src;
			return *this;
		}


		GPtr<C>& SetPtr(C* a_src)
		{
			if (a_src) {
				a_src->AddRef();
			}
			if (_object) {
				_object->Release();
			}
			_object = a_src;
			return *this;
		}


		GPtr<C>& SetPtr(C& a_src)
		{
			if (_object) {
				_object->Release();
			}
			_object = &a_src;
			return *this;
		}


		void NullWithoutRelease()
		{
			_object = 0;
		}


		void Clear()
		{
			if (_object) {
				_object->Release();
			}
			_object = 0;
		}


		C*& GetRawRef()
		{
			return _object;
		}


		C* GetPtr() const
		{
			return _object;
		}


		C& operator*() const
		{
			return *_object;
		}


		C* operator->()  const
		{
			return _object;
		}


		operator C*() const
		{
			return _object;
		}

	protected:
		// members
		C* _object;	// 0
	};
	STATIC_ASSERT(sizeof(GPtr<void*>) == 0x8);
}
