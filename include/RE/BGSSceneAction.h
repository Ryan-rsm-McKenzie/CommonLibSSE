#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSSceneAction


namespace RE
{
	class BGSLoadGameBuffer;
	class TESFile;


	class BGSSceneAction
	{
	public:
		inline static const void* RTTI = RTTI_BGSSceneAction;


		enum class Type : UInt32
		{
			kDialogue = 0,
			kPackage = 1,
			kTimer = 2
		};


		enum class EmotionType : UInt32
		{
			kNeutral = 0,
			kAnger = 1,
			kDisgust = 2,
			kFear = 3,
			kSad = 4,
			kHappy = 5,
			kSurprise = 6,
			kPuzzled = 7,
		};


		enum class Flag : UInt32
		{
			kNone = 0,
			kFaceTarget = 1 << 15,
			kLooping = 1 << 16,
			kHeadTrackPlayer = 1 << 17
		};


		virtual ~BGSSceneAction();													// 00

		// add
		virtual bool		LoadSceneAction(TESFile* a_mod);						// 01
		virtual void		Unk_02(void);											// 02
		virtual void		Unk_03(void);											// 03 - { return; }
		virtual void		ClearFlags();											// 04 - { flags = kNone; }
		virtual bool		Loops() const;											// 05 - { return false; }
		virtual bool		FacesTarget() const;									// 06 - { return true; }
		virtual Type		GetType() const = 0;									// 07
		virtual void		Unk_08(void);											// 08 - { return 0; }
		virtual void		LoadBuffer(void* a_arg1, BGSLoadGameBuffer*  a_buf);	// 09
		virtual void		Unk_0A(void);											// 0A
		virtual void		Unk_0B(void);											// 0B - { unk14 &= 0xFC; }
		virtual void		Unk_0C(void);											// 0C - { return; }
		virtual void		Unk_0D(void);											// 0D
		virtual EmotionType	GetEmotionType() const;									// 0E - { return kNeutral; }
		virtual UInt32		GetEmotionValue() const;								// 0F - { return 0; }
		virtual void		Unk_10(void);											// 10 - { unk14 |= 1; }
		virtual void		Unk_11(void);											// 11
		virtual void		Unk_12(void);											// 12 - { return; }
		virtual void		Unk_13(void);											// 13 - { return; }


		// members
		UInt32	actorID;	// 08 - ALID
		UInt16	startPhase;	// 0C - SNAM
		UInt16	endPhase;	// 0E - ENAM
		Flag	flags;		// 10
		UInt8	unk14;		// 14
		UInt8	unk15;		// 15
		UInt16	unk16;		// 16
		UInt32	index;		// 18 - INAM
		UInt32	unk1C;		// 1C
	};
	STATIC_ASSERT(sizeof(BGSSceneAction) == 0x20);
}
