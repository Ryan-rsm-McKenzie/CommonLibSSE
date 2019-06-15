#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSDebris

#include "RE/BGSPreloadable.h"  // BGSPreloadable
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FileHash.h"  // FileHash
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSDebris :
		public TESForm,			// 00
		public BGSPreloadable	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSDebris;


		enum { kTypeID = FormType::Debris };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Model
		{
			struct Data	// DATA
			{
				enum class Flag : UInt8
				{
					kNone = 0,
					kHasCollisionData = 1 << 0
				};


				UInt8	percentage;	// 0
				Flag	flags;		// 1
				UInt16	pad2;		// 2
				UInt32	pad4;		// 4
			};
			STATIC_ASSERT(sizeof(Data) == 0x8);


			Data				data;				// 00 - DATA
			const char*			modelFileName;		// 10
			BSTArray<FileHash*>	textureFileHashes;	// 18 - MODT
		};
		STATIC_ASSERT(sizeof(Model) == 0x28);


		virtual ~BGSDebris();								// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04 - { return; }
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06


		// members
		BSSimpleList<Model*> models;	// 28
	};
	STATIC_ASSERT(sizeof(BGSDebris) == 0x38);
}
