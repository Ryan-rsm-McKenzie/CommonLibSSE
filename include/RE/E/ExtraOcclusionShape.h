#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/N/NiSmartPointer.h"

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
