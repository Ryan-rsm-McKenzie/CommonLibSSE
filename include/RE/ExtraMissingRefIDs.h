#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraMissingRefIDs : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraMissingRefIDs;


		enum { kExtraTypeID = ExtraDataType::kMissingRefIDs };


		struct Data
		{
			UInt64 unk0;	// 0
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		virtual ~ExtraMissingRefIDs();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kMissingRefIDs; }


		// members
		Data*	unk10;	// 10
		UInt32	unk18;	// 18
		UInt32	unk1C;	// 1C
		UInt64	unk20;	// 20
	};
	STATIC_ASSERT(sizeof(ExtraMissingRefIDs) == 0x28);
}
