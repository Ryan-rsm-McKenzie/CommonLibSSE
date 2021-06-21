#pragma once

#include "RE/H/hkpSphereRepShape.h"

namespace RE
{
	class hkpConvexShape : public hkpSphereRepShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpConvexShape;

		virtual ~hkpConvexShape();  // 00

		// override (hkpSphereRepShape)
		virtual float GetMaximumProjection(const hkVector4& a_direction) const override;                                                                         // 03
		virtual bool  IsConvex() const override;                                                                                                                 // 05 - { return true; }
		virtual void  CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const override;  // 09

		// add
		virtual void          GetCentreImpl(hkVector4& a_centreOut) = 0;  // 0D
		virtual void          Unk_0E(void) = 0;                           // 0E
		virtual void          Unk_0F(void) = 0;                           // 0F
		virtual std::uint32_t Unk_10(void);                               // 10 - { return 2; }
		virtual void          Unk_11(void);                               // 11

		// members
		float         radius;  // 20
		std::uint32_t pad1C;   // 24
	};
	static_assert(sizeof(hkpConvexShape) == 0x28);
}
