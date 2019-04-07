#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class Script : public TESForm
	{
	public:
		enum { kTypeID = FormType::Script };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~Script();									// 00

		// override (TESForm)
		virtual void	InitDefaults();						// 04
		virtual void	ReleaseManagedData();				// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		void*	unk38;	// 38
		void*	unk40;	// 40
		UInt64	unk48;	// 48
		UInt32	unk50;	// 50
		UInt32	pad54;	// 54
		UInt64	unk58;	// 58
		UInt64	unk60;	// 60
		UInt64	unk68;	// 68
		UInt64	unk70;	// 70
		UInt64	unk78;	// 78
	};
	STATIC_ASSERT(sizeof(Script) == 0x80);
}
