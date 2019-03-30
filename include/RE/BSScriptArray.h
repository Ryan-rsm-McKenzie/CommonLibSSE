#pragma once

#include <cassert>  // assert
#include <iterator>  // random_access_iterator_tag
#include <stdexcept>  // out_of_range
#include <string>  // string, to_string

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSScriptType.h"  // BSScriptType
#include "RE/BSScriptVariable.h"  // BSScriptVariable
#include "RE/BSSpinLock.h"  // BSSpinLock


namespace RE
{
	namespace BSScript
	{
		class BSScriptArray : public BSIntrusiveRefCounted
		{
		public:
			using value_type = BSScriptVariable;
			using size_type = UInt32;
			using difference_type = SInt32;
			using reference = value_type & ;
			using const_reference = const value_type &;
			using pointer = value_type * ;
			using const_pointer = const value_type*;


			template <class T>
			class iterator_base
			{
				friend class BSScriptArray;

			public:
				using difference_type = std::ptrdiff_t;
				using value_type = T;
				using pointer = T * ;
				using reference = T & ;
				using iterator_category = std::random_access_iterator_tag;


				constexpr iterator_base();
				constexpr iterator_base(const iterator_base& a_rhs);
				constexpr iterator_base(iterator_base&& a_rhs);
				constexpr explicit iterator_base(pointer a_ptr, std::size_t a_idx = 0);

				constexpr iterator_base& operator=(const iterator_base& a_rhs);
				constexpr iterator_base& operator=(iterator_base&& a_rhs);

				[[nodiscard]] constexpr reference operator*() const;
				[[nodiscard]] constexpr pointer operator->() const;

				constexpr iterator_base& operator++();
				constexpr iterator_base operator++(int);

				constexpr iterator_base& operator--();
				constexpr iterator_base operator--(int);

				constexpr iterator_base& operator+=(const difference_type a_offset);
				[[nodiscard]] constexpr iterator_base operator+(const difference_type a_offset) const;

				constexpr iterator_base& operator-=(const difference_type a_offset);
				[[nodiscard]] constexpr iterator_base operator-(const difference_type a_offset) const;
				[[nodiscard]] constexpr difference_type operator-(const iterator_base& a_rhs) const;

				[[nodiscard]] constexpr reference operator[](const difference_type a_offset) const;

				[[nodiscard]] constexpr bool operator==(const iterator_base& a_rhs) const;
				[[nodiscard]] constexpr bool operator!=(const iterator_base& a_rhs) const;
				[[nodiscard]] constexpr bool operator<(const iterator_base& a_rhs) const;
				[[nodiscard]] constexpr bool operator>(const iterator_base& a_rhs) const;
				[[nodiscard]] constexpr bool operator<=(const iterator_base& a_rhs) const;
				[[nodiscard]] constexpr bool operator>=(const iterator_base& a_rhs) const;

			protected:
				pointer _ptr;
#if _DEBUG
				std::size_t _idx;

			private:
				constexpr BSScriptArray* get_proxy() const;
				constexpr void verify_offset(const difference_type a_offset) const noexcept;
				constexpr void verify_compatibilty(const iterator_base& a_rhs) const;
#endif
			};


			using iterator = iterator_base<value_type>;
			using const_iterator = iterator_base<const value_type>;
			using reverse_iterator = std::reverse_iterator<iterator>;
			using const_reverse_iterator = std::reverse_iterator<const_iterator>;


			~BSScriptArray();

			[[nodiscard]] constexpr reference at(size_type a_pos);
			[[nodiscard]] constexpr const_reference at(size_type a_pos) const;

			[[nodiscard]] constexpr reference operator[](size_type a_pos);
			[[nodiscard]] constexpr const_reference operator[](size_type a_pos) const;

			[[nodiscard]] constexpr reference front();
			[[nodiscard]] constexpr const_reference front() const;

			[[nodiscard]] constexpr reference back();
			[[nodiscard]] constexpr const_reference back() const;

			[[nodiscard]] constexpr BSScriptVariable* data() noexcept;
			[[nodiscard]] constexpr const BSScriptVariable* data() const noexcept;

			[[nodiscard]] constexpr iterator begin() noexcept;
			[[nodiscard]] constexpr const_iterator begin() const noexcept;
			[[nodiscard]] constexpr const_iterator cbegin() const noexcept;

			[[nodiscard]] constexpr iterator end() noexcept;
			[[nodiscard]] constexpr const_iterator end() const noexcept;
			[[nodiscard]] constexpr const_iterator cend() const noexcept;

			[[nodiscard]] constexpr reverse_iterator rbegin() noexcept;
			[[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept;
			[[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept;

			[[nodiscard]] constexpr reverse_iterator rend() noexcept;
			[[nodiscard]] constexpr const_reverse_iterator rend() const noexcept;
			[[nodiscard]] constexpr const_reverse_iterator crend() const noexcept;

			[[nodiscard]] constexpr bool empty() const noexcept;

			[[nodiscard]] constexpr size_type size() const noexcept;

			[[nodiscard]] constexpr size_type max_size() const noexcept;

			[[nodiscard]] BSScriptType& type();
			[[nodiscard]] const BSScriptType& type() const;

			[[nodiscard]] VMTypeID type_id() const;

		protected:
			template <class T> friend class iterator_base;

			enum { kMaxSize = 128 };

			// members
			BSScriptType		_type;		// 08
			UInt32				_len;		// 10
			UInt32				_pad14;		// 14
			BSSpinLock			_lock;		// 18
			BSScriptVariable	_data[0];	// 20

		private:
			void dtor();
			void out_of_range(const char* a_fnName, size_type a_pos) const;
		};
		STATIC_ASSERT(sizeof(BSScriptArray) == 0x20);


		template <class T>
		constexpr BSScriptArray::iterator_base<T>::iterator_base() :
			_ptr{}
#if _DEBUG
			, _idx(0)
#endif
		{}


		template <class T>
		constexpr BSScriptArray::iterator_base<T>::iterator_base(const iterator_base& a_rhs) :
			_ptr(a_rhs._ptr)
#if _DEBUG
			, _idx(a_rhs._idx)
#endif
		{}


		template <class T>
		constexpr BSScriptArray::iterator_base<T>::iterator_base(iterator_base&& a_rhs) :
			_ptr(std::move(a_rhs._ptr))
#if _DEBUG
			, _idx(std::move(a_rhs._idx))
#endif
		{}


		template <class T>
		constexpr BSScriptArray::iterator_base<T>::iterator_base(pointer a_ptr, std::size_t a_idx) :
#if _DEBUG
			_ptr(a_ptr),
			_idx(a_idx)
#else
			_ptr(a_ptr + a_idx)
#endif
		{}


		template <class T>
		constexpr auto BSScriptArray::iterator_base<T>::operator=(const iterator_base& a_rhs)
			-> iterator_base&
		{
			_ptr = a_rhs._ptr;
#if _DEBUG
			_idx = a_rhs._idx;
#endif
			return *this;
		}


		template <class T>
		constexpr auto BSScriptArray::iterator_base<T>::operator=(iterator_base&& a_rhs)
			-> iterator_base&
		{
			_ptr = std::move(a_rhs._ptr);
#if _DEBUG
			_idx = std::mvoe(a_rhs._idx);
#endif
			return *this;
		}


		template <class T>
		[[nodiscard]] constexpr auto BSScriptArray::iterator_base<T>::operator*() const
			-> reference
		{
#if _DEBUG
			return *(operator->());
#else
			return *_ptr;
#endif
		}


		template <class T>
		[[nodiscard]] constexpr auto BSScriptArray::iterator_base<T>::operator->() const
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
		constexpr auto BSScriptArray::iterator_base<T>::operator++()
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
		constexpr auto BSScriptArray::iterator_base<T>::operator++(int)
			-> iterator_base
		{
			iterator_base tmp(*this);
			operator++();
			return tmp;
		}


		// prefix
		template <class T>
		constexpr auto BSScriptArray::iterator_base<T>::operator--()
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
		constexpr auto BSScriptArray::iterator_base<T>::operator--(int)
			-> iterator_base
		{
			iterator_base tmp(*this);
			operator--();
			return tmp;
		}


		template <class T>
		constexpr auto BSScriptArray::iterator_base<T>::operator+=(const difference_type a_offset)
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
		[[nodiscard]] constexpr auto BSScriptArray::iterator_base<T>::operator+(const difference_type a_offset) const
			-> iterator_base
		{
			iterator_base tmp(*this);
			return tmp += a_offset;
		}


		template <class T>
		constexpr auto BSScriptArray::iterator_base<T>::operator-=(const difference_type a_offset)
			-> iterator_base&
		{
			return operator+=(-a_offset);
		}


		template <class T>
		[[nodiscard]] constexpr auto BSScriptArray::iterator_base<T>::operator-(const difference_type a_offset) const
			-> iterator_base
		{
			iterator_base tmp(*this);
			return tmp -= a_offset;
		}


		template <class T>
		[[nodiscard]] constexpr auto BSScriptArray::iterator_base<T>::operator-(const iterator_base& a_rhs) const
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
		[[nodiscard]] constexpr auto BSScriptArray::iterator_base<T>::operator[](const difference_type a_offset) const
			-> reference
		{
			return *operator+(a_offset);
		}


		template <class T>
		[[nodiscard]] constexpr bool BSScriptArray::iterator_base<T>::operator==(const iterator_base& a_rhs) const
		{
#if _DEBUG
			verify_compatibilty(a_rhs);
			return _idx == a_rhs._idx;
#else
			return _ptr == a_rhs._ptr;
#endif
		}


		template <class T>
		[[nodiscard]] constexpr bool BSScriptArray::iterator_base<T>::operator!=(const iterator_base& a_rhs) const
		{
			return !operator==(a_rhs);
		}


		template <class T>
		[[nodiscard]] constexpr bool BSScriptArray::iterator_base<T>::operator<(const iterator_base& a_rhs) const
		{
#if _DEBUG
			verify_compatibilty(a_rhs);
			return _idx < a_rhs._idx;
#else
			return _ptr < a_rhs._ptr;
#endif
		}


		template <class T>
		[[nodiscard]] constexpr bool BSScriptArray::iterator_base<T>::operator>(const iterator_base& a_rhs) const
		{
			return a_rhs < *this;
		}


		template <class T>
		[[nodiscard]] constexpr bool BSScriptArray::iterator_base<T>::operator<=(const iterator_base& a_rhs) const
		{
			return !(a_rhs < *this);
		}


		template <class T>
		[[nodiscard]] constexpr bool BSScriptArray::iterator_base<T>::operator>=(const iterator_base& a_rhs) const
		{
			return !(*this < a_rhs);
		}


		template <class T>
		constexpr BSScriptArray* BSScriptArray::iterator_base<T>::get_proxy() const
		{
			return reinterpret_cast<BSScriptArray*>(reinterpret_cast<std::uintptr_t>(_ptr) - offsetof(BSScriptArray, _data));
		}


		template <class T>
		constexpr void BSScriptArray::iterator_base<T>::verify_offset(const difference_type a_offset) const noexcept
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
		constexpr void BSScriptArray::iterator_base<T>::verify_compatibilty(const iterator_base& a_rhs) const
		{
			assert(_ptr == a_rhs._ptr);	// iterators incompatible
		}


		[[nodiscard]] constexpr auto BSScriptArray::at(size_type a_pos)
			-> reference
		{
			if (a_pos >= size()) {
				out_of_range(__FUNCTION__, a_pos);
			} else {
				return _data[a_pos];
			}
		}


		[[nodiscard]] constexpr auto BSScriptArray::at(size_type a_pos) const
			-> const_reference
		{
			if (a_pos >= size()) {
				out_of_range(__FUNCTION__, a_pos);
			} else {
				return _data[a_pos];
			}
		}


		[[nodiscard]] constexpr auto BSScriptArray::operator[](size_type a_pos)
			-> reference
		{
			assert(a_pos < size());
			return _data[a_pos];
		}


		[[nodiscard]] constexpr auto BSScriptArray::operator[](size_type a_pos) const
			-> const_reference
		{
			assert(a_pos < size());
			return _data[a_pos];
		}


		[[nodiscard]] constexpr auto BSScriptArray::front()
			-> reference
		{
			assert(size() > 0);
			return _data[0];
		}


		[[nodiscard]] constexpr auto BSScriptArray::front() const
			-> const_reference
		{
			assert(size() > 0);
			return _data[0];
		}


		[[nodiscard]] constexpr auto BSScriptArray::back()
			-> reference
		{
			assert(size() > 0);
			return _data[size() - 1];
		}


		[[nodiscard]] constexpr auto BSScriptArray::back() const
			-> const_reference
		{
			assert(size() > 0);
			return _data[size() - 1];
		}


		[[nodiscard]] constexpr BSScriptVariable* BSScriptArray::data() noexcept
		{
			return size() > 0 ? _data : 0;
		}


		[[nodiscard]] constexpr auto BSScriptArray::begin() noexcept
			-> iterator
		{
			return iterator(_data);
		}


		[[nodiscard]] constexpr auto BSScriptArray::begin() const noexcept
			-> const_iterator
		{
			return const_iterator(_data);
		}


		[[nodiscard]] constexpr auto BSScriptArray::cbegin() const noexcept
			-> const_iterator
		{
			return begin();
		}


		[[nodiscard]] constexpr auto BSScriptArray::end() noexcept
			-> iterator
		{
			return iterator(_data, _len);
		}


		[[nodiscard]] constexpr auto BSScriptArray::end() const noexcept
			-> const_iterator
		{
			return const_iterator(_data, _len);
		}


		[[nodiscard]] constexpr auto BSScriptArray::cend() const noexcept
			-> const_iterator
		{
			return end();
		}


		[[nodiscard]] constexpr auto BSScriptArray::rbegin() noexcept
			-> reverse_iterator
		{
			return reverse_iterator(end());
		}


		[[nodiscard]] constexpr auto BSScriptArray::rbegin() const noexcept
			-> const_reverse_iterator
		{
			return const_reverse_iterator(end());
		}


		[[nodiscard]] constexpr auto BSScriptArray::crbegin() const noexcept
			-> const_reverse_iterator
		{
			return rbegin();
		}


		[[nodiscard]] constexpr auto BSScriptArray::rend() noexcept
			-> reverse_iterator
		{
			return reverse_iterator(begin());
		}


		[[nodiscard]] constexpr auto BSScriptArray::rend() const noexcept
			-> const_reverse_iterator
		{
			return const_reverse_iterator(begin());
		}


		[[nodiscard]] constexpr auto BSScriptArray::crend() const noexcept
			-> const_reverse_iterator
		{
			return rend();
		}


		[[nodiscard]] constexpr const BSScriptVariable* BSScriptArray::data() const noexcept
		{
			return size() > 0 ? _data : 0;
		}


		[[nodiscard]] constexpr bool BSScriptArray::empty() const noexcept
		{
			return size() > 0;
		}


		[[nodiscard]] constexpr auto BSScriptArray::size() const noexcept
			-> size_type
		{
			return _len;
		}


		[[nodiscard]] constexpr auto BSScriptArray::max_size() const noexcept
			-> size_type
		{
			return kMaxSize;
		}
	}
}
