#include "RE/BSGlobalStringTable.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


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


	BSGlobalStringTable* BSGlobalStringTable::GetSingleton()
	{
		using func_t = function_type_t<decltype(&BSGlobalStringTable::GetSingleton)>;
		REL::Offset<func_t*> func(Offset::BSGlobalStringTable::GetSingleton);
		return func();
	}
}
