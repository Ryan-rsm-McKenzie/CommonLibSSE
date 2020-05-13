#pragma once

#include <cassert>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

#include "RE/BSScript/CommonTypeTraits.h"


namespace RE
{
	namespace BSScript
	{
		class Variable;


		template <class, class = void>
		class reference_array;


		namespace Impl
		{
			// a helper class to delay implementation so as to avoid circular dependencies
			struct reference_array_helper
			{
				template <class T>
				static void wrap(reference_array<T>& a_arr);

				template <class T>
				static void unwrap(reference_array<T>& a_arr, Variable* a_wrapped);
			};
		}


		template <class T>
		class reference_array<
			T,
			std::enable_if_t<
				std::disjunction_v<
					is_builtin_convertible<T>,
					is_form_pointer<T>>>>
		{
		public:
			using container_type = std::vector<T>;
			using value_type = typename container_type::value_type;
			using size_type = typename container_type::size_type;
			using difference_type = typename container_type::difference_type;
			using reference = typename container_type::reference;
			using const_reference = typename container_type::const_reference;
			using pointer = typename container_type::pointer;
			using const_pointer = typename container_type::const_pointer;
			using iterator = typename container_type::iterator;
			using const_iterator = typename container_type::const_iterator;
			using reverse_iterator = typename container_type::reverse_iterator;
			using const_reverse_iterator = typename container_type::const_reverse_iterator;

			reference_array() :
				_unwrapped(),
				_wrapped(nullptr)
			{}

			reference_array(Variable* a_wrapped) :
				_unwrapped(),
				_wrapped(nullptr)
			{
				do_unwrap(a_wrapped);
			}

			reference_array(const reference_array&) = delete;

			reference_array(reference_array&& a_rhs) :
				_unwrapped(std::move(a_rhs._unwrapped)),
				_wrapped(std::move(a_rhs._wrapped))
			{
				a_rhs._wrapped = nullptr;
			}

			~reference_array() { do_wrap(); }

			reference_array& operator=(Variable* a_wrapped)
			{
				do_unwrap(a_wrapped);
				return *this;
			}

			reference_array& operator=(const reference_array&) = delete;

			reference_array& operator=(reference_array&& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					do_wrap();
					_unwrapped = std::move(a_rhs._unwrapped);
					_wrapped = std::move(a_rhs._wrapped);
					a_rhs._wrapped = nullptr;
				}
				return *this;
			}

			[[nodiscard]] operator container_type() const { return _unwrapped; }

			[[nodiscard]] reference		  at(size_type a_pos) { return _unwrapped.at(a_pos); }
			[[nodiscard]] const_reference at(size_type a_pos) const { return _unwrapped.at(a_pos); }

			[[nodiscard]] reference		  operator[](size_type a_pos) { return _unwrapped[a_pos]; }
			[[nodiscard]] const_reference operator[](size_type a_pos) const { return _unwrapped[a_pos]; }

			[[nodiscard]] reference		  front() { return _unwrapped.front(); }
			[[nodiscard]] const_reference front() const { return _unwrapped.front(); }

			[[nodiscard]] reference		  back() { return _unwrapped.back(); }
			[[nodiscard]] const_reference back() const { return _unwrapped.back(); }

			[[nodiscard]] pointer		data() noexcept { return _unwrapped.data(); }
			[[nodiscard]] const_pointer data() const noexcept { return _unwrapped.data(); }

			[[nodiscard]] iterator		 begin() noexcept { return _unwrapped.begin(); }
			[[nodiscard]] const_iterator begin() const noexcept { return _unwrapped.begin(); }
			[[nodiscard]] const_iterator cbegin() const noexcept { return _unwrapped.cbegin(); }

			[[nodiscard]] iterator		 end() noexcept { return _unwrapped.end(); }
			[[nodiscard]] const_iterator end() const noexcept { return _unwrapped.end(); }
			[[nodiscard]] const_iterator cend() const noexcept { return _unwrapped.cend(); }

			[[nodiscard]] reverse_iterator		 rbegin() noexcept { return _unwrapped.rbegin(); }
			[[nodiscard]] const_reverse_iterator rbegin() const noexcept { return _unwrapped.rbegin(); }
			[[nodiscard]] const_reverse_iterator crbegin() const noexcept { return _unwrapped.crbegin(); }

			[[nodiscard]] reverse_iterator		 rend() noexcept { return _unwrapped.rend(); }
			[[nodiscard]] const_reverse_iterator rend() const noexcept { return _unwrapped.rend(); }
			[[nodiscard]] const_reverse_iterator crend() const noexcept { return _unwrapped.crend(); }

			[[nodiscard]] bool empty() const noexcept { return _unwrapped.empty(); }

			[[nodiscard]] size_type size() const noexcept { return _unwrapped.size(); }

			void swap(reference_array& a_rhs)
			{
				using std::swap;
				swap(_unwrapped, a_rhs._unwrapped);
				swap(_wrapped, a_rhs._wrapped);
			}

		protected:
			friend struct Impl::reference_array_helper;

			container_type _unwrapped;
			Variable*	   _wrapped;

		private:
			void do_wrap()
			{
				Impl::reference_array_helper::wrap(*this);
			}

			void do_unwrap(Variable* a_wrapped)
			{
				Impl::reference_array_helper::unwrap(*this, a_wrapped);
			}
		};


		template <class T>
		void swap(reference_array<T>& a_lhs, reference_array<T>& a_rhs)
		{
			a_lhs.swap(a_rhs);
		}
	}


	template <class T>
	using reference_array = BSScript::reference_array<T>;
}
