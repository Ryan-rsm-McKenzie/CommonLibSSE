#pragma once

#include <type_traits>

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTSmartPointer.h"
#include "RE/MemoryManager.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSNavmeshObstacleData;
	class BSNavmeshObstacleUndoData;
	class BSPathingCell;
	class BSPathingDoor;


	enum class EDGE_EXTRA_INFO_TYPE : UInt32
	{
		kInvalid = static_cast<std::underlying_type_t<EDGE_EXTRA_INFO_TYPE>>(-1),
		kPortal = 0,
		kLedgeUp = 1,
		kLedgeDown = 2,
		kEnableDisablePortal = 3
	};


	struct BSNavmeshVertex
	{
	public:
		// members
		NiPoint3 location;	// 0
	};
	STATIC_ASSERT(sizeof(BSNavmeshVertex) == 0xC);


	struct BSNavmeshTriangle
	{
	public:
		// reference:
		// edge 0-1 = 0
		// edge 1-2 = 1
		// edge 2-0 = 2
		enum class TriangleFlag : UInt16
		{
			kNone = 0,
			kEdge0_Link = 1 << 0,
			kEdge1_Link = 1 << 1,
			kEdge2_Link = 1 << 2,
			kDeleted = 1 << 3,
			kNoLargeCreatures = 1 << 4,
			kOverlapping = 1 << 5,
			kPreferred = 1 << 6,
		};


		// reference:
		// quarter = 1/4
		// half = 2/4
		// tri = 3/4
		// full = 4/4
		enum class TraversalFlag : UInt16
		{
			kNone = 0,
			kEdge0_CoverValueQuarter = 1 << 0,
			kEdge0_CoverValueHalf = 1 << 1,
			kEdge0_CoverValueTri = 1 << 2,
			kEdge0_CoverValueFull = 1 << 3,
			kEdge0_Left = 1 << 4,
			kEdge0_Right = 1 << 5,
			kEdge1_CoverValueQuarter = 1 << 6,
			kEdge1_CoverValueHalf = 1 << 7,
			kEdge1_CoverValueTri = 1 << 8,
			kEdge1_CoverValueFull = 1 << 9,
			kEdge1_Left = 1 << 10,
			kEdge1_Right = 1 << 11
		};


		// members
		UInt16		  vertices[3];	   // 00
		UInt16		  triangles[3];	   // 06 - 0xFF == NONE
		TriangleFlag  triangleFlags;   // 0C
		TraversalFlag traversalFlags;  // 0E
	};
	STATIC_ASSERT(sizeof(BSNavmeshTriangle) == 0x10);


	struct BSNavmeshTriangleEdgePortal
	{
	public:
		// members
		FormID otherMeshID;	 // 0
		UInt16 triangle;	 // 4
		SInt8  edgeIndex;	 // 6
		UInt8  pad7;		 // 7
	};
	STATIC_ASSERT(sizeof(BSNavmeshTriangleEdgePortal) == 0x8);


	struct BSNavmeshEdgeExtraInfo
	{
	public:
		// members
		EDGE_EXTRA_INFO_TYPE		type;	 // 0
		BSNavmeshTriangleEdgePortal portal;	 // 4
	};
	STATIC_ASSERT(sizeof(BSNavmeshEdgeExtraInfo) == 0xC);


	struct BSNavmeshTriangleDoorPortal
	{
	public:
		// members
		BSTSmartPointer<BSPathingDoor> door;				 // 00
		UInt16						   owningTriangleIndex;	 // 08
		UInt16						   pad0A;				 // 0A
		UInt32						   pad0C;				 // 0C
	};
	STATIC_ASSERT(sizeof(BSNavmeshTriangleDoorPortal) == 0x10);


	struct BSNavmeshClosedDoorInfo
	{
	public:
		// members
		BSTSmartPointer<BSPathingDoor> door;		   // 00
		UInt16						   triangleIndex;  // 08
		UInt16						   pad0A;		   // 0A
		UInt32						   pad0C;		   // 0C
	};
	STATIC_ASSERT(sizeof(BSNavmeshClosedDoorInfo) == 0x10);


	struct BSNavmeshCoverEdge
	{
	public:
		// members
		UInt16 vertices[2];	 // 00
		UInt32 data;		 // 08
	};
	STATIC_ASSERT(sizeof(BSNavmeshCoverEdge) == 0x8);


	struct BSNavmeshGrid
	{
	public:
		// members
		UInt32						  gridSize;			 // 00
		float						  columnSectionLen;	 // 04
		float						  rowSectionLen;	 // 08
		NiPoint3					  gridBoundsMin;	 // 0C
		NiPoint3					  gridBoundsMax;	 // 18
		UInt32						  pad24;			 // 14
		SimpleArray<BSTArray<UInt16>> gridData;			 // 28
	};
	STATIC_ASSERT(sizeof(BSNavmeshGrid) == 0x30);


	class BSNavmesh : public BSIntrusiveRefCounted	// NVNM
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSNavmesh;


		virtual ~BSNavmesh();  // 00

		// add
		virtual UInt32 QNavmeshID() = 0;  // 01


		// members
		UInt32												  pad00C;				  // 00C
		BSTArray<BSNavmeshVertex>							  vertices;				  // 010
		BSTArray<BSNavmeshTriangle>							  triangles;			  // 028
		BSTArray<BSNavmeshEdgeExtraInfo>					  extraEdgeInfo;		  // 040
		BSTArray<BSNavmeshTriangleDoorPortal>				  doorPortals;			  // 058
		BSTArray<BSNavmeshClosedDoorInfo>					  closedDoors;			  // 070
		BSTArray<BSNavmeshCoverEdge>						  coverArray;			  // 088
		BSNavmeshGrid										  meshGrid;				  // 0A0
		BSTArray<NiPointer<BSNavmeshObstacleUndoData>>		  obstacles;			  // 0D0
		BSTHashMap<UInt16, NiPointer<BSNavmeshObstacleData>>* triangleToObstacleMap;  // 0E8
		BSTArray<void*>										  unk0F0;				  // 0F0 - obstaclePOVs/disabledLinks?
		BSTSmartPointer<BSPathingCell>						  parentCell;			  // 108
		void*												  unk110;				  // 110 - navmeshInfo?
	};
	STATIC_ASSERT(sizeof(BSNavmesh) == 0x118);
}
