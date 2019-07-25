#include "RE/BSGlobalStringTable.h"


namespace RE
{
	bool BSGlobalStringTable::Entry::IsWideChar() const
	{
		return (_flagsAndRefCount & kIsWideChar) != 0;
	}


	UInt16 BSGlobalStringTable::Entry::GetRefCount() const
	{
		return _flagsAndRefCount & kRefCountMask;
	}


	UInt32 BSGlobalStringTable::Entry::GetLength() const
	{
		return _lengthAndRef.length & kLengthMask;
	}


	char* BSGlobalStringTable::Entry::GetDataU8()
	{
		return std::addressof(_data->u8);
	}


	wchar_t* BSGlobalStringTable::Entry::GetDataU16()
	{
		return std::addressof(_data->u16);
	}
}
