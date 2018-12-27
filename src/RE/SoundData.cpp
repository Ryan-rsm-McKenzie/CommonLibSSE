#include "RE/SoundData.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include <cstring>  // memset

#include "RE/Offsets.h"


namespace RE
{
	SoundData::SoundData()
	{
		memset(this, 0, sizeof(SoundData));
		unk00 = -1;
		unk04 = 0;
		unk08 = 0;
	}


	bool SoundData::SetPosition(NiPoint3 a_pos)
	{
		typedef bool _SetPosition_t(SoundData* a_this, NiPoint3 a_pos);
		RelocAddr<_SetPosition_t*> _SetPosition(BGS_SOUND_DESCRIPTOR_SOUND_DATA_SET_POSITION);
		return _SetPosition(this, a_pos);
	}


	void SoundData::SetNode(NiNode* a_node)
	{
		typedef void _SetNode_t(SoundData* a_this, NiNode* a_node);
		RelocAddr<_SetNode_t*> _SetNode(BGS_SOUND_DESCRIPTOR_SOUND_DATA_SET_NI_NODE);
		_SetNode(this, a_node);
	}


	bool SoundData::Play()
	{
		typedef bool _Play_t(SoundData* a_this);
		RelocAddr<_Play_t*> _Play(BGS_SOUND_DESCRIPTOR_SOUND_DATA_PLAY);
		return _Play(this);
	}
}
