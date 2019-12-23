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
		public TESForm,			// 00
		public TESModel,		// 20
		public BSMaterialObject	// 48
	{
	public:
		inline static const void* RTTI = RTTI_BGSMaterialObject;


		enum { kTypeID = FormType::MaterialObject };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMaterialObject();					// 00

		// override (TESForm)
		virtual void	ClearData() override;			// 05
		virtual bool	Load(TESFile* a_mod) override;	// 06


		// members
		BSTArray<BSString> propertyData;	// A0 - DNAM
	};
	STATIC_ASSERT(sizeof(BGSMaterialObject) == 0xB8);
}
