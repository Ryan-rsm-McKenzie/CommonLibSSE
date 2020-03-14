#pragma once

#include <cassert>
#include <iterator>
#include <memory>
#include <utility>

#include "RE/MemoryManager.h"


namespace RE
{
	// forward list
	template <class T>
	class BSSimpleList
	{
	public:
		using value_type = T;
		using size_type = UInt32;
		using reference = value_type&;
		using const_reference = const value_type&;


		struct Node
		{
			Node() :
				item{},
				next(nullptr)
			{}


			Node(value_type a_value, Node* a_next) :
				item(a_value),
				next(a_next)
			{}


			Node(const Node& a_rhs) :
				item(a_rhs.item),
				next(a_rhs.next)
			{}


			Node(Node&& a_rhs) :
				item(std::move(a_rhs.item)),
				next(std::move(a_rhs.next))
			{
				a_rhs.next = nullptr;
			}


			Node(const value_type& a_value) :
				item(a_value),
				next(nullptr)
			{}


			Node(value_type&& a_value) :
				item(std::move(a_value)),
				next(nullptr)
			{}


			~Node() = default;


			Node& operator=(const Node& a_rhs)
			{
				if (this == &a_rhs) {
					return *this;
				}

				item = a_rhs.item;
				next = a_rhs.next;

				return *this;
			}


			Node& operator=(Node&& a_rhs)
			{
				if (this == &a_rhs) {
					return *this;
				}

				item = std::move(a_rhs.item);

				next = std::move(a_rhs.next);
				a_rhs.next = 0;

				return *this;
			}


			TES_HEAP_REDEFINE_NEW();


			// members
			value_type item;  // 00
			Node*	   next;  // ??
		};


		template <class U>
		class iterator_base
		{
		public:
			using difference_type = std::ptrdiff_t;
			using value_type = U;
			using pointer = U*;
			using reference = U&;
			using iterator_category = std::forward_iterator_tag;


			iterator_base() :
				_cur(0),
				_managed(0)
			{}


			iterator_base(Node* a_node) :
				_cur(a_node),
				_managed(nullptr)
			{}


			iterator_base(Node* a_node, Node* a_managed) :
				_cur(a_node),
				_managed(a_managed)
			{}


			iterator_base(const iterator_base& a_rhs) :
				_cur(a_rhs._cur),
				_managed(0)
			{
				if (a_rhs._managed) {
					_managed = new Node(*a_rhs._managed);
				}
			}


			iterator_base(iterator_base&& a_rhs) :
				_cur(std::move(a_rhs._cur)),
				_managed(std::move(a_rhs._managed))
			{
				a_rhs._cur = nullptr;
				a_rhs._managed = nullptr;
			}


			~iterator_base()
			{
				if (_managed) {
					delete _managed;
				}
			}


			iterator_base& operator=(const iterator_base& a_rhs)
			{
				if (this == &a_rhs) {
					return *this;
				}

				_cur = a_rhs._cur;

				if (_managed) {
					delete _managed;
					_managed = 0;
				}
				if (a_rhs._managed) {
					_managed = new Node(*a_rhs._managed);
				}

				return *this;
			}


			iterator_base& operator=(iterator_base&& a_rhs)
			{
				if (this == &a_rhs) {
					return *this;
				}

				_cur = std::move(a_rhs._cur);
				a_rhs._cur = 0;

				if (_managed) {
					delete _managed;
				}
				_managed = std::move(a_rhs._managed);
				a_rhs._managed = 0;

				return *this;
			}


			[[nodiscard]] reference operator*() const
			{
				return _cur->item;
			}


			[[nodiscard]] pointer operator->() const
			{
				return std::addressof(_cur->item);
			}


			[[nodiscard]] bool operator==(const iterator_base& a_rhs) const
			{
				return _cur == a_rhs._cur;
			}


			[[nodiscard]] bool operator!=(const iterator_base& a_rhs) const
			{
				return !operator==(a_rhs);
			}


			// prefix
			iterator_base& operator++()
			{
				assert(_cur);
				_cur = _cur->next;
				return *this;
			}


			// postfix
			iterator_base operator++(int)
			{
				iterator_base tmp(*this);
				operator++();
				return tmp;
			}

		protected:
			friend class BSSimpleList<T>;


			bool comes_before(const iterator_base& a_it) const
			{
				auto node = _cur;
				while (node != a_it._cur) {
					if (!node) {
						return false;
					}
					node = node->next;
				}
				return true;
			}


			Node* _cur;
			Node* _managed;
		};


		using iterator = iterator_base<T>;
		using const_iterator = iterator_base<const T>;


		BSSimpleList() :
			_listHead()
		{}


		BSSimpleList(const BSSimpleList& a_rhs) :
			_listHead()
		{
			auto lhs = head_node();
			auto rhs = a_rhs.head_node();
			lhs->item = rhs->item;
			while (rhs->next) {
				rhs = rhs->next;
				lhs->next = new Node(rhs->item);
				lhs = lhs->next;
			}
		}


		BSSimpleList(BSSimpleList&& a_rhs) :
			_listHead(std::move(a_rhs._listHead))
		{}


		~BSSimpleList()
		{
			clear();
		}


		BSSimpleList& operator=(const BSSimpleList& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			clear();
			auto lhs = head_node();
			auto rhs = a_rhs.head_node();
			lhs->item = rhs->item;
			while (rhs->next) {
				rhs = rhs->next;
				lhs->next = new Node(rhs->item);
				lhs = lhs->next;
			}

			return *this;
		}


		BSSimpleList& operator=(BSSimpleList&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			_listHead = std::move(a_rhs._listHead);

			return *this;
		}


		TES_HEAP_REDEFINE_NEW();


		reference front()
		{
			assert(!empty());
			return *begin();
		}


		const_reference front() const
		{
			assert(!empty());
			return *cbegin();
		}


		iterator before_begin() noexcept
		{
			auto node = new Node(value_type{}, head_node());
			return iterator(node, node);
		}


		const_iterator before_begin() const noexcept
		{
			auto node = new Node(value_type{}, head_node());
			return const_iterator(node, node);
		}


		const_iterator cbefore_begin() const noexcept
		{
			auto node = new Node(value_type{}, head_node());
			return const_iterator(node, node);
		}


		iterator begin() noexcept
		{
			return empty() ? end() : iterator(head_node());
		}


		const_iterator begin() const noexcept
		{
			return empty() ? end() : const_iterator(head_node());
		}


		const_iterator cbegin() const noexcept
		{
			return empty() ? end() : const_iterator(head_node());
		}


		iterator end() noexcept
		{
			return iterator(nullptr);
		}


		const_iterator end() const noexcept
		{
			return const_iterator(nullptr);
		}


		const_iterator cend() const noexcept
		{
			return const_iterator(nullptr);
		}


		[[nodiscard]] bool empty() const noexcept
		{
			return !_listHead.next && !_listHead.item;
		}


		void clear() noexcept
		{
			while (!empty()) {
				pop_front();
			}
		}


		iterator insert_after(const_iterator a_pos, const T& a_value)
		{
			auto node = new Node(a_value);
			node->next = a_pos._cur->next;
			a_pos._cur->next = node;
			return iterator(node);
		}


		iterator insert_after(const_iterator a_pos, T&& a_value)
		{
			auto node = new Node(std::move(a_value));
			node->next = a_pos._cur->next;
			a_pos._cur->next = node;
			return iterator(node);
		}


		iterator insert_after(const_iterator a_pos, size_type a_count, const T& a_value)
		{
			Node* node = 0;
			while (a_count--) {
				node = new Node(a_value);
				node->next = a_pos._cur->next;
				a_pos._cur->next = node;
				++a_pos;
			}
			return iterator(a_pos._cur);
		}


		iterator erase_after(const_iterator a_pos)
		{
			if (a_pos == cend()) {
				return end();
			}

			auto before = a_pos++;
			before._cur->next = a_pos._cur->next;
			delete a_pos._cur;
			a_pos._cur = 0;
			return before._cur->next == 0 ? end() : iterator((++before)._cur);
		}


		iterator erase_after(const_iterator a_first, const_iterator a_last)
		{
			assert(a_first.comes_before(a_last));
			const_iterator pos(a_first._cur);
			if (pos == a_last) {
				return iterator(a_last._cur);
			}

			++pos;
			while (pos != a_last) {
				auto old = pos._cur;
				++pos;
				if (old == &_listHead) {
					old->item.~value_type();
					new (std::addressof(old->item)) value_type{};
					old->next = 0;
				} else {
					delete old;
				}
			}
			a_first._cur->next = a_last._cur;
			return iterator(a_last._cur);
		}


		void push_front(const T& a_value)
		{
			if (empty()) {
				new (std::addressof(_listHead.item)) value_type(a_value);
			} else {
				auto node = new Node(std::move(_listHead));
				new (std::addressof(_listHead.item)) value_type(a_value);
				_listHead.next = node;
			}
		}


		void push_front(T&& a_value)
		{
			if (empty()) {
				new (std::addressof(_listHead.item)) value_type(std::move(a_value));
			} else {
				auto node = new Node(std::move(_listHead));
				new (std::addressof(_listHead.item)) value_type(std::move(a_value));
				_listHead.next = node;
			}
		}


		template <class... Args>
		reference emplace_front(Args&&... a_args)
		{
			if (empty()) {
				new (std::addressof(_listHead.item)) value_type{ std::forward<Args>(a_args)... };
			} else {
				auto node = new Node(std::move(_listHead));
				new (std::addressof(_listHead.item)) value_type{ std::forward<Args>(a_args)... };
				_listHead.next = node;
			}
			return _listHead.item;
		}


		void pop_front()
		{
			assert(!empty());
			_listHead.item.~value_type();

			if (_listHead.next) {
				new (std::addressof(_listHead.item)) value_type(std::move(_listHead.next->item));
				auto old = _listHead.next;
				_listHead.next = old->next;
				delete old;
			} else {
				new (std::addressof(_listHead.item)) value_type{};
			}
		}


		void resize(size_type a_count)
		{
			resize(a_count);
		}


		void resize(size_type a_count, const value_type& a_value)
		{
			resize(a_count, a_value);
		}

	protected:
		Node* head_node()
		{
			return std::addressof(_listHead);
		}


		const Node* head_node() const
		{
			return std::addressof(_listHead);
		}


		const Node* chead_node() const
		{
			return std::addressof(_listHead);
		}


		template <class... Args>
		void resize_impl(size_type a_count, Args&&... a_args)
		{
			if (empty() && a_count == 0) {
				return;
			}

			auto	  cur = begin();
			size_type elems = 1;
			while (cur != end() && elems != a_count) {
				++cur;
				++elems;
			}

			if (elems < a_count) {
				// need to grow
				Node* node = 0;
				while (elems < a_count) {
					node = new Node(std::forward<Args>(a_args)...);
					cur._cur->next = node;
					++cur;
					++elems;
				}
			} else if (cur != end()) {
				// need to shrink
				auto prev = cur++;
				prev._cur->next = 0;
				while (cur != end()) {
					prev = cur++;
					if (prev._cur != head_node()) {
						delete prev._cur;
					}
				}
			} else {
				// already required size
			}
		}


		// members
		Node _listHead;	 // 00

		// T				_item;	// 00
		// BSSimpleList<T>* _next;	// ??
	};
}
