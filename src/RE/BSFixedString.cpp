#include "RE/BSFixedString.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameTypes.h"  // BSFixedString

#include <cctype>  // tolower
#include <cstdint>  // uintptr_t
#include <cstring>  // strlen
#include <memory>  // pointer_traits
#include <stdexcept>  // out_of_range, length_error
#include <string>  // string

#include "RE/BSString.h"  // BSString
#include "RE/Offsets.h"
#include "RE/StringCache.h"  // StringCache::Entry


namespace RE
{
	BSFixedString::const_iterator::const_iterator() :
		_ptr(0)
	{}


	BSFixedString::const_iterator::const_iterator(pointer a_ptr) :
		_ptr(a_ptr)
	{}


	BSFixedString::const_iterator::reference BSFixedString::const_iterator::operator*() const
	{
		return *_ptr;
	}


	BSFixedString::const_iterator::pointer BSFixedString::const_iterator::operator->() const
	{
		return std::pointer_traits<pointer>::pointer_to(operator*());
	}


	// prefix
	BSFixedString::const_iterator& BSFixedString::const_iterator::operator++()
	{
		++_ptr;
		return *this;
	}


	// postfix
	BSFixedString::const_iterator BSFixedString::const_iterator::operator++(int)
	{
		const_iterator tmp(*this);
		operator++();
		return tmp;
	}


	// prefix
	BSFixedString::const_iterator& BSFixedString::const_iterator::operator--()
	{
		--_ptr;
		return *this;
	}


	// postfix
	BSFixedString::const_iterator BSFixedString::const_iterator::operator--(int)
	{
		const_iterator tmp(*this);
		operator--();
		return tmp;
	}


	BSFixedString::const_iterator& BSFixedString::const_iterator::operator+=(const difference_type a_off)
	{
		_ptr += a_off;
		return *this;
	}


	BSFixedString::const_iterator BSFixedString::const_iterator::operator+(const difference_type a_off) const
	{
		const_iterator tmp(*this);
		return tmp += a_off;
	}


	BSFixedString::const_iterator& BSFixedString::const_iterator::operator-=(const difference_type a_off)
	{
		return operator+=(-a_off);
	}


	BSFixedString::const_iterator BSFixedString::const_iterator::operator-(const difference_type a_off) const
	{
		const_iterator tmp(*this);
		return tmp -= a_off;
	}


	BSFixedString::const_iterator::difference_type BSFixedString::const_iterator::operator-(const const_iterator& a_rhs) const
	{
		return _ptr - a_rhs._ptr;
	}


	BSFixedString::const_iterator::reference BSFixedString::const_iterator::operator[](const difference_type a_off) const
	{
		return *(operator+(a_off));
	}


	bool BSFixedString::const_iterator::operator==(const const_iterator& a_rhs) const
	{
		return _ptr == a_rhs._ptr;
	}


	bool BSFixedString::const_iterator::operator!=(const const_iterator& a_rhs) const
	{
		return !operator==(a_rhs);
	}


	bool BSFixedString::const_iterator::operator<(const const_iterator& a_rhs) const
	{
		return _ptr < a_rhs._ptr;
	}


	bool BSFixedString::const_iterator::operator>(const const_iterator& a_rhs) const
	{
		return a_rhs.operator<(*this);
	}


	bool BSFixedString::const_iterator::operator<=(const const_iterator& a_rhs) const
	{
		return !operator>(a_rhs);
	}


	bool BSFixedString::const_iterator::operator>=(const const_iterator& a_rhs) const
	{
		return !operator<(a_rhs);
	}


	BSFixedString::BSFixedString() :
		_data(0)
	{
		ctor_internal(this, "");
	}


	BSFixedString::BSFixedString(size_type a_count, char a_ch) :
		_data(0)
	{
		char* arr = insert_char_internal(0, a_count, a_ch);
		ctor_internal(this, arr);
		::delete[] arr;
	}


	BSFixedString::BSFixedString(const BSFixedString& a_other, size_type a_pos, size_type a_count) :
		_data(0)
	{
		a_other.assert_out_of_range(a_pos, __FUNCTION__);
		size_type size = ((a_count == npos) || ((a_count - a_pos) > a_other.size())) ? (a_other.size() - a_pos) : (a_count - a_pos);
		char* arr = insert_internal(0, a_other.c_str() + a_pos, size);
		ctor_internal(this, arr);
		::delete[] arr;
	}


	BSFixedString::BSFixedString(const char* a_s) :
		_data(0)
	{
		ctor_internal(this, a_s);
	}


	BSFixedString::BSFixedString(const BSFixedString& a_other)
	{
		ctor_copy_internal(this, a_other);
	}


	BSFixedString::BSFixedString(BSFixedString&& a_other) noexcept
	{
		_data = a_other._data;
		a_other._data = 0;
	}


	BSFixedString::BSFixedString(std::initializer_list<char> a_ilist)
	{
		char* arr = insert_internal(0, a_ilist.begin(), a_ilist.size());
		ctor_internal(this, arr);
		::delete[] arr;
	}


	BSFixedString::~BSFixedString()
	{
		dtor_internal(this);
	}


	BSFixedString& BSFixedString::operator=(const BSFixedString& a_rhs)
	{
		if (_data && _data[0]) {
			dtor_internal(this);
		}

		return *set_copy_internal(this, a_rhs);
	}


	BSFixedString& BSFixedString::operator=(BSFixedString&& a_rhs)
	{
		_data = a_rhs._data;
		a_rhs._data = 0;

		return *this;
	}


	BSFixedString& BSFixedString::operator=(const char* a_rhs)
	{
		if (_data && _data[0]) {
			dtor_internal(this);
		}

		return *set_internal(this, a_rhs);
	}


	BSFixedString::const_reference BSFixedString::at(size_type a_pos) const
	{
		if (a_pos >= size()) {
			std::string err = __FUNCTION__;
			err += ": ";
			err += MAKE_STR(a_pos);
			err += " (which is" + std::to_string(a_pos) + ") >= this->size() (which is" + std::to_string(this->size()) + ")";
			throw std::out_of_range(err);
		} else {
			return operator[](a_pos);
		}
	}


	BSFixedString::const_reference BSFixedString::operator[](size_type a_pos) const
	{
		if (a_pos == size()) {
			return NULL_CHARACTER;
		} else {
			return _data[a_pos];
		}
	}


	const char& BSFixedString::front() const
	{
		return operator[](0);
	}


	const char& BSFixedString::back() const
	{
		return operator[](size() - 1);
	}


	const char* BSFixedString::data() const noexcept
	{
		return _data;
	}


	const char* BSFixedString::c_str() const noexcept
	{
		return data();
	}


	BSFixedString::const_iterator BSFixedString::begin() const noexcept
	{
		return const_iterator(std::addressof(_data[0]));
	}


	BSFixedString::const_iterator BSFixedString::cbegin() const noexcept
	{
		return begin();
	}


	BSFixedString::const_iterator BSFixedString::end() const noexcept
	{
		return const_iterator(std::addressof(_data[size()]));
	}


	BSFixedString::const_iterator BSFixedString::cend() const noexcept
	{
		return end();
	}


	BSFixedString::const_reverse_iterator BSFixedString::rbegin() const noexcept
	{
		return const_reverse_iterator(std::addressof(_data[size() - 1]));
	}


	BSFixedString::const_reverse_iterator BSFixedString::crbegin() const noexcept
	{
		return rbegin();
	}


	BSFixedString::const_reverse_iterator BSFixedString::rend() const noexcept
	{
		return const_reverse_iterator(std::addressof(_data[-1]));
	}


	BSFixedString::const_reverse_iterator BSFixedString::crend() const noexcept
	{
		return rend();
	}


	bool BSFixedString::empty() const noexcept
	{
		return size() == 0;
	}


	BSFixedString::size_type BSFixedString::size() const noexcept
	{
		UInt32 len = 0;
		if (this && _data) {
			StringCache::Entry* entry = (StringCache::Entry*)((std::uintptr_t)_data - offsetof(StringCache::Entry, data));
			len = entry->length & StringCache::Entry::kLengthMask;
		}
		return len;
	}


	BSFixedString::size_type BSFixedString::length() const noexcept
	{
		return size();
	}


	BSFixedString::size_type BSFixedString::max_size() noexcept
	{
		return 0xFFFFFFE6;
	}


	void BSFixedString::clear() noexcept
	{
		set_internal(this, "");
	}


	BSFixedString& BSFixedString::insert(size_type a_index, size_type a_count, char a_ch)
	{
		assert_out_of_range(a_index, __FUNCTION__);
		insert_char_internal(a_index, a_count, a_ch);
		return *this;
	}


	BSFixedString& BSFixedString::insert(size_type a_index, const char* a_s)
	{
		assert_out_of_range(std::strlen(a_s), __FUNCTION__);
		char* arr = insert_internal(a_index, a_s, std::strlen(a_s));
		set_internal(this, arr);
		::delete[] arr;
		return *this;
	}


	BSFixedString& BSFixedString::insert(size_type a_index, const char* a_s, size_type a_count)
	{
		assert_out_of_range(a_count, __FUNCTION__);
		char* arr = insert_internal(a_index, a_s, a_count);
		set_internal(this, arr);
		::delete[] arr;
		return *this;
	}


	BSFixedString& BSFixedString::insert(size_type a_index, const BSFixedString& a_str)
	{
		assert_out_of_range(a_str.size(), __FUNCTION__);
		char* arr = insert_internal(a_index, a_str.c_str(), a_str.size());
		set_internal(this, arr);
		::delete[] arr;
		return *this;
	}


	BSFixedString& BSFixedString::insert(size_type a_index, const BSFixedString& a_str, size_type a_index_str, size_type a_count)
	{
		return insert(a_index, a_str.substr(a_index_str, a_count));
	}


	void BSFixedString::push_back(char a_ch)
	{
		assert_length_error(1, __FUNCTION__);
		insert_char_internal(size(), 1, a_ch);
	}


	void BSFixedString::pop_back()
	{
		if (size() == 0) {
			return;
		}

		char* arr = ::new char[size()];
		for (size_type i = 0; i < size() - 1; ++i) {
			arr[i] = operator[](i);
		}
		arr[size() - 1] = '\0';

		set_internal(this, arr);

		::delete[] arr;
	}


	BSFixedString& BSFixedString::append(size_type a_count, char a_ch)
	{
		assert_length_error(a_count, __FUNCTION__);
		char* arr = insert_char_internal(size(), a_count, a_ch);
		set_internal(this, arr);
		::delete[] arr;
		return *this;
	}


	BSFixedString& BSFixedString::append(const BSFixedString& a_str)
	{
		assert_length_error(a_str.size(), __FUNCTION__);
		char* arr = insert_internal(size(), a_str.c_str(), a_str.size());
		set_internal(this, arr);
		::delete[] arr;
		return *this;
	}


	BSFixedString& BSFixedString::append(const BSFixedString& a_str, size_type a_pos, size_type a_count)
	{
		return append(a_str.substr(a_pos, a_pos + a_count));
	}


	BSFixedString& BSFixedString::append(const char* a_s, size_type a_count)
	{
		assert_length_error(a_count, __FUNCTION__);
		char* arr = insert_internal(size(), a_s, a_count);
		set_internal(this, arr);
		::delete[] arr;
		return *this;
	}


	BSFixedString& BSFixedString::append(const char* a_s)
	{
		assert_length_error(std::strlen(a_s), __FUNCTION__);
		char* arr = insert_internal(size(), a_s, std::strlen(a_s));
		set_internal(this, arr);
		::delete[] arr;
		return *this;
	}


	BSFixedString& BSFixedString::append(std::initializer_list<char> a_ilist)
	{
		assert_length_error(a_ilist.size(), __FUNCTION__);
		char* arr = insert_internal(size(), 0, a_ilist.size());
		set_internal(this, arr);
		::delete[] arr;
		return *this;
	}


	BSFixedString& BSFixedString::operator+=(const BSFixedString& a_str)
	{
		return append(a_str);
	}


	BSFixedString& BSFixedString::operator+=(char a_ch)
	{
		return append(1, a_ch);
	}


	BSFixedString& BSFixedString::operator+=(const char* a_s)
	{
		return append(a_s);
	}


	BSFixedString& BSFixedString::operator+=(std::initializer_list<char> a_ilist)
	{
		return append(a_ilist);
	}


	int BSFixedString::compare(const BSFixedString& a_str) const noexcept
	{
		return _stricmp(data(), a_str.data());
	}


	int BSFixedString::compare(size_type a_pos1, size_type a_count1, const BSFixedString& a_str) const
	{
		return compare(a_pos1, a_count1, a_str.c_str());
	}


	int BSFixedString::compare(size_type a_pos1, size_type a_count1, const BSFixedString& a_str, size_type a_pos2, size_type a_count2) const
	{
		assert_out_of_range(a_pos1, __FUNCTION__);
		a_str.assert_out_of_range(a_pos2, __FUNCTION__);

		size_type max1 = (a_count1 > size() - a_pos1) ? size() : (a_pos1 + a_count1);
		size_type max2 = (a_count2 > a_str.size() - a_pos2) ? a_str.size() : (a_pos2 + a_count2);

		const_iterator lIt(data() + a_pos1);
		const_iterator lEnd(data() + max1);

		const_iterator rIt(data() + a_pos2);
		const_iterator rEnd(data() + max2);

		while (lIt != lEnd && rIt != rEnd) {
			if (std::tolower(*lIt) != std::tolower(*rIt)) {
				return std::tolower(*lIt) < std::tolower(*rIt) ? -1 : 1;
			}
			++lIt;
			++rIt;
		}

		if (lIt != lEnd) {
			return 1;
		} else if (rIt != rEnd) {
			return -1;
		} else {
			return 0;
		}
	}


	int BSFixedString::compare(const char* a_s) const
	{
		return _stricmp(data(), a_s);
	}


	int BSFixedString::compare(size_type a_pos1, size_type a_count1, const char* a_s) const
	{
		assert_out_of_range(a_pos1, __FUNCTION__);

		size_type max1 = (a_count1 > size() - a_pos1) ? size() : (a_pos1 + a_count1);

		const_iterator it(data() + a_pos1);
		const_iterator end(data() + max1);

		size_type i = 0;

		while (a_s[i] != '\0' && it != end) {
			if (std::tolower(*it) != std::tolower(a_s[i])) {
				return std::tolower(*it) < std::tolower(a_s[i]) ? -1 : 1;
			}
			++i;
			++it;
		}

		if (it != end) {
			return 1;
		} else if (a_s[i] != '\0') {
			return -1;
		} else {
			return 0;
		}
	}


	BSFixedString BSFixedString::substr(size_type a_pos, size_type a_count) const
	{
		assert_out_of_range(a_pos, __FUNCTION__);

		size_type max = (a_count == npos || a_count > size()) ? size() : (a_pos + a_count);

		const_iterator begin(data() + a_pos);
		const_iterator end(data() + max);

		return { begin, end };
	}


	bool BSFixedString::operator==(const BSString& a_rhs) const
	{
		return (*this == a_rhs.c_str());
	}


	bool BSFixedString::operator!=(const BSString& a_rhs) const
	{
		return !operator==(a_rhs);
	}


	BSFixedString* BSFixedString::ctor_internal(BSFixedString* a_this, const char* a_s)
	{
		typedef BSFixedString* _ctor_t(BSFixedString* a_this, const char* a_s);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSFixedString*>(a_this)->_ctor_GetPtr());
		static _ctor_t* _ctor = reinterpret_cast<_ctor_t*>(*ptr);
		return _ctor(a_this, a_s);
	}


	BSFixedString* BSFixedString::ctor_copy_internal(BSFixedString* a_this, const BSFixedString& a_other)
	{
		typedef BSFixedString* _ctor_copy_t(BSFixedString* a_this, const BSFixedString& a_other);
		static RelocAddr<_ctor_copy_t*> _ctor_copy(BS_FIXED_STRING_COPY_CTOR);
		return _ctor_copy(a_this, a_other);
	}


	void BSFixedString::dtor_internal(BSFixedString* a_this)
	{
		typedef void _dtor_t(BSFixedString* a_this);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSFixedString*>(a_this)->_Release_GetPtr());
		static _dtor_t* _dtor = reinterpret_cast<_dtor_t*>(*ptr);
		_dtor(a_this);
	}


	BSFixedString* BSFixedString::set_internal(BSFixedString* a_this, const char* a_rhs)
	{
		typedef BSFixedString* _set_t(BSFixedString* a_this, const char* a_rhs);
		static uintptr_t* ptr2 = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSFixedString*>(a_this)->_Set_GetPtr());
		static _set_t* _set = reinterpret_cast<_set_t*>(*ptr2);
		return _set(a_this, a_rhs);
	}


	BSFixedString* BSFixedString::set_copy_internal(BSFixedString* a_this, const BSFixedString& a_rhs)
	{
		typedef BSFixedString* _set_copy_t(BSFixedString* a_this, const BSFixedString& a_rhs);
		static RelocAddr<_set_copy_t*> _set_copy(BS_FIXED_STRING_SET_COPY);
		return _set_copy(a_this, a_rhs);
	}


	void BSFixedString::assert_out_of_range(size_type a_index, const char* a_func) const
	{
		if (a_index > size()) {
			std::string err = a_func;
			err += ": ";
			err += MAKE_STR(a_index);
			err += "(which is " + std::to_string(a_index) + ") > ";
			err += MAKE_STR(this->size());
			err += " (which is" + std::to_string(this->size()) + ")";
			throw std::out_of_range(err);
		}
	}


	void BSFixedString::assert_length_error(size_type a_count, const char* a_func) const
	{
		if (size() + a_count > max_size()) {
			std::string err = a_func;
			err += ": operation would result in ";
			err += MAKE_STR(size() > max_size());
			throw std::length_error(err);
		}
	}


	char* BSFixedString::insert_internal(size_type a_index, const char* a_s, size_type a_count)
	{
		size_type newSize = size() + a_count;
		char* arr = ::new char[newSize + 1];
		for (size_type i = 0; i < a_index; ++i) {
			arr[i] = operator[](i);
		}
		for (size_type i = a_index, j = 0; i < a_index + a_count; ++i, ++j) {
			arr[i] = a_s[j];
		}
		for (size_type i = a_index + a_count, j = a_index; i < newSize; ++i, ++j) {
			arr[i] = operator[](j);
		}
		arr[newSize] = '\0';

		return arr;
	}


	char* BSFixedString::insert_char_internal(size_type a_index, size_type a_count, char a_ch)
	{
		size_type newSize = size() + a_count;
		char* arr = ::new char[newSize + 1];
		for (size_type i = 0; i < a_index; ++i) {
			arr[i] = operator[](i);
		}
		for (size_type i = a_index; i < a_index + a_count; ++i) {
			arr[i] = a_ch;
		}
		for (size_type i = a_index + a_count, j = a_index; i < newSize; ++i, ++j) {
			arr[i] = operator[](j);
		}
		arr[newSize] = '\0';

		return arr;
	}
}
