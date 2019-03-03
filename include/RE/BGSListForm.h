#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType, BGSMessage
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSListForm : public TESForm
	{
	public:
		enum { kTypeID = FormType::FormList };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSListForm();											// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;					// 05
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
		virtual void	InitItem() override;							// 13


		// members
		BSTArray<BGSMessage*>	forms;	// 20 - LNAM
		UInt64					unk38;	// 38
		UInt64					unk40;	// 40
	};
	STATIC_ASSERT(sizeof(BGSListForm) == 0x48);
}
