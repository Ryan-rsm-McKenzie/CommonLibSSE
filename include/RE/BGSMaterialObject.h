#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMaterialObject

#include "RE/BSMaterialObject.h"  // BSMaterialObject
#include "RE/BSString.h"  // BSString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESModel.h"  // TESModel


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


		virtual ~BGSMaterialObject();						// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06


		// members
		BSTArray<BSString> propertyData;	// A0 - DNAM
	};
	STATIC_ASSERT(sizeof(BGSMaterialObject) == 0xB8);
}
