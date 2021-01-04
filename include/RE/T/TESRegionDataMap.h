#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/T/TESRegionData.h"

namespace RE
{
	class TESRegionDataMap : public TESRegionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRegionDataMap;
		inline static constexpr auto TYPE = Type::kMap;

		virtual ~TESRegionDataMap();  // 00

		// override (TESRegionData)
		virtual Type GetType() const override;								// 03 - { return Type::kMap; }
		virtual void ConstructSelf() override;								// 04
		virtual void Unk_05(void) override;									// 05
		virtual void CopyFrom(TESRegionData* a_src, bool a_copy) override;	// 06
		virtual bool IsLoaded() const override;								// 07 - { return true; }

		// members
		BSFixedString mapName;	// 10 - RDMP
	};
	static_assert(sizeof(TESRegionDataMap) == 0x18);
}
