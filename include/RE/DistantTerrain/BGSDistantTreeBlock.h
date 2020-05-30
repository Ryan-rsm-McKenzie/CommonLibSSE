#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/NiSmartPointer.h"


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
			FormID id;		// 00 - Only the lower 24 bits used
			UInt16 x;		// 04
			UInt16 y;		// 06
			UInt16 z;		// 08
			UInt16 rotZ;	// 0A
			UInt16 scale;	// 0C
			UInt16 alpha;	// 0E - This is Float2Word(fAlpha)
			bool   hidden;	// 10 - alpha <= 0.0f or set by object flags
			UInt8  pad11;	// 11
			UInt16 pad12;	// 12
		};
		STATIC_ASSERT(sizeof(InstanceData) == 0x14);


		struct TreeGroup
		{
		public:
			// members
			NiPointer<BSMultiStreamInstanceTriShape> geometry;				  // 00
			BSTArray<InstanceData>					 instances;				  // 08
			UInt32									 num;					  // 20
			bool									 shaderPropertyUpToDate;  // 24
			SInt8									 treeType;				  // 25
			UInt16									 pad26;					  // 26
		};
		STATIC_ASSERT(sizeof(TreeGroup) == 0x28);


		// members
		BSTArray<TreeGroup*>			  treeGroups;	// 00
		BSTHashMap<UInt32, InstanceData*> instanceMap;	// 18
		BSTHashMap<UInt32, TreeGroup*>	  nextGroup;	// 48
		BGSTerrainNode*					  node;			// 78
		bool							  doneLoading;	// 80
		bool							  attached;		// 81
		bool							  allVisible;	// 82
		UInt8							  pad83;		// 83
		UInt32							  pad84;		// 84
	};
	STATIC_ASSERT(sizeof(BGSDistantTreeBlock) == 0x88);
}
