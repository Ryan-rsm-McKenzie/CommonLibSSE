#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSNavmesh

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer
#include "RE/NiPoint3.h"  // NiPoint3


namespace RE
{
	class BSPathingCell;


	class BSNavmesh : public BSIntrusiveRefCounted
	{
	public:
		inline static const void* RTTI = RTTI_BSNavmesh;


		using Vertex = NiPoint3;
		STATIC_ASSERT(sizeof(Vertex) == 0xC);


		struct Triangle
		{
			// reference:
			// edge 0-1 = 0
			// edge 1-2 = 1
			// edge 2-0 = 2
			enum class Flag : UInt16
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
			enum class CoverFlag : UInt16
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


			UInt16		vertex[3];	// 00
			UInt16		edge[3];	// 06 - 0xFF == NONE
			Flag		flags;		// 0C
			CoverFlag	coverFlags;	// 0E
		};
		STATIC_ASSERT(sizeof(Triangle) == 0x10);


		struct EdgeLink
		{
			UInt32	unk0;		// 0
			FormID	mesh;		// 4
			UInt16	triangle;	// 8
			UInt16	padE;		// A
		};
		STATIC_ASSERT(sizeof(EdgeLink) == 0xC);


		virtual ~BSNavmesh();			// 00

		// add
		virtual void Unk_01(void) = 0;	// 01


		// members
		UInt32								unk00C;				// 00C
		BSTArray<Vertex>					vertices;			// 010
		BSTArray<Triangle>					triangles;			// 028
		BSTArray<EdgeLink>					edgeLinks;			// 040
		BSTArray<void*>						unk058;				// 058
		BSTArray<void*>						unk070;				// 070
		BSTArray<UInt16>					coverTriangles;		// 088
		UInt32								naxMeshGridDivisor;	// 0A0
		float								maxXDistance;		// 0A4
		float								maxYDistance;		// 0A8
		NiPoint3							min;				// 0AC
		NiPoint3							max;				// 0B8
		UInt32								unk0C4;				// 0C4
		BSTSimpleArray<BSTArray<UInt16>*>	navMeshGrid;		// 0C8
		BSTArray<void*>						unk0D0;				// 0D0
		UInt64								unk0E8;				// 0E8
		BSTArray<void*>						unk0F0;				// 0F0
		BSTSmartPointer<BSPathingCell>		unk108;				// 108
		UInt64								unk110;				// 110
	};
	STATIC_ASSERT(sizeof(BSNavmesh) == 0x118);
}
