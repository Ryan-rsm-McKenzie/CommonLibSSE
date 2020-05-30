#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class NavMesh;


	struct NAVMESH_PORTAL
	{
		union Nav
		{
			FormID	 navMeshID;
			NavMesh* navMesh;
		};
		STATIC_ASSERT(sizeof(Nav) == 0x8);


		Nav	   nav;		  // 00
		UInt16 triIndex;  // 08
		UInt16 pad0A;	  // 0A
		UInt32 pad0C;	  // 0C
	};
	STATIC_ASSERT(sizeof(NAVMESH_PORTAL) == 0x10);


	class ExtraNavMeshPortal : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraNavMeshPortal;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kNavMeshPortal;


		virtual ~ExtraNavMeshPortal();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kNavMeshPortal; }


		// members
		NAVMESH_PORTAL portal;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraNavMeshPortal) == 0x20);
}
