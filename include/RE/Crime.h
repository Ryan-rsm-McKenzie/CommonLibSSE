#pragma once

#include <type_traits>

#include "RE/BSAtomic.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"


namespace RE
{
	class TESBoundObject;
	class TESFaction;
	class TESForm;


	namespace PackageNS
	{
		struct CRIME_TYPES
		{
			enum CRIME_TYPE : UInt32
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
		UInt64					unk00;				// 00
		UInt64					unk08;				// 08
		UInt64					unk10;				// 10
		UInt64					unk18;				// 18
		UInt64					unk20;				// 20
		BSTArray<ActorHandle>	actorsKnowOfCrime;	// 28
		UInt64					unk40;				// 40
		UInt64					unk48;				// 48
		UInt64					unk50;				// 50
		UInt64					unk58;				// 58
		TESFaction*				crimeFaction;		// 60
		UInt32					unk68;				// 68
		mutable BSReadWriteLock lock;				// 68
		UInt32					unk74;				// 74
	};
	STATIC_ASSERT(sizeof(Crime) == 0x78);
}
