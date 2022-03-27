#pragma once

#include "RE/B/BSStringPool.h"
#include "RE/C/CRC.h"

namespace RE
{
	namespace detail
	{
		template <class CharT>
		class BSFixedString
		{
		public:
			using size_type = std::uint32_t;
			using value_type = CharT;
			using pointer = value_type*;
			using const_pointer = const value_type*;
			using reference = value_type&;
			using const_reference = const value_type&;

			constexpr BSFixedString() noexcept = default;

			inline BSFixedString(const BSFixedString& a_rhs) :
				_data(a_rhs._data)
			{
				try_acquire();
			}

			inline BSFixedString(BSFixedString&& a_rhs) :
				_data(a_rhs._data)
			{
				a_rhs._data = nullptr;
			}

			inline BSFixedString(const_pointer a_string)
			{
				if (a_string) {
					ctor(a_string);
				}
			}

			template <
				class T,
				std::enable_if_t<
					std::conjunction_v<
						std::is_convertible<const T&, std::basic_string_view<value_type>>,
						std::negation<
							std::is_convertible<const T&, const_pointer>>>,
					int> = 0>
			inline BSFixedString(const T& a_string)
			{
				const auto view = static_cast<std::basic_string_view<value_type>>(a_string);
				if (!view.empty()) {
					ctor(view.data());
				}
			}

			inline ~BSFixedString() { try_release(); }

			inline BSFixedString& operator=(const BSFixedString& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					try_release();
					_data = a_rhs._data;
					try_acquire();
				}
				return *this;
			}

			inline BSFixedString& operator=(BSFixedString&& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					try_release();
					_data = a_rhs._data;
					a_rhs._data = nullptr;
				}
				return *this;
			}

			inline BSFixedString& operator=(const_pointer a_string)
			{
				try_release();
				if (a_string) {
					ctor(a_string);
				}
				return *this;
			}

			template <
				class T,
				std::enable_if_t<
					std::conjunction_v<
						std::is_convertible<const T&, std::basic_string_view<value_type>>,
						std::negation<
							std::is_convertible<const T&, const_pointer>>>,
					int> = 0>
			inline BSFixedString& operator=(const T& a_string)
			{
				const auto view = static_cast<std::basic_string_view<value_type>>(a_string);
				try_release();
				if (!view.empty()) {
					ctor(view.data());
				}
				return *this;
			}

			[[nodiscard]] inline const_reference operator[](size_type a_pos) const noexcept
			{
				assert(a_pos < size());
				return _data[a_pos];
			}

			[[nodiscard]] inline const_reference front() const noexcept { return _data[0]; }
			[[nodiscard]] inline const_reference back() const noexcept { return _data[size() - 1]; }

			[[nodiscard]] inline const_pointer data() const noexcept
			{
				const auto proxy = get_proxy();
				const auto cstr = proxy ? proxy->template data<value_type>() : nullptr;
				return cstr ? cstr : EMPTY;
			}

			[[nodiscard]] inline const_pointer c_str() const noexcept { return data(); }

			[[nodiscard]] constexpr operator std::basic_string_view<value_type>() const { return { c_str(), length() }; }

			[[nodiscard]] constexpr bool empty() const noexcept { return size() == 0; }

			[[nodiscard]] constexpr size_type size() const noexcept
			{
				const auto proxy = get_proxy();
				return proxy ? proxy->size() : 0;
			}

			[[nodiscard]] constexpr size_type length() const noexcept { return size(); }

			[[nodiscard]] inline friend bool operator==(const BSFixedString& a_lhs, const BSFixedString& a_rhs) noexcept
			{
				return a_lhs._data == a_rhs._data || a_lhs.empty() && a_rhs.empty();
			}

			[[nodiscard]] inline friend bool operator!=(const BSFixedString& a_lhs, const BSFixedString& a_rhs) noexcept { return !(a_lhs == a_rhs); }

			[[nodiscard]] inline friend bool operator==(const BSFixedString& a_lhs, std::basic_string_view<value_type> a_rhs)
			{
				if (a_lhs.empty() && a_rhs.empty()) {
					return true;
				} else if (const auto length = a_lhs.length(); length != a_rhs.length()) {
					return false;
				} else {
					return strncmp(a_lhs.c_str(), a_rhs.data(), length) == 0;
				}
			}

			[[nodiscard]] inline friend bool operator!=(const BSFixedString& a_lhs, std::basic_string_view<value_type> a_rhs) { return !(a_lhs == a_rhs); }
			[[nodiscard]] inline friend bool operator==(std::basic_string_view<value_type> a_lhs, const BSFixedString& a_rhs) { return a_rhs == a_lhs; }
			[[nodiscard]] inline friend bool operator!=(std::basic_string_view<value_type> a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }

			[[nodiscard]] inline friend bool operator==(const BSFixedString& a_lhs, const_pointer a_rhs) { return a_lhs == std::basic_string_view<value_type>(a_rhs ? a_rhs : EMPTY); }
			[[nodiscard]] inline friend bool operator!=(const BSFixedString& a_lhs, const_pointer a_rhs) { return !(a_lhs == a_rhs); }
			[[nodiscard]] inline friend bool operator==(const_pointer a_lhs, const BSFixedString& a_rhs) { return a_rhs == a_lhs; }
			[[nodiscard]] inline friend bool operator!=(const_pointer a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }

		private:
			[[nodiscard]] static inline int strncmp(const char* a_lhs, const char* a_rhs, std::size_t a_length)
			{
				return _strnicmp(a_lhs, a_rhs, a_length);
			}

			[[nodiscard]] static inline int strncmp(const wchar_t* a_lhs, const wchar_t* a_rhs, std::size_t a_length)
			{
				return _wcsnicmp(a_lhs, a_rhs, a_length);
			}

			inline BSFixedString* ctor(const char* a_data) { return ctor8(a_data); }
			inline BSFixedString* ctor(const wchar_t* a_data) { return ctor16(a_data); }

			inline BSFixedString* ctor8(const char* a_data)
			{
				using func_t = decltype(&BSFixedString::ctor8);
				REL::Relocation<func_t> func{ REL::ID(69161) };
				return func(this, a_data);
			}

			inline BSFixedString* ctor16(const wchar_t* a_data)
			{
				using func_t = decltype(&BSFixedString::ctor16);
				REL::Relocation<func_t> func{ REL::ID(69176) };
				return func(this, a_data);
			}

			[[nodiscard]] inline BSStringPool::Entry* get_proxy() noexcept
			{
				return _data ?
                           reinterpret_cast<BSStringPool::Entry*>(const_cast<pointer>(_data)) - 1 :
                           nullptr;
			}

			[[nodiscard]] inline const BSStringPool::Entry* get_proxy() const noexcept
			{
				return _data ?
                           reinterpret_cast<const BSStringPool::Entry*>(_data) - 1 :
                           nullptr;
			}

			inline void try_acquire()
			{
				const auto proxy = get_proxy();
				if (proxy) {
					proxy->acquire();
				}
			}

			inline void try_release() { BSStringPool::Entry::release(_data); }

			static constexpr const value_type EMPTY[]{ 0 };

			// members
			const_pointer _data{ nullptr };  // 0
		};

		extern template class BSFixedString<char>;
		extern template class BSFixedString<wchar_t>;
	}

	using BSFixedString = detail::BSFixedString<char>;
	using BSFixedStringCI = BSFixedString;
	using BSFixedStringW = detail::BSFixedString<wchar_t>;

	template <class CharT>
	struct BSCRC32_<detail::BSFixedString<CharT>>
	{
	public:
		[[nodiscard]] inline std::uint32_t operator()(const detail::BSFixedString<CharT>& a_key) const noexcept
		{
			return BSCRC32_<const void*>()(a_key.data());
		}
	};
}
