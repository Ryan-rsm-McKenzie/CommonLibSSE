#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint3.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESProduceForm.h"

namespace RE
{
	struct OBJ_TREE  // CNAM
	{
		float trunkFlexibility;   // 00
		float branchFlexibility;  // 04
		float trunkAmplitude;     // 08
		float frontAmplitude;     // 0C
		float backAmplitude;      // 10
		float sideAmplitude;      // 14
		float frontFrequency;     // 18
		float backFrequency;      // 1C
		float sideFrequency;      // 20
		float leafFlexibility;    // 24
		float leafAmplitude;      // 28
		float leafFrequency;      // 2C
	};
	static_assert(sizeof(OBJ_TREE) == 0x30);

	struct BoneData
	{
		NiMatrix3     localBoneRotation;             // 00
		NiPoint3      worldBoneDir;                  // 24
		std::uint32_t parentWorldBoneRotationIndex;  // 30
	};
	static_assert(sizeof(BoneData) == 0x34);

	struct BaseTreeData : public BSIntrusiveRefCounted
	{
		std::uint32_t       pad04;                     // 04
		BSTArray<BoneData>  branchBoneData;            // 08
		BSTArray<NiMatrix3> parentWorldBoneRotations;  // 20
	};
	static_assert(sizeof(BaseTreeData) == 0x38);

	class TESObjectTREE :
		public TESBoundObject,  // 00
		public TESModel,        // 30
		public TESFullName,     // 58
		public TESProduceForm   // 68
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectTREE;
		inline static constexpr auto VTABLE = VTABLE_TESObjectTREE;
		inline static constexpr auto FORMTYPE = FormType::Tree;

		enum class etTreeType
		{
			kShortAndThin = 0,
			kShortAndThick = 1,
			kTallAndThin = 2,
			kTallAndThick = 3
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15
			};
		};

		~TESObjectTREE() override;  // 00

		// override (TESBoundObject)
		void InitializeData() override;                                                                                                                                // 04
		bool Load(TESFile* a_mod) override;                                                                                                                            // 06
		void InitItemImpl() override;                                                                                                                                  // 13
		bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		bool ReplaceModel() override;                                                                                                                                  // 44
		bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;                                                                                    // 4C
		void OnRemove3D(NiAVObject* a_obj3D) override;                                                                                                                 // 4F
		void OnCheckModels() override;                                                                                                                                 // 50 - { return; }
		void OnCopyReference() override;                                                                                                                               // 51 - { return; }
		void OnFinishScale() override;                                                                                                                                 // 52 - { return; }

		// members
		OBJ_TREE                                    data;      // 88
		BaseTreeData*                               baseData;  // B8
		stl::enumeration<etTreeType, std::uint32_t> type;      // C0
		std::uint32_t                               padC4;     // C4
	};
	static_assert(sizeof(TESObjectTREE) == 0xC8);
}
