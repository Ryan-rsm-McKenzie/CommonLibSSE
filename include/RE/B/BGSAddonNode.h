#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESModelTextureSwap.h"

namespace RE
{
	struct ADDON_DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kAlwaysLoaded = 3
		};

		// members
		std::uint16_t                        masterParticleCap;  // 0
		stl::enumeration<Flag, std::uint8_t> flags;              // 2
		std::uint8_t                         pad3;               // 3
	};
	static_assert(sizeof(ADDON_DATA) == 0x4);

	class BGSAddonNode :
		public TESBoundObject,      // 00
		public TESModelTextureSwap  // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAddonNode;
		inline static constexpr auto VTABLE = VTABLE_BGSAddonNode;
		inline static constexpr auto FORMTYPE = FormType::AddonNode;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSAddonNode() override;  // 00

		// override (TESBoundObject)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		std::uint32_t           index;  // 68 - DATA
		std::uint32_t           pad6C;  // 6C
		BGSSoundDescriptorForm* sound;  // 70 - SNAM
		ADDON_DATA              data;   // 78 - DNAM
		std::uint32_t           pad7C;  // 7C
	};
	static_assert(sizeof(BGSAddonNode) == 0x80);
}
