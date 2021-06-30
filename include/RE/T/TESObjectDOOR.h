#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModelTextureSwap.h"

namespace RE
{
	class TESObjectDOOR :
		public TESBoundAnimObject,         // 00
		public TESFullName,                // 30
		public TESModelTextureSwap,        // 40
		public BGSDestructibleObjectForm,  // 78
		public BGSOpenCloseForm            // 88
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectDOOR;
		inline static constexpr auto FORMTYPE = FormType::Door;

		enum class Flag
		{
			kNone = 0,
			kAutomatic = 1 << 1,
			kHidden = 1 << 2,
			kMinimalUse = 1 << 3,
			kSliding = 1 << 4,
			kDoNotOpenInCombatSearch = 1 << 5
		};

		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kTeleportExtra = 1 << 17
			};
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kIsMarker = 1 << 23
			};
		};

		~TESObjectDOOR() override;  // 00

		// override (TESBoundAnimObject)
		void        InitializeData() override;                                                                                                                                // 04
		void        ClearData() override;                                                                                                                                     // 05
		bool        Load(TESFile* a_mod) override;                                                                                                                            // 06
		void        InitItemImpl() override;                                                                                                                                  // 13
		bool        Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		NiAVObject* Clone3D(TESObjectREFR* a_ref) override;                                                                                                                   // 4A
		bool        GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;                                                                                    // 4C
		bool        CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;                                                    // 4D

		// override (BGSOpenCloseForm)
		void HandleOpen(TESObjectREFR* a_target, TESObjectREFR* a_activator) override;  // 01

		// members
		std::uint64_t                        unk90;            // 90
		BGSSoundDescriptorForm*              openSound;        // 98 - SNAM
		BGSSoundDescriptorForm*              closeSound;       // A0 - ANAM
		BGSSoundDescriptorForm*              loopSound;        // A8 - BNAM
		stl::enumeration<Flag, std::uint8_t> flags;            // B0 - FNAM
		std::uint8_t                         padB1;            // B1
		std::uint16_t                        padB2;            // B2
		std::uint32_t                        padB4;            // B4
		BSTArray<TESForm*>                   randomTeleports;  // B8
	};
	static_assert(sizeof(TESObjectDOOR) == 0xD0);
}
