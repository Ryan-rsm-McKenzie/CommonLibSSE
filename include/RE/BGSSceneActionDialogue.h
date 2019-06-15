#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSSceneActionDialogue

#include "RE/BGSSceneAction.h"  // BGSSceneAction
#include "RE/FormTypes.h"  // TESTopic


namespace RE
{
	class BGSSceneActionDialogue : public BGSSceneAction
	{
	public:
		inline static const void* RTTI = RTTI_BGSSceneActionDialogue;


		enum { kTypeID = Type::kDialogue };


		virtual ~BGSSceneActionDialogue();													// 00

		// override (BGSSceneAction)
		virtual bool		LoadSceneAction(TESFile* a_mod) override;						// 01
		virtual void		Unk_02(void) override;											// 02
		virtual void		Unk_03(void) override;											// 03
		virtual bool		Loops() const override;											// 05 - { return (flags >> 16) & 1; }
		virtual bool		FacesTarget() const override;									// 06 - { return (flags >> 15) & 1; }
		virtual Type		GetType() const override;										// 07 - { return kDialogue; }
		virtual void		LoadBuffer(void* a_arg1, BGSLoadGameBuffer*  a_buf) override;	// 09
		virtual void		Unk_0A(void) override;											// 0A
		virtual void		Unk_0B(void) override;											// 0B
		virtual void		Unk_0C(void) override;											// 0C
		virtual EmotionType	GetEmotionType() const override;								// 0E - { return emotionType; }
		virtual UInt32		GetEmotionValue() const override;								// 0F - { return emotionValue; }
		virtual void		Unk_10(void) override;											// 10
		virtual void		Unk_11(void) override;											// 11
		virtual void		Unk_13(void) override;											// 13


		// members
		TESTopic*	topic;				// 20 - DATA
		SInt32		headtrackActorID;	// 28 - HTID
		float		loopingMax;			// 2C - DMAX
		float		loopingMin;			// 30 - DMIN
		UInt32		unk34;				// 34
		EmotionType	emotionType;		// 38 - DEMO
		UInt32		emotionValue;		// 3C - DEMA
	};
	STATIC_ASSERT(sizeof(BGSSceneActionDialogue) == 0x40);
}
