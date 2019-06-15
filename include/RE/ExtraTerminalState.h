#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraTerminalState

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraTerminalState : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraTerminalState;


		enum { kExtraTypeID = ExtraDataType::kTerminalState };


		virtual ~ExtraTerminalState();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kTerminalState; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraTerminalState) == 0x18);
}
