#pragma once

#include "RE/BGSPreloadable.h"
#include "RE/BSTArray.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	namespace BSResource
	{
		struct ID;
	}


	struct BGSDebrisData
	{
		enum class BGSDebrisDataFlags : UInt8
		{
			kNone = 0,
			kCollisionData = 1 << 0
		};


		SInt8					 percentage;  // 00 - DATA~
		BGSDebrisDataFlags		 flags;		  // 01 - ~DATA
		UInt16					 pad02;		  // 02
		UInt32					 pad04;		  // 04
		const char*				 fileName;	  // 08
		BSTArray<BSResource::ID> textureIDs;  // 10 - MODT
		BSTArray<UInt32>		 addons;	  // 28
	};
	STATIC_ASSERT(sizeof(BGSDebrisData) == 0x40);


	class BGSDebris :
		public TESForm,		   // 00
		public BGSPreloadable  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDebris;
		inline static constexpr auto FORMTYPE = FormType::Debris;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSDebris();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04 - { return; }
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06


		// members
		BSSimpleList<BGSDebrisData*> data;	// 28
	};
	STATIC_ASSERT(sizeof(BGSDebris) == 0x38);
}
