#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSHeadPart;
	class BSFaceGenModel;
	class BSFaceGenNiNode;
	class TESNPC;

	struct BSFaceGenModelMap
	{
	public:
		class Entry : public NiRefObject
		{
		public:
			// members
			NiPointer<BSFaceGenModel> model;  // 10
			std::uint64_t             time;   // 18
		};
		static_assert(sizeof(Entry) == 0x20);

		// members
		BSTHashMap<BSFixedString, NiPointer<Entry>> map;             // 00
		BSReadWriteLock                             lock;            // 30
		bool                                        hasFaceGenData;  // 38
	};
	static_assert(sizeof(BSFaceGenModelMap) == 0x40);

	class BSFaceGenManager : public BSTSingletonSDM<BSFaceGenManager>
	{
	public:
		[[nodiscard]] static BSFaceGenManager* GetSingleton()
		{
			REL::Relocation<BSFaceGenManager**> singleton{ REL::ID(514182) };
			return *singleton;
		}

		void PrepareHeadPartForShaders(BSFaceGenNiNode* a_node, BGSHeadPart* a_headPart, TESNPC* a_npc)
		{
			using func_t = decltype(&BSFaceGenManager::PrepareHeadPartForShaders);
			REL::Relocation<func_t> func{ REL::ID(26259) };
			return func(this, a_node, a_headPart, a_npc);
		}

		// members
		std::uint32_t     numActorsToMorph;  // 04
		bool              emotions;          // 08
		std::uint8_t      pad09[7];          // 09
		std::uint64_t     unk10;             // 10
		BSFaceGenModelMap modelMap;          // 18
		std::uint8_t      isReset;           // 58
		std::uint8_t      pad59[3];          // 59
		std::uint32_t     unk5C;             // 5C
		std::uint8_t      unk60;             // 60
		std::uint8_t      pad61[7];          // 61
	};
	static_assert(sizeof(BSFaceGenManager) == 0x68);
};
