#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiAVObject;
	class NiNode;

	class BSPortalGraph : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPortalGraph;

		~BSPortalGraph() override;  // 00

		// members
		std::uint64_t                   unk10;             // 10
		std::uint64_t                   unk18;             // 18
		std::uint32_t                   unk20;             // 20
		std::uint32_t                   unk24;             // 24
		std::uint64_t                   unk28;             // 28
		std::uint64_t                   unk30;             // 30
		std::uint32_t                   unk38;             // 38
		std::uint32_t                   unk3C;             // 3C
		BSTArray<void*>                 unk40;             // 40
		BSTArray<void*>                 unk58;             // 58
		NiPointer<NiNode>               portalSharedNode;  // 70
		BSTArray<NiPointer<NiAVObject>> unk78;             // 78
		BSTArray<NiPointer<NiAVObject>> unk90;             // 90
		BSTArray<void*>                 unkA8;             // A8
		FormID                          cellID;            // C0
		std::uint32_t                   padC4;             // C4
	};
	static_assert(sizeof(BSPortalGraph) == 0xC8);
}
