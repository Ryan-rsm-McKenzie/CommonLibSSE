#pragma once

#include "RE/BSMaterialObject.h"
#include "RE/BSString.h"
#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESModel.h"


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
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct FILE_DATA
		{
			char*  buffer;		// 00
			UInt32 bufferSize;	// 08
			UInt32 pad0C;		// 0C
		};
		STATIC_ASSERT(sizeof(FILE_DATA) == 0x10);


		virtual ~BGSMaterialObject();  // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06

		// override (BSMaterialObject)
		virtual void EnsureLoaded() override;  // 01


		// members
		BSTArray<FILE_DATA> fileData;  // A0 - DNAM
	};
	STATIC_ASSERT(sizeof(BGSMaterialObject) == 0xB8);
}
