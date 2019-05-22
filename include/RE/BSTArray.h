#pragma once

#include "skse64/GameAPI.h"

#include <stdint.h>
#include <memory>
#include <utility>
#include <functional>

#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	class BSTArrayBase
	{
	public:
		using size_type = UInt32;


		class IAllocatorFunctor
		{
		public:
			IAllocatorFunctor();

			// add
			virtual bool	Allocate(size_type a_num, size_type a_valueSize) = 0;																				// 00
			virtual bool	Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_valueSize) = 0;	// 01
			virtual void	Free(void* a_ptr) = 0;																												// 02

			virtual ~IAllocatorFunctor();																														// 03

			TES_HEAP_REDEFINE_NEW();
		};
		STATIC_ASSERT(sizeof(IAllocatorFunctor) == 0x8);


		BSTArrayBase() :
			_count(0),
			_pad4(0)
		{}


		bool empty() const
		{
			return _count == 0;
		}


		size_type size() const
		{
			return _count;
		}

	protected:
		void _allocate(IAllocatorFunctor& a_functor, size_type a_num, size_type a_valueSize)
		{
			a_functor.Allocate(a_num, a_valueSize);
		}


		void _resize(IAllocatorFunctor& a_functor, size_type a_num, size_type a_valueSize)
		{
			a_functor.Resize(a_num, _count, 0, 0, a_valueSize);
		}


		void _pop(size_type a_num)
		{
			_count -= a_num;
		}


		void _clear()
		{
			_count = 0;
		}


		SInt32 _push(IAllocatorFunctor& a_functor, size_type a_capacity, size_type a_valueSize)
		{
			using func_t = function_type_t<decltype(&BSTArrayBase::_push)>;
			REL::Offset<func_t*> func(RE::Offset::BSTArrayBase::Push);
			return func(this, a_functor, a_capacity, a_valueSize);
		}


		void _move(void* a_entries, size_type a_to, size_type a_from, size_type a_num, size_type a_valueSize)
		{
			using func_t = function_type_t<decltype(&BSTArrayBase::_move)>;
			REL::Offset<func_t*> func(RE::Offset::BSTArrayBase::Move);
			return func(this, a_entries, a_to, a_from, a_num, a_valueSize);
		}

	public:
		// members
		size_type	_count;	// 0
		size_type	_pad4;	// 4
	};
	STATIC_ASSERT(sizeof(BSTArrayBase) == 0x8);


	/*---------------------------------------------------
	/ Allocator
	/----------------------------------------------------*/
	template <class Allocator> class BSTArrayAllocatorFunctor;


	class BSTArrayHeapAllocator
	{
		friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;


		BSTArrayHeapAllocator() :
			_entries(nullptr),
			_capacity(0),
			_pad0C(0)
		{}


		~BSTArrayHeapAllocator()
		{
			if (_entries) {
				_Free();
			}
		}


		size_type capacity() const
		{
			return _capacity;
		}

	protected:
		void* _GetEntries()
		{
			return _entries;
		}


		const void* _GetEntries() const
		{
			return _entries;
		}


		inline bool _Allocate(size_type a_num, size_type a_valueSize)
		{
			using func_t = function_type_t<decltype(&BSTArrayHeapAllocator::_Allocate)>;
			REL::Offset<func_t*> func(RE::Offset::BSTArrayHeapAllocator::Allocate);
			return func(this, a_num, a_valueSize);
		}


		inline bool _Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_valueSize)
		{
			using func_t = function_type_t<decltype(&BSTArrayHeapAllocator::_Resize)>;
			REL::Offset<func_t*> func(RE::Offset::BSTArrayHeapAllocator::Resize);
			return func(this, a_needNum, a_copyFrontNum, a_copySkipNum, a_copyTailNum, a_valueSize);
		}


		inline void _Free()
		{
			using func_t = function_type_t<decltype(&BSTArrayHeapAllocator::_Free)>;
			REL::Offset<func_t*> func(RE::Offset::BSTArrayHeapAllocator::Free);
			return func(this);
		}

	public:
		// members
		void*		_entries;	// 00
		size_type	_capacity;	// 08
		size_type	_pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(BSTArrayHeapAllocator) == 0x10);


	template <std::uint32_t LOCAL_SIZE>
	class BSTSmallArrayHeapAllocator
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator>;


		enum { kLocalAlloc = 0x80000000 };


		BSTSmallArrayHeapAllocator() :
			_pad04(0),
			_capacity(LOCAL_SIZE | kLocalAlloc),
			_entries()
		{}


		~BSTSmallArrayHeapAllocator()
		{
			if (!_IsLocal() && _capacity) {
				_Free();
			}
		}


		size_type capacity() const
		{
			return (_capacity & ~kLocalAlloc);
		}

	protected:
		void* _GetEntries()
		{
			return _IsLocal() ? _entries.local : _entries.heap;
		}


		const void* _GetEntries() const
		{
			return _IsLocal() ? _entries.local : _entries.heap;
		}


		bool _IsLocal() const
		{
			return (_capacity & kLocalAlloc) != 0;
		}

	protected:
		union Entry
		{
			Entry() : heap(0) {}

			void*	heap;
			char	local[LOCAL_SIZE];
		};

	public:
		// members
		size_type	_capacity;	// 00
		size_type	_pad04;		// 04
		Entry		_entries;	// 08

	private:
		friend class BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator>;


		inline bool _Allocate(size_type a_num, size_type a_valueSize, size_type a_localSize = LOCAL_SIZE)
		{
			using func_t = function_type_t<decltype(&_Allocate)>;
			REL::Offset<func_t*> func(Offset::BSTSmallArrayHeapAllocator::Allocate);
			return func(this, a_num, a_valueSize, a_localSize);
		}


		inline bool _Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_valueSize, size_type a_localSize = LOCAL_SIZE)
		{
			using func_t = function_type_t<decltype(&_Resize)>;
			REL::Offset<func_t*> func(Offset::BSTSmallArrayHeapAllocator::Resize);
			return func(this, a_needNum, a_copyFrontNum, a_copySkipNum, a_copyTailNum, a_valueSize, a_localSize);
		}


		inline void _Free()
		{
			using func_t = function_type_t<decltype(&_Free)>;
			REL::Offset<func_t*> func(Offset::BSTSmallArrayHeapAllocator::Free);
			return func(this);
		}
	};


	class BSScrapArrayAllocator
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSScrapArrayAllocator>;


		BSScrapArrayAllocator() :
			_allocator(nullptr),
			_entries(nullptr),
			_capacity(0),
			_pad14(0)
		{}


		~BSScrapArrayAllocator()
		{
			if (_entries) {
				_Free();
			}
		}


		size_type capacity() const
		{
			return _capacity;
		}

	protected:
		void* _GetEntries()
		{
			return _entries;
		}


		const void* _GetEntries() const
		{
			return _entries;
		}

	public:
		// members
		void*		_allocator;	// 00 - ScrapHeap*
		void*		_entries;	// 08
		size_type	_capacity;	// 10
		size_type	_pad14;		// 14

	private:
		friend class BSTArrayAllocatorFunctor<BSScrapArrayAllocator>;
		friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;


		inline bool _Allocate(size_type a_num, size_type a_valueSize)
		{
			using func_t = function_type_t<decltype(&BSScrapArrayAllocator::_Allocate)>;
			REL::Offset<func_t*> func(RE::Offset::BSScrapArrayAllocator::Allocate);
			return func(this, a_num, a_valueSize);
		}


		inline bool _Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_valueSize)
		{
			using func_t = function_type_t<decltype(&BSScrapArrayAllocator::_Resize)>;
			REL::Offset<func_t*> func(RE::Offset::BSScrapArrayAllocator::Resize);
			return func(this, a_needNum, a_copyFrontNum, a_copySkipNum, a_copyTailNum, a_valueSize);
		}


		inline void _Free()
		{
			using func_t = function_type_t<decltype(&BSScrapArrayAllocator::_Free)>;
			REL::Offset<func_t*> func(RE::Offset::BSScrapArrayAllocator::Free);
			return func(this);
		}
	};


	// AllocatorFunctor
	template <class Allocator>
	class BSTArrayAllocatorFunctor : public BSTArrayBase::IAllocatorFunctor
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using allocator_type = Allocator;


		explicit BSTArrayAllocatorFunctor(allocator_type* a_allocator) :
			_allocator(a_allocator)
		{}


		virtual bool Allocate(size_type a_num, size_type a_value_size) override
		{
			return _allocator->_Allocate(a_num, a_value_size);
		}


		virtual bool Resize(size_type a_needNum, size_type a_copyFrontNum, size_type a_copySkipNum, size_type a_copyTailNum, size_type a_value_size) override
		{
			return _allocator->_Resize(a_needNum, a_copyFrontNum, a_copySkipNum, a_copyTailNum, a_value_size);
		}


		virtual void Free(void* a_ptr) override
		{
			_allocator->_Free();
		}

	public:
		// members
		allocator_type* _allocator;	// 08
	};

	/*---------------------------------------------------
	/ BSTArray
	/----------------------------------------------------*/

	// the same type as tArray in skse
	template <class T, class Allocator = BSTArrayHeapAllocator>
	class BSTArray :
		public Allocator,
		public BSTArrayBase
	{
	public:
		using allocator_type = Allocator;
		using functor_type = BSTArrayAllocatorFunctor<allocator_type>;
		using value_type = T;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using size_type = typename BSTArrayBase::size_type;
		using difference_type = std::ptrdiff_t;
		using iterator = pointer;
		using const_iterator = const_pointer;

		using Allocator::_GetEntries;
		using Allocator::capacity;


		TES_HEAP_REDEFINE_NEW();

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
				new(p) value_type(a_val);
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
				pointer p = a_rhs._head();
				pointer last = a_rhs._last();
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


		template <class... Args>
		void emplace_front(Args&& ... a_args)
		{
			functor_type pred(this);
			SInt32 index = _push(pred, capacity(), sizeof(value_type));
			if (index >= 0) {
				_move(_head(), 1, 0, index, sizeof(value_type));
				new(_head())value_type(std::forward<Args>(a_args)...);
			}
		}


		template <class... Args>
		void emplace_back(Args&& ... a_args)
		{
			functor_type pred(this);
			SInt32 index = _push(pred, capacity(), sizeof(value_type));
			if (index >= 0) {
				new(_head() + index)value_type(std::forward<Args>(a_args)...);
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
			UInt32 num = size();
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
				UInt32 num = size() - next;
				if (num > 0) {
					_move(_head(), index, next, num, sizeof(value_type));
				}
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
				if (num > 0) {
					_move(_head(), index, next, num, sizeof(value_type));
				}
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
		//void*		_entries;	// 00
		//size_type	_capacity;	// 08
		//size_type	_pad0C;		// 0C
		//size_type _count;		// 10
		//size_type _pad14;		// 14
	};
	namespace { using TestBSTArray = BSTArray<std::uint32_t>; }
	STATIC_ASSERT(offsetof(TestBSTArray, _entries) == 0x00);
	STATIC_ASSERT(offsetof(TestBSTArray, _capacity) == 0x08);
	STATIC_ASSERT(offsetof(TestBSTArray, _count) == 0x10);
	STATIC_ASSERT(sizeof(TestBSTArray) == 0x18);


	template<class T, std::uint32_t SIZE = 1>
	using BSTSmallArray = BSTArray<T, BSTSmallArrayHeapAllocator<sizeof(T) * SIZE>>;
	//members
	//size_type	_capacity;	// 00
	//size_type	_pad04;		// 04
	//Entry		_entries;	// 08
	//size_type _count;		// 10
	//size_type _pad14;		// 14
	namespace { using TestBSTSmallArray = BSTSmallArray<std::uint32_t>; }
	STATIC_ASSERT(offsetof(TestBSTSmallArray, _capacity) == 0x00);
	STATIC_ASSERT(offsetof(TestBSTSmallArray, _entries) == 0x08);
	STATIC_ASSERT(offsetof(TestBSTSmallArray, _count) == 0x10);
	STATIC_ASSERT(sizeof(TestBSTSmallArray) == 0x18);


	template <class T>
	class BSScrapArray : public BSTArray <T, BSScrapArrayAllocator>
	{
	public:
		BSScrapArray() : BSTArray() {}
		explicit BSScrapArray(std::uint32_t a_size) : BSTArray(a_size) {}

	protected:
		// members
		//void*		_allocator;	// 00 - memory allocator
		//void*		_entries;	// 08
		//size_type	_capacity;	// 10
		//size_type	_pad14;		// 14
		//size_type _count;		// 18
		//size_type _pad14;		// 1C
	};
	namespace { using TestBSScrapArray = BSScrapArray<std::uint32_t>; }
	STATIC_ASSERT(offsetof(TestBSScrapArray, _allocator) == 0x00);
	STATIC_ASSERT(offsetof(TestBSScrapArray, _entries) == 0x08);
	STATIC_ASSERT(offsetof(TestBSScrapArray, _capacity) == 0x10);
	STATIC_ASSERT(offsetof(TestBSScrapArray, _count) == 0x18);
	STATIC_ASSERT(sizeof(TestBSScrapArray) == 0x20);


	// Returns if/where the element was found, otherwise indexOut can be used as insert position
	template <class T>
	bool GetSortIndex(const BSTArray<T>& a_sortedArray, const T& a_elem, std::size_t& a_indexOut)
	{
		if (a_sortedArray.empty()) {
			a_indexOut = 0;
			return false;
		}

		std::size_t leftIdx = 0;
		std::size_t rightIdx = a_sortedArray.size() - 1;

		while (true) {
			int pivotIdx = leftIdx + ((rightIdx - leftIdx) / 2);

			const T& val = a_sortedArray[pivotIdx];

			if (a_elem == val) {
				a_indexOut = pivotIdx;
				return true;
			} else if (a_elem > val) {
				leftIdx = pivotIdx + 1;
			} else {
				rightIdx = pivotIdx - 1;
			}

			if (leftIdx > rightIdx) {
				a_indexOut = leftIdx;
				return false;
			}
		}
	}
}
