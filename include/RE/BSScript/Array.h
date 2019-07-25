#pragma once

#include <cassert>  // assert
#include <iterator>  // random_access_iterator_tag
#include <stdexcept>  // out_of_range
#include <string>  // string, to_string

#include "RE/BSScript/Type.h"  // BSScript::Type
#include "RE/BSScript/Variable.h"  // BSScript::Variable
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSLock.h"  // BSUniqueLock


namespace RE
{
	namespace BSScript
	{
		class Array : public BSIntrusiveRefCounted
		{
		public:
			using value_type = Variable;
			using size_type = UInt32;
			using difference_type = SInt32;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;
			using const_pointer = const value_type*;


			template <class T>
			class iterator_base
			{
				friend class Array;

			public:
				using difference_type = std::ptrdiff_t;
				using value_type = T;
				using pointer = T*;
				using reference = T&;
				using iterator_category = std::random_access_iterator_tag;


				iterator_base();
				iterator_base(const iterator_base& a_rhs);
				iterator_base(iterator_base&& a_rhs);
				explicit iterator_base(pointer a_ptr, std::size_t a_idx = 0);

				iterator_base& operator=(const iterator_base& a_rhs);
				iterator_base& operator=(iterator_base&& a_rhs);

				[[nodiscard]] reference operator*() const;
				[[nodiscard]] pointer operator->() const;

				iterator_base& operator++();
				iterator_base operator++(int);

				iterator_base& operator--();
				iterator_base operator--(int);

				iterator_base& operator+=(const difference_type a_offset);
				[[nodiscard]] iterator_base operator+(const difference_type a_offset) const;

				iterator_base& operator-=(const difference_type a_offset);
				[[nodiscard]] iterator_base operator-(const difference_type a_offset) const;
				[[nodiscard]] difference_type operator-(const iterator_base& a_rhs) const;

				[[nodiscard]] reference operator[](const difference_type a_offset) const;

				[[nodiscard]] bool operator==(const iterator_base& a_rhs) const;
				[[nodiscard]] bool operator!=(const iterator_base& a_rhs) const;
				[[nodiscard]] bool operator<(const iterator_base& a_rhs) const;
				[[nodiscard]] bool operator>(const iterator_base& a_rhs) const;
				[[nodiscard]] bool operator<=(const iterator_base& a_rhs) const;
				[[nodiscard]] bool operator>=(const iterator_base& a_rhs) const;

			protected:
				pointer _ptr;
#if _DEBUG
				std::size_t _idx;

			private:
				Array* get_proxy() const;
				void verify_offset(const difference_type a_offset) const noexcept;
				void verify_compatibilty(const iterator_base& a_rhs) const;
#endif
			};


			using iterator = iterator_base<value_type>;
			using const_iterator = iterator_base<const value_type>;
			using reverse_iterator = std::reverse_iterator<iterator>;
			using const_reverse_iterator = std::reverse_iterator<const_iterator>;


			~Array();

			[[nodiscard]] reference at(size_type a_pos);
			[[nodiscard]] const_reference at(size_type a_pos) const;

			[[nodiscard]] reference operator[](size_type a_pos);
			[[nodiscard]] const_reference operator[](size_type a_pos) const;

			[[nodiscard]] reference front();
			[[nodiscard]] const_reference front() const;

			[[nodiscard]] reference back();
			[[nodiscard]] const_reference back() const;

			[[nodiscard]] Variable* data() noexcept;
			[[nodiscard]] const Variable* data() const noexcept;

			[[nodiscard]] iterator begin() noexcept;
			[[nodiscard]] const_iterator begin() const noexcept;
			[[nodiscard]] const_iterator cbegin() const noexcept;

			[[nodiscard]] iterator end() noexcept;
			[[nodiscard]] const_iterator end() const noexcept;
			[[nodiscard]] const_iterator cend() const noexcept;

			[[nodiscard]] reverse_iterator rbegin() noexcept;
			[[nodiscard]] const_reverse_iterator rbegin() const noexcept;
			[[nodiscard]] const_reverse_iterator crbegin() const noexcept;

			[[nodiscard]] reverse_iterator rend() noexcept;
			[[nodiscard]] const_reverse_iterator rend() const noexcept;
			[[nodiscard]] const_reverse_iterator crend() const noexcept;

			[[nodiscard]] bool empty() const noexcept;

			[[nodiscard]] size_type size() const noexcept;

			[[nodiscard]] size_type max_size() const noexcept;

			[[nodiscard]] Type& type();
			[[nodiscard]] const Type& type() const;

			[[nodiscard]] VMTypeID type_id() const;

		protected:
			template <class T> friend class iterator_base;

			enum { kMaxSize = 128 };

			// members
			UInt32					_pad04;		// 04
			Type					_type;		// 08
			UInt32					_len;		// 10
			UInt32					_pad14;		// 14
			mutable BSUniqueLock	_lock;		// 18
			Variable				_data[0];	// 20

		private:
			void dtor();
			void out_of_range(const char* a_fnName, size_type a_pos) const;
		};
		STATIC_ASSERT(sizeof(Array) == 0x20);


		template <class T>
		Array::iterator_base<T>::iterator_base() :
			_ptr{}
#if _DEBUG
			, _idx(0)
#endif
		{}


		template <class T>
		Array::iterator_base<T>::iterator_base(const iterator_base& a_rhs) :
			_ptr(a_rhs._ptr)
#if _DEBUG
			, _idx(a_rhs._idx)
#endif
		{}


		template <class T>
		Array::iterator_base<T>::iterator_base(iterator_base&& a_rhs) :
			_ptr(std::move(a_rhs._ptr))
#if _DEBUG
			, _idx(std::move(a_rhs._idx))
#endif
		{}


		template <class T>
		Array::iterator_base<T>::iterator_base(pointer a_ptr, std::size_t a_idx) :
#if _DEBUG
			_ptr(a_ptr),
			_idx(a_idx)
#else
			_ptr(a_ptr + a_idx)
#endif
		{}


		template <class T>
		auto Array::iterator_base<T>::operator=(const iterator_base& a_rhs)
			-> iterator_base&
		{
			_ptr = a_rhs._ptr;
#if _DEBUG
			_idx = a_rhs._idx;
#endif
			return *this;
		}


		template <class T>
		auto Array::iterator_base<T>::operator=(iterator_base&& a_rhs)
			-> iterator_base&
		{
			_ptr = std::move(a_rhs._ptr);
#if _DEBUG
			_idx = std::mvoe(a_rhs._idx);
#endif
			return *this;
		}


		template <class T>
		[[nodiscard]] auto Array::iterator_base<T>::operator*() const
			-> reference
		{
#if _DEBUG
			return *(operator->());
#else
			return *_ptr;
#endif
		}


		template <class T>
		[[nodiscard]] auto Array::iterator_base<T>::operator->() const
			-> pointer
		{
#if _DEBUG
			assert(_ptr != 0);	// cannot dereference value-initialized iterator
			std::size_t proxySize = get_proxy()->size();
			assert(_idx < proxySize);	// cannot dereference out of range iterator
			return _ptr + _idx;
#else
			return _ptr;
#endif
		}


		// prefix
		template <class T>
		auto Array::iterator_base<T>::operator++()
			-> iterator_base&
		{
#if _DEBUG
			assert(_ptr != 0);	// cannot dereference value-initialized iterator
			std::size_t proxySize = get_proxy()->size();
			assert(_idx < proxySize);	// cannot decrement iterator past end
			++_idx;
#else
			++_ptr;
#endif
			return *this;
		}


		// postfix
		template <class T>
		auto Array::iterator_base<T>::operator++(int)
			-> iterator_base
		{
			iterator_base tmp(*this);
			operator++();
			return tmp;
		}


		// prefix
		template <class T>
		auto Array::iterator_base<T>::operator--()
			-> iterator_base&
		{
#if _DEBUG
			assert(_ptr != 0);	// cannot dereference value-initialized iterator
			assert(_idx != 0);	// cannot decrement iterator before begin
			--_idx;
#else
			--_ptr;
#endif
			return *this;
		}


		// postfix
		template <class T>
		auto Array::iterator_base<T>::operator--(int)
			-> iterator_base
		{
			iterator_base tmp(*this);
			operator--();
			return tmp;
		}


		template <class T>
		auto Array::iterator_base<T>::operator+=(const difference_type a_offset)
			-> iterator_base&
		{
#if _DEBUG
			verify_offset(a_offset);
			_idx += a_offset;
#else
			_ptr += a_offset;
#endif
			return *this;
		}


		template <class T>
		[[nodiscard]] auto Array::iterator_base<T>::operator+(const difference_type a_offset) const
			-> iterator_base
		{
			iterator_base tmp(*this);
			return tmp += a_offset;
		}


		template <class T>
		auto Array::iterator_base<T>::operator-=(const difference_type a_offset)
			-> iterator_base&
		{
			return operator+=(-a_offset);
		}


		template <class T>
		[[nodiscard]] auto Array::iterator_base<T>::operator-(const difference_type a_offset) const
			-> iterator_base
		{
			iterator_base tmp(*this);
			return tmp -= a_offset;
		}


		template <class T>
		[[nodiscard]] auto Array::iterator_base<T>::operator-(const iterator_base& a_rhs) const
			-> difference_type
		{
#if _DEBUG
			verify_compatibilty(a_rhs);
			return static_cast<difference_type>(_idx - a_rhs._idx);
#else
			return _ptr - a_rhs._ptr;
#endif
		}


		template <class T>
		[[nodiscard]] auto Array::iterator_base<T>::operator[](const difference_type a_offset) const
			-> reference
		{
			return *operator+(a_offset);
		}


		template <class T>
		[[nodiscard]] bool Array::iterator_base<T>::operator==(const iterator_base& a_rhs) const
		{
#if _DEBUG
			verify_compatibilty(a_rhs);
			return _idx == a_rhs._idx;
#else
			return _ptr == a_rhs._ptr;
#endif
		}


		template <class T>
		[[nodiscard]] bool Array::iterator_base<T>::operator!=(const iterator_base& a_rhs) const
		{
			return !operator==(a_rhs);
		}


		template <class T>
		[[nodiscard]] bool Array::iterator_base<T>::operator<(const iterator_base& a_rhs) const
		{
#if _DEBUG
			verify_compatibilty(a_rhs);
			return _idx < a_rhs._idx;
#else
			return _ptr < a_rhs._ptr;
#endif
		}


		template <class T>
		[[nodiscard]] bool Array::iterator_base<T>::operator>(const iterator_base& a_rhs) const
		{
			return a_rhs < *this;
		}


		template <class T>
		[[nodiscard]] bool Array::iterator_base<T>::operator<=(const iterator_base& a_rhs) const
		{
			return !(a_rhs < *this);
		}


		template <class T>
		[[nodiscard]] bool Array::iterator_base<T>::operator>=(const iterator_base& a_rhs) const
		{
			return !(*this < a_rhs);
		}


#if _DEBUG
		template <class T>
		Array* Array::iterator_base<T>::get_proxy() const
		{
			return reinterpret_cast<Array*>(reinterpret_cast<std::uintptr_t>(_ptr) - offsetof(Array, _data));
		}


		template <class T>
		void Array::iterator_base<T>::verify_offset(const difference_type a_offset) const noexcept
		{
			if (a_offset != 0) {
				assert(_ptr != 0);	// cannot dereference value-initialized iterator

				if (a_offset < 0) {
					assert(_idx >= (-1 * static_cast<std::size_t>(a_offset)));	// seek before begin
				} else {
					assert(_idx >= static_cast<std::size_t>(a_offset));	// seek after end
				}
			}
		}


		template <class T>
		void Array::iterator_base<T>::verify_compatibilty(const iterator_base& a_rhs) const
		{
			assert(_ptr == a_rhs._ptr);	// iterators incompatible
		}
#endif
	}
}
