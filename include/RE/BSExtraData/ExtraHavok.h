#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class bhkWorld;
	class NiRefObject;


	class ExtraHavok : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHavok;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHavok;


		virtual ~ExtraHavok();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kHavok; }


		// members
		NiPointer<bhkWorld>	   world;  // 10
		NiPointer<NiRefObject> unk18;  // 18
	};
	STATIC_ASSERT(sizeof(ExtraHavok) == 0x20);
}
