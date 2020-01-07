#include "RE/ExtraCanTalkToPlayer.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraCanTalkToPlayer::ExtraCanTalkToPlayer() :
		ExtraCanTalkToPlayer(false)
	{}


	ExtraCanTalkToPlayer::ExtraCanTalkToPlayer(bool a_canTalk) :
		BSExtraData(),
		talk(a_canTalk),
		pad11(0),
		pad12(0),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraCanTalkToPlayer::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraCanTalkToPlayer::GetType() const
	{
		return ExtraDataType::kCanTalkToPlayer;
	}
}
