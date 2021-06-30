#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESIdleForm;

	class BGSIdleCollection : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSIdleCollection;

		enum class IdleFlags
		{
			kNone = 0,
			kPickSequence = 1 << 0,
			kOldPickConditions = 1 << 1,
			kDoOnce = 1 << 2,
			kLooseOnly = 1 << 3,
			kNoSandbox = 1 << 4
		};

		~BGSIdleCollection() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01
		void ClearDataComponent() override;                     // 02
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		stl::enumeration<IdleFlags, std::int8_t> idleFlags;          // 08 - IDLF
		std::int8_t                              idleCount;          // 09 - IDLC
		std::uint16_t                            pad0A;              // 0A
		std::uint32_t                            pad0C;              // 0C
		TESIdleForm**                            idles;              // 10 - IDLA
		float                                    timerCheckForIdle;  // 18 - IDLT
		std::uint32_t                            pad1C;              // 1C
	};
	static_assert(sizeof(BGSIdleCollection) == 0x20);
}
