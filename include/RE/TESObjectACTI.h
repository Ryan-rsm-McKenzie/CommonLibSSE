#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BGSOpenCloseForm.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESFullName.h"
#include "RE/TESMagicTargetForm.h"
#include "RE/TESModelTextureSwap.h"


namespace RE
{
	class TESObjectACTI :
		public TESBoundAnimObject,		   // 00
		public TESFullName,				   // 30
		public TESModelTextureSwap,		   // 40
		public TESMagicTargetForm,		   // A8
		public BGSDestructibleObjectForm,  // 78
		public BGSOpenCloseForm,		   // 88
		public BGSKeywordForm			   // 90
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectACTI;
		inline static constexpr auto FORMTYPE = FormType::Activator;


		enum class ActiFlags : UInt16
		{
			kNone = 0,
			kNoDisplacement = 1 << 0,
			kIgnoredBySandbox = 1 << 1,
			kIsProceduralWater = 1 << 2,
			kIsLODWater = 1 << 3
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kHasTreeLOD = 1 << 6,
				kMustUpdateAnims = 1 << 8,
				kHiddenFromLocalMap = 1 << 9,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kDangerous = 1 << 17,
				kIgnoresObjectInteraction = 1 << 20,
				kIsMarker = 1 << 23,
				kObstacle = 1 << 25,
				kNavMeshGeneration_Filter = 1 << 26,
				kNavMeshGeneration_BoundingBox = 1 << 27,
				kChildCanUse = 1 << 29,
				kNavMeshGeneration_Ground = 1 << 30
			};
		};


		virtual ~TESObjectACTI();  // 00

		// override (TESBoundAnimObject)
		virtual void		  InitializeData() override;																												   // 04
		virtual void		  ClearData() override;																														   // 05
		virtual bool		  Load(TESFile* a_mod) override;																											   // 06
		virtual void		  SaveGame(BGSSaveFormBuffer* a_buf) override;																								   // 0E
		virtual void		  LoadGame(BGSLoadFormBuffer* a_buf) override;																								   // 0F
		virtual void		  InitItemImpl() override;																													   // 13
		virtual bool		  GetIgnoredBySandbox() const override;																										   // 22 - { return (flags >> 1) & 1; }
		virtual bool		  IsWater() const override;																													   // 2A - { return waterType != 0; }
		virtual bool		  Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, TESBoundObject* a_object, SInt32 a_targetCount) override;  // 37
		virtual TESWaterForm* GetWaterType() const override;																											   // 3D - { return waterType; }
		virtual bool		  GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;																	   // 4C
		virtual bool		  CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;									   // 4D


		// members
		BGSSoundDescriptorForm* soundLoop;		// A8 - SNAM
		BGSSoundDescriptorForm* soundActivate;	// B0 - VNAM
		TESWaterForm*			waterForm;		// B8 - WNAM
		ActiFlags				flags;			// C0 - FNAM
		UInt16					padC2;			// C2
		UInt32					padC4;			// C4
	};
	STATIC_ASSERT(sizeof(TESObjectACTI) == 0xC8);
}
