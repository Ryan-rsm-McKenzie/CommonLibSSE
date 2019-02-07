#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	class TESObjectCELL :
		public TESForm,		// 000
		public TESFullName	// 020
	{
	public:
		enum { kTypeID = FormType::Cell };


		typedef UInt32 UnkKey;


		enum class Flag : UInt16	// DATA
		{
			kIsInteriorCell = 1 << 0,
			kHasWater = 1 << 1,
			kCantTravelFromHere = 1 << 2,
			kNoLODWater = 1 << 3,
			kPublicArea = 1 << 5,
			kHandChanged = 1 << 6,
			kShowSky = 1 << 7,
			kUseSkyLighting = 1 << 8
		};


		struct Data
		{
			UInt32	unk0;
			UInt32	unk4;
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		struct Lighting	// XCLL
		{
			enum class Inherit : UInt32
			{
				kAmbientColor = 1 << 0,
				kDirectionalColor = 1 << 1,
				kFogColor = 1 << 2,
				kFogNear = 1 << 3,
				kFogFar = 1 << 4,
				kDirectionalRotation = 1 << 5,
				kDirectionalFade = 1 << 6,
				kClipDistance = 1 << 7,
				kFogPower = 1 << 8,
				kFogMax = 1 << 9,
				kLightFadeDistances = 1 << 10
			};


			struct AmbientColors
			{
				struct Directional
				{
					Color	xPlus;	// 00
					Color	xMinus;	// 04
					Color	yPlus;	// 08
					Color	yMinus;	// 0C
					Color	zPlus;	// 10
					Color	zMinus;	// 14
				};
				STATIC_ASSERT(sizeof(Directional) == 0x18);


				Directional	directional;	// 00
				Color		specular;		// 18
				float		scale;			// 1C
			};
			STATIC_ASSERT(sizeof(AmbientColors) == 0x20);


			Color			ambientColor;			// 00
			Color			directionalColor;		// 04
			Color			fogColorNear;			// 08
			float			fogNear;				// 0C
			float			fogFar;					// 10
			UInt32			directionalRotationXY;	// 14
			UInt32			directionalRotationZ;	// 18
			float			directionalFade;		// 1C
			float			fogClipDistance;		// 20
			float			fogPower;				// 24
			AmbientColors	ambientColors;			// 28
			Color			fogColorFar;			// 48
			float			fogMax;					// 4C
			float			lightFadeBegin;			// 50
			float			lightFadeEnd;			// 54
			Inherit			inherits;				// 58
			UInt32			pad5C;					// 5C
		};
		STATIC_ASSERT(sizeof(Lighting) == 0x60);


		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;							// 06
		virtual TESForm*	DupulicateForm(uintptr_t a_arg1, void* a_arg2) override;	// 09
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;				// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;				// 0F
		virtual void		InitItem() override;										// 13
		virtual void		GetFormDesc(char* a_buf, UInt32 a_bufLen) override;			// 16
		virtual void		SetFlag00000002(bool a_set) override;						// 24
		virtual const char*	GetName() override;											// 32
		virtual bool		SetName(const char* a_str) override;						// 33

		double GetNorthRotation();


		// members
		Data								unk030;				// 030
		Data								unk038;				// 038
		Flag								flags;				// 040
		UInt16								unk042;				// 042
		UInt8								unk044;				// 044
		UInt8								unk045;				// 045
		UInt8								unk046;				// 046
		UInt8								pad047;				// 047
		BSExtraData*						extraData;			// 048
		UInt32*								unk050;				// 050
		UInt64								unk058;				// 058
		Lighting*							lighting;			// 060
		TESObjectLAND*						land;				// 068 - NEEDS CHECKING
		float								waterHeight;		// 070 - XCLW
		void*								unk078;				// 078
		BSTHashMap<UInt32, TESObjectREFR>	persistentRefMap;	// 088
		TESForm*							unk0B0;				// 0B0 - REFR owner of cell?
		BSTArray<TESObjectREFR*>			objectList;			// 0B8 - temporary refs?
		UnkArray							unk0D0;				// 0D0
		UnkArray							unk0F8;				// 0F8
		UnkArray							unk100;				// 100
		SimpleLock							cellRefLock;		// 118
		TESWorldSpace*						worldSpace;			// 120
		UInt64								unk128;				// 128
		BGSLightingTemplate*				lightingTemplate;	// 130
		UInt64								unk138;				// 138
	};
	STATIC_ASSERT(offsetof(TESObjectCELL, persistentRefMap) == 0x80);
	STATIC_ASSERT(offsetof(TESObjectCELL, objectList) == 0xB8);
	STATIC_ASSERT(sizeof(TESObjectCELL) == 0x140);
}
