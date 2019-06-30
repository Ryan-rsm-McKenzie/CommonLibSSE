#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Hazard

#include "RE/FormTypes.h"  // FormType
#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	class Hazard : public TESObjectREFR
	{
	public:
		inline static const void* RTTI = RTTI_Hazard;


		enum { kTypeID = FormType::PlacedHazard };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~Hazard();												// 00

		// override (TESObjectREFR)
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_11(void) override;							// 11
		virtual void	Unk_12(void) override;							// 12
		virtual void	InitItem() override;							// 13
		virtual void	SetActorCause(void* a_cause) override;			// 50
		virtual void	Unk_6B(void) override;							// 6B
		virtual void	Unk_90(void) override;							// 90 - { return 0; }

		// add
		virtual void	Unk_A2(void);									// A2
		virtual void	Unk_A3(void);									// A3 - { return; }
		virtual bool	IsNotGeneratedForm() const;						// A4 - { return TESDataHandler::GetSingleton()->IsGeneratedFormID(formID) == 0; }


		// members
		UInt64	unk98;	// 98
		UInt64	unkA0;	// A0
		UInt64	unkA8;	// A8
		UInt64	unkB0;	// B0
		UInt64	unkB8;	// B8
		UInt64	unkC0;	// C0
		UInt64	unkC8;	// C8
		UInt64	unkD0;	// D0
	};
	STATIC_ASSERT(sizeof(Hazard) == 0xD8);
}
