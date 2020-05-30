#pragma once

#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESContainer.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSConstructibleObject : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSConstructibleObject;
		inline static constexpr auto FORMTYPE = FormType::ConstructibleObject;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct ConstructibleObjectData
		{
			UInt16 numConstructed;	// 0 - NAM1
		};
		STATIC_ASSERT(sizeof(ConstructibleObjectData) == 0x2);


		virtual ~BGSConstructibleObject();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		TESContainer			requiredItems;	// 20
		TESCondition			conditions;		// 38
		TESForm*				createdItem;	// 40 - CNAM
		BGSKeyword*				benchKeyword;	// 48 - BNAM
		ConstructibleObjectData data;			// 50
		UInt16					pad52;			// 52
		UInt32					unk54;			// 54
	};
	STATIC_ASSERT(sizeof(BGSConstructibleObject) == 0x58);
}
