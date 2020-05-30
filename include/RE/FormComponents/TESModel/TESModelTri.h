#pragma once

#include "RE/TESModel.h"


namespace RE
{
	class TESModelTri : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelTri;


		virtual ~TESModelTri();	 // 00

		// override (TESModel)
		virtual void SetModel(const char* a_model) override;  // 05
	};
	STATIC_ASSERT(sizeof(TESModelTri) == 0x28);
}
