#pragma once

#include "RE/TESModel.h"


namespace RE
{
	class BGSTextureModel : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSTextureModel;


		virtual ~BGSTextureModel();	 // 00

		// override (TESModel)
		virtual void SetModel(const char* a_model) override;  // 05
	};
	STATIC_ASSERT(sizeof(BGSTextureModel) == 0x28);
}
