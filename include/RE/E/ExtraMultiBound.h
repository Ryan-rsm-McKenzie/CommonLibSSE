#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSMultiBound;

	class ExtraMultiBound : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMultiBound;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMultiBound;

		virtual ~ExtraMultiBound();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kMultiBound; }

		// members
		NiPointer<BSMultiBound> bound;	// 10
	};
	static_assert(sizeof(ExtraMultiBound) == 0x18);
}
