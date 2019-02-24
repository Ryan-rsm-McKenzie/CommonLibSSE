#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESObjectLAND : public TESForm
	{
	public:
		enum { kTypeID = FormType::Land };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~TESObjectLAND();													// 00

		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;						// 06 - { return true; }
		virtual TESForm*	DupulicateForm(void* a_arg1, void* a_arg2) override;	// 09
		virtual void		SetFlag00000002(bool a_set) override;					// 24
		virtual void		Unk_30(void) override;									// 30
		virtual void		Unk_31(void) override;									// 31


		// members
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
	};
	STATIC_ASSERT(sizeof(TESObjectLAND) == 0x48);
}
