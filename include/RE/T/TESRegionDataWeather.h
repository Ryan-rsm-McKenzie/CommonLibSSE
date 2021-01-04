#pragma once

#include "RE/B/BSTList.h"
#include "RE/T/TESRegionData.h"

namespace RE
{
	struct WeatherType;

	class TESRegionDataWeather : public TESRegionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRegionDataWeather;
		inline static constexpr auto TYPE = Type::kWeather;

		virtual ~TESRegionDataWeather();  // 00

		// override (TESRegionData)
		virtual Type GetType() const override;								// 03 - { return Type::kWeather; }
		virtual void ConstructSelf() override;								// 04
		virtual void Unk_05(void) override;									// 05
		virtual void CopyFrom(TESRegionData* a_src, bool a_copy) override;	// 06
		virtual bool IsLoaded() const override;								// 07 - { return weatherTypes.next || weatherTypes.cur; }

		// add
		virtual void Unk_08(void);	// 08

		// members
		BSSimpleList<WeatherType*> weatherTypes;  // 10
	};
	static_assert(sizeof(TESRegionDataWeather) == 0x20);
}
