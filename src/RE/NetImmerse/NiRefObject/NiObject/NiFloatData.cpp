#include "RE/NiFloatData.h"


namespace RE
{
	NiFloatData::NiFloatData() :
		numKeys(0),
		pad14(0),
		keys(nullptr),
		type(KeyType::kNoInterp),
		keySize(0),
		pad25(0),
		pad26(0)
	{}


	UInt32 NiFloatData::GetNumKeys() const
	{
		return numKeys;
	}


	NiFloatKey* NiFloatData::GetAnim(UInt32& a_numKeys, KeyType& a_type, UInt8& a_size) const
	{
		a_numKeys = numKeys;
		a_type = type;
		a_size = keySize;
		return keys;
	}
}
