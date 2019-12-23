#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESFullName.h"
#include "RE/TESModel.h"
#include "RE/TESProduceForm.h"


namespace RE
{
	class TESObjectTREE :
		public TESBoundObject,	// 00
		public TESModel,		// 30
		public TESFullName,		// 58
		public TESProduceForm	// 68
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectTREE;


		enum { kTypeID = FormType::Tree };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15
			};
		};


		struct Data	// CNAM
		{
			float	trunkFlexibility;	// 00
			float	branchFlexibility;	// 04
			float	unk08;				// 08
			float	unk0C;				// 0C
			float	unk10;				// 10
			float	unk14;				// 14
			float	unk18;				// 18
			float	unk1C;				// 1C
			float	unk20;				// 20
			float	unk24;				// 24
			float	leafAmplitude;		// 28
			float	leafFrequency;		// 2C
		};
		STATIC_ASSERT(sizeof(Data) == 0x30);


		struct UnkB8
		{
			UInt64			unk00;	// 00
			BSTArray<void*>	unk08;	// 08
			BSTArray<void*>	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(UnkB8) == 0x38);


		virtual ~TESObjectTREE();																															// 00

		// override (TESBoundObject)
		virtual void	InitializeData() override;																											// 04
		virtual bool	Load(TESFile* a_mod) override;																										// 06
		virtual void	InitItemImpl() override;																											// 13
		virtual bool	Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void	Unk_44(void) override;																												// 44
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																	// 4C
		virtual void	Unk_4F(void) override;																												// 4F
		virtual void	Unk_50(void) override;																												// 50 - { return; }
		virtual void	Unk_51(void) override;																												// 51 - { return; }
		virtual void	Unk_52(void) override;																												// 52 - { return; }


		// members
		Data	data;	// 88
		UnkB8*	unkB8;	// B8
		UInt64	unkC0;	// C0
	};
	STATIC_ASSERT(sizeof(TESObjectTREE) == 0xC8);
}
