#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSListForm

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSListForm : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSListForm;


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
		BSTArray<TESForm*>		forms;			// 20 - LNAM
		BSTArray<RE::FormID>*	formIDs;		// 38 - holds references and generated form ids
		UInt32					numAddedForms;	// 40
		UInt32					pad44;			// 44
	};
	STATIC_ASSERT(sizeof(BGSListForm) == 0x48);
}
