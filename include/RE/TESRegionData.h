#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESRegionData


namespace RE
{
	class TESForm;


	class TESRegionData
	{
	public:
		inline static const void* RTTI = RTTI_TESRegionData;


		enum class Type : UInt16
		{
			kObjects = 2,
			kWeather = 3,
			kMap = 4,
			kLand = 5,
			kGrass = 6,
			kSound = 7,
			kImposter = 8
		};


		struct DataHeader	// RDAT
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kOverride = 1 << 0
			};


			Flag	flags;		// 0
			UInt8	unk09;		// 1
			UInt8	priority;	// 2
			UInt8	unk0B;		// 3
			UInt32	unk0C;		// 4
		};
		STATIC_ASSERT(sizeof(DataHeader) == 0x8);


		virtual ~TESRegionData();											// 00

		// add
		virtual bool	LoadDataHeader(void* a_arg1);						// 01
		virtual void	LoadData(TESForm* a_form);							// 02 - { return; }
		virtual Type	GetType() const = 0;								// 03
		virtual void	ConstructSelf() = 0;								// 04
		virtual void	Unk_05(void) = 0;									// 05
		virtual void	CopyFrom(TESRegionData* a_src, bool a_copy) = 0;	// 06
		virtual bool	IsLoaded() const = 0;								// 07


		// members
		DataHeader dataHeader;	// 08 - RDAT
	};
	STATIC_ASSERT(sizeof(TESRegionData) == 0x10);
}
