#pragma once

#include <iterator>  // random_access_iterator_tag, reverse_iterator
#include <initializer_list>  // initializer_list


namespace RE
{
	class BSString;


	class BSFixedString
	{
	public:
		struct const_iterator
		{
		public:
			typedef std::int64_t					difference_type;
			typedef const char						value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef std::random_access_iterator_tag	iterator_category;


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


		typedef char									value_type;
		typedef UInt32									size_type;
		typedef value_type								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;


		// (constructor)
		BSFixedString();
		BSFixedString(size_type a_count, char a_ch);
		BSFixedString(const BSFixedString& a_other, size_type a_pos, size_type a_count = npos);
		BSFixedString(const char* a_s);
		template <class InputIt>
		BSFixedString(InputIt a_first, InputIt a_last)
		{
			char* arr = insert_internal(0, a_first.operator->(), a_last - a_first);
			ctor_internal(this, arr);
			::delete[] arr;
		}
		BSFixedString(const BSFixedString& a_other);
		BSFixedString(BSFixedString&& a_other) noexcept;
		BSFixedString(std::initializer_list<char> a_ilist);

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
		bool		empty() const noexcept;
		size_type	size() const noexcept;
		size_type	length() const noexcept;
		size_type	max_size() const noexcept;

		// Operations
		void			clear() noexcept;
		BSFixedString&	insert(size_type a_index, size_type a_count, char a_ch);
		BSFixedString&	insert(size_type a_index, const char* a_s);
		BSFixedString&	insert(size_type a_index, const char* a_s, size_type a_count);
		BSFixedString&	insert(size_type a_index, const BSFixedString& a_str);
		BSFixedString&	insert(size_type a_index, const BSFixedString& a_str, size_type a_index_str, size_type a_count = npos);
		void			push_back(char a_ch);
		void			pop_back();
		BSFixedString&	append(size_type a_count, char a_ch);
		BSFixedString&	append(const BSFixedString& a_str);
		BSFixedString&	append(const BSFixedString& a_str, size_type a_pos, size_type a_count = npos);
		BSFixedString&	append(const char* a_s, size_type a_count);
		BSFixedString&	append(const char* a_s);
		template <class InputIt>
		BSFixedString&	append(InputIt a_first, InputIt a_last)
		{
			char* arr = insert_internal(0, a_first.operator->(), a_last - a_first);
			set_internal(this, arr);
			::delete[] arr;
			return *this;
		}
		BSFixedString&	append(std::initializer_list<char> a_ilist);
		BSFixedString&	operator+=(const BSFixedString& a_str);
		BSFixedString&	operator+=(char a_ch);
		BSFixedString&	operator+=(const char* a_s);
		BSFixedString&	operator+=(std::initializer_list<char> a_ilist);
		int				compare(const BSFixedString& a_str) const noexcept;
		int				compare(size_type a_pos1, size_type a_count1, const BSFixedString& a_str) const;
		int				compare(size_type a_pos1, size_type a_count1, const BSFixedString& a_str, size_type a_pos2, size_type a_count2 = npos) const;
		int				compare(const char* a_s) const;
		int				compare(size_type a_pos1, size_type a_count1, const char* a_s) const;
		BSFixedString	substr(size_type a_pos = 0, size_type a_count = npos) const;

		friend bool	operator==(const BSFixedString& a_lhs, const char* a_rhs) { return (a_lhs._data == a_rhs || _stricmp(a_lhs._data, a_rhs) == 0); }
		friend bool	operator!=(const BSFixedString& a_lhs, const char* a_rhs) { return !(a_lhs == a_rhs); }
		friend bool	operator==(const char* a_lhs, const BSFixedString& a_rhs) { return (a_rhs == a_lhs); }
		friend bool	operator!=(const char* a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		friend bool	operator==(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return (a_lhs == a_rhs._data); }
		friend bool	operator!=(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		bool		operator==(const BSString& a_rhs) const;
		bool		operator!=(const BSString& a_rhs) const;


		static constexpr size_type npos{ static_cast<size_type>(-1) };	// NOT PART OF NATIVE TYPE

	protected:
		static BSFixedString*	ctor_internal(BSFixedString* a_this, const char* a_s);
		static BSFixedString*	ctor_copy_internal(BSFixedString* a_this, const BSFixedString& a_other);
		static void				dtor_internal(BSFixedString* a_this);
		static BSFixedString*	set_internal(BSFixedString* a_this, const char* a_rhs);
		static BSFixedString*	set_copy_internal(BSFixedString* a_this, const BSFixedString& a_rhs);

		void					assert_out_of_range(size_type a_index, const char* a_func) const;
		void					assert_length_error(size_type a_count, const char* a_func) const;
		char*					insert_internal(size_type a_index, const char* a_s, size_type a_count);
		char*					insert_char_internal(size_type a_index, size_type a_count, char a_ch);


		static constexpr const_reference NULL_CHARACTER{ char() };	// NOT PART OF NATIVE TYPE

		// members
		const char* _data;	// 0
	};
	STATIC_ASSERT(sizeof(BSFixedString) == 0x8);
}
