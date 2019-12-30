#pragma once

#include "RE/BGSDirectionalAmbientLightingColors.h"
#include "RE/BSLock.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTList.h"
#include "RE/Color.h"
#include "RE/ExtraDataList.h"
#include "RE/FormTypes.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"
#include "RE/TESObjectREFR.h"


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


		enum class CellState : UInt8
		{
			kAttached = 7
		};


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kFlags = 1 << 1,
				kFullName = 1 << 2,
				kOwnership = 1 << 3,
				kExteriorShort = 1 << 28,
				kExteriorChar = 1 << 29,
				kDetachTime = 1 << 30,
				kSeendData = (UInt32)1 << 31
			};
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


			Color								ambientColor;			// 00
			Color								directionalColor;		// 04
			Color								fogColorNear;			// 08
			float								fogNear;				// 0C
			float								fogFar;					// 10
			UInt32								directionalRotationXY;	// 14
			UInt32								directionalRotationZ;	// 18
			float								directionalFade;		// 1C
			float								fogClipDistance;		// 20
			float								fogPower;				// 24
			BGSDirectionalAmbientLightingColors	ambientColors;			// 28
			Color								fogColorFar;			// 48
			float								fogMax;					// 4C
			float								lightFadeBegin;			// 50
			float								lightFadeEnd;			// 54
			Inherit								inherits;				// 58
			UInt32								unk5C;					// 5C
		};
		STATIC_ASSERT(sizeof(Lighting) == 0x60);


		struct Coordinates	// XCLC
		{
			SInt32	cellX;			// 00
			SInt32	cellY;			// 04
			char*	maxHeightData;	// 08
			UInt64	unk18;			// 10
			float	worldX;			// 18
			float	worldY;			// 1C
			UInt64	unk20;			// 20
		};
		STATIC_ASSERT(sizeof(Coordinates) == 0x28);


		union LightingCoordinates
		{
			Lighting*		lighting;		// XCLL
			Coordinates*	coordinates;	// XCLC
		};
		STATIC_ASSERT(sizeof(LightingCoordinates) == 0x8);


		struct LoadedData
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
		STATIC_ASSERT(sizeof(LoadedData) == 0x180);


		virtual ~TESObjectCELL();															// 00

		// override (TESForm)
		virtual void		ClearData() override;											// 05
		virtual bool		Load(TESFile* a_mod) override;									// 06
		virtual TESForm*	CreateDuplicateForm(void* a_arg1, void* a_arg2) override;		// 09 - { return 0; }
		virtual bool		FindInFileFast(TESFile* a_mod) override;						// 0C
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;					// 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;					// 0F
		virtual void		Revert(void* a_arg1) override;									// 12
		virtual void		InitItemImpl() override;										// 13
		virtual void		GetFormDetailedString(char* a_buf, UInt32 a_bufLen) override;	// 16
		virtual void		SetAltered(bool a_set) override;								// 24
		virtual bool		BelongsInGroup(void) override;									// 30
		virtual void		CreateGroupData(void) override;									// 31
		virtual const char*	GetFormEditorID() override;										// 32
		virtual bool		SetFormEditorID(const char* a_str) override;					// 33
		virtual bool		IsParentForm() const override;									// 34 - { return true; }
		virtual bool		IsFormTypeChild(FormType a_type) const override;				// 36

		TESNPC*			GetActorOwner();
		Coordinates*	GetCoordinates();
		TESFaction*		GetFactionOwner();
		Lighting*		GetLighting();
		float			GetNorthRotation();
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
		mutable BSSpinLock					grassCreateLock;		// 030
		mutable BSSpinLock					grassTaskLock;			// 038
		Flag								cellFlags;				// 040
		UInt16								unk042;					// 042
		CellState							cellState;				// 044
		bool								autoWaterLoaded;		// 045
		bool								cellDetached;			// 046
		UInt8								pad047;					// 047
		ExtraDataList						extraList;				// 048
		LightingCoordinates					lightingCoordinates;	// 060 - XCLL if interior, XCLC if exterior
		TESObjectLAND*						land;					// 068
		float								waterHeight;			// 070 - XCLW
		BSTArray<BSTSmartPointer<NavMesh>>*	navMeshes;				// 078
		BSTSet<NiPointer<TESObjectREFR>>	objectMap;				// 080
		TESForm*							unk0B0;					// 0B0 - REFR owner of cell?
		BSTArray<TESObjectREFR*>			objectList;				// 0B8 - persistent
		BSTArray<void*>						unk0D0;					// 0D0
		BSTArray<void*>						unk0F8;					// 0F8
		BSTArray<void*>						unk100;					// 100
		mutable BSSpinLock					spinLock;				// 118
		TESWorldSpace*						worldSpace;				// 120
		LoadedData*							loadedData;				// 128
		BGSLightingTemplate*				lightingTemplate;		// 130 - LTMP
		UInt64								unk138;					// 138
	};
	STATIC_ASSERT(sizeof(TESObjectCELL) == 0x140);
}
