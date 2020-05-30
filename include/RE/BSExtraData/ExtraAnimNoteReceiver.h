#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraAnimNoteReceiver : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAnimNoteReceiver;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAnimNoteReceiver;


		virtual ~ExtraAnimNoteReceiver();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kAnimNoteReceiver; }


		// members
		void* unk10;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraAnimNoteReceiver) == 0x18);
}
