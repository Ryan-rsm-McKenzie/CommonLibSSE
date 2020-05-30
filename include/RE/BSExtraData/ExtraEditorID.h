#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraEditorID : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEditorID;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEditorID;


		virtual ~ExtraEditorID();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kEditorID; }


		// members
		BSFixedString editorID;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraEditorID) == 0x18);
}
