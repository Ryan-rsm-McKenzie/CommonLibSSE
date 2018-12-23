#pragma once

#include "skse64/GameAPI.h"

#include <stdint.h>
#include <memory>
#include <utility>
#include <functional>

#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW
#include "RE/Offsets.h"


namespace RE
{
	class BSTArrayBase
	{
	public:
		typedef std::uint32_t size_type;


		BSTArrayBase() :
			_M_count(0)
		{}


		class IAllocatorFunctor
		{
		public:
			IAllocatorFunctor() {}

			virtual bool	Allocate(size_type a_num, size_type a_value_size) = 0;																					// 0
			virtual bool	Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size) = 0;	// 1
			virtual void	Free(void* a_ptr) = 0;																													// 2
			virtual ~IAllocatorFunctor() {}																															// 3


			TES_HEAP_REDEFINE_NEW();
		};


		bool empty() const
		{
			return _M_count == 0;
		}


		size_type size() const
		{
			return _M_count;
		}

	protected:
		void _allocate(IAllocatorFunctor& a_functor, size_type a_num, size_type a_value_size)
		{
			a_functor.Allocate(a_num, a_value_size);
		}


		void _resize(IAllocatorFunctor& a_functor, size_type a_num, size_type a_value_size)
		{
			a_functor.Resize(a_num, _M_count, 0, 0, a_value_size);
		}


		void _pop(size_type a_num)
		{
			_M_count -= a_num;
		}


		void _clear()
		{
			_M_count = 0;
		}


		SInt32 _push(IAllocatorFunctor& a_functor, size_type a_capacity, size_type a_value_size)
		{
			return _Push_Impl(this, a_functor, a_capacity, a_value_size);
		}


		void _move(void* a_entries, size_type a_to, size_type a_from, size_type a_num, size_type a_value_size)
		{
			_Move_Impl(this, a_entries, a_to, a_from, a_num, a_value_size);
		}


		// members
		size_type _M_count;	// 0
		size_type pad4;		// 4

	private:
		typedef SInt32 _Push_Impl_t(BSTArrayBase* a_this, IAllocatorFunctor& a_functor, size_type a_capacity, size_type a_value_size);
		static RelocAddr<_Push_Impl_t*> _Push_Impl;

		typedef void _Move_Impl_t(BSTArrayBase* a_this, void* a_entries, size_type a_to, size_type a_from, size_type a_num, size_type a_value_size);
		static RelocAddr<_Move_Impl_t*> _Move_Impl;
	};


	/*---------------------------------------------------
	/ Allocator
	/----------------------------------------------------*/
	template <class _TAlloc>
	class BSTArrayAllocatorFunctor;

	class BSTArrayHeapAllocator
	{
		friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;
	public:
		typedef BSTArrayBase::size_type size_type;
		typedef BSTArrayAllocatorFunctor<BSTArrayHeapAllocator> functor_type;


		BSTArrayHeapAllocator() :
			_M_entries(nullptr),
			_M_capacity(0)
		{}


		~BSTArrayHeapAllocator()
		{
			if (_M_entries)
				_Free();
		}


		size_type capacity() const
		{
			return _M_capacity;
		}

	protected:
		void* _GetEntries()
		{
			return _M_entries;
		}


		const void* _GetEntries() const
		{
			return _M_entries;
		}


		inline bool _Allocate(size_type a_num, size_type a_value_size)
		{
			return _Allocate_Impl(this, a_num, a_value_size);
		}


		inline bool _Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size)
		{
			return _Resize_Impl(this, a_needNum, a_copyFrontNum, a_copySkipNum, a_copyTailNum, a_value_size);
		}


		inline void _Free()
		{
			_Free_Impl(this);
		}


		// members
		void*		_M_entries;		// 0
		size_type	_M_capacity;	// 8
		size_type	padC;			// C

	private:
		typedef bool _Allocate_Impl_t(BSTArrayHeapAllocator* a_this, size_type a_num, size_type a_value_size);
		static RelocAddr<_Allocate_Impl_t*> _Allocate_Impl;

		typedef bool _Resize_Impl_t(BSTArrayHeapAllocator* a_this, size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size);
		static RelocAddr<_Resize_Impl_t*> _Resize_Impl;

		typedef void _Free_Impl_t(BSTArrayHeapAllocator* a_this);
		static RelocAddr<_Free_Impl_t*> _Free_Impl;
	};


	template <std::uint32_t LOCAL_SIZE>
	class BSTSmallArrayHeapAllocator
	{
	public:
		typedef BSTArrayBase::size_type size_type;
		typedef BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator> functor_type;


		enum { kLocalAlloc = 0x80000000 };


		BSTSmallArrayHeapAllocator() :
			_M_capacity(LOCAL_SIZE | kLocalAlloc)
		{}


		~BSTSmallArrayHeapAllocator()
		{
			if (!_IsLocal() && _M_capacity) {
				_Free();
			}
		}


		size_type capacity() const
		{
			return (_M_capacity & ~kLocalAlloc);
		}

	protected:
		void* _GetEntries()
		{
			return _IsLocal() ? _M_entries.local : _M_entries.heap;
		}


		const void* _GetEntries() const
		{
			return _IsLocal() ? _M_entries.local : _M_entries.heap;
		}


		bool _IsLocal() const
		{
			return (_M_capacity & kLocalAlloc) != 0;
		}

	protected:
		union Entry
		{
			void*	heap;
			char	local[LOCAL_SIZE];
		};


		// members
		size_type	_M_capacity;	// 00
		size_type	pad04;			// 04
		Entry		_M_entries;		// 08

	private:
		friend class BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator>;


		inline bool _Allocate(size_type a_num, size_type a_value_size, size_type a_local_size = LOCAL_SIZE)
		{
			return _Allocate_Impl(this, a_num, a_value_size, a_local_size);
		}


		inline bool _Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size, size_type a_local_size = LOCAL_SIZE)
		{
			return _Resize_Impl(this, a_needNum, a_copyFrontNum, a_copySkipNum, a_copyTailNum, a_value_size, a_local_size);
		}


		inline void _Free()
		{
			_Free_Impl(this, );
		}

	private:
		typedef bool _Allocate_Impl_t(BSTSmallArrayHeapAllocator* a_this, size_type a_num, size_type a_value_size, size_type a_local_size);
		static RelocAddr<_Allocate_Impl_t*> _Allocate_Impl;

		typedef bool _Resize_Impl_t(BSTSmallArrayHeapAllocator* a_this, size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size, size_type a_local_size);
		static RelocAddr<_Resize_Impl_t*> _Resize_Impl;

		typedef void _Free_Impl_t(BSTSmallArrayHeapAllocator* a_this);
		static RelocAddr<_Free_Impl_t*> _Free_Impl;
	};


	template <std::uint32_t LOCAL_SIZE>
	RelocAddr<typename BSTSmallArrayHeapAllocator<LOCAL_SIZE>::_Allocate_Impl_t*> BSTSmallArrayHeapAllocator<LOCAL_SIZE>::_Allocate_Impl(BST_SMALL_ARRAY_HEAP_ALLOCATOR_ALLOCATE_IMPL);
	template <std::uint32_t LOCAL_SIZE>
	RelocAddr<typename BSTSmallArrayHeapAllocator<LOCAL_SIZE>::_Resize_Impl_t*> BSTSmallArrayHeapAllocator<LOCAL_SIZE>::_Resize_Impl(BST_SMALL_ARRAY_HEAP_ALLOCATOR_RESIZE_IMPL);
	template <std::uint32_t LOCAL_SIZE>
	RelocAddr<typename BSTSmallArrayHeapAllocator<LOCAL_SIZE>::_Free_Impl_t*> BSTSmallArrayHeapAllocator<LOCAL_SIZE>::_Free_Impl(BST_SMALL_ARRAY_HEAP_ALLOCATOR_FREE_IMPL);


	class BSScrapArrayAllocator
	{
	public:
		typedef BSTArrayBase::size_type size_type;
		typedef BSTArrayAllocatorFunctor<BSScrapArrayAllocator> functor_type;


		BSScrapArrayAllocator() :
			_M_allocator(nullptr),
			_M_entries(nullptr),
			_M_capacity(0)
		{}


		~BSScrapArrayAllocator()
		{
			if (_M_entries) {
				_Free();
			}
		}


		size_type capacity() const
		{
			return _M_capacity;
		}

	protected:
		void* _GetEntries()
		{
			return _M_entries;
		}


		const void* _GetEntries() const
		{
			return _M_entries;
		}


		// members
		void*		_M_allocator;	// 00 - memory allocator
		void*		_M_entries;		// 08
		size_type	_M_capacity;	// 10

	private:
		friend class BSTArrayAllocatorFunctor<BSScrapArrayAllocator>;
		friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;


		inline bool _Allocate(size_type a_num, size_type a_value_size)
		{
			return _Allocate_Impl(this, a_num, a_value_size);
		}


		inline bool _Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size)
		{
			return _Resize_Impl(this, a_needNum, a_copyFrontNum, a_copySkipNum, a_copyTailNum, a_value_size);
		}


		inline void _Free()
		{
			_Free_Impl(this);
		}

	private:
		typedef bool _Allocate_Impl_t(BSScrapArrayAllocator* a_this, size_type a_num, size_type a_value_size);
		static RelocAddr<_Allocate_Impl_t*> _Allocate_Impl;

		typedef bool _Resize_Impl_t(BSScrapArrayAllocator* a_this, size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size);
		static RelocAddr<_Resize_Impl_t*> _Resize_Impl;

		typedef void _Free_Impl_t(BSScrapArrayAllocator* a_this);
		static RelocAddr<_Free_Impl_t*> _Free_Impl;
	};


	// AllocatorFunctor
	template <class _TAlloc>
	class BSTArrayAllocatorFunctor : public BSTArrayBase::IAllocatorFunctor
	{
	public:
		typedef BSTArrayBase::size_type size_type;
		typedef _TAlloc allocator_type;


		explicit BSTArrayAllocatorFunctor(allocator_type * a_allocator) :
			m_pAllocator(a_allocator)
		{}


		virtual bool Allocate(size_type a_num, size_type a_value_size) override
		{
			return m_pAllocator->_Allocate(a_num, a_value_size);
		}


		virtual bool Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size) override
		{
			return m_pAllocator->_Resize(a_needNum, a_copyFrontNum, a_copySkipNum, a_copyTailNum, a_value_size);
		}


		virtual void Free(void* a_ptr) override
		{
			m_pAllocator->_Free();
		}

	protected:
		// members
		allocator_type*	m_pAllocator;	// 08
	};

	/*---------------------------------------------------
	/ BSTArray
	/----------------------------------------------------*/

	// the same type as tArray in skse
	template <class _Ty, class _TAlloc = BSTArrayHeapAllocator>
	class BSTArray : public _TAlloc, public BSTArrayBase
	{
	public:
		typedef _TAlloc allocator_type;
		typedef BSTArrayAllocatorFunctor<allocator_type> functor_type;
		typedef _Ty value_type;
		typedef _Ty* pointer;
		typedef const _Ty* const_pointer;
		typedef _Ty& reference;
		typedef const _Ty& const_reference;
		typedef BSTArrayBase::size_type size_type;
		typedef std::ptrdiff_t difference_type;


		// compiler hints for GCC
		using _TAlloc::_GetEntries;
		using _TAlloc::capacity;


		TES_HEAP_REDEFINE_NEW();


		typedef pointer			iterator;
		typedef const_pointer	const_iterator;

	protected:
		pointer _head() const
		{
			return const_cast<pointer>((const_pointer)_GetEntries());
		}


		pointer _tail() const
		{
			return _head() + size() - 1;
		}


		pointer _last() const
		{
			return _head() + size();
		}


		void _set(UInt32 a_index, UInt32 a_num, const value_type& a_val)
		{
			pointer *p = _head() + a_index;
			while (a_num > 0) {
				new(p)value_type(a_val);
				--a_num;
			}
		}

	public:
		BSTArray()
		{}


		BSTArray(const BSTArray& a_rhs)
		{
			UInt32 size = a_rhs.GetSize();
			if (size > 0) {
				functor_type pred(this);
				_allocate(pred, size, sizeof(value_type));
				pointer p = a_rhs->_head();
				pointer last = a_rhs->_last();
				while (p <= last)
					push_back(*p++);
			}
		}


		explicit BSTArray(std::uint32_t a_num)
		{
			functor_type pred(this);
			_allocate(pred, a_num, sizeof(value_type));
		}


		~BSTArray()
		{
			for (std::uint32_t i = 0; i < size(); ++i) {
				(*this)[i].~value_type();
			}
		}


		iterator begin()
		{
			return _head();
		}


		const_iterator cbegin() const
		{
			return _head();
		}


		const_iterator begin() const
		{
			return cbegin();
		}


		iterator end()
		{
			return _last();
		}


		const_iterator cend() const
		{
			return _last();
		}


		const_iterator end() const
		{
			return cend();
		}


		reference front()
		{
			return *_head();
		}


		const_reference front() const
		{
			return *_head();
		}


		reference back()
		{
			return *_tail();
		}


		const_reference back() const
		{
			return *_tail();
		}


		reference operator[] (size_type a_index)
		{
			return *(&front() + a_index);
		}


		const_reference operator[] (size_type a_index) const
		{
			return *(&front() + a_index);
		}


		void clear()
		{
			pointer last = _last();
			for (pointer p = _head(); p < last; ++p)
				p->~value_type();
			_clear();
		}


		void reserve(size_type a_num)
		{
			const size_type cap = capacity();
			if (cap >= a_num)
				return;

			functor_type pred(this);
			if (cap) {
				_resize(pred, a_num, sizeof(value_type));
			} else {
				_allocate(pred, a_num, sizeof(value_type));
			}
		}


		void push_front(const_reference a_ref)
		{
			functor_type pred(this);
			SInt32 index = _push(pred, capacity(), sizeof(value_type));
			if (index >= 0) {
				_move(_head(), 1, 0, index, sizeof(value_type));
				new(_head())value_type(a_ref);
			}
		}


		void push_front(value_type&& a_ref)
		{
			functor_type pred(this);
			SInt32 index = _push(pred, capacity(), sizeof(value_type));
			if (index >= 0) {
				_move(_head(), 1, 0, index, sizeof(value_type));
				new(_head())value_type(a_ref);
			}
		}


		void push_back(const_reference a_ref)
		{
			functor_type pred(this);
			SInt32 index = _push(pred, capacity(), sizeof(value_type));
			if (index >= 0) {
				new(_head() + index)value_type(a_ref);
			}
		}


		void push_back(value_type&& a_ref)
		{
			functor_type pred(this);
			SInt32 index = _push(pred, capacity(), sizeof(value_type));
			if (index >= 0) {
				new(_head() + index)value_type(a_ref);
			}
		}


		template <class... ValTy>
		void emplace_front(ValTy&&... a_val)
		{
			functor_type pred(this);
			SInt32 index = _push(pred, capacity(), sizeof(value_type));
			if (index >= 0) {
				_move(_head(), 1, 0, index, sizeof(value_type));
				new(_head())value_type(std::forward<ValTy>(a_val)...);
			}
		}


		template <class... ValTy>
		void emplace_back(ValTy&&... a_val)
		{
			functor_type pred(this);
			SInt32 index = _push(pred, capacity(), sizeof(value_type));
			if (index >= 0) {
				new(_head() + index)value_type(std::forward<ValTy>(a_val)...);
			}
		}


		void pop_front()
		{
			if (size()) {
				_head()->~value_type();
				_move(_head(), 0, size() - 1, 1, sizeof(value_type));
				_pop(1);
			}
		}


		void pop_back()
		{
			std::uint32_t num = size();
			if (num) {
				pointer p = &front() + (num - 1);
				p->~value_type();
				_pop(1);
			}
		}


		inline iterator erase(iterator a_it)
		{
			if (begin() <= a_it && a_it < end()) {
				difference_type index = a_it - begin();
				a_it->~value_type();

				difference_type next = index + 1;
				std::uint32_t num = size() - next;
				if (num > 0)
					_move(_head(), index, next, num, sizeof(value_type));
				_pop(1);
			}
			return a_it;
		}


		//==================================================


		inline UInt32 GetSize() const
		{
			return size();
		}


		inline UInt32 GetCapacity() const
		{
			return capacity();
		}


		inline reference Front()
		{
			return front();
		}


		inline const_reference Front() const
		{
			return front();
		}


		inline bool GetAt(size_type a_index, reference a_val) const
		{
			return (a_index < size()) ? (a_val = *(_head() + a_index), true) : false;
		}


		inline bool SetAt(size_type a_index, const_reference a_val)
		{
			return (a_index < size()) ? (*(_head() + a_index) = a_val, true) : false;
		}


		inline bool SetAt(size_type a_index, value_type&& a_rval)
		{
			return (a_index < size()) ? (*(_head() + a_index) = a_rval, true) : false;
		}


		inline bool GetNthItem(size_type a_index, reference a_val) const
		{
			return (a_index < size()) ? (a_val = *(_head() + a_index), true) : false;
		}


		inline void Add(const_reference a_ref)
		{
			push_back(a_ref);
		}


		inline void Add(value_type&& a_ref)
		{
			push_back(a_ref);
		}


		void Remove(const_reference a_ref)
		{
			SInt32 index = Find(a_ref);
			if (index != -1) {
				pointer p = _head() + index;
				p->~value_type();

				UInt32 next = index + 1;
				std::uint32_t num = size() - next;
				if (num > 0)
					_move(_head(), index, next, num, sizeof(value_type));
				_pop(1);
			}
		}


		void RemoveAtEndFill(size_type a_index, size_type a_num = 1)
		{
			pointer p = _head() + a_index;
			for (std::uint32_t i = 0; i < a_num; i++) {
				(p++)->~value_type();
			}

			size_type n = size();
			size_type tailNum = n - (a_index + a_num);
			if (tailNum > 0) {
				if (tailNum >= a_num)
					tailNum = a_num;
				size_type from = n - tailNum;
				size_type to = a_index;
				_move(_head(), to, from, tailNum, sizeof(value_type));
			}
			_pop(a_num);
		}


		inline void RemoveEnd()
		{
			pop_back();
		}


		inline void RemoveAll()
		{
			clear();
		}


		inline void PopBack()
		{
			pop_back();
		}


		inline void PopFront()
		{
			pop_front();
		}


		SInt32 Find(const_reference a_ref) const
		{
			const_pointer entries = _head();
			SInt32 index = -1;
			for (size_type i = 0; i < size(); ++i) {
				if (entries[i] == a_ref) {
					index = i;
					break;
				}
			}
			return index;
		}


		template <class Predicate>
		SInt32 FindIf(Predicate a_pred) const
		{
			const_pointer entries = _head();
			SInt32 index = -1;
			for (size_type i = 0; i < size(); ++i) {
				if (a_pred(entries[i])) {
					index = i;
					break;
				}
			}
			return index;
		}

	protected:
		//members
		//void*		_M_entries;		// 00
		//size_type	_M_capacity;	// 08
		//size_type	padC;			// 0C
		//size_type _M_count;		// 10
		//size_type pad4;			// 14
	};


	template<class _Ty, std::uint32_t num = 1>
	using BSTSmallArray = BSTArray <_Ty, BSTSmallArrayHeapAllocator<sizeof(_Ty)*num>>;
	//members
	//size_type	_M_capacity;	// 00
	//size_type	pad04;			// 04
	//Entry		_M_entries;		// 08
	//size_type _M_count;		// 10
	//size_type pad4;			// 14


	template <class _Ty>
	class BSScrapArray : public BSTArray <_Ty, BSScrapArrayAllocator>
	{
	public:
		BSScrapArray() : BSTArray() {}
		explicit BSScrapArray(std::uint32_t a_size) : BSTArray(a_size) {}

	protected:
		// members
		//void*		_M_allocator;	// 00 - memory allocator
		//void*		_M_entries;		// 08
		//size_type	_M_capacity;	// 10
		//size_type _M_count;		// 10
		//size_type pad4;			// 14
	};


	// Returns if/where the element was found, otherwise indexOut can be used as insert position
	template <typename Ty>
	bool GetSortIndex(const BSTArray<Ty>& a_sortedArray, const Ty& a_elem, std::uint32_t* a_indexOut)
	{
		if (a_sortedArray.empty()) {
			*a_indexOut = 0;
			return false;
		}

		int leftIdx = 0;
		int rightIdx = a_sortedArray.size() - 1;

		while (true) {
			int pivotIdx = leftIdx + ((rightIdx - leftIdx) / 2);

			const Ty &val = a_sortedArray[pivotIdx];

			if (a_elem == val) {
				*a_indexOut = pivotIdx;
				return true;
			} else if (a_elem > val) {
				leftIdx = pivotIdx + 1;
			} else {
				rightIdx = pivotIdx - 1;
			}

			if (leftIdx > rightIdx) {
				*a_indexOut = leftIdx;
				return false;
			}
		}
	}
}
