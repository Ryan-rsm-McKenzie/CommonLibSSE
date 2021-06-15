#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class BSLight;
	class ExtraDataList;
	class ImageSpaceModifierInstanceRB;
	class TESBoundObject;

	class VATS : public BSTSingletonSDM<VATS>
	{
	public:
		[[nodiscard]] static VATS* GetSingleton()
		{
			REL::Relocation<VATS**> singleton{ REL::ID(514725) };
			return *singleton;
		}

		// members
		std::uint32_t                 pad00;                  // 00
		BSTArray<void*>               unk08;                  // 08
		std::uint32_t                 vatsMode;               // 20
		std::uint32_t                 pad24;                  // 24
		std::uint64_t                 unk28;                  // 28
		std::uint64_t                 unk30;                  // 30
		float                         safetyTime;             // 38
		float                         cameraTime;             // 3C
		float                         castingAfterKillDelay;  // 40
		std::uint32_t                 pad44;                  // 44
		NiPointer<Actor>              unk48;                  // 48
		std::uint64_t                 unk50;                  // 50
		std::uint64_t                 unk58;                  // 58
		std::uint64_t                 unk60;                  // 60
		ImageSpaceModifierInstanceRB* unk68;                  // 68
		NiPointer<BSLight>            light;                  // 70
		std::uint16_t                 unk78;                  // 78
		std::uint16_t                 pad7A;                  // 7A
		std::uint32_t                 unk7C;                  // 7C
		float                         timeMult;               // 80
		float                         timePCMult;             // 84
		TESBoundObject*               item;                   // 88
		ExtraDataList*                extraList;              // 90
		Actor*                        unk98;                  // 98
		std::uint32_t                 unkA0;                  // A0
		std::uint32_t                 padA4;                  // A4
		NiPointer<Actor>              unkA8;                  // A8
		NiPointer<Actor>              unkB0;                  // B0
		mutable BSSpinLock            lock;                   // B8
	};
	static_assert(sizeof(VATS) == 0xC0);
};
