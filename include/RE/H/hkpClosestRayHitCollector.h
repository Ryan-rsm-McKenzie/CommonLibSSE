#pragma once

#include "RE/H/hkpRayHitCollector.h"
#include "RE/H/hkpWorldRayCastOutput.h"

namespace RE
{
	class hkpClosestRayHitCollector : public hkpRayHitCollector
	{
	public:
		hkpClosestRayHitCollector() noexcept :
			hkpRayHitCollector(Offset::hkpClosestRayHitCollector::Vtbl.address()){};
		
		hkpWorldRayCastOutput* rayHit;		   // 10
		std::uint64_t		   pad18;		   // 18
		float				   pad20{ 1.0F };  // 20
		std::int32_t		   pad24{ 0 };	   // 24
		std::int32_t		   pad28{ -1 };	   // 28
		std::uint32_t		   pad2C;		   // 2C
		std::int32_t		   pad30{ -1 };	   // 30
		std::uint32_t		   pad34;		   // 34
		std::uint32_t		   pad38;		   // 38
		std::uint32_t		   pad3C;		   // 3C
		std::uint32_t		   pad40;		   // 40
		std::uint32_t		   pad44;		   // 44
		std::uint32_t		   pad48;		   // 48
		std::uint32_t		   pad4C;		   // 4C
		std::uint32_t		   pad50{ 0 };	   // 50
		std::uint32_t		   pad54;		   // 54
		std::uint64_t		   pad58;		   // 58
		std::uint64_t		   pad60{ 0 };	   // 60
		std::uint64_t		   pad68;		   // 68
	};
	static_assert(sizeof(hkpClosestRayHitCollector) == 0x70);
}
