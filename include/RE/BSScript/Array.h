#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSScript/TypeInfo.h"
#include "RE/BSScript/Variable.h"


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
			using iterator = value_type*;
			using const_iterator = const value_type*;
			using reverse_iterator = std::reverse_iterator<iterator>;
			using const_reverse_iterator = std::reverse_iterator<const_iterator>;


			~Array();

			[[nodiscard]] reference		  at(size_type a_pos);
			[[nodiscard]] const_reference at(size_type a_pos) const;

			[[nodiscard]] reference		  operator[](size_type a_pos);
			[[nodiscard]] const_reference operator[](size_type a_pos) const;

			[[nodiscard]] reference		  front();
			[[nodiscard]] const_reference front() const;

			[[nodiscard]] reference		  back();
			[[nodiscard]] const_reference back() const;

			[[nodiscard]] pointer		data() noexcept;
			[[nodiscard]] const_pointer data() const noexcept;

			[[nodiscard]] iterator		 begin() noexcept;
			[[nodiscard]] const_iterator begin() const noexcept;
			[[nodiscard]] const_iterator cbegin() const noexcept;

			[[nodiscard]] iterator		 end() noexcept;
			[[nodiscard]] const_iterator end() const noexcept;
			[[nodiscard]] const_iterator cend() const noexcept;

			[[nodiscard]] reverse_iterator		 rbegin() noexcept;
			[[nodiscard]] const_reverse_iterator rbegin() const noexcept;
			[[nodiscard]] const_reverse_iterator crbegin() const noexcept;

			[[nodiscard]] reverse_iterator		 rend() noexcept;
			[[nodiscard]] const_reverse_iterator rend() const noexcept;
			[[nodiscard]] const_reverse_iterator crend() const noexcept;

			[[nodiscard]] bool empty() const noexcept;

			[[nodiscard]] size_type size() const noexcept;

			[[nodiscard]] size_type max_size() const noexcept;

			[[nodiscard]] TypeInfo&		  type_info();
			[[nodiscard]] const TypeInfo& type_info() const;

			[[nodiscard]] TypeInfo::RawType type() const;

		private:
			void out_of_range(const char* a_fnName, size_type a_pos) const;


			static inline constexpr size_type MAX_SIZE = 128;

			// members
			UInt32			   _pad04;		  // 04
			TypeInfo		   _elementType;  // 08
			UInt32			   _size;		  // 10
			UInt32			   _pad14;		  // 14
			mutable BSSpinLock _lock;		  // 18
			Variable		   _data[0];	  // 20
		};
		STATIC_ASSERT(sizeof(Array) == 0x20);
	}
}
