#include "RE/BSScript/Array.h"


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


		[[nodiscard]] auto Array::at(size_type a_pos)
			-> reference
		{
			if (a_pos >= size()) {
				out_of_range(__FUNCTION__, a_pos);
			}

			return _data[a_pos];
		}


		[[nodiscard]] auto Array::at(size_type a_pos) const
			-> const_reference
		{
			if (a_pos >= size()) {
				out_of_range(__FUNCTION__, a_pos);
			}

			return _data[a_pos];
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
			assert(size() > 0);
			return _data[0];
		}


		[[nodiscard]] auto Array::front() const
			-> const_reference
		{
			assert(size() > 0);
			return _data[0];
		}


		[[nodiscard]] auto Array::back()
			-> reference
		{
			assert(size() > 0);
			return _data[size() - 1];
		}


		[[nodiscard]] auto Array::back() const
			-> const_reference
		{
			assert(size() > 0);
			return _data[size() - 1];
		}


		[[nodiscard]] Variable* Array::data() noexcept
		{
			return size() > 0 ? _data : 0;
		}


		[[nodiscard]] auto Array::begin() noexcept
			-> iterator
		{
			return iterator(_data);
		}


		[[nodiscard]] auto Array::begin() const noexcept
			-> const_iterator
		{
			return const_iterator(_data);
		}


		[[nodiscard]] auto Array::cbegin() const noexcept
			-> const_iterator
		{
			return begin();
		}


		[[nodiscard]] auto Array::end() noexcept
			-> iterator
		{
			return iterator(_data, _len);
		}


		[[nodiscard]] auto Array::end() const noexcept
			-> const_iterator
		{
			return const_iterator(_data, _len);
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


		[[nodiscard]] const Variable* Array::data() const noexcept
		{
			return size() > 0 ? _data : 0;
		}


		[[nodiscard]] bool Array::empty() const noexcept
		{
			return size() > 0;
		}


		[[nodiscard]] auto Array::size() const noexcept
			-> size_type
		{
			return _len;
		}


		[[nodiscard]] auto Array::max_size() const noexcept
			-> size_type
		{
			return kMaxSize;
		}


		[[nodiscard]] Type& Array::type()
		{
			return _type;
		}


		[[nodiscard]] const Type& Array::type() const
		{
			return _type;
		}


		[[nodiscard]] VMTypeID Array::type_id() const
		{
			auto typeID = _type.GetTypeID();
			switch (typeID) {
			case VMTypeID::kNone:
			case VMTypeID::kObject:
			case VMTypeID::kString:
			case VMTypeID::kInt:
			case VMTypeID::kFloat:
			case VMTypeID::kBool:
				return typeID + VMTypeID::kNoneArray;
			default:
				return typeID + VMTypeID::kObject;
			}
		}


		void Array::out_of_range(const char* a_fnName, size_type a_pos) const
		{
			std::string err = a_fnName;
			err += ": a_pos (which is ";
			err += std::to_string(a_pos);
			err += ") >= _len (which is ";
			err += std::to_string(_len);
			err += ")";
			throw std::out_of_range(err);
		}
	}
}
