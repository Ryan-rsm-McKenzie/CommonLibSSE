#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectDOOR

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSOpenCloseForm.h"  // BGSOpenCloseForm
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap


namespace RE
{
	class TESObjectDOOR :
		public TESBoundAnimObject,			// 00
		public TESFullName,					// 30
		public TESModelTextureSwap,			// 40
		public BGSDestructibleObjectForm,	// 78
		public BGSOpenCloseForm				// 88
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectDOOR;


		enum { kTypeID = FormType::Door };


		enum class Flag : UInt8
		{
			kNone = 0,
			kAutomatic = 1 << 1,
			kHidden = 1 << 2,
			kMinimalUse = 1 << 3,
			kSliding = 1 << 4,
			kDoNotOpenInCombatSearch = 1 << 5
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kIsMarker = 1 << 23
			};
		};


		virtual ~TESObjectDOOR();																																	// 00

		// override (TESBoundAnimObject)
		virtual void	InitDefaults() override;																													// 04
		virtual void	ReleaseManagedData() override;																												// 05
		virtual bool	LoadForm(TESFile* a_mod) override;																											// 06
		virtual void	InitItem() override;																														// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void	Unk_4A(void) override;																														// 4A
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																			// 4C
		virtual void	Unk_4D(void) override;																														// 4D


		// members
		UInt64					unk90;		// 90
		BGSSoundDescriptorForm*	openSound;	// 98 - SNAM
		BGSSoundDescriptorForm*	closeSound;	// A0 - ANAM
		BGSSoundDescriptorForm*	loopSound;	// A8 - BNAM
		Flag					flags;		// B0 - FNAM
		UInt8					unkB1;		// B1
		UInt16					unkB2;		// B2
		UInt32					unkB4;		// B4
		UInt64					unkB8;		// B8
		UInt64					unkC0;		// C0
		UInt64					unkC8;		// C8
	};
	STATIC_ASSERT(sizeof(TESObjectDOOR) == 0xD0);
}
