#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/C/Color.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSCollisionLayer :
		public TESForm,        // 00
		public TESDescription  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSCollisionLayer;
		inline static constexpr auto VTABLE = VTABLE_BGSCollisionLayer;
		inline static constexpr auto FORMTYPE = FormType::CollisionLayer;

		enum class FLAG  // GNAM
		{
			kNone = 0,
			kTriggerVolume = 1 << 0,
			kSensor = 1 << 1,
			kNavmeshObstacle = 1 << 2
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSCollisionLayer() override;  // 00

		// override (TESForm)
		void ClearData() override;            // 05
		bool Load(TESFile* a_mod) override;   // 06
		void InitItemImpl() override;         // 13
		void SetDelete(bool a_set) override;  // 23 - { TESForm::SetDelete(a_set); }

		// members
		std::uint32_t                         collisionIdx;  // 30 - BNAM
		Color                                 debugColor;    // 34 - FNAM
		stl::enumeration<FLAG, std::uint32_t> flags;         // 38 - GNAM
		std::uint32_t                         pad3C;         // 3C
		BSFixedString                         name;          // 40 - MNAM
		BSTArray<BGSCollisionLayer*>          collidesWith;  // 48 - CNAM
	};
	static_assert(sizeof(BGSCollisionLayer) == 0x60);
}
