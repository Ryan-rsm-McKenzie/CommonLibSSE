#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/C/CollisionLayers.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	struct CollisionData
	{
		COL_LAYER layer;  // 0
	};
	static_assert(sizeof(CollisionData) == 0x4);

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
	static_assert(sizeof(ExtraCollisionData) == 0x18);
}
