#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSSceneActionTimer

#include "RE/BGSSceneAction.h"  // BGSSceneAction


namespace RE
{
	class BGSSceneActionTimer : public BGSSceneAction
	{
	public:
		inline static const void* RTTI = RTTI_BGSSceneActionTimer;


		enum { kTypeID = Type::kTimer };


		virtual ~BGSSceneActionTimer();													// 00

		// override (BGSSceneAction)
		virtual bool	LoadSceneAction(TESFile* a_mod) override;						// 01
		virtual void	ClearFlags() override;											// 04 - { BGSSceneAction::ClearFlags(); }
		virtual Type	GetType() const override;										// 07 - { return kTimer; }
		virtual void	LoadBuffer(void* a_arg1, BGSLoadGameBuffer*  a_buf) override;	// 09
		virtual void	Unk_0A(void) override;											// 0A
		virtual void	Unk_0B(void) override;											// 0B
		virtual void	Unk_0D(void) override;											// 0D
		virtual void	Unk_11(void) override;											// 11
		virtual void	Unk_13(void) override;											// 13


		// members
		float	timerSeconds;	// 20 - SNAM
		UInt32	unk24;			// 24
		UInt64	unk28;			// 28
	};
	STATIC_ASSERT(sizeof(BGSSceneActionTimer) == 0x30);
}
