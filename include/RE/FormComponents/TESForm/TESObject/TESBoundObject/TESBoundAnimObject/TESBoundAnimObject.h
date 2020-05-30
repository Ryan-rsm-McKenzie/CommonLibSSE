#pragma once

#include "RE/TESBoundObject.h"


namespace RE
{
	class TESBoundAnimObject : public TESBoundObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESBoundAnimObject;


		virtual ~TESBoundAnimObject();	// 00

		// override (TESBoundObject)
		virtual bool IsBoundAnimObject() override;				// 3C - { return true; }
		virtual bool ReplaceModel(const char* a_str) override;	// 4B
	};
	STATIC_ASSERT(sizeof(TESBoundAnimObject) == 0x30);
}
