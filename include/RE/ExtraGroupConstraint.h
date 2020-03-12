#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiPoint3.h"


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
		SInt32			constraintType;			  // 10
		ObjectRefHandle entityB;				  // 14
		BSFixedString	attachNodeNameA;		  // 18
		BSFixedString	attachNodeNameB;		  // 20
		NiPoint3		constraintOffsetA;		  // 28
		NiPoint3		constraintOffsetB;		  // 34
		UInt32			originalCollisionGroupB;  // 40
		float			dynamicMassScaleB;		  // 44
	};
	STATIC_ASSERT(sizeof(ExtraGroupConstraint) == 0x48);
}
