#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundAnimObject.h"

namespace RE
{
	class TESSound : public TESBoundAnimObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESSound;
		inline static constexpr auto VTABLE = VTABLE_TESSound;
		inline static constexpr auto FORMTYPE = FormType::Sound;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~TESSound() override;  // 00

		// override (TESBoundAnimObject)
		void        InitializeData() override;                    // 04
		bool        Load(TESFile* a_mod) override;                // 06
		void        InitItemImpl() override;                      // 13
		bool        SetFormEditorID(const char* a_str) override;  // 33
		void        UnClone3D(TESObjectREFR* a_ref) override;     // 41
		NiAVObject* Clone3D(TESObjectREFR* a_ref) override;       // 4A - { return 0; }

		// members
		BGSSoundDescriptorForm* descriptor;  // 30 - SDSC
	};
	static_assert(sizeof(TESSound) == 0x38);
}
