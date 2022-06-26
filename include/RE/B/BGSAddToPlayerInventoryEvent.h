#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class BGSLocation;
	class TESForm;

	enum class AQUIRE_TYPE
	{
		kNone = 0,
		kSteal = 1,
		kBuy = 2,
		kPickPocket = 3,
		kPickup = 4,
		kContainer = 5,
		kDeadBody = 6
	};

	class BGSAddToPlayerInventoryEvent
	{
	public:
		[[nodiscard]] static std::uint32_t& GetIndex()
		{
			REL::Relocation<std::uint32_t*> index{ REL::ID(380074) };
			return *index;
		}

		// members
		ObjectRefHandle                              ownerRef;                           // 0x00
		ObjectRefHandle                              containerRef;                       // 0x04
		BGSLocation*                                 location{ nullptr };                // 0x08
		TESForm*                                     itemBase{ nullptr };                // 0x10
		stl::enumeration<AQUIRE_TYPE, std::uint32_t> acquireType{ AQUIRE_TYPE::kNone };  // 0x18
	};
	static_assert(sizeof(BGSAddToPlayerInventoryEvent) == 0x20);
}
