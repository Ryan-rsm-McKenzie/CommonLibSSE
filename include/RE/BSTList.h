#pragma once

#include "skse64/GameAPI.h"  // Heap

#include <new>
#include <utility>

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/Memory.h"


namespace RE
{
	// forward list
	template <class _Ty>
	class BSSimpleList
	{
	public:
		typedef _Ty			value_type;
		typedef _Ty*		pointer;
		typedef const _Ty*	const_pointer;
		typedef _Ty&		reference;
		typedef const _Ty&	const_reference;
		typedef std::size_t	size_type;


		struct Node
		{
			value_type	item;
			Node*		next;


			Node() :
				item(0),
				next(0)
			{}


			bool empty() const
			{
				return this == 0;
			}
		};
		typedef Node* NodePtr;


		class const_iterator
		{
		protected:
			friend class iterator;

		public:
			typedef const_iterator							_iter;
			typedef typename BSSimpleList::const_reference	reference;
			typedef typename BSSimpleList::const_pointer	pointer;


			const_iterator() :
				m_cur(0)
			{}


			const_iterator(const NodePtr a_node) :
				m_cur(const_cast<NodePtr>(a_node))
			{}


			operator pointer() const
			{
				return &m_cur->item;
			}


			bool empty() const
			{
				return m_cur->empty();
			}


			operator bool() const
			{
				return !empty();
			}


			reference operator*() const
			{
				return m_cur->item;
			}


			pointer operator->() const
			{
				return &m_cur->item;
			}


			_iter& operator++()
			{
				m_cur = m_cur->next;
				return *this;
			}


			_iter operator++(int)
			{
				_iter tmp = *this;
				++*this;
				return tmp;
			}


			bool operator==(const _iter& a_rhs) const
			{
				return (m_cur == a_rhs.m_cur);
			}


			bool operator!=(const _iter& a_rhs) const
			{
				return (!(*this == a_rhs));
			}

		protected:
			NodePtr m_cur;
		};


		class iterator : public const_iterator
		{
		public:
			typedef iterator							_iter;
			typedef typename BSSimpleList::reference	reference;
			typedef typename BSSimpleList::pointer		pointer;

			using const_iterator::m_cur;


			iterator()
			{}


			iterator(NodePtr a_node) :
				const_iterator(a_node)
			{}


			operator pointer()
			{
				return &m_cur->item;
			}


			reference operator*()
			{
				return m_cur->item;
			}


			pointer operator->()
			{
				return &m_cur->item;
			}


			_iter& operator++()
			{
				m_cur = m_cur->next;
				return *this;
			}


			_iter operator++(int)
			{
				_iter tmp = *this;
				++*this;
				return tmp;
			}


			bool operator==(const _iter& a_rhs) const
			{
				return (m_cur == a_rhs.m_cur);
			}


			bool operator!=(const _iter& a_rhs) const
			{
				return (!(*this == a_rhs));
			}


			bool operator==(const const_iterator& a_rhs) const
			{
				return (m_cur == a_rhs.m_cur);
			}


			bool operator!=(const const_iterator& a_rhs) const
			{
				return (!(*this == a_rhs));
			}
		};


		BSSimpleList()
		{
			m_listHead.item = 0;
			m_listHead.next = 0;
		}


		~BSSimpleList()
		{
			clear();
		}


		static void* operator new(std::size_t a_size)
		{
			return Heap_Allocate(a_size);
		}


		static void* operator new(std::size_t a_size, const std::nothrow_t&)
		{
			return Heap_Allocate(a_size);
		}


		static void* operator new(std::size_t a_size, void* a_ptr)
		{
			return a_ptr;
		}


		static void operator delete(void* a_ptr)
		{
			Heap_Free(a_ptr);
		}


		static void operator delete(void* a_ptr, const std::nothrow_t&)
		{
			Heap_Free(a_ptr);
		}


		static void operator delete(void*, void*)
		{}

	private:
		NodePtr _head() const
		{
			return const_cast<NodePtr>(&m_listHead);
		}


		NodePtr _tail() const
		{
			NodePtr cur = _head();
			while (cur->next) {
				cur = cur->next;
			}
			return const_cast<NodePtr>(cur);
		}

	public:
		iterator begin()
		{
			return iterator(empty() ? 0 : _head());
		}


		const_iterator cbegin() const
		{
			return const_iterator(empty() ? 0 : _head());
		}


		const_iterator begin() const
		{
			return cbegin();
		}


		iterator end()
		{
			return iterator(0);
		}


		const_iterator cend() const
		{
			return const_iterator(0);
		}


		const_iterator end() const
		{
			return cend();
		}


		reference front()
		{
			return _head()->item;
		}


		const_reference front() const
		{
			return _head()->item;
		}


		reference back()
		{
			return _tail()->item;
		}


		const_reference back() const
		{
			return _tail()->item;
		}


		bool empty() const
		{
			return (!m_listHead.next && !m_listHead.item);
		}


		size_type size() const
		{
			size_type num = 0;
			for (const_iterator it = cbegin(); !it.empty(); ++it)
				++num;
			return num;
		}


		void clear()
		{
			while (!empty())
				pop_front();
		}


		void push_front(const_reference a_ref)
		{
			NodePtr node = _make_node_front();
			if (node) {
				new (&node->item)value_type(a_ref);
			}
		}


		void push_back(const_reference a_ref)
		{
			NodePtr node = _make_node_back();
			if (node) {
				new (&node->item)value_type(a_ref);
			}
		}


		void pop_front()
		{
			if (empty())
				return;

			NodePtr next = m_listHead.next;
			if (next->empty()) {
				m_listHead.item.~value_type();
				m_listHead.item = 0;
				m_listHead.next = 0;
			} else {
				m_listHead.item = std::move(next->item);
				m_listHead.next = next->next;
			}

			Heap_Free(next);
		}


		// insert ref before it
		void insert(const_iterator a_it, const_reference a_ref)
		{
			NodePtr node = _make_node_at(a_it);
			if (node) {
				new (&node->item)value_type(a_ref);
			}
		}


		// insert ref after it
		void insert_after(const_iterator a_it, const_reference a_ref)
		{
			NodePtr node = _make_node_after(a_it);
			if (node) {
				new (&node->item)value_type(a_ref);
			}
		}

	private:
		NodePtr _make_node_front()
		{
			if (!empty()) {
				NodePtr newNode = Heap_Allocate<Node>();
				if (!newNode) {
					return 0;
				}
				new (&newNode->item)value_type(std::move(m_listHead.item));
				newNode->next = m_listHead.next;
				m_listHead.next = newNode;
			}
			return &m_listHead;
		}


		NodePtr _make_node_back()
		{
			if (empty()) {
				return &m_listHead;
			}

			NodePtr newNode = Heap_Allocate<Node>();
			if (!newNode) {
				return 0;
			}

			NodePtr tail = _tail();
			tail->next = newNode;
			newNode->next = 0;
			return tail;
		}


		// make node before it
		NodePtr _make_node_at(const_iterator a_it)
		{
			if (a_it == cbegin()) {
				return _make_node_front();
			}

			NodePtr node = &m_listHead;
			do {
				if (node->next == a_it.m_cur) {
					NodePtr newNode = Heap_Allocate<Node>();
					if (newNode) {
						newNode->next = node->next;
						node->next = newNode;
					}
					return newNode;
				}

				node = node->next;
			} while (!node->empty());

			return 0;
		}


		// make node after it
		NodePtr _make_node_after(const_iterator a_it)
		{
			NodePtr node = a_it.m_cur;
			NodePtr newNode = Heap_Allocate<Node>();
			if (newNode) {
				newNode->next = node->next;
				node->next = newNode;
			}
			return newNode;
		}

	protected:
		Node m_listHead;	// 00
	};


	// forward list
	template <>
	class BSSimpleList<BSExtraData*>
	{
	public:
		typedef BSExtraData			value_type;
		typedef BSExtraData*		pointer;
		typedef const BSExtraData*	const_pointer;
		typedef std::size_t			size_type;


		typedef BSExtraData* NodePtr;

		class iterator;


		class const_iterator
		{
		protected:
			friend class iterator;

		public:
			const_iterator() :
				_cur(0)
			{}


			const_iterator(const NodePtr a_node) :
				_cur(const_cast<NodePtr>(a_node))
			{}


			operator pointer() const
			{
				return _cur;
			}


			bool empty() const
			{
				return _cur == 0;
			}


			operator bool() const
			{
				return !empty();
			}


			pointer operator->() const
			{
				return _cur;
			}


			const_iterator& operator++()
			{
				_cur = _cur->next;
				return *this;
			}


			const_iterator operator++(int)
			{
				const_iterator tmp = *this;
				++*this;
				return tmp;
			}


			bool operator==(const const_iterator& a_rhs) const
			{
				return (_cur == a_rhs._cur);
			}


			bool operator!=(const const_iterator& a_rhs) const
			{
				return !this->operator==(a_rhs);
			}

		protected:
			NodePtr _cur;
		};


		class iterator : public const_iterator
		{
		public:
			using const_iterator::_cur;


			iterator()
			{}


			iterator(NodePtr a_node) :
				const_iterator(a_node)
			{}


			operator pointer()
			{
				return _cur;
			}


			pointer operator*()
			{
				return _cur;
			}


			pointer operator->()
			{
				return _cur;
			}


			iterator& operator++()
			{
				_cur = _cur->next;
				return *this;
			}


			iterator operator++(int)
			{
				iterator tmp = *this;
				++*this;
				return tmp;
			}


			bool operator==(const iterator& a_rhs) const
			{
				return _cur == a_rhs._cur;
			}


			bool operator!=(const iterator& a_rhs) const
			{
				return !this->operator==(a_rhs);
			}


			bool operator==(const const_iterator& a_rhs) const
			{
				return _cur == a_rhs._cur;
			}


			bool operator!=(const const_iterator& a_rhs) const
			{
				return !this->operator==(a_rhs);
			}
		};


		BSSimpleList() :
			_listHead(0)
		{}


		~BSSimpleList()
		{
			clear();
		}


		static void* operator new(std::size_t a_size)
		{
			return Heap_Allocate(a_size);
		}


		static void* operator new(std::size_t a_size, const std::nothrow_t&)
		{
			return Heap_Allocate(a_size);
		}


		static void* operator new(std::size_t a_size, void* a_ptr)
		{
			return a_ptr;
		}


		static void operator delete(void* a_ptr)
		{
			Heap_Free(a_ptr);
		}


		static void operator delete(void* a_ptr, const std::nothrow_t&)
		{
			Heap_Free(a_ptr);
		}


		static void operator delete(void*, void*)
		{}

	private:
		NodePtr _head() const
		{
			return const_cast<NodePtr>(_listHead);
		}


		NodePtr _tail() const
		{
			NodePtr cur = _head();
			while (cur->next) {
				cur = cur->next;
			}
			return const_cast<NodePtr>(cur);
		}

	public:
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
			return iterator(0);
		}


		const_iterator cend() const
		{
			return const_iterator(0);
		}


		const_iterator end() const
		{
			return cend();
		}


		pointer front()
		{
			return _head();
		}


		const_pointer front() const
		{
			return _head();
		}


		pointer back()
		{
			return _tail();
		}


		const_pointer back() const
		{
			return _tail();
		}


		bool empty() const
		{
			return !_listHead;
		}


		size_type size() const
		{
			size_type num = 0;
			for (const_iterator it = cbegin(); !it.empty(); ++it) {
				++num;
			}
			return num;
		}


		void clear()
		{
			while (!empty()) {
				pop_front();
			}
		}


		void push_front(pointer a_ref)
		{
			a_ref->next = _listHead;
			_listHead = a_ref;
		}


		void push_back(pointer a_ref)
		{
			_tail()->next = a_ref;
		}


		void pop_front()
		{
			if (!empty()) {
				_listHead = _listHead->next;
			} 
		}


		// insert ref before it
		void insert(iterator a_it, pointer a_ref)
		{
			iterator node = begin();
			while (node && node->next != a_it) {
				node = node->next;
			}
			if (node) {
				node->next = a_ref;
				a_ref->next = a_it;
			}
		}


		// insert ref after it
		void insert_after(iterator a_it, pointer a_ref)
		{
			iterator node = begin();
			while (node && a_it->next != node) {
				node = node->next;
			}
			if (node) {
				a_it->next = a_ref;
				a_ref->next = node;
			}
		}

	protected:
		NodePtr _listHead;	// 0
	};
}
