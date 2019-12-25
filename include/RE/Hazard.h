#pragma once

#include "RE/FormTypes.h"
#include "RE/TESObjectREFR.h"


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


		virtual ~Hazard();																		// 00

		// override (TESObjectREFR)
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;							// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;							// 0F
		virtual void	FinishLoadGame(void* a_arg1) override;									// 11
		virtual void	Revert(void* a_arg1) override;											// 12
		virtual void	InitItemImpl() override;												// 13
		virtual void	SetActorCause(ActorCause* a_cause) override;							// 50
		virtual void	Release3DRelatedData() override;										// 6B
		virtual bool	OnAddCellPerformQueueReference(TESObjectCELL* a_cell) const override;	// 90 - { return false; }

		// add
		virtual void	Unk_A2(void);															// A2
		virtual void	Unk_A3(void);															// A3 - { return; }
		virtual bool	IsNotGeneratedForm() const;												// A4 - { return TESDataHandler::GetSingleton()->IsGeneratedFormID(formID) == 0; }


		// members
		UInt64		unk98;	// 98
		RefHandle	unkA0;	// A0
		UInt32		unkA4;	// A4
		UInt64		unkA8;	// A8
		UInt64		unkB0;	// B0
		UInt64		unkB8;	// B8
		void*		unkC0;	// C0 - smart ptr
		UInt64		unkC8;	// C8
		UInt64		unkD0;	// D0
	};
	STATIC_ASSERT(sizeof(Hazard) == 0xD8);
}
