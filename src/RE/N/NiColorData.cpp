#include "RE/N/NiColorData.h"

namespace RE
{
	NiColorData::NiColorData() :
		numKeys(0),
		pad14(0),
		keys(nullptr),
		type(KeyType::kNoInterp),
		keySize(0),
		pad25(0),
		pad26(0)
	{}

	std::uint32_t NiColorData::GetNumKeys() const
	{
		return numKeys;
	}

	NiColorKey* NiColorData::GetAnim(std::uint32_t& a_numKeys, KeyType& a_type, std::uint8_t& a_size) const
	{
		a_numKeys = numKeys;
		a_type = type;
		a_size = keySize;
		return keys;
	}
}
