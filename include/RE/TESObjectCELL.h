#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectCELL

#include "RE/BaseExtraList.h"  // BaseExtraList
#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashSet
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Color.h"  // Color
#include "RE/DirectionalAmbientLightingColor.h"  // DirectionalAmbientLightingColor
#include "RE/FormTypes.h"  // FormType
#include "RE/NiSmartPointer.h"  // NiPointer
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	class NavMesh;


	class TESObjectCELL :
		public TESForm,		// 000
		public TESFullName	// 020
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectCELL;


		enum { kTypeID = FormType::Cell };


		enum class Flag : UInt16	// DATA
		{
			kNone = 0,
			kIsInteriorCell = 1 << 0,
			kHasWater = 1 << 1,
			kCanTravelFromHere = 1 << 2,
			kNoLODWater = 1 << 3,
			kPublicArea = 1 << 5,
			kHandChanged = 1 << 6,
			kShowSky = 1 << 7,
			kUseSkyLighting = 1 << 8
		};


		enum class AttachedState : UInt8
		{
			kAttached = 7
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kPersistent = 1 << 10,
				kIgnored = 1 << 12,
				kOffLimits = 1 << 17,
				kCompressed = 1 << 18,
				kCantWait = 1 << 19
			};
		};


		struct Data038
		{
			UInt32	unk0;
			UInt32	unk4;
		};
		STATIC_ASSERT(sizeof(Data038) == 0x8);


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


			Color							ambientColor;			// 00
			Color							directionalColor;		// 04
			Color							fogColorNear;			// 08
			float							fogNear;				// 0C
			float							fogFar;					// 10
			UInt32							directionalRotationXY;	// 14
			UInt32							directionalRotationZ;	// 18
			float							directionalFade;		// 1C
			float							fogClipDistance;		// 20
			float							fogPower;				// 24
			DirectionalAmbientLightingColor	ambientColors;			// 28
			Color							fogColorFar;			// 48
			float							fogMax;					// 4C
			float							lightFadeBegin;			// 50
			float							lightFadeEnd;			// 54
			Inherit							inherits;				// 58
			UInt32							unk5C;					// 5C
		};
		STATIC_ASSERT(sizeof(Lighting) == 0x60);


		struct Coordinates	// XCLC
		{
			SInt32	x;		// 00
			SInt32	y;		// 04
			UInt64	unk08;	// 08
			UInt64	unk18;	// 10
			float	fx;		// 18 - fx = (float)(x << 12)
			float	fy;		// 1C - fy = (float)(y << 12)
			UInt64	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(Coordinates) == 0x28);


		union LightingCoordinates
		{
			Lighting*		lighting;		// XCLL
			Coordinates*	coordinates;	// XCLC
		};
		STATIC_ASSERT(sizeof(LightingCoordinates) == 0x8);


		struct Data
		{
			UInt64				unk000;			// 000
			void*				unk008;			// 008
			UInt64				unk010;			// 010
			UInt64				unk018;			// 018
			UInt64				unk020;			// 020
			UInt64				unk028;			// 028
			UInt64				unk030;			// 030
			UInt64				unk038;			// 038
			UInt64				unk040;			// 040
			UInt64				unk048;			// 048
			UInt64				unk050;			// 050
			UInt64				unk058;			// 058
			UInt64				unk060;			// 060
			UInt64				unk068;			// 068
			UInt64				unk070;			// 070
			UInt64				unk078;			// 078
			UInt64				unk080;			// 080
			UInt64				unk088;			// 088
			UInt64				unk090;			// 090
			UInt64				unk098;			// 098
			UInt64				unk0A0;			// 0A0
			UInt64				unk0A8;			// 0A8
			UInt64				unk0B0;			// 0B0
			UInt64				unk0B8;			// 0B8
			UInt64				unk0C0;			// 0C0
			UInt64				unk0C8;			// 0C8
			UInt64				unk0D0;			// 0D0
			UInt64				unk0D8;			// 0D8
			UInt64				unk0E0;			// 0E0
			UInt64				unk0E8;			// 0E8
			BSSimpleList<void*>	unk0F0;			// 0F0
			UInt64				unk100;			// 100
			UInt64				unk108;			// 108
			UInt64				unk110;			// 110
			UInt64				unk118;			// 118
			UInt64				unk120;			// 120
			UInt64				unk128;			// 128
			UInt64				unk130;			// 130
			UInt64				unk138;			// 138
			UInt64				unk140;			// 140
			UInt64				unk148;			// 148
			UInt64				unk150;			// 150
			UInt64				unk158;			// 158
			BGSEncounterZone*	encounterZone;	// 160
			UInt64				unk168;			// 168
			UInt64				unk170;			// 170
			UInt64				unk178;			// 178
		};
		STATIC_ASSERT(sizeof(Data) == 0x180);


		virtual ~TESObjectCELL();													// 00

		// override (TESForm)
		virtual void		ReleaseManagedData() override;							// 05
		virtual bool		LoadForm(TESFile* a_mod) override;						// 06
		virtual TESForm*	DupulicateForm(void* a_arg1, void* a_arg2) override;	// 09 - { return 0; }
		virtual void		Unk_0C(void) override;									// 0C
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;			// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;			// 0F
		virtual void		Unk_12(void) override;									// 12
		virtual void		InitItem() override;									// 13
		virtual void		GetFormDesc(char* a_buf, UInt32 a_bufLen) override;		// 16
		virtual void		SetFlag00000002(bool a_set) override;					// 24
		virtual void		Unk_30(void) override;									// 30
		virtual void		Unk_31(void) override;									// 31
		virtual const char*	GetEditorID() override;									// 32
		virtual bool		SetEditorID(const char* a_str) override;				// 33
		virtual void		Unk_34(void) override;									// 34 - { return 1; }
		virtual void		Unk_36(void) override;									// 36

		TESNPC*			GetActorOwner();
		Coordinates*	GetCoordinates();
		TESFaction*		GetFactionOwner();
		Lighting*		GetLighting();
		double			GetNorthRotation();
		TESForm*		GetOwner();
		bool			IsAttached() const;
		bool			IsExteriorCell() const;
		bool			IsInteriorCell() const;
		void			SetActorOwner(TESNPC* a_owner);
		void			SetFactionOwner(TESFaction* a_owner);
		void			SetFogColor(Color a_near, Color a_far);
		void			SetFogPlanes(float a_near, float a_far);
		void			SetFogPower(float a_power);
		void			SetHandChanged(bool a_changed);
		void			SetOwner(TESForm* a_owner);
		void			SetPublic(bool a_public);
		bool			UsesSkyLighting() const;


		// members
		mutable BSUniqueLock					unk030;					// 030
		Data038									unk038;					// 038
		Flag									flags;					// 040
		UInt16									unk042;					// 042
		AttachedState							attachedState;			// 044
		UInt8									unk045;					// 045
		UInt8									unk046;					// 046
		UInt8									pad047;					// 047
		BaseExtraList							extraList;				// 048
		LightingCoordinates						lightingCoordinates;	// 060 - XCLL if interior, XCLC if exterior
		TESObjectLAND*							land;					// 068
		float									waterHeight;			// 070 - XCLW
		BSTArray<BSTSmartPointer<NavMesh>>*		navMeshes;				// 078
		BSTHashSet<NiPointer<TESObjectREFR>>	persistentRefMap;		// 080
		TESForm*								unk0B0;					// 0B0 - REFR owner of cell?
		BSTArray<TESObjectREFR*>				objectList;				// 0B8 - persistent
		BSTArray<void*>							unk0D0;					// 0D0
		BSTArray<void*>							unk0F8;					// 0F8
		BSTArray<void*>							unk100;					// 100
		mutable BSUniqueLock					cellRefLock;			// 118
		TESWorldSpace*							worldSpace;				// 120
		Data*									data;					// 128
		BGSLightingTemplate*					lightingTemplate;		// 130 - LTMP
		UInt64									unk138;					// 138
	};
	STATIC_ASSERT(offsetof(TESObjectCELL, persistentRefMap) == 0x80);
	STATIC_ASSERT(offsetof(TESObjectCELL, objectList) == 0xB8);
	STATIC_ASSERT(sizeof(TESObjectCELL) == 0x140);
}
