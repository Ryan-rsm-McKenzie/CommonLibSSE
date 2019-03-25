#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraTerminalState : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kTerminalState };


		virtual ~ExtraTerminalState();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kTerminalState; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraTerminalState) == 0x18);
}
