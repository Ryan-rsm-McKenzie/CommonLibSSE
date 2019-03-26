#pragma once

#include <cstddef>  // size_t, ptrdiff_t
#include <cstdint>  // uint32_t
#include <memory>  // pointer_traits
#include <utility>  // move, swap, forward
#include <iterator>  // forward_iterator_tag

#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	// forward list
	template <class T>
	class BSSimpleList
	{
	public:
		using value_type = T;
		using size_type = std::uint32_t;
		using difference_type = std::ptrdiff_t;
		using reference = value_type & ;
		using const_reference = const value_type&;
		using pointer = value_type * ;
		using const_pointer = std::pointer_traits<pointer>::rebind<const value_type>;

	protected:
		struct Node
		{
			Node() :
				item{},
				next{ 0 }
			{}


			Node(value_type a_value, Node* a_next) :
				item(a_value),
				next(a_next)
			{}


			Node(const Node& a_rhs) :
				item{ a_rhs.item },
				next{ a_rhs.next }
			{}


			Node(Node&& a_rhs) :
				item{ std::move(a_rhs.item) },
				next{ std::move(a_rhs.next) }
			{
				a_rhs.next = 0;
			}


			Node(const value_type& a_value) :
				item{ a_value },
				next{ 0 }
			{}


			Node(value_type&& a_value) :
				item{ a_value },
				next{ 0 }
			{}


			static void swap(Node& a_lhs, Node& a_rhs)
			{
				std::swap(a_lhs.item, a_rhs.item);
				std::swap(a_lhs.next, a_rhs.next);
			}


			Node& operator=(const Node& a_rhs)
			{
				Node tmp(a_rhs);
				swap(*this, tmp);
				return *this;
			}


			Node& operator=(Node&& a_rhs)
			{
				item = a_rhs.item;
				next = a_rhs.next;
			}


			TES_HEAP_REDEFINE_NEW();


			// members
			value_type	item;
			Node*		next;
		};

	public:
		template <class U>
		struct iterator_traits
		{
			using difference_type = std::ptrdiff_t;
			using value_type = U;
			using pointer = U * ;
			using reference = U & ;
			using iterator_category = std::forward_iterator_tag;
		};


		template <class U>
		class iterator_base : public iterator_traits<U>
		{
			friend class BSSimpleList<T>;

			using Traits = iterator_traits<U>;

		public:
			using difference_type = typename Traits::difference_type;
			using value_type = typename Traits::value_type;
			using pointer = typename Traits::pointer;
			using reference = typename Traits::reference;
			using iterator_category = typename Traits::iterator_category;


			iterator_base() :
				_cur(0),
				_managed(0)
			{}


			iterator_base(Node* a_node, Node* a_managed = 0) :
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
				a_rhs._cur = 0;
				a_rhs._managed = 0;
			}


			~iterator_base()
			{
				if (_managed) {
					delete _managed;
				}
			}


			static void swap(iterator_base& a_lhs, iterator_base& a_rhs)
			{
				std::swap(a_lhs._cur, a_rhs._cur);
				std::swap(a_lhs._cur, a_rhs._cur);
			}


			iterator_base& operator=(const iterator_base& a_rhs)
			{
				iterator_base tmp(a_rhs);
				swap(*this, tmp);
				return *this;
			}


			iterator_base& operator=(iterator_base&& a_rhs)
			{
				_cur = std::move(a_rhs._cur);
				a_rhs._cur = 0;

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
				return std::pointer_traits<pointer>::pointer_to(operator*());
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
				_cur = _cur->next;
				return *this;
			}


			// postfix
			iterator_base operator++(int)
			{
				iterator_base tmp{ *this };
				operator++();
				return tmp;
			}

		protected:
			Node* _cur;
			Node* _managed;
		};


		using iterator = iterator_base<T>;
		using const_iterator = iterator_base<const T>;


		constexpr BSSimpleList() :
			_listHead{}
		{}


		~BSSimpleList()
		{
			clear();
		}


		TES_HEAP_REDEFINE_NEW();


		reference front()
		{
			return *begin();
		}


		const_reference front() const
		{
			return *cbegin();
		}


		iterator before_begin() noexcept
		{
			Node* node = new Node({}, &_listHead);
			return iterator{ node, node };
		}


		const_iterator before_begin() const noexcept
		{
			Node* node = new Node({}, const_cast<Node*>(&_listHead));
			return const_iterator{ node, node };
		}


		const_iterator cbefore_begin() const noexcept
		{
			Node* node = new Node({}, const_cast<Node*>(&_listHead));
			return const_iterator{ node, node };
		}


		iterator begin() noexcept
		{
			return empty() ? end() : iterator{ &_listHead };
		}


		const_iterator begin() const noexcept
		{
			return empty() ? end() : const_iterator{ const_cast<Node*>(&_listHead) };
		}


		const_iterator cbegin() const noexcept
		{
			return empty() ? cend() : const_iterator{ const_cast<Node*>(&_listHead) };
		}


		iterator end() noexcept
		{
			return { 0 };
		}


		const_iterator end() const noexcept
		{
			return { 0 };
		}


		const_iterator cend() const noexcept
		{
			return { 0 };
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
			Node* node = new Node();
			node->item = a_value;
			node->next = a_pos._cur->next;
			a_pos._cur->next = node;
			return iterator{ node };
		}


		iterator insert_after(const_iterator a_pos, T&& a_value)
		{
			Node* node = new Node();
			node->item = std::move(a_value);
			node->next = a_pos._cur->next;
			a_pos._cur->next = node;
			return iterator{ node };
		}


		iterator insert_after(const_iterator a_pos, size_type a_count, const T& a_value)
		{
			Node* node = 0;
			while (a_count--) {
				node = new Node();
				node->item = a_value;
				node->next = a_pos._cur->next;
				a_pos._cur->next = node;
				++a_pos;
			}
			return iterator{ a_pos._cur };
		}


		template <class InputIt>
		iterator insert_after(const_iterator a_pos, InputIt a_first, InputIt a_last)
		{
			Node* node = 0;
			while (a_first != a_last) {
				node = new Node();
				node->item = *a_first;
				node->next = a_pos._cur->next;
				a_pos._cur->next = node;
				++a_pos;
				++a_first;
			}
			return iterator{ a_pos._cur };
		}


		iterator insert_after(const_iterator a_pos, std::initializer_list<T> a_ilist)
		{
			Node* node = 0;
			for (auto& elem : a_ilist) {
				node = new Node();
				node->item = elem;
				node->next = a_pos._cur->next;
				a_pos._cur->next = node;
				++a_pos;
			}
			return iterator{ a_pos._cur };
		}


		iterator erase_after(const_iterator a_pos)
		{
			const_iterator before = a_pos++;
			before._cur->next = a_pos._cur->next;
			delete a_pos._cur;
			return before._cur->next == 0 ? end() : iterator{ ++before._cur };
		}


		iterator erase_after(const_iterator a_first, const_iterator a_last)
		{
			const_iterator pos{ a_first };
			while (++pos != a_last) {
				delete pos._cur;
			}
			a_first._cur->next = a_last._cur;
			return iterator{ a_last._cur };
		}


		void push_front(const T& a_value)
		{
			if (empty()) {
				_listHead.item = a_value;
			} else {
				Node* node = new Node(_listHead);
				_listHead.item = a_value;
				_listHead.next = node;
			}
		}


		void push_front(T&& a_value)
		{
			if (empty()) {
				_listHead.item = a_value;
			} else {
				Node* node = new Node(_listHead);
				_listHead.item = a_value;
				_listHead.next = node;
			}
		}


		void pop_front()
		{
			if (_listHead.next) {
				_listHead.item = _listHead.next->item;
				_listHead.next = _listHead.next->next;
			} else {
				_listHead.item = value_type{};
				_listHead.next = 0;
			}
		}


		void resize(size_type a_count)
		{
			if (empty()) {
				if (a_count == 0) {
					return;
				} else {
					_listHead.item = value_type{};
					_listHead.next = 0;
				}
			}

			iterator pos = begin();
			size_type elems = 1;
			while (pos._cur->next != 0 && elems != a_count) {
				++elems;
				++pos;
			}

			if (elems > a_count) {
				// need to shrink
				if (pos == begin()) {
					_listHead.item = value_type{};
				}
				pos++._cur->next = 0;
				while (pos != end()) {
					delete pos++._cur;
				}
			} else if (elems == a_count) {
				// already required size
				return;
			} else {
				// need to expand
				Node* node = 0;
				while (elems < a_count) {
					node = new Node();
					pos._cur->next = node;
					++pos;
					++elems;
				}
			}
		}


		void resize(size_type a_count, const value_type& a_value)
		{
			if (empty()) {
				if (a_count == 0) {
					return;
				} else {
					_listHead.item = value_type{ a_value };
					_listHead.next = 0;
				}
			}

			iterator pos = begin();
			size_type elems = 1;
			while (pos._cur->next != 0 && elems != a_count) {
				++elems;
				++pos;
			}

			if (elems > a_count) {
				// need to shrink
				if (pos == begin()) {
					_listHead.item = value_type{};
				}
				pos++._cur->next = 0;
				while (pos != end()) {
					delete pos++._cur;
				}
			} else if (elems == a_count) {
				// already required size
				return;
			} else {
				// need to expand
				Node* node = 0;
				while (elems < a_count) {
					node = new Node(a_value);
					pos._cur->next = node;
					++pos;
					++elems;
				}
			}
		}


		void swap(BSSimpleList& a_other) noexcept
		{
			Node tmp = _listHead;
			_listHead = a_other._listHead;
			a_other._listHead = tmp;
		}

	protected:
		// members
		Node _listHead;	// 00
	};
}
