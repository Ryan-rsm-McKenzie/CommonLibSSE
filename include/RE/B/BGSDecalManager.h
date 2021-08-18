#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSShaderAccumulator;
	class BGSDecalNode;
	class BSTempEffect;
	class NiCamera;

	class BGSDecalManager
	{
	public:
		static BGSDecalManager* GetSingleton()
		{
			REL::Relocation<BGSDecalManager**> singleton{ REL::ID(514414) };
			return *singleton;
		}

		// members
		std::uint32_t                     unk00;                       // 00
		std::uint32_t                     decalCountCurrentFrame;      // 04
		std::uint32_t                     skinDecalCountCurrentFrame;  // 08
		std::uint32_t                     decalCount;                  // 0C
		std::uint32_t                     skinDecalCount;              // 10
		bool                              unk14;                       // 14
		std::uint8_t                      pad15;                       // 15
		std::uint16_t                     pad16;                       // 16
		BSTArray<NiPointer<BSTempEffect>> decals;                      // 18
		BSTArray<void*>                   unk30;                       // 30
		BSTArray<NiPointer<BGSDecalNode>> decalNodes;                  // 48
		BSTArray<NiPointer<BSTempEffect>> unk60;                       // 60
		NiPointer<NiCamera>               camera;                      // 78
		NiPointer<BSShaderAccumulator>    shaderAccumulator;           // 80
		std::uint32_t                     unk88;                       // 88
	};
	static_assert(sizeof(BGSDecalManager) == 0x90);
};
