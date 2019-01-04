#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class TESModel : public BaseFormComponent
	{
	public:
		struct TextureFileHash	// MODT
		{
			UInt32	fileNameHash;	// 0
			char	fileExt[4];		// 4
			UInt32	dirHash;		// 8
		};
		STATIC_ASSERT(sizeof(TextureFileHash) == 0xC);


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
		virtual void		Unk_06(void);										// 06


		// members
		BSFixedString		modelName;				// 08 - MODL
		TextureFileHash**	textureFileHashes;		// 10 - MODT - ptr to array of ptrs
		ExtraHash*			extraHashes;			// 18
		UInt16				numTextureFileHashes;	// 20
		UInt16				numExtraHashes;			// 22
		UInt32				pad24;					// 24
	};
	STATIC_ASSERT(sizeof(TESModel) == 0x28);
}
