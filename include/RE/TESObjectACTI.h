#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectACTI

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSOpenCloseForm.h"  // BGSOpenCloseForm
#include "RE/FormTypes.h"  // FormType, BGSSoundDescriptorForm, TESWaterForm
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESMagicTargetForm.h"  // TESMagicTargetForm
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap


namespace RE
{
	class TESObjectACTI :
		public TESBoundAnimObject,			// 00
		public TESFullName,					// 30
		public TESModelTextureSwap,			// 40
		public TESMagicTargetForm,			// A8
		public BGSDestructibleObjectForm,	// 78
		public BGSOpenCloseForm,			// 88
		public BGSKeywordForm				// 90
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectACTI;


		enum { kTypeID = FormType::Activator };


		enum class Flag : UInt16
		{
			kNone = 0,
			kNoDisplacement = 1 << 0,
			kIgnoredBySandbox = 1 << 1
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


		virtual ~TESObjectACTI();																																			// 00

		// override (TESBoundAnimObject)
		virtual void			InitDefaults() override;																													// 04
		virtual void			ReleaseManagedData() override;																												// 05
		virtual bool			LoadForm(TESFile* a_mod) override;																											// 06
		virtual void			SaveBuffer(BGSSaveFormBuffer* a_buf) override;																								// 0E
		virtual void			LoadBuffer(BGSLoadFormBuffer* a_buf) override;																								// 0F
		virtual void			InitItem() override;																														// 13
		virtual bool			IgnoredBySandbox() const;																													// 22 - { return (flags >> 1) & 1; }
		virtual bool			IsWaterActivator() override;																												// 2A - { return waterType != 0; }
		virtual bool			ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual TESWaterForm*	GetWaterActivator();																														// 3D - { return waterType; }
		virtual bool			GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																			// 4C
		virtual void			Unk_4D(void) override;																														// 4D


		// members
		BGSSoundDescriptorForm*	soundLooping;		// A8 - SNAM
		BGSSoundDescriptorForm*	soundActivation;	// B0 - VNAM
		TESWaterForm*			waterType;			// B8 - WNAM
		Flag					flags;				// C0 - FNAM
		UInt16					padC2;				// C2
		UInt32					padC4;				// C4
	};
	STATIC_ASSERT(sizeof(TESObjectACTI) == 0xC8);
}
