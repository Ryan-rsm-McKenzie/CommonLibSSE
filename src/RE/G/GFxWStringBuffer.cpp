#include "RE/G/GFxWStringBuffer.h"

#include "RE/G/GMemory.h"

namespace RE
{
	GFxWStringBuffer::ReserveHeader::ReserveHeader() :
		buffer(nullptr),
		size(0)
	{}

	GFxWStringBuffer::ReserveHeader::ReserveHeader(const ReserveHeader& a_rhs) :
		buffer(a_rhs.buffer),
		size(a_rhs.size)
	{}

	GFxWStringBuffer::ReserveHeader::ReserveHeader(ReserveHeader&& a_rhs) :
		buffer(std::move(a_rhs.buffer)),
		size(std::move(a_rhs.size))
	{
		a_rhs.buffer = nullptr;
		a_rhs.size = 0;
	}

	GFxWStringBuffer::ReserveHeader::ReserveHeader(wchar_t* a_buffer, UPInt a_size) :
		buffer(a_buffer),
		size(a_size)
	{}

	auto GFxWStringBuffer::ReserveHeader::operator=(const ReserveHeader& a_rhs)
		-> ReserveHeader&
	{
		buffer = a_rhs.buffer;
		size = a_rhs.size;
		return *this;
	}

	auto GFxWStringBuffer::ReserveHeader::operator=(ReserveHeader&& a_rhs)
		-> ReserveHeader&
	{
		buffer = std::move(a_rhs.buffer);
		a_rhs.buffer = nullptr;

		size = std::move(a_rhs.size);
		a_rhs.size = 0;

		return *this;
	}

	GFxWStringBuffer::GFxWStringBuffer() :
		_text(nullptr),
		_length(0),
		_reserved(nullptr, 0)
	{}

	GFxWStringBuffer::GFxWStringBuffer(const GFxWStringBuffer& a_rhs) :
		_text(nullptr),
		_length(a_rhs._length),
		_reserved(a_rhs._reserved)
	{
		if (a_rhs._text) {
			_text = alloc(_length);
			std::wmemcpy(_text, a_rhs._text, _length);
		}
	}

	GFxWStringBuffer::GFxWStringBuffer(GFxWStringBuffer&& a_rhs) :
		_text(std::move(a_rhs._text)),
		_length(std::move(a_rhs._length)),
		_reserved(std::move(a_rhs._reserved))
	{
		a_rhs._text = nullptr;
		a_rhs._length = 0;
	}

	GFxWStringBuffer::GFxWStringBuffer(const ReserveHeader& a_reserve) :
		_text(a_reserve.buffer),
		_length(0),
		_reserved(a_reserve)
	{}

	GFxWStringBuffer::GFxWStringBuffer(ReserveHeader&& a_reserve) :
		_text(a_reserve.buffer),
		_length(0),
		_reserved(std::move(a_reserve))
	{}

	GFxWStringBuffer::~GFxWStringBuffer()
	{
		release();
	}

	GFxWStringBuffer& GFxWStringBuffer::operator=(const GFxWStringBuffer& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		release();
		_length = 0;
		_reserved = a_rhs._reserved;
		resize(a_rhs._length);

		if (a_rhs._text) {
			std::wmemcpy(_text, a_rhs._text, _length);
			_text[_length] = '\0';
		}

		return *this;
	}

	GFxWStringBuffer& GFxWStringBuffer::operator=(GFxWStringBuffer&& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		release();

		_text = std::move(a_rhs._text);
		a_rhs._text = nullptr;

		_length = std::move(a_rhs._length);
		a_rhs._length = 0;

		_reserved = std::move(a_rhs._reserved);

		return *this;
	}

	GFxWStringBuffer& GFxWStringBuffer::operator=(const wchar_t* a_rhs)
	{
		release();
		_length = 0;
		auto len = a_rhs ? std::wcslen(a_rhs) : 0;
		resize(len);

		if (a_rhs) {
			std::wmemcpy(_text, a_rhs, _length);
			_text[_length] = L'\0';
		}

		return *this;
	}

	GFxWStringBuffer& GFxWStringBuffer::operator=(const std::wstring_view& a_rhs)
	{
		release();
		_length = 0;
		resize(a_rhs.length());

		if (!a_rhs.empty()) {
			std::wmemcpy(_text, a_rhs.data(), _length);
			_text[_length] = L'\0';
		}

		return *this;
	}

	auto GFxWStringBuffer::operator[](size_type a_pos)
		-> reference
	{
		assert(a_pos < _length);
		return _text[a_pos];
	}

	auto GFxWStringBuffer::operator[](size_type a_pos) const
		-> const_reference
	{
		assert(a_pos < _length);
		return _text[a_pos];
	}

	wchar_t& GFxWStringBuffer::front()
	{
		return operator[](0);
	}

	const wchar_t& GFxWStringBuffer::front() const
	{
		return operator[](0);
	}

	wchar_t& GFxWStringBuffer::back()
	{
		return operator[](size());
	}

	const wchar_t& GFxWStringBuffer::back() const
	{
		return operator[](size());
	}

	const wchar_t* GFxWStringBuffer::data() const noexcept
	{
		return empty() ? L"" : _text;
	}

	wchar_t* GFxWStringBuffer::data() noexcept
	{
		return empty() ? const_cast<wchar_t*>(L"") : _text;
	}

	const wchar_t* GFxWStringBuffer::c_str() const noexcept
	{
		return data();
	}

	GFxWStringBuffer::operator std::wstring_view() const noexcept
	{
		return { data(), size() };
	}

	[[nodiscard]] bool GFxWStringBuffer::empty() const noexcept
	{
		return _length == 0;
	}

	auto GFxWStringBuffer::size() const noexcept
		-> size_type
	{
		return _length;
	}

	auto GFxWStringBuffer::length() const noexcept
		-> size_type
	{
		return size();
	}

	void GFxWStringBuffer::clear() noexcept
	{
		_length = 0;
		if (_text) {
			_text[0] = L'\0';
		}
	}

	void GFxWStringBuffer::resize(size_type a_count)
	{
		if (_length == a_count) {
			return;
		}
		++a_count;

		if (a_count <= _reserved.size) {
			if (_text != _reserved.buffer) {
				if (_text && _reserved.buffer) {
					auto toCopy = std::min(_length, a_count);
					std::wmemcpy(_reserved.buffer, _text, toCopy);
					GFREE(_text);
				}
				_text = _reserved.buffer;
			}
		} else {
			auto newText = alloc(a_count);
			if (_text) {
				auto toCopy = std::min(_length, a_count);
				std::wmemcpy(newText, _text, toCopy);
				release();
			}
			_text = newText;
		}
		_length = a_count - 1;
	}

	wchar_t* GFxWStringBuffer::alloc(size_type a_count)
	{
		return static_cast<wchar_t*>(GALLOC(a_count * sizeof(wchar_t)));
	}

	void GFxWStringBuffer::release()
	{
		if (_text != _reserved.buffer) {
			GFREE(_text);
			_text = _reserved.buffer;
		}
	}
}
