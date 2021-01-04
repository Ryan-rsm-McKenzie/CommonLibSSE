#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class TESForm;

	class MagicFavorites :
		public BSTSingletonSDM<MagicFavorites>	// 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicFavorites;

		virtual ~MagicFavorites();	// 00

		static MagicFavorites* GetSingleton();

		// members
		std::uint8_t	   pad09;	 // 09
		std::uint16_t	   pad0A;	 // 0A
		std::uint32_t	   pad0C;	 // 0C
		BSTArray<TESForm*> spells;	 // 10
		BSTArray<TESForm*> hotkeys;	 // 28
	};
	static_assert(sizeof(MagicFavorites) == 0x40);
}
