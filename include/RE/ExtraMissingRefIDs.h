#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct ActivateParentID
	{
		UInt32 refID;		   // 0
		float  activateDelay;  // 4
	};
	STATIC_ASSERT(sizeof(ActivateParentID) == 0x8);


	class ExtraMissingRefIDs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMissingRefIDs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMissingRefIDs;


		virtual ~ExtraMissingRefIDs();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kMissingRefIDs; }


		// members
		ActivateParentID* unk10;  // 10
		UInt32			  unk18;  // 18
		UInt32			  unk1C;  // 1C
		UInt64			  unk20;  // 20
	};
	STATIC_ASSERT(sizeof(ExtraMissingRefIDs) == 0x28);
}
