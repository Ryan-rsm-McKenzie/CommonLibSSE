#pragma once

#include "RE/B/BSMaterialObject.h"
#include "RE/B/BSString.h"
#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class BGSMaterialObject :
		public TESForm,          // 00
		public TESModel,         // 20
		public BSMaterialObject  // 48
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMaterialObject;
		inline static constexpr auto VTABLE = VTABLE_BGSMaterialObject;
		inline static constexpr auto FORMTYPE = FormType::MaterialObject;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct FILE_DATA
		{
			char*         buffer;      // 00
			std::uint32_t bufferSize;  // 08
			std::uint32_t pad0C;       // 0C
		};
		static_assert(sizeof(FILE_DATA) == 0x10);

		~BGSMaterialObject() override;  // 00

		// override (TESForm)
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06

		// override (BSMaterialObject)
		void EnsureLoaded() override;  // 01

		// members
		BSTArray<FILE_DATA> fileData;  // A0 - DNAM
	};
	static_assert(sizeof(BGSMaterialObject) == 0xB8);
}
