#pragma once

#include "RE/B/BSISoundDescriptor.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSSoundDescriptor;

	class BGSSoundDescriptorForm :
		public TESForm,            // 00
		public BSISoundDescriptor  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSoundDescriptorForm;
		inline static constexpr auto VTABLE = VTABLE_BGSSoundDescriptorForm;
		inline static constexpr auto FORMTYPE = FormType::SoundRecord;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSSoundDescriptorForm() override;  // 00

		// override (TESForm)
		void ClearData() override;                         // 05
		bool Load(TESFile* a_mod) override;                // 06
		void InitItemImpl() override;                      // 13
		bool SetFormEditorID(const char* a_str) override;  // 33

		// add
		virtual std::uint32_t GetDescriptorType();  // 3B - { return soundDescriptor->GetType(); }

		// members
		BGSSoundDescriptor* soundDescriptor;  // 28
	};
	static_assert(sizeof(BGSSoundDescriptorForm) == 0x30);
}
