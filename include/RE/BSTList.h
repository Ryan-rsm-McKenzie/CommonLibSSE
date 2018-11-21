#pragma once

#include "skse64/GameAPI.h"  // Heap

#include <new>
#include <utility>

#include "RE/Memory.h"


namespace RE
{
	// forward list
	template <class _Ty>
	class BSSimpleList
	{
	public:
		typedef _Ty			value_type;
		typedef _Ty			* pointer;
		typedef const _Ty	* const_pointer;
		typedef _Ty			& reference;
		typedef const _Ty	& const_reference;
		typedef std::size_t	size_type;

		struct Node
		{
			value_type	item;
			Node		* next;

			Node() : item(0), next(nullptr) {}

			bool empty() const
			{
				return this == nullptr;
				//return next == nullptr;
			}
		};
		typedef Node *NodePtr;

		class const_iterator
		{
		public:
			typedef const_iterator _iter;
			typedef typename BSSimpleList::const_reference reference;
			typedef typename BSSimpleList::const_pointer pointer;

			const_iterator() : m_cur(nullptr) {}
			const_iterator(const NodePtr pNode) : m_cur(const_cast<NodePtr>(pNode)) {}

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
			bool operator==(const _iter& rhs) const
			{
				return (m_cur == rhs.m_cur);
			}
			bool operator!=(const _iter& rhs) const
			{
				return (!(*this == rhs));
			}
		protected:
			NodePtr m_cur;

			friend class iterator;
		};

		class iterator : public const_iterator
		{
		public:
			typedef iterator _iter;
			typedef typename BSSimpleList::reference reference;
			typedef typename BSSimpleList::pointer pointer;

			using const_iterator::m_cur;

			iterator() {}
			iterator(NodePtr pNode) : const_iterator(pNode) {}

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
			bool operator==(const _iter& rhs) const
			{
				return (m_cur == rhs.m_cur);
			}
			bool operator!=(const _iter& rhs) const
			{
				return (!(*this == rhs));
			}
			bool operator==(const const_iterator& rhs) const
			{
				return (m_cur == rhs.m_cur);
			}
			bool operator!=(const const_iterator& rhs) const
			{
				return (!(*this == rhs));
			}
		};

		BSSimpleList()
		{
			m_listHead.item = 0;
			m_listHead.next = nullptr;
		}

		~BSSimpleList()
		{
			clear();
		}

		static void * operator new(std::size_t size)
		{
			return Heap_Allocate(size);
		}
		static void * operator new(std::size_t size, const std::nothrow_t &)
		{
			return Heap_Allocate(size);
		}
		static void * operator new(std::size_t size, void * ptr)
		{
			return ptr;
		}
		static void operator delete(void * ptr)
		{
			Heap_Free(ptr);
		}
		static void operator delete(void * ptr, const std::nothrow_t &)
		{
			Heap_Free(ptr);
		}
		static void operator delete(void *, void *)
		{}


	private:
		NodePtr _head() const
		{
			return const_cast<NodePtr>(&m_listHead);
		}

		NodePtr _tail() const
		{
			NodePtr cur = _head();
			while (cur->next)
				cur = cur->next;
			return const_cast<NodePtr>(cur);
		}

	public:
		iterator begin()
		{
			return iterator(empty() ? nullptr : _head());
		}
		const_iterator cbegin() const
		{
			return const_iterator(empty() ? nullptr : _head());
		}
		const_iterator begin() const
		{
			return cbegin();
		}

		iterator end()
		{
			return iterator(nullptr);
		}
		const_iterator cend() const
		{
			return const_iterator(nullptr);
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

		void push_front(const_reference ref)
		{
			NodePtr node = _make_node_front();
			if (node) {
				// node->item = ref;
				new (&node->item)value_type(ref);
			}
		}

		void push_back(const_reference ref)
		{
			NodePtr node = _make_node_back();
			if (node) {
				// node->item = ref;
				new (&node->item)value_type(ref);
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
				m_listHead.next = nullptr;
			} else {
				m_listHead.item = std::move(next->item);
				m_listHead.next = next->next;
			}

			Heap_Free(next);
		}

		// insert ref before it
		void insert(const_iterator it, const_reference ref)
		{
			NodePtr node = _make_node_at(it);
			if (node) {
				// node->item = ref;
				new (&node->item)value_type(ref);
			}
		}

		// insert ref after it
		void insert_after(const_iterator it, const_reference ref)
		{
			NodePtr node = _make_node_after(it);
			if (node) {
				// node->item = ref;
				new (&node->item)value_type(ref);
			}
		}

	private:
		NodePtr _make_node_front()
		{
			if (!empty()) {
				NodePtr newNode = Heap_Allocate<Node>();
				if (!newNode)
					return nullptr;

				new (&newNode->item)value_type(std::move(m_listHead.item));
				newNode->next = m_listHead.next;
				m_listHead.next = newNode;
			}

			return &m_listHead;
		}

		NodePtr _make_node_back()
		{
			if (empty())
				return &m_listHead;

			NodePtr newNode = Heap_Allocate<Node>();
			if (!newNode)
				return nullptr;

			NodePtr tail = _tail();
			tail->next = newNode;
			newNode->next = nullptr;

			return tail;
		}

		// make node before it
		NodePtr _make_node_at(const_iterator it)
		{
			if (it == cbegin())
				return _make_node_front();

			NodePtr node = &m_listHead;
			do {
				if (node->next == it.m_cur) {
					NodePtr newNode = Heap_Allocate<Node>();
					if (newNode) {
						newNode->next = node->next;
						node->next = newNode;
					}
					return newNode;
				}

				node = node->next;
			} while (!node->empty());

			return nullptr;
		}

		// make node after it
		NodePtr _make_node_after(const_iterator it)
		{
			NodePtr node = it.m_cur;
			NodePtr newNode = Heap_Allocate<Node>();
			if (newNode) {
				newNode->next = node->next;
				node->next = newNode;
			}
			return newNode;
		}

	protected:
		Node m_listHead;
	};

}
