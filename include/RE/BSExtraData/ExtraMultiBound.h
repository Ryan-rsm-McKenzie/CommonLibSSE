#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


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
	STATIC_ASSERT(sizeof(ExtraMultiBound) == 0x18);
}
