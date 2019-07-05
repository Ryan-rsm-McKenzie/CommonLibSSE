#include "RE/SoundData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	SoundData::SoundData() :
		unk00(-1),
		unk04(0),
		pad05(0),
		pad06(0),
		unk08(0)
	{}


	bool SoundData::SetPosition(NiPoint3 a_pos)
	{
		using func_t = function_type_t<decltype(&SoundData::SetPosition)>;
		REL::Offset<func_t*> func(Offset::SoundData::SetPosition);
		return func(this, a_pos);
	}


	void SoundData::SetNode(NiNode* a_node)
	{
		using func_t = function_type_t<decltype(&SoundData::SetNode)>;
		REL::Offset<func_t*> func(Offset::SoundData::SetNode);
		return func(this, a_node);
	}


	bool SoundData::Play()
	{
		using func_t = function_type_t<decltype(&SoundData::Play)>;
		REL::Offset<func_t*> func(Offset::SoundData::Play);
		return func(this);
	}
}
