#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMusicTrack

#include "RE/BSIMusicTrack.h"  // BSIMusicTrack
#include "RE/Condition.h"  // Condition


namespace RE
{
	class TESFile;


	class BGSMusicTrack : public BSIMusicTrack
	{
	public:
		inline static const void* RTTI = RTTI_BGSMusicTrack;


		virtual ~BGSMusicTrack();						// 00

		// override (BSIMusicTrack)
		virtual bool	CanPlay(void) override;			// 07 - { return conditions ? conditions->Run(g_thePlayer, g_thePlayer) : true; }

		// add
		virtual bool	InitTrack(TESFile* a_mod);		// 0B
		virtual bool	LoadTrack(TESFile* a_mod) = 0;	// 0C


		// members
		Condition	conditions;	// 10
		UInt64		unk18;		// 18
	};
	STATIC_ASSERT(sizeof(BGSMusicTrack) == 0x20);
}
