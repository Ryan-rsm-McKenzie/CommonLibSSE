#pragma once

#include "RE/TESModel.h"


namespace RE
{
	class BGSTextureModel : public TESModel
	{
	public:
		inline static const void* RTTI = RTTI_BGSTextureModel;


		virtual ~BGSTextureModel();										// 00

		// override (TESModel)
		virtual void SetModelName(const char* a_modelName) override;	// 05
	};
	STATIC_ASSERT(sizeof(BGSTextureModel) == 0x28);
}
