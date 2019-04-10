#pragma once

#include <iterator>  // random_access_iterator_tag, reverse_iterator
#include <initializer_list>  // initializer_list

#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class BSString;


	class BSFixedString
	{
	public:
		struct const_iterator
		{
		public:
			using difference_type = std::ptrdiff_t;
			using value_type = const char;
			using pointer = value_type * ;
			using reference = value_type & ;
			using iterator_category = std::random_access_iterator_tag;


			const_iterator();
			const_iterator(pointer a_ptr);
			const_iterator(const const_iterator&) = default;
			const_iterator(const_iterator&&) = default;

			reference		operator*() const;
			pointer			operator->() const;
			const_iterator&	operator++();
			const_iterator	operator++(int);
			const_iterator&	operator--();
			const_iterator	operator--(int);
			const_iterator&	operator+=(const difference_type a_off);
			const_iterator	operator+(const difference_type a_off) const;
			const_iterator&	operator-=(const difference_type a_off);
			const_iterator	operator-(const difference_type a_off) const;
			difference_type	operator-(const const_iterator& a_rhs) const;
			reference		operator[](const difference_type a_off) const;
			bool			operator==(const const_iterator& a_rhs) const;
			bool			operator!=(const const_iterator& a_rhs) const;
			bool			operator<(const const_iterator& a_rhs) const;
			bool			operator>(const const_iterator& a_rhs) const;
			bool			operator<=(const const_iterator& a_rhs) const;
			bool			operator>=(const const_iterator& a_rhs) const;


		protected:
			pointer _ptr;
		};


		using value_type = char;
		using size_type = UInt32;
		using reference = value_type;
		using const_reference = const value_type&;
		using pointer = value_type * ;
		using const_pointer = const value_type*;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;


		// (constructor)
		BSFixedString();
		BSFixedString(const char* a_rhs);
		BSFixedString(const BSFixedString& a_rhs);
		BSFixedString(BSFixedString&& a_rhs) noexcept;

		// (destructor)
		~BSFixedString();

		// operator=
		BSFixedString&	operator=(const BSFixedString& a_rhs);
		BSFixedString&	operator=(BSFixedString&& a_rhs);
		BSFixedString&	operator=(const char* a_rhs);

		// Element access
		const_reference	at(size_type a_pos) const;
		const_reference	operator[](size_type a_pos) const;
		const char&		front() const;
		const char&		back() const;
		const char*		data() const noexcept;
		const char*		c_str() const noexcept;

		// Iterators
		const_iterator			begin() const noexcept;
		const_iterator			cbegin() const noexcept;
		const_iterator			end() const noexcept;
		const_iterator			cend() const noexcept;
		const_reverse_iterator	rbegin() const noexcept;
		const_reverse_iterator	crbegin() const noexcept;
		const_reverse_iterator	rend() const noexcept;
		const_reverse_iterator	crend() const noexcept;

		// Capacity
		bool				empty() const noexcept;
		size_type			size() const noexcept;
		size_type			length() const noexcept;
		static size_type	max_size() noexcept;

		// Operations
		void	clear() noexcept;
		int		compare(const BSFixedString& a_rhs) const noexcept;
		int		compare(const char* a_rhs) const;

		inline friend bool	operator==(const BSFixedString& a_lhs, const char* a_rhs) { return (a_lhs._data == a_rhs || _stricmp(a_lhs._data, a_rhs) == 0); }
		inline friend bool	operator!=(const BSFixedString& a_lhs, const char* a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool	operator==(const char* a_lhs, const BSFixedString& a_rhs) { return (a_rhs == a_lhs); }
		inline friend bool	operator!=(const char* a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool	operator==(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return (a_lhs == a_rhs._data); }
		inline friend bool	operator!=(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		bool				operator==(const BSString& a_rhs) const;
		bool				operator!=(const BSString& a_rhs) const;

		TES_HEAP_REDEFINE_NEW();


		static constexpr size_type npos{ static_cast<size_type>(-1) };	// NOT PART OF NATIVE TYPE

	protected:
		BSFixedString*	ctor_cstr(const char* a_rhs);
		BSFixedString*	ctor_copy(const BSFixedString& a_rhs);
		void			dtor();
		BSFixedString*	set_cstr(const char* a_rhs);
		BSFixedString*	set_copy(const BSFixedString& a_rhs);
		void			assert_out_of_range(size_type a_index, const char* a_func) const;
		void			assert_length_error(size_type a_count, const char* a_func) const;


		static constexpr value_type NULL_CHARACTER{ char() };	// NOT PART OF NATIVE TYPE

		// members
		const char* _data;	// 0
	};
	STATIC_ASSERT(sizeof(BSFixedString) == 0x8);
}
