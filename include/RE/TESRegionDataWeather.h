#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESRegionDataWeather

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/TESRegionData.h"  // TESRegionData


namespace RE
{
	struct WeatherType;


	class TESRegionDataWeather : public TESRegionData
	{
	public:
		inline static const void* RTTI = RTTI_TESRegionDataWeather;


		enum { kTypeID = Type::kWeather };


		virtual ~TESRegionDataWeather();										// 00

		// override (TESRegionData)
		virtual Type	GetType() const override;								// 03 - { return Type::kWeather; }
		virtual void	ConstructSelf() override;								// 04
		virtual void	Unk_05(void) override;									// 05
		virtual void	CopyFrom(TESRegionData* a_src, bool a_copy) override;	// 06
		virtual bool	IsLoaded() const override;								// 07 - { return weatherTypes.next || weatherTypes.cur; }

		// add
		virtual void	Unk_08(void);				// 08


		// members
		BSSimpleList<WeatherType*> weatherTypes;	// 10
	};
	STATIC_ASSERT(sizeof(TESRegionDataWeather) == 0x20);
}
