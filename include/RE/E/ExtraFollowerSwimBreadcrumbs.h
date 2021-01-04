#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTList.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	enum class BREADCRUMB_STATE
	{
		kInvalid = 0,
		kOnGround = 1,
		kInWater = 2
	};

	struct ExtraFollowerSwimBreadcrumb
	{
		NiPoint3	  startLocation;   // 00
		std::uint32_t startNavMeshID;  // 0C
		NiPoint3	  endLocation;	   // 10
		std::uint32_t endNavMeshID;	   // 1C
		bool		  enteringWater;   // 20
		std::uint8_t  pad21;		   // 21
		std::uint16_t pad22;		   // 22
	};
	static_assert(sizeof(ExtraFollowerSwimBreadcrumb) == 0x24);

	class ExtraFollowerSwimBreadcrumbs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFollowerSwimBreadcrumbs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFollowerSwimBreadcrumbs;

		virtual ~ExtraFollowerSwimBreadcrumbs();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFollowerSwimBreadcrumbs; }

		// members
		stl::enumeration<BREADCRUMB_STATE, std::uint32_t> leaderState;		// 10
		NiPoint3										  leaderLocation;	// 14
		std::uint32_t									  leaderNavMeshID;	// 20
		std::uint32_t									  pad24;			// 24
		BSSimpleList<ExtraFollowerSwimBreadcrumb*>		  crumbs;			// 28
	};
	static_assert(sizeof(ExtraFollowerSwimBreadcrumbs) == 0x38);
}
