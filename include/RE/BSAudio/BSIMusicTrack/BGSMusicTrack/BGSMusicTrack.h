#pragma once

#include "RE/BSIMusicTrack.h"
#include "RE/TESCondition.h"


namespace RE
{
	class TESFile;
	class TESForm;


	class BGSMusicTrack : public BSIMusicTrack
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicTrack;


		virtual ~BGSMusicTrack();  // 00

		// override (BSIMusicTrack)
		virtual bool TestCanPlay() const override;	// 07 - { return conditions ? conditions->Run(g_thePlayer, g_thePlayer) : true; }

		// add
		virtual void InitItem(TESForm* a_form);	 // 0B
		virtual void Load(TESFile* a_mod) = 0;	 // 0C


		// members
		TESCondition conditions;  // 10
		UInt64		 unk18;		  // 18
	};
	STATIC_ASSERT(sizeof(BGSMusicTrack) == 0x20);
}
