#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiSmartPointer.h"

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
		NiPoint3			  origin;			// 00
		NiPoint3			  direction;		// 0C
		NiPoint3			  surfaceNormal;	// 18
		ObjectRefHandle		  objectRefHandle;	// 24
		NiPointer<NiAVObject> avObject;			// 28
		NiNode*				  clone;			// 30
		BGSTextureSet*		  textureSet;		// 38
		BGSTextureSet*		  textureSet2;		// 40
		std::int32_t		  unk48;			// 48
		float				  width;			// 4C
		float				  height;			// 50
		float				  depth;			// 54
		NiMatrix3			  rotation;			// 58
		TESObjectCELL*		  parentCell;		// 80
		std::uint32_t		  unk88;			// 88
		float				  parallaxScale;	// 88
		std::uint64_t		  unk90;			// 90
		float				  shininess;		// 98
		float				  angleThreshold;	// 9C
		float				  unkA0;			// A0
		float				  red;				// A4
		float				  green;			// A8
		float				  blue;				// AC
		std::uint32_t		  unkB0;			// B0
		std::int16_t		  noSubtextures;	// B4
		std::uint8_t		  unkB6;			// B6
		std::uint8_t		  parallax;			// B7
		std::uint8_t		  alphaTesting;		// B8
		std::uint8_t		  alphaBlending;	// B9
		std::uint8_t		  parallaxPasses;	// BA
		std::uint8_t		  unkBB;			// BB
		std::uint8_t		  unkBC;			// BC
		std::uint8_t		  unkBD;			// BD
		std::uint8_t		  unkBE;			// BE
		std::uint8_t		  unkBF;			// BF
		std::uint32_t		  unkC0;			// C0
		std::uint32_t		  padC4;			// C4
	};
	static_assert(sizeof(DECAL_CREATION_DATA) == 0xC8);

	struct BGSDecalGroup
	{
	public:
		// members
		bool						   permanentGroup;	// 00
		bool						   manualSaveLoad;	// 01
		std::uint16_t				   pad02;			// 02
		std::uint32_t				   pad04;			// 04
		BSTArray<std::uint32_t>		   decalGroups;		// 08
		BSTArray<DECAL_CREATION_DATA*> pendingDecals;	// 20
	};
	static_assert(sizeof(BGSDecalGroup) == 0x38);
}
