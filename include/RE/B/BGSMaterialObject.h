#pragma once

#include "RE/BSCore/BSString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/Components/BSMaterialObject.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/FormComponents/TESModel/TESModel.h"


namespace RE
{
	class BGSMaterialObject :
		public TESForm,			 // 00
		public TESModel,		 // 20
		public BSMaterialObject	 // 48
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMaterialObject;
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
			char*		  buffer;	   // 00
			std::uint32_t bufferSize;  // 08
			std::uint32_t pad0C;	   // 0C
		};
		static_assert(sizeof(FILE_DATA) == 0x10);


		virtual ~BGSMaterialObject();  // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06

		// override (BSMaterialObject)
		virtual void EnsureLoaded() override;  // 01


		// members
		BSTArray<FILE_DATA> fileData;  // A0 - DNAM
	};
	static_assert(sizeof(BGSMaterialObject) == 0xB8);
}
