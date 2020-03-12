#pragma once

#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/NiColor.h"
#include "RE/NiPoint2.h"
#include "RE/TESForm.h"


namespace RE
{
	struct TESRegionDataList;


	class TESRegionPoint
	{
	public:
		NiPoint2 point;	 // 00
	};
	STATIC_ASSERT(sizeof(TESRegionPoint) == 0x8);


	class TESRegionPointList : public BSSimpleList<TESRegionPoint*>	 // RPLD
	{
	public:
		struct ScaleResult
		{
			TESRegionPoint point;  // 00
			float		   dist;   // 08
			float		   scale;  // 0C
		};
		STATIC_ASSERT(sizeof(ScaleResult) == 0x10);


		ScaleResult* lastScaleResult;	   // 10
		bool		 ownsPointMemory;	   // 18
		UInt8		 pad19;				   // 19
		UInt16		 pad1A;				   // 1A
		NiPoint2	 minimums;			   // 1C
		NiPoint2	 maximums;			   // 24
		UInt32		 distanceInsideAtMax;  // 2C - RPLI
		UInt32		 count;				   // 30
		UInt32		 pad34;				   // 34
	};
	STATIC_ASSERT(sizeof(TESRegionPointList) == 0x38);


	class TESRegion : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRegion;
		inline static constexpr auto FORMTYPE = FormType::Region;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
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
		UInt32							   pad4C;			// 4C
	};
	STATIC_ASSERT(sizeof(TESRegion) == 0x50);
}
