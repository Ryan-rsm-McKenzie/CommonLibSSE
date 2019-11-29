#include "RE/NiBinaryStream.h"

#include <cassert>


namespace RE
{
	NiBinaryStream::NiBinaryStream() :
		_absoluteCurrentPos(0),
		_pad0C(0),
		_readFn(0),
		_writeFn(0)
	{}


	NiBinaryStream::~NiBinaryStream()
	{}


	UInt32 NiBinaryStream::tell() const
	{
		return _absoluteCurrentPos;
	}


	void NiBinaryStream::copy_from(void* a_rhs)
	{}


	UInt32 NiBinaryStream::binary_read(void* a_buffer, UInt32 a_totalBytes, UInt32* a_componentSizes, UInt32 a_numComponents)
	{
		assert(_readFn != 0);

		UInt32 bytesRead = _readFn(this, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
		_absoluteCurrentPos += bytesRead;
		return bytesRead;
	}


	UInt32 NiBinaryStream::binary_write(const void* a_buffer, UInt32 a_totalBytes, UInt32* a_componentSizes, UInt32 a_numComponents)
	{
		assert(_writeFn != 0);

		UInt32 bytesWritten = _writeFn(this, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
		_absoluteCurrentPos += bytesWritten;
		return bytesWritten;
	}
}
