#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class BGSShaderParticleGeometryData : public TESForm
	{
	public:
		enum { kTypeID = FormType::SPGD };


		union Data
		{
			float	f;
			UInt32	i;
		};


		virtual ~BGSShaderParticleGeometryData();			// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		BSTArray<Data>	data;		// 20 - DATA
		TESTexture		texture;	// 38
	};
	STATIC_ASSERT(sizeof(BGSShaderParticleGeometryData) == 0x48);
}
