#include "RE/SoundData.h"

#include <cstring>  // memset

#include "RE/Offsets.h"


namespace RE
{
	SoundData::SoundData()
	{
		std::memset(this, 0, sizeof(SoundData));
		unk00 = -1;
		unk04 = 0;
		unk08 = 0;
	}


	bool SoundData::SetPosition(NiPoint3 a_pos)
	{
		using func_t = function_type_t<decltype(&SoundData::SetPosition)>;
		RelocUnrestricted<func_t*> func(Offset::SoundData::SetPosition);
		return func(this, a_pos);
	}


	void SoundData::SetNode(NiNode* a_node)
	{
		using func_t = function_type_t<decltype(&SoundData::SetNode)>;
		RelocUnrestricted<func_t*> func(Offset::SoundData::SetNode);
		return func(this, a_node);
	}


	bool SoundData::Play()
	{
		using func_t = function_type_t<decltype(&SoundData::Play)>;
		RelocUnrestricted<func_t*> func(Offset::SoundData::Play);
		return func(this);
	}
}
