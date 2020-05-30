#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/Movement.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSMovementType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMovementType;
		inline static constexpr auto FORMTYPE = FormType::MovementType;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMovementType();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		Movement::TypeData movementTypeData;  // 20
	};
	STATIC_ASSERT(sizeof(BGSMovementType) == 0x60);
}
