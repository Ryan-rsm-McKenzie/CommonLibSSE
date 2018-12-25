#include "RE/SoundData.h"

#include <cstring>  // memset


namespace RE
{
	SoundData::SoundData()
	{
		memset(this, 0, sizeof(SoundData));
		unk00 = -1;
		unk04 = 0;
		unk08 = 0;
	}
}
