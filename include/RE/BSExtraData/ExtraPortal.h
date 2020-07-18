#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BSPortal;


	class ExtraPortal : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPortal;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPortal;


		virtual ~ExtraPortal();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kPortal; }


		// members
		NiPointer<BSPortal> portal;	 // 10
	};
	static_assert(sizeof(ExtraPortal) == 0x18);
}
