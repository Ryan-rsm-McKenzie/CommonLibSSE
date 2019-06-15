#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESRegionDataMap

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/TESRegionData.h"  // TESRegionData


namespace RE
{
	class TESRegionDataMap : public TESRegionData
	{
	public:
		inline static const void* RTTI = RTTI_TESRegionDataMap;


		enum { kTypeID = Type::kMap };


		virtual ~TESRegionDataMap();											// 00

		// override (TESRegionData)
		virtual Type	GetType() const override;								// 03 - { return Type::kMap; }
		virtual void	ConstructSelf() override;								// 04
		virtual void	Unk_05(void) override;									// 05
		virtual void	CopyFrom(TESRegionData* a_src, bool a_copy) override;	// 06
		virtual bool	IsLoaded() const override;								// 07 - { return true; }


		// members
		BSFixedString mapName;	// 10 - RDMP
	};
	STATIC_ASSERT(sizeof(TESRegionDataMap) == 0x18);
}
