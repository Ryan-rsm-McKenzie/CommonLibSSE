#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BGSTextureSet;
	class NiAVObject;
	class NiNode;
	class TESObjectCELL;


	struct DECAL_CREATION_DATA
	{
	public:
		// members
		NiPoint3			  origin;		  // 00
		NiPoint3			  direction;	  // 0C
		NiPoint3			  surfaceNormal;  // 18
		ObjectRefHandle		  objRef;		  // 24
		NiPointer<NiAVObject> avObj;		  // 28
		NiNode*				  clone;		  // 30
		BGSTextureSet*		  texSet;		  // 38
		BGSTextureSet*		  texSet2;		  // 40
		UInt64				  unk48;		  // 48
		UInt64				  unk50;		  // 50
		float				  unk58;		  // 58
		UInt32				  unk5C;		  // 5C
		UInt64				  unk60;		  // 60
		float				  unk68;		  // 68
		UInt32				  unk6C;		  // 6C
		UInt64				  unk70;		  // 70
		float				  unk78;		  // 78
		UInt32				  unk7C;		  // 7C
		TESObjectCELL*		  parentCell;	  // 80
		UInt64				  unk88;		  // 88
		UInt64				  unk90;		  // 90
		float				  unk98;		  // 98
		float				  unk9C;		  // 9C
		float				  unkA0;		  // A0
		float				  unkA4;		  // A4
		UInt32				  unkA8;		  // A8
		float				  unkAC;		  // AC
		UInt32				  unkB0;		  // B0
		UInt16				  unkB4;		  // B4
		UInt8				  unkB6;		  // B6
		UInt8				  unkB7;		  // B7
		UInt16				  unkB8;		  // B8
		UInt8				  unkBA;		  // BA
		UInt8				  unkBB;		  // BB
		UInt16				  unkBC;		  // BC
		UInt8				  unkBE;		  // BE
		UInt32				  unkC0;		  // C0
		UInt32				  padC4;		  // C4
	};
	STATIC_ASSERT(sizeof(DECAL_CREATION_DATA) == 0xC8);


	struct BGSDecalGroup
	{
	public:
		// members
		bool						   permanentGroup;	// 00
		bool						   manualSaveLoad;	// 01
		UInt16						   pad02;			// 02
		UInt32						   pad04;			// 04
		BSTArray<UInt32>			   decalGroups;		// 08
		BSTArray<DECAL_CREATION_DATA*> pendingDecals;	// 20
	};
	STATIC_ASSERT(sizeof(BGSDecalGroup) == 0x38);
}
