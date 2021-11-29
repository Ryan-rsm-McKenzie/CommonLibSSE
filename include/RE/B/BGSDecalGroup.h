#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPoint3.h"
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
		NiPoint3              origin;         // 00
		NiPoint3              direction;      // 0C
		NiPoint3              surfaceNormal;  // 18
		ObjectRefHandle       objRef;         // 24
		NiPointer<NiAVObject> avObj;          // 28
		NiNode*               clone;          // 30
		BGSTextureSet*        texSet;         // 38
		BGSTextureSet*        texSet2;        // 40
		std::uint64_t         unk48;          // 48
		std::uint64_t         unk50;          // 50
		float                 unk58;          // 58
		std::uint32_t         unk5C;          // 5C
		std::uint64_t         unk60;          // 60
		float                 unk68;          // 68
		std::uint32_t         unk6C;          // 6C
		std::uint64_t         unk70;          // 70
		float                 unk78;          // 78
		std::uint32_t         unk7C;          // 7C
		TESObjectCELL*        parentCell;     // 80
		std::uint64_t         unk88;          // 88
		std::uint64_t         unk90;          // 90
		float                 unk98;          // 98
		float                 unk9C;          // 9C
		float                 unkA0;          // A0
		float                 unkA4;          // A4
		std::uint32_t         unkA8;          // A8
		float                 unkAC;          // AC
		std::uint32_t         unkB0;          // B0
		std::uint16_t         unkB4;          // B4
		std::uint8_t          unkB6;          // B6
		std::uint8_t          unkB7;          // B7
		std::uint16_t         unkB8;          // B8
		std::uint8_t          unkBA;          // BA
		std::uint8_t          unkBB;          // BB
		std::uint16_t         unkBC;          // BC
		std::uint8_t          unkBE;          // BE
		std::uint32_t         unkC0;          // C0
		std::uint32_t         padC4;          // C4
	};
	static_assert(sizeof(DECAL_CREATION_DATA) == 0xC8);

	struct BGSDecalGroup
	{
	public:
		// members
		bool                           permanentGroup;  // 00
		bool                           manualSaveLoad;  // 01
		std::uint16_t                  pad02;           // 02
		std::uint32_t                  pad04;           // 04
		BSTArray<std::uint32_t>        decalGroups;     // 08
		BSTArray<DECAL_CREATION_DATA*> pendingDecals;   // 20
	};
	static_assert(sizeof(BGSDecalGroup) == 0x38);
}
