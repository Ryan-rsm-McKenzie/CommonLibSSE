#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTSingleton.h"


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
		UInt8			   pad09;	 // 09
		UInt16			   pad0A;	 // 0A
		UInt32			   pad0C;	 // 0C
		BSTArray<TESForm*> spells;	 // 10
		BSTArray<TESForm*> hotkeys;	 // 28
	};
	STATIC_ASSERT(sizeof(MagicFavorites) == 0x40);
}
