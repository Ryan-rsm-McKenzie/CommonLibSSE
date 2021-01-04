#include "RE/E/ExtraCanTalkToPlayer.h"

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
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraCanTalkToPlayer::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraCanTalkToPlayer::GetType() const
	{
		return ExtraDataType::kCanTalkToPlayer;
	}
}
