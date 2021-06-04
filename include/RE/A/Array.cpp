#include "RE/A/Array.h"

namespace RE
{
	namespace BSScript
	{
		Array::~Array()
		{
			for (size_type i = 0; i < size(); ++i) {
				operator[](i).~Variable();
			}
		}

		[[nodiscard]] auto Array::operator[](size_type a_pos)
			-> reference
		{
			assert(a_pos < size());
			return _data[a_pos];
		}

		[[nodiscard]] auto Array::operator[](size_type a_pos) const
			-> const_reference
		{
			assert(a_pos < size());
			return _data[a_pos];
		}

		[[nodiscard]] auto Array::front()
			-> reference
		{
			return operator[](0);
		}

		[[nodiscard]] auto Array::front() const
			-> const_reference
		{
			return operator[](0);
		}

		[[nodiscard]] auto Array::back()
			-> reference
		{
			return operator[](size() - 1);
		}

		[[nodiscard]] auto Array::back() const
			-> const_reference
		{
			return operator[](size() - 1);
		}

		[[nodiscard]] auto Array::data() noexcept
			-> pointer
		{
			return size() > 0 ? _data : nullptr;
		}

		[[nodiscard]] auto Array::data() const noexcept
			-> const_pointer
		{
			return size() > 0 ? _data : nullptr;
		}

		[[nodiscard]] auto Array::begin() noexcept
			-> iterator
		{
			return data();
		}

		[[nodiscard]] auto Array::begin() const noexcept
			-> const_iterator
		{
			return data();
		}

		[[nodiscard]] auto Array::cbegin() const noexcept
			-> const_iterator
		{
			return begin();
		}

		[[nodiscard]] auto Array::end() noexcept
			-> iterator
		{
			return size() > 0 ? _data + size() : nullptr;
		}

		[[nodiscard]] auto Array::end() const noexcept
			-> const_iterator
		{
			return size() > 0 ? _data + size() : nullptr;
		}

		[[nodiscard]] auto Array::cend() const noexcept
			-> const_iterator
		{
			return end();
		}

		[[nodiscard]] auto Array::rbegin() noexcept
			-> reverse_iterator
		{
			return reverse_iterator(end());
		}

		[[nodiscard]] auto Array::rbegin() const noexcept
			-> const_reverse_iterator
		{
			return const_reverse_iterator(end());
		}

		[[nodiscard]] auto Array::crbegin() const noexcept
			-> const_reverse_iterator
		{
			return rbegin();
		}

		[[nodiscard]] auto Array::rend() noexcept
			-> reverse_iterator
		{
			return reverse_iterator(begin());
		}

		[[nodiscard]] auto Array::rend() const noexcept
			-> const_reverse_iterator
		{
			return const_reverse_iterator(begin());
		}

		[[nodiscard]] auto Array::crend() const noexcept
			-> const_reverse_iterator
		{
			return rend();
		}

		[[nodiscard]] bool Array::empty() const noexcept
		{
			return size() > 0;
		}

		[[nodiscard]] auto Array::size() const noexcept
			-> size_type
		{
			return _size;
		}

		[[nodiscard]] auto Array::max_size() const noexcept
			-> size_type
		{
			return MAX_SIZE;
		}

		[[nodiscard]] TypeInfo& Array::type_info()
		{
			return _elementType;
		}

		[[nodiscard]] const TypeInfo& Array::type_info() const
		{
			return _elementType;
		}

		[[nodiscard]] TypeInfo::RawType Array::type() const
		{
			const stl::enumeration typeID = _elementType.GetRawType();
			switch (*typeID) {
			case TypeInfo::RawType::kNone:
			case TypeInfo::RawType::kObject:
			case TypeInfo::RawType::kString:
			case TypeInfo::RawType::kInt:
			case TypeInfo::RawType::kFloat:
			case TypeInfo::RawType::kBool:
				return *(typeID + TypeInfo::RawType::kNoneArray);
			default:
				return *(typeID + TypeInfo::RawType::kObject);
			}
		}
	}
}
