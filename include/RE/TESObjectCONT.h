#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSOpenCloseForm.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESContainer.h"
#include "RE/TESFullName.h"
#include "RE/TESMagicCasterForm.h"
#include "RE/TESMagicTargetForm.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	struct CONT_DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kAllowsSoundsWhenAnimation = 1 << 0,
			kRespawn = 1 << 1,
			kShowOwner = 1 << 2
		};


		Flag flags;	 // 0
	};
	STATIC_ASSERT(sizeof(CONT_DATA) == 0x1);


	class TESObjectCONT :
		public TESBoundAnimObject,		   // 00
		public TESContainer,			   // 30
		public TESFullName,				   // 48
		public TESModelTextureSwap,		   // 58
		public TESWeightForm,			   // 90
		public TESMagicCasterForm,		   // B8
		public TESMagicTargetForm,		   // B9
		public BGSDestructibleObjectForm,  // A0
		public BGSOpenCloseForm			   // B0
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectCONT;
		inline static constexpr auto FORMTYPE = FormType::Container;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kObstacle = 1 << 25,
				kNavMeshGeneration_Filter = 1 << 26,
				kNavMeshGeneration_BoundingBox = 1 << 27,
				kNavMeshGeneration_Ground = 1 << 30
			};
		};


		virtual ~TESObjectCONT();  // 00

		// override (TESBoundAnimObject)
		virtual void InitializeData() override;																													  // 04
		virtual bool Load(TESFile* a_mod) override;																												  // 06
		virtual void InitItemImpl() override;																													  // 13
		virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, TESBoundObject* a_object, SInt32 a_targetCount) override;  // 37
		virtual bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;																		  // 4C
		virtual bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;										  // 4D

		// override (BGSOpenCloseForm)
		virtual void HandleOpen(TESObjectREFR* a_target, TESObjectREFR* a_activator) override;	 // 01
		virtual void HandleClose(TESObjectREFR* a_target, TESObjectREFR* a_activator) override;	 // 02


		// members
		CONT_DATA				data;		 // B9 - DATA
		UInt16					padBA;		 // BA
		UInt32					padBC;		 // BC
		BGSSoundDescriptorForm* openSound;	 // C0 - SNAM
		BGSSoundDescriptorForm* closeSound;	 // C8 - QNAM
	};
	STATIC_ASSERT(offsetof(TESObjectCONT, data) == 0xB9);
	STATIC_ASSERT(sizeof(TESObjectCONT) == 0xD0);
}
