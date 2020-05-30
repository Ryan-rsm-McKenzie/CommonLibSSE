#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraTerminalState : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraTerminalState;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kTerminalState;


		virtual ~ExtraTerminalState();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kTerminalState; }


		// members
		UInt64 unk10;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraTerminalState) == 0x18);
}
