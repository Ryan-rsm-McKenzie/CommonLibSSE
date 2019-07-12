#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraEditorID

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraEditorID : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEditorID;


		enum { kExtraTypeID = ExtraDataType::kEditorID };


		virtual ~ExtraEditorID();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kEditorID; }


		// members
		BSFixedString editorID;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraEditorID) == 0x18);
}
