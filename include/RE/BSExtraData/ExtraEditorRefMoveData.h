#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class ExtraEditorRefMoveData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEditorRefMoveData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEditorRefMoveData;


		virtual ~ExtraEditorRefMoveData();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kEditorRefMoveData; }


		// members
		NiPoint3 realAngle;		// 10
		NiPoint3 realLocation;	// 1C
		NiPoint3 oldLocation;	// 28
		UInt32	 pad34;			// 34
	};
	STATIC_ASSERT(sizeof(ExtraEditorRefMoveData) == 0x38);
}
