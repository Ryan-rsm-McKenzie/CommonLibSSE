#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSString.h"
#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESForm.h"


namespace RE
{
	class NiFormArray;


	struct IDLE_DATA  // DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kParent = 1 << 0,
			kSequence = 1 << 1,
			kNoAttacking = 1 << 2,
			kBlocking = 1 << 3
		};


		SInt8  loopMin;					 // 0
		SInt8  loopMax;					 // 1
		Flag   flags;					 // 2
		UInt8  animationGroupSelection;	 // 3
		UInt16 replayDelay;				 // 4
	};
	STATIC_ASSERT(sizeof(IDLE_DATA) == 0x6);


	class TESIdleForm : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESIdleForm;
		inline static constexpr auto FORMTYPE = FormType::Idle;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESIdleForm();	 // 00

		// override (TESForm)
		virtual void		InitializeData() override;											// 04
		virtual void		ClearData() override;												// 05
		virtual bool		Load(TESFile* a_mod) override;										// 06
		virtual TESForm*	CreateDuplicateForm(bool a_createEditorID, void* a_arg2) override;	// 09
		virtual void		InitItemImpl() override;											// 13
		virtual const char* GetFormEditorID() const override;									// 32 - { return formEditorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;						// 33


		// members
		TESCondition  conditions;	  // 20
		IDLE_DATA	  data;			  // 28 - DATA
		UInt16		  pad2E;		  // 2E
		NiFormArray*  childIdles;	  // 30
		TESIdleForm*  parentIdle;	  // 38 - ANAM~
		TESIdleForm*  prevIdle;		  // 40 - ~ANAM
		BSFixedString animFileName;	  // 48 - DNAM
		BSFixedString animEventName;  // 50 - ENAM
		BSString	  formEditorID;	  // 58 - EDID
	};
	STATIC_ASSERT(sizeof(TESIdleForm) == 0x68);
}
