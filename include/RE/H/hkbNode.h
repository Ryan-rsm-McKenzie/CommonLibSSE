#pragma once

#include "RE/H/hkStringPtr.h"
#include "RE/H/hkbBindable.h"
#include "RE/H/hkbContext.h"

namespace RE
{
	class hkbNode : public hkbBindable
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbNode;

		~hkbNode() override;  // 00

		// add
		virtual void Activate(const hkbContext& a_context);                  // 04 - { return; }
		virtual void Update(const hkbContext& a_context, float a_timestep);  // 05 - { userData |= 1; }
		virtual void Unk_06(void);                                           // 06 - { return; }
		virtual void Deactivate(const hkbContext& a_context);                // 07 - { return; }
		virtual void Unk_08(void);                                           // 08 - { return 2; }
		virtual void Unk_09(void);                                           // 09 - { return; }
		virtual void Unk_0A(void);                                           // 0A - { return 1; }
		virtual void Unk_0B(void);                                           // 0B - { return; }
		virtual void Unk_0C(void);                                           // 0C
		virtual void Unk_0D(void);                                           // 0D - { return 0; }
		virtual void Unk_0E(void);                                           // 0E - { return; }
		virtual void Unk_0F(void);                                           // 0F - { return; }
		virtual void Unk_10(void);                                           // 10 - { return; }
		virtual void Unk_11(void);                                           // 11 - { return; }
		virtual void Unk_12(void);                                           // 12 - { return; }
		virtual void Unk_13(void);                                           // 13 - { return 0; }
		virtual void Unk_14(void);                                           // 14 - { return; }
		virtual void Unk_15(void);                                           // 15 - { return 0; }
		virtual void Unk_16(void);                                           // 16 - { return 0; }

		enum class GetChildrenFlagBits
		{
			kActiveOnly = 1 << 0,
			kGeneratorsOnly = 1 << 1,
			kIgnoreReferencedBehaviour = 1 << 2
		};

		enum class CloneState
		{
			kDefault = 0,
			kTemplate = 1,
			kClone = 2,
			kShareable = 3
		};

		// members
		std::uint32_t                              userData;    // 30
		std::uint32_t                              pad34;       // 34
		hkStringPtr                                name;        // 38
		std::uint16_t                              id;          // 40
		stl::enumeration<CloneState, std::uint8_t> cloneState;  // 42
		std::uint8_t                               pad43;       // 43
		std::uint32_t                              pad44;       // 44
	};
	static_assert(sizeof(hkbNode) == 0x48);
}
