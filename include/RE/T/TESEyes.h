#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class TESEyes :
		public TESForm,      // 00
		public TESFullName,  // 20
		public TESTexture    // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESEyes;
		inline static constexpr auto VTABLE = VTABLE_TESEyes;
		inline static constexpr auto FORMTYPE = FormType::Eyes;

		enum class Flag
		{
			kNone = 0,
			kPlayable = 1 << 0,
			kNotMale = 1 << 1,
			kNotFemale = 1 << 2
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~TESEyes() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04 - { flags = 0; }
		bool Load(TESFile* a_mod) override;  // 06 - { return true; }

		// members
		stl::enumeration<Flag, std::uint8_t> flags;  // 40 - DATA
		std::uint8_t                         pad41;  // 41
		std::uint16_t                        pad42;  // 42
		std::uint32_t                        pad44;  // 44
	};
	static_assert(sizeof(TESEyes) == 0x48);
}
