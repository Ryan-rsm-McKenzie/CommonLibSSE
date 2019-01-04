#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class BSShader;


	class TESModel : public BaseFormComponent
	{
	public:
		struct TextureFileHash	// MODT
		{
			enum
			{
				kTotal = 3
			};


			UInt32 hash[kTotal];	// 0
		};
		STATIC_ASSERT(sizeof(TextureFileHash) == 0xC);


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
		BSFixedString		modelFileName;			// 08 - MODL
		TextureFileHash**	textureFileHashes;		// 10 - MODT
		void*				unk18;					// 18
		UInt16				textureFileHashesSize;	// 20
		UInt16				unk22;					// 22
		UInt32				pad24;					// 24
	};
	STATIC_ASSERT(sizeof(TESModel) == 0x28);
}
