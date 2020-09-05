#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BSOcclusionShape;


	class ExtraOcclusionShape : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOcclusionShape;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOcclusionShape;


		virtual ~ExtraOcclusionShape();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kOcclusionShape; }


		// members
		NiPointer<BSOcclusionShape> shape;	// 10
	};
	static_assert(sizeof(ExtraOcclusionShape) == 0x18);
}
