#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAnimNoteReceiver

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAnimNoteReceiver : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAnimNoteReceiver;


		enum { kExtraTypeID = ExtraDataType::kAnimNoteReceiver };


		virtual ~ExtraAnimNoteReceiver();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kAnimNoteReceiver; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraAnimNoteReceiver) == 0x18);
}
