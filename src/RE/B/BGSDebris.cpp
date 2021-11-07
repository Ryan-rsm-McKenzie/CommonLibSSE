#include "RE/B/BGSDebris.h"

namespace RE
{
	BGSDebrisData::BGSDebrisData() :
		percentage(100),
		flags(BGSDebrisDataFlags::kNone),
		pad02(0),
		pad04(0),
		fileName(nullptr),
		textureIDs(),
		addons()
	{
	}

	BGSDebrisData::BGSDebrisData(const char* a_fileName) :
		percentage(100),
		flags(BGSDebrisDataFlags::kNone),
		pad02(0),
		pad04(0),
		fileName(a_fileName),
		textureIDs(),
		addons()
	{
	}
}
