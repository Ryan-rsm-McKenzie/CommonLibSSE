#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSTerrainNode;
	class BSMultiStreamInstanceTriShape;

	class BGSDistantTreeBlock
	{
	public:
		struct InstanceData
		{
		public:
			// members
			FormID        id;      // 00 - Only the lower 24 bits used
			std::uint16_t x;       // 04
			std::uint16_t y;       // 06
			std::uint16_t z;       // 08
			std::uint16_t rotZ;    // 0A
			std::uint16_t scale;   // 0C
			std::uint16_t alpha;   // 0E - This is Float2Word(fAlpha)
			bool          hidden;  // 10 - alpha <= 0.0f or set by object flags
			std::uint8_t  pad11;   // 11
			std::uint16_t pad12;   // 12
		};
		static_assert(sizeof(InstanceData) == 0x14);

		struct TreeGroup
		{
		public:
			// members
			NiPointer<BSMultiStreamInstanceTriShape> geometry;                // 00
			BSTArray<InstanceData>                   instances;               // 08
			std::uint32_t                            num;                     // 20
			bool                                     shaderPropertyUpToDate;  // 24
			std::int8_t                              treeType;                // 25
			std::uint16_t                            pad26;                   // 26
		};
		static_assert(sizeof(TreeGroup) == 0x28);

		// members
		BSTArray<TreeGroup*>                     treeGroups;   // 00
		BSTHashMap<std::uint32_t, InstanceData*> instanceMap;  // 18
		BSTHashMap<std::uint32_t, TreeGroup*>    nextGroup;    // 48
		BGSTerrainNode*                          node;         // 78
		bool                                     doneLoading;  // 80
		bool                                     attached;     // 81
		bool                                     allVisible;   // 82
		std::uint8_t                             pad83;        // 83
		std::uint32_t                            pad84;        // 84
	};
	static_assert(sizeof(BGSDistantTreeBlock) == 0x88);
}
