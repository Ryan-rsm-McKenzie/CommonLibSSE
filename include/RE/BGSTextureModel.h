#pragma once

#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSTextureModel : public TESModel
	{
	public:
		virtual ~BGSTextureModel();										// 00

		// override (TESModel)
		virtual void SetModelName(const char* a_modelName) override;	// 05
	};
	STATIC_ASSERT(sizeof(BGSTextureModel) == 0x28);
}
