#pragma once

#include "RE/BSExtraData.h"
#include "RE/CollisionLayers.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct CollisionData
	{
		COL_LAYER layer;  // 0
	};
	STATIC_ASSERT(sizeof(CollisionData) == 0x4);


	class ExtraCollisionData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCollisionData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCollisionData;


		virtual ~ExtraCollisionData();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCollisionData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		CollisionData* collisionData;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraCollisionData) == 0x18);
}
