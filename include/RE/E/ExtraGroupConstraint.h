#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class ExtraGroupConstraint : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraGroupConstraint;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kGroupConstraint;


		virtual ~ExtraGroupConstraint();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kGroupConstraint; }


		// members
		std::int32_t	constraintType;			  // 10
		ObjectRefHandle entityB;				  // 14
		BSFixedString	attachNodeNameA;		  // 18
		BSFixedString	attachNodeNameB;		  // 20
		NiPoint3		constraintOffsetA;		  // 28
		NiPoint3		constraintOffsetB;		  // 34
		std::uint32_t	originalCollisionGroupB;  // 40
		float			dynamicMassScaleB;		  // 44
	};
	static_assert(sizeof(ExtraGroupConstraint) == 0x48);
}
