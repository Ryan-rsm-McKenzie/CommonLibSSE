#include "RE/N/NiBinaryStream.h"

namespace RE
{
	NiBinaryStream::NiBinaryStream() :
		_absoluteCurrentPos(0),
		_pad0C(0),
		_readFn(nullptr),
		_writeFn(nullptr)
	{}

	NiBinaryStream::~NiBinaryStream()
	{}

	std::uint32_t NiBinaryStream::tell() const
	{
		return _absoluteCurrentPos;
	}

	void NiBinaryStream::get_info([[maybe_unused]] BufferInfo& a_buf)
	{}

	std::uint32_t NiBinaryStream::binary_read(void* a_buffer, std::uint32_t a_totalBytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents)
	{
		assert(_readFn != nullptr);

		std::uint32_t bytesRead = _readFn(this, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
		_absoluteCurrentPos += bytesRead;
		return bytesRead;
	}

	std::uint32_t NiBinaryStream::binary_write(const void* a_buffer, std::uint32_t a_totalBytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents)
	{
		assert(_writeFn != nullptr);

		std::uint32_t bytesWritten = _writeFn(this, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
		_absoluteCurrentPos += bytesWritten;
		return bytesWritten;
	}
}
