#pragma once

#include "RE/H/hkpRayHitCollector.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	struct hkpWorldRayCastInput
	{
	public:
		// members
		hkVector4			from;								   // 00
		hkVector4			to;									   // 10
		bool				enableShapeCollectionFilter{ false };  // 20
		std::uint32_t		filterInfo{ 0 };					   // 24
		std::uint64_t		pad30;								   // 30
		std::uint64_t		pad38;								   // 38
		float				pad40{ 1.0f };						   // 40
		std::int32_t		pad44{ -1 };						   // 44
		std::int32_t		pad48{ -1 };						   // 48
		std::uint32_t		pad4C;								   // 4C
		std::int32_t		pad50{ -1 };						   // 50
		std::uint32_t		pad54;								   // 54
		std::uint32_t		pad58;								   // 58
		std::uint32_t		pad5C;								   // 5C
		std::uint32_t		pad60;								   // 60
		std::uint32_t		pad64;								   // 64
		std::uint32_t		pad68;								   // 68
		std::uint32_t		pad6C;								   // 6C
		std::uint32_t		pad70{ 0 };							   // 70
		std::uint32_t		pad74;								   // 74
		std::uint64_t		pad78;								   // 78
		std::uint64_t		pad80{ 0 };							   // 80
		std::uint64_t		pad88;								   // 88
		hkVector4			ray;								   // 90
		hkpRayHitCollector* rayHitCollectorA0{ nullptr };		   // A0
		hkpRayHitCollector* rayHitCollectorA8{ nullptr };		   // A8
		hkpRayHitCollector* rayHitCollectorB0{ nullptr };		   // B0
		hkpRayHitCollector* rayHitCollectorB8{ nullptr };		   // B8
		bool				padC0{ false };						   // C0
		std::uint8_t		padC1;								   // C1
		std::uint16_t		padC2;								   // C2
		std::uint32_t		padC4;								   // C4
		std::uint64_t		padC8;								   // C8
	};
	static_assert(sizeof(hkpWorldRayCastInput) == 0xD0);
}
