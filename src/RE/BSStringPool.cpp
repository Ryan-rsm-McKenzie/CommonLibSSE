#include "RE/BSStringPool.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	bool BSStringPool::Entry::IsWideChar() const
	{
		return (_flagsAndRefCount & kIsWideChar) != 0;
	}


	UInt16 BSStringPool::Entry::GetRefCount() const
	{
		return _flagsAndRefCount & kRefCountMask;
	}


	UInt32 BSStringPool::Entry::GetLength() const
	{
		return _lengthAndRef.length & kLengthMask;
	}


	char* BSStringPool::Entry::GetDataU8()
	{
		return std::addressof(_data->u8);
	}


	wchar_t* BSStringPool::Entry::GetDataU16()
	{
		return std::addressof(_data->u16);
	}


	BucketTable* BucketTable::GetSingleton()
	{
		using func_t = decltype(&BucketTable::GetSingleton);
		REL::Offset<func_t> func(Offset::BucketTable::GetSingleton);
		return func();
	}
}
