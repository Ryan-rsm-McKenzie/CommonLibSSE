#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/BSFixedString.h"
#include "RE/FileHash.h"


namespace RE
{
	class TESModel : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESModel;


		struct ExtraHash
		{
			UInt32 hash;
		};
		STATIC_ASSERT(sizeof(ExtraHash) == 0x4);


		virtual ~TESModel();													// 00

		// override (BaseFormComponent)
		virtual void		Init() override;									// 01
		virtual void		ReleaseRefs() override;								// 02
		virtual void		CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual const char*	GetModelName() const;								// 04 - { return modelName.c_str(); }
		virtual void		SetModelName(const char* a_modelName);				// 05 - { modelName = name; }
		virtual void		Unk_06(void);										// 06 - { return 0; } - set file name?


		// members
		BSFixedString	modelName;		// 08 - MODL
		FileHash**		fileHashes;		// 10 - MODT
		ExtraHash*		extraHashes;	// 18
		UInt16			numFileHashes;	// 20
		UInt16			numExtraHashes;	// 22
		UInt32			unk24;			// 24
	};
	STATIC_ASSERT(sizeof(TESModel) == 0x28);
}
