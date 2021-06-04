#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/M/MemoryManager.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSNavmeshObstacleData;
	class BSNavmeshObstacleUndoData;
	class BSPathingCell;
	class BSPathingDoor;

	enum class EDGE_EXTRA_INFO_TYPE
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
		NiPoint3 location;  // 0
	};
	static_assert(sizeof(BSNavmeshVertex) == 0xC);

	struct BSNavmeshTriangle
	{
	public:
		// reference:
		// edge 0-1 = 0
		// edge 1-2 = 1
		// edge 2-0 = 2
		enum class TriangleFlag
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
		enum class TraversalFlag
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
		std::uint16_t                                  vertices[3];     // 00
		std::uint16_t                                  triangles[3];    // 06 - 0xFF == NONE
		stl::enumeration<TriangleFlag, std::uint16_t>  triangleFlags;   // 0C
		stl::enumeration<TraversalFlag, std::uint16_t> traversalFlags;  // 0E
	};
	static_assert(sizeof(BSNavmeshTriangle) == 0x10);

	struct BSNavmeshTriangleEdgePortal
	{
	public:
		// members
		FormID        otherMeshID;  // 0
		std::uint16_t triangle;     // 4
		std::int8_t   edgeIndex;    // 6
		std::uint8_t  pad7;         // 7
	};
	static_assert(sizeof(BSNavmeshTriangleEdgePortal) == 0x8);

	struct BSNavmeshEdgeExtraInfo
	{
	public:
		// members
		stl::enumeration<EDGE_EXTRA_INFO_TYPE, std::uint32_t> type;    // 0
		BSNavmeshTriangleEdgePortal                           portal;  // 4
	};
	static_assert(sizeof(BSNavmeshEdgeExtraInfo) == 0xC);

	struct BSNavmeshTriangleDoorPortal
	{
	public:
		// members
		BSTSmartPointer<BSPathingDoor> door;                 // 00
		std::uint16_t                  owningTriangleIndex;  // 08
		std::uint16_t                  pad0A;                // 0A
		std::uint32_t                  pad0C;                // 0C
	};
	static_assert(sizeof(BSNavmeshTriangleDoorPortal) == 0x10);

	struct BSNavmeshClosedDoorInfo
	{
	public:
		// members
		BSTSmartPointer<BSPathingDoor> door;           // 00
		std::uint16_t                  triangleIndex;  // 08
		std::uint16_t                  pad0A;          // 0A
		std::uint32_t                  pad0C;          // 0C
	};
	static_assert(sizeof(BSNavmeshClosedDoorInfo) == 0x10);

	struct BSNavmeshCoverEdge
	{
	public:
		// members
		std::uint16_t vertices[2];  // 00
		std::uint32_t data;         // 08
	};
	static_assert(sizeof(BSNavmeshCoverEdge) == 0x8);

	struct BSNavmeshGrid
	{
	public:
		// members
		std::uint32_t                        gridSize;          // 00
		float                                columnSectionLen;  // 04
		float                                rowSectionLen;     // 08
		NiPoint3                             gridBoundsMin;     // 0C
		NiPoint3                             gridBoundsMax;     // 18
		std::uint32_t                        pad24;             // 14
		SimpleArray<BSTArray<std::uint16_t>> gridData;          // 28
	};
	static_assert(sizeof(BSNavmeshGrid) == 0x30);

	class BSNavmesh : public BSIntrusiveRefCounted  // NVNM
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSNavmesh;

		virtual ~BSNavmesh();  // 00

		// add
		virtual std::uint32_t QNavmeshID() = 0;  // 01

		// members
		std::uint32_t                                                pad00C;                 // 00C
		BSTArray<BSNavmeshVertex>                                    vertices;               // 010
		BSTArray<BSNavmeshTriangle>                                  triangles;              // 028
		BSTArray<BSNavmeshEdgeExtraInfo>                             extraEdgeInfo;          // 040
		BSTArray<BSNavmeshTriangleDoorPortal>                        doorPortals;            // 058
		BSTArray<BSNavmeshClosedDoorInfo>                            closedDoors;            // 070
		BSTArray<BSNavmeshCoverEdge>                                 coverArray;             // 088
		BSNavmeshGrid                                                meshGrid;               // 0A0
		BSTArray<NiPointer<BSNavmeshObstacleUndoData>>               obstacles;              // 0D0
		BSTHashMap<std::uint16_t, NiPointer<BSNavmeshObstacleData>>* triangleToObstacleMap;  // 0E8
		BSTArray<void*>                                              unk0F0;                 // 0F0 - obstaclePOVs/disabledLinks?
		BSTSmartPointer<BSPathingCell>                               parentCell;             // 108
		void*                                                        unk110;                 // 110 - navmeshInfo?
	};
	static_assert(sizeof(BSNavmesh) == 0x118);
}
