#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/BSFixedString.h"


namespace RE
{
	namespace BSResource
	{
		struct ID;
	}


	class TESModel : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESModel;


		virtual ~TESModel();													// 00

		// override (BaseFormComponent)
		virtual void		InitializeDataComponent() override;					// 01
		virtual void		ClearDataComponent() override;						// 02
		virtual void		CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual const char*	GetModelName() const;								// 04 - { return modelName.c_str(); }
		virtual void		SetModelName(const char* a_modelName);				// 05 - { modelName = name; }
		virtual void		Unk_06(void);										// 06 - { return 0; } - set file name?


		// members
		BSFixedString	model;			// 08 - MODL
		BSResource::ID*	textures;		// 10 - MODT
		UInt32*			addons;			// 18
		UInt16			numTextures;	// 20
		UInt16			numAddons;		// 22
		UInt32			pad24;			// 24
	};
	STATIC_ASSERT(sizeof(TESModel) == 0x28);
}
