#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSListForm : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSListForm;
		inline static constexpr auto FORMTYPE = FormType::FormList;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kAddedForm = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSListForm();	 // 00

		// override (TESForm)
		virtual void ClearData() override;						   // 05
		virtual bool Load(TESFile* a_mod) override;				   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;	   // 12
		virtual void InitItemImpl() override;					   // 13

		void AddForm(TESForm* a_form);
		bool HasForm(const TESForm* a_form) const;
		bool HasForm(FormID a_formID) const;


		// members
		BSTArray<TESForm*> forms;				  // 20 - LNAM
		BSTArray<FormID>*  scriptAddedTempForms;  // 38
		UInt32			   scriptAddedFormCount;  // 40
		UInt32			   pad44;				  // 44
	};
	STATIC_ASSERT(sizeof(BGSListForm) == 0x48);
}
