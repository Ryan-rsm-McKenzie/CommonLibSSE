#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class TESBoundObject;
	class TESFaction;
	class TESForm;

	namespace PackageNS
	{
		struct CRIME_TYPES
		{
			enum CRIME_TYPE : std::uint32_t
			{
				kNone = static_cast<std::underlying_type_t<CRIME_TYPE>>(-1),
				kSteal = 0,
				kPickpocket = 1,
				kTrespass = 2,
				kAttack = 3,
				kMurder = 4,
				kEscape = 5,
				kUnused = 6,

				kTotal = 7
			};
		};
		using CRIME_TYPE = CRIME_TYPES::CRIME_TYPE;
	}

	struct Crime
	{
	public:
		// members
		std::uint64_t           unk00;              // 00
		std::uint64_t           unk08;              // 08
		std::uint64_t           unk10;              // 10
		std::uint64_t           unk18;              // 18
		std::uint64_t           unk20;              // 20
		BSTArray<ActorHandle>   actorsKnowOfCrime;  // 28
		std::uint64_t           unk40;              // 40
		std::uint64_t           unk48;              // 48
		std::uint64_t           unk50;              // 50
		std::uint64_t           unk58;              // 58
		TESFaction*             crimeFaction;       // 60
		std::uint32_t           unk68;              // 68
		mutable BSReadWriteLock lock;               // 68
		std::uint32_t           unk74;              // 74
	};
	static_assert(sizeof(Crime) == 0x78);
}
