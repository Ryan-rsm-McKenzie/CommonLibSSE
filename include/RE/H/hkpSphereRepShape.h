#pragma once

#include "RE/H/hkpShape.h"

namespace RE
{
	class hkpSphere;

	class hkpSphereRepShape : public hkpShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpSphereRepShape;

		virtual ~hkpSphereRepShape();  // 00

		// add
		virtual std::int32_t     GetNumCollisionSpheresImpl() = 0;                       // 0B
		virtual const hkpSphere* GetCollisionSpheresImpl(hkSphere* a_sphereBuffer) = 0;  // 0C
	};
	static_assert(sizeof(hkpSphereRepShape) == 0x20);
}
