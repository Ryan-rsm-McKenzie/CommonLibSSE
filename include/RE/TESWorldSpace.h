#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESWorldSpace

#include "RE/BSString.h"  // BSString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // FormType, TESForm
#include "RE/NiTPointerMap.h"  // NiTPointerMap
#include "RE/TESForm.h"  // FormType
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModel.h"  // TESModel
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESWorldSpace :
		public TESForm,		// 000
		public TESFullName,	// 020
		public TESModel		// 030
	{
	public:
		inline static const void* RTTI = RTTI_TESWorldSpace;


		enum { kTypeID = FormType::WorldSpace };


		enum class DataFlag : UInt8
		{
			kNone = 0,
			kSmallWorld = 1 << 0,
			kCantFastTravel = 1 << 1,
			kNoLODWater = 1 << 3,
			kNoLandscape = 1 << 4,
			kNoSky = 1 << 5,
			kFixedDimensions = 1 << 6,
			kNoGrass = 1 << 7,
		};


		enum class ParentFlag : UInt8
		{
			kNone = 0,
			kUseLandData = 1 << 0,
			kUseLODData = 1 << 1,
			kDontUseMapData = 1 << 2,
			kUseWaterData = 1 << 3,
			kUseClimateData = 1 << 4,
			kUseImageSpaceData = 1 << 5,	// unused
			kUseSkyCell = 1 << 6,
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCantWait = 1 << 19
			};
		};


		struct XYPlane
		{
			SInt16	x;
			SInt16	y;
		};
		STATIC_ASSERT(sizeof(XYPlane) == 0x4);


		struct MapData	// MNAM
		{
			struct CellCoordinates
			{
				XYPlane	nwCell;	// 0
				XYPlane	seCell;	// 4
			};
			STATIC_ASSERT(sizeof(CellCoordinates) == 0x8);


			struct CameraData
			{
				float	minHeight;		// 0
				float	maxHeight;		// 4
				float	initialPitch;	// 8
			};
			STATIC_ASSERT(sizeof(CameraData) == 0xC);


			XYPlane			usableDimensions;	// 00
			UInt32			pad04;				// 04
			CellCoordinates	cellCoordinates;	// 08
			CameraData		cameraData;			// 10
		};
		STATIC_ASSERT(sizeof(MapData) == 0x1C);


		struct WorldMapOffsetData	// ONAM
		{
			float	worldMapScale;	// 00
			float	cellXOffset;	// 04
			float	cellYOffset;	// 08
			float	cellZOffset;	// 0C
		};
		STATIC_ASSERT(sizeof(WorldMapOffsetData) == 0x10);


		struct LargeReferenceData   // RNAM
		{
			// RNAM format in plugins is cell x,y -> formID + cell that contains refr x,y
			// a lot of RNAM data is for refrs that are actually in adjacent cells, it is currently unknown what behavior this has in game
			BSTHashMap<XYPlane, UInt32*>	cellFormIDMap;				// 00 - full data merged at runtime, value is an array of FormIDs with array size as the first entry
			BSTHashMap<UInt32, XYPlane>		formIDCellMap;				// 30 - maps FormID to cell so opposite of above map

			// this filtered version of the full data removes all duplicate RNAM entries and also all entries where cell x,y doesn't match cell that contains refr x,y
			// this is the one actually used for loading large references on cell attach
			BSTHashMap<XYPlane, UInt32*>	cellFormIDMapFiltered;		// 60
		};
		STATIC_ASSERT(sizeof(LargeReferenceData) == 0x90);


		struct ObjectBounds
		{
			// The bounds are the CK value * 4096
			struct Bounds
			{
				float	GetX() const;
				float	GetY() const;


				float	x;	// 0
				float	y;	// 4
			};
			STATIC_ASSERT(sizeof(Bounds) == 0x8);


			Bounds	min;	// 00 - NAM0
			Bounds	max;	// 08 - NAM9
		};
		STATIC_ASSERT(sizeof(ObjectBounds) == 0x10);


		struct LandData	// DNAM
		{
			float	defaultLandHeight;	// 0
			float	defaultWaterHeight;	// 4
		};
		STATIC_ASSERT(sizeof(LandData) == 0x8);


		BSTHashMap<UnkKey, UnkValue>							unk058;						// 058
		TESObjectCELL*											cell;						// 088
		void*													unk90;						// 090
		TESClimate*												climate;					// 098 - CNAM
		DataFlag												dataFlags;					// 0A0 - DATA
		UInt8													unk0A1;						// 0A1 - more flags
		ParentFlag												parentFlags;				// 0A2 - PNAM
		UInt8													pad0A3;						// 0A2
		XYPlane													fixedDimensionsCenterCell;	// 0A4 - WCTR
		BSTHashMap<UnkKey, UnkValue>							unk0A8;						// 0A8
		BSTArray<TESObjectREFR*>								objects;					// 0D8
		NiTPointerMap<UInt32, BSSimpleList<TESObjectREFR*>*>*	refrListPtrMap;				// 0F0
		TESObjectCELL*											unk0F8;						// 0F8 - uses a generated formID
		BSTHashMap<UnkKey, UnkValue>							unk100;						// 100
		UInt64													unk130;						// 130
		UInt64													unk138;						// 138
		UInt64													unk140;						// 140
		UInt64													unk148;						// 148
		UInt64													unk150;						// 150
		TESWorldSpace*											parentWorldSpace;			// 158 - WNAM
		BGSLightingTemplate*									interiorLighting;			// 160 - LTMP
		TESWaterForm*											water;						// 168 - NAM2
		TESWaterForm*											lodWaterType;				// 170 - NAM3
		float													lodWaterHeight;				// 178 - NAM4
		UInt32													pad17C;						// 17C
		UInt64													unk180;						// 180
		MapData													mapData;					// 188 - MNAM
		WorldMapOffsetData										worldMapOffsetData;			// 1A4 - ONAM
		UInt32													pad1B4;						// 1B4
		BGSMusicType*											music;						// 1B8 - ZNAM
		ObjectBounds											objectBounds;				// 1C0
		BSTHashMap<UnkKey, UnkValue>							unk1D0;						// 1D0
		BSString												editorID;					// 200 - EDID
		LandData												landData;					// 210 - DNAM
		float													distantLODMultiplier;		// 218 - NAMA
		UInt32													pad21C;						// 21C
		BGSEncounterZone*										encounterZone;				// 220 - XEZN
		BGSLocation*											location;					// 228 - XLCN
		TESTexture												hdLODDiffuseTexture;		// 230 - TNAM
		TESTexture												hdLODNormalTexture;			// 240 - UNAM
		LargeReferenceData                                      largeReferenceData;			// 250 - RNAM
		UInt64													unk2E0;						// 2E0
		BSTHashMap<UnkKey, UnkValue>							unk2E8;						// 2E8
		BSTHashMap<UnkKey, UnkValue>							unk318;						// 318
		UInt64													unk348;						// 348
		UInt8*													maxHeightData;				// 350 - MHDT (it's an array, but idk how big it is)
	};
	STATIC_ASSERT(offsetof(TESWorldSpace, cell) == 0x088);
	STATIC_ASSERT(offsetof(TESWorldSpace, unk100) == 0x100);
	STATIC_ASSERT(offsetof(TESWorldSpace, unk180) == 0x180);
	STATIC_ASSERT(offsetof(TESWorldSpace, editorID) == 0x200);
	STATIC_ASSERT(offsetof(TESWorldSpace, largeReferenceData) == 0x250);
	STATIC_ASSERT(offsetof(TESWorldSpace, unk318) == 0x318);
	STATIC_ASSERT(offsetof(TESWorldSpace, maxHeightData) == 0x350);
	STATIC_ASSERT(sizeof(TESWorldSpace) == 0x358);
}
