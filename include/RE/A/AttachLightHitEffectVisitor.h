#pragma once

#include "RE/A/ActiveEffect.h"

namespace RE
{
	class NiAVObject;

	namespace
	{
		class AttachLightHitEffectVisitor : public ActiveEffect::ForEachHitEffectVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI___AttachLightHitEffectVisitor;

			virtual ~AttachLightHitEffectVisitor();  // 00

			// override (ActiveEffect::ForEachHitEffectVisitor)
			virtual std::uint32_t Accept(ReferenceEffect* a_hitEffect) override;  // 01

			// members
			NiAVObject*   actorRoot;        // 08
			NiAVObject*   attachLightNode;  // 10
			bool          unk18;            // 18
			std::uint8_t  pad19;            // 19
			std::uint16_t pad1A;            // 1A
			std::uint32_t pad1C;            // 1C
		};
		static_assert(sizeof(AttachLightHitEffectVisitor) == 0x20);
	}
}
