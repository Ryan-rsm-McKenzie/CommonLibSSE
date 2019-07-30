#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraEditorRefMoveData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraEditorRefMoveData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEditorRefMoveData;


		enum { kExtraTypeID = ExtraDataType::kEditorRefMoveData };


		virtual ~ExtraEditorRefMoveData();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kEditorRefMoveData; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
	};
	STATIC_ASSERT(sizeof(ExtraEditorRefMoveData) == 0x38);
}
