#pragma once

#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint2.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct TESRegionDataList;

	class TESRegionPoint
	{
	public:
		NiPoint2 point;	 // 00
	};
	static_assert(sizeof(TESRegionPoint) == 0x8);

	class TESRegionPointList : public BSSimpleList<TESRegionPoint*>	 // RPLD
	{
	public:
		struct ScaleResult
		{
			TESRegionPoint point;  // 00
			float		   dist;   // 08
			float		   scale;  // 0C
		};
		static_assert(sizeof(ScaleResult) == 0x10);

		ScaleResult*  lastScaleResult;		// 10
		bool		  ownsPointMemory;		// 18
		std::uint8_t  pad19;				// 19
		std::uint16_t pad1A;				// 1A
		NiPoint2	  minimums;				// 1C
		NiPoint2	  maximums;				// 24
		std::uint32_t distanceInsideAtMax;	// 2C - RPLI
		std::uint32_t count;				// 30
		std::uint32_t pad34;				// 34
	};
	static_assert(sizeof(TESRegionPointList) == 0x38);

	class TESRegion : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRegion;
		inline static constexpr auto FORMTYPE = FormType::Region;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kBorderRegion = 1 << 6,
				kIgnored = 1 << 12
			};
		};

		virtual ~TESRegion();  // 00

		// override (TESForm)
		virtual void ClearData(void) override;		 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		// add
		virtual bool Validate();  // 3B

		// members
		TESRegionDataList*				   dataList;		// 20
		BSSimpleList<TESRegionPointList*>* pointLists;		// 28
		TESWorldSpace*					   worldSpace;		// 30 - WNAM
		TESWeather*						   currentWeather;	// 38
		NiColor							   emittanceColor;	// 40
		std::uint32_t					   pad4C;			// 4C
	};
	static_assert(sizeof(TESRegion) == 0x50);
}
