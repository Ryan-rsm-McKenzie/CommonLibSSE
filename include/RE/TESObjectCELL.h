#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSBitField.h"
#include "RE/BSMultiBoundNode.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTList.h"
#include "RE/Color.h"
#include "RE/ExtraDataList.h"
#include "RE/FormTypes.h"
#include "RE/InteriorData.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTMap.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"
#include "RE/TESObjectREFR.h"


namespace RE
{
	class NavMesh;
	class NiNode;


	class BGSTerrainVisibilityData
	{
	public:
		BSBitField<>* visData;	// 0
	};
	STATIC_ASSERT(sizeof(BGSTerrainVisibilityData) == 0x8);


	struct EXTERIOR_DATA  // XCLC
	{
		enum class LandHideFlag : UInt8
		{
			kNone = 0,
			kQuad1 = 1 << 0,
			kQuad2 = 1 << 1,
			kQuad3 = 1 << 2,
			kQuad4 = 1 << 3
		};


		SInt32					  cellX;		  // 00
		SInt32					  cellY;		  // 04
		char*					  maxHeightData;  // 08
		BGSTerrainVisibilityData* lodVisData;	  // 10
		float					  worldX;		  // 18
		float					  worldY;		  // 1C
		LandHideFlag			  landHideFlags;  // 20
		UInt8					  pad21;		  // 21
		UInt16					  pad22;		  // 22
		UInt32					  pad24;		  // 24
	};
	STATIC_ASSERT(sizeof(EXTERIOR_DATA) == 0x28);


	class NavMeshArray
	{
	public:
		BSTArray<BSTSmartPointer<NavMesh>> navMeshes;  // 00
	};
	STATIC_ASSERT(sizeof(NavMeshArray) == 0x18);


	struct LOADED_CELL_DATA
	{
		void*												 unk000;				// 000 - smart ptr
		NiPointer<NiNode>									 cell3D;				// 008
		void*												 unk010;				// 010 - smart ptr
		void*												 unk018;				// 018 - smart ptr
		void*												 unk020;				// 020 - smart ptr
		UInt64												 unk028;				// 028
		UInt64												 unk030;				// 030
		UInt64												 unk038;				// 038
		BSTArray<void*>										 unk040;				// 040
		BSTArray<void*>										 unk058;				// 058
		NiTMap<TESForm*, ObjectRefHandle>					 unk070;				// 070
		NiTMap<ObjectRefHandle, NiNode*>					 emittanceLightRefMap;	// 090
		NiTMap<ObjectRefHandle, NiPointer<BSMultiBoundNode>> multiboundRefMap;		// 0B0
		NiTMap<BSMultiBoundNode*, ObjectRefHandle>			 refMultiboundMap;		// 0D0
		BSSimpleList<ObjectRefHandle>						 activatingRefs;		// 0F0
		BSSimpleList<ObjectRefHandle>						 unk100;				// 100
		UInt64												 unk110;				// 110
		BSTArray<void*>										 unk118;				// 118
		BSTArray<void*>										 unk130;				// 130
		BSTArray<void*>										 unk148;				// 148
		BGSEncounterZone*									 encounterZone;			// 160
		UInt64												 unk168;				// 168
		UInt64												 unk170;				// 170
		UInt64												 unk178;				// 178
	};
	STATIC_ASSERT(sizeof(LOADED_CELL_DATA) == 0x180);


	class TESObjectCELL :
		public TESForm,		// 000
		public TESFullName	// 020
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectCELL;
		inline static constexpr auto FORMTYPE = FormType::Cell;


		enum class Flag : UInt16  // DATA
		{
			kNone = 0,
			kIsInteriorCell = 1 << 0,
			kHasWater = 1 << 1,
			kCanTravelFromHere = 1 << 2,
			kNoLODWater = 1 << 3,
			kHasTempData = 1 << 4,
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


		union CellData
		{
			EXTERIOR_DATA* exterior;  // XCLC
			INTERIOR_DATA* interior;  // XCLL
		};
		STATIC_ASSERT(sizeof(CellData) == 0x8);


		virtual ~TESObjectCELL();  // 00

		// override (TESForm)
		virtual void		ClearData() override;																  // 05
		virtual bool		Load(TESFile* a_mod) override;														  // 06
		virtual TESForm*	CreateDuplicateForm(bool a_createEditorID, void* a_arg2) override;					  // 09 - { return 0; }
		virtual bool		FindInFileFast(TESFile* a_mod) override;											  // 0C
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;										  // 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;										  // 0F
		virtual void		Revert(BGSLoadFormBuffer* a_buf) override;											  // 12
		virtual void		InitItemImpl() override;															  // 13
		virtual void		GetFormDetailedString(char* a_buf, UInt32 a_bufLen) override;						  // 16
		virtual void		SetAltered(bool a_set) override;													  // 24
		virtual bool		BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly) override;  // 30
		virtual void		CreateGroupData(FORM* a_form, FORM_GROUP* a_group) override;						  // 31
		virtual const char* GetFormEditorID() const override;													  // 32
		virtual bool		SetFormEditorID(const char* a_str) override;										  // 33
		virtual bool		IsParentForm() override;															  // 34 - { return true; }
		virtual bool		IsFormTypeChild(FormType a_type) override;											  // 36

		TESNPC*		   GetActorOwner();
		EXTERIOR_DATA* GetCoordinates();
		TESFaction*	   GetFactionOwner();
		INTERIOR_DATA* GetLighting();
		float		   GetNorthRotation();
		TESForm*	   GetOwner();
		bool		   IsAttached() const;
		bool		   IsExteriorCell() const;
		bool		   IsInteriorCell() const;
		void		   SetActorOwner(TESNPC* a_owner);
		void		   SetFactionOwner(TESFaction* a_owner);
		void		   SetFogColor(Color a_near, Color a_far);
		void		   SetFogPlanes(float a_near, float a_far);
		void		   SetFogPower(float a_power);
		void		   SetHandChanged(bool a_changed);
		void		   SetOwner(TESForm* a_owner);
		void		   SetPublic(bool a_public);
		bool		   UsesSkyLighting() const;


		// members
		mutable BSSpinLock				 grassCreateLock;	// 030
		mutable BSSpinLock				 grassTaskLock;		// 038
		Flag							 cellFlags;			// 040
		UInt16							 cellGameFlags;		// 042
		CellState						 cellState;			// 044
		bool							 autoWaterLoaded;	// 045
		bool							 cellDetached;		// 046
		UInt8							 pad047;			// 047
		ExtraDataList					 extraList;			// 048
		CellData						 cellData;			// 060 - XCLL if interior, XCLC if exterior
		TESObjectLAND*					 cellLand;			// 068
		float							 waterHeight;		// 070 - XCLW
		NavMeshArray*					 navMeshes;			// 078
		BSTSet<NiPointer<TESObjectREFR>> references;		// 080
		TESForm*						 unk0B0;			// 0B0 - REFR owner of cell?
		BSTArray<TESObjectREFR*>		 objectList;		// 0B8 - persistent
		BSTArray<void*>					 unk0D0;			// 0D0
		BSTArray<void*>					 unk0E8;			// 0E8
		BSTArray<void*>					 unk100;			// 100
		mutable BSSpinLock				 spinLock;			// 118
		TESWorldSpace*					 worldSpace;		// 120
		LOADED_CELL_DATA*				 loadedData;		// 128
		BGSLightingTemplate*			 lightingTemplate;	// 130 - LTMP
		UInt64							 unk138;			// 138
	};
	STATIC_ASSERT(sizeof(TESObjectCELL) == 0x140);
}
