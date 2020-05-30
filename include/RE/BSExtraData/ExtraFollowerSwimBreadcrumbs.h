#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiPoint3.h"


namespace RE
{
	enum class BREADCRUMB_STATE : UInt32
	{
		kInvalid = 0,
		kOnGround = 1,
		kInWater = 2
	};


	struct ExtraFollowerSwimBreadcrumb
	{
		NiPoint3 startLocation;	  // 00
		UInt32	 startNavMeshID;  // 0C
		NiPoint3 endLocation;	  // 10
		UInt32	 endNavMeshID;	  // 1C
		bool	 enteringWater;	  // 20
		UInt8	 pad21;			  // 21
		UInt16	 pad22;			  // 22
	};
	STATIC_ASSERT(sizeof(ExtraFollowerSwimBreadcrumb) == 0x24);


	class ExtraFollowerSwimBreadcrumbs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFollowerSwimBreadcrumbs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFollowerSwimBreadcrumbs;


		virtual ~ExtraFollowerSwimBreadcrumbs();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFollowerSwimBreadcrumbs; }


		// members
		BREADCRUMB_STATE						   leaderState;		 // 10
		NiPoint3								   leaderLocation;	 // 14
		UInt32									   leaderNavMeshID;	 // 20
		UInt32									   pad24;			 // 24
		BSSimpleList<ExtraFollowerSwimBreadcrumb*> crumbs;			 // 28
	};
	STATIC_ASSERT(sizeof(ExtraFollowerSwimBreadcrumbs) == 0x38);
}
