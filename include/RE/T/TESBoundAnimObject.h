#pragma once

#include "RE/T/TESBoundObject.h"

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
	static_assert(sizeof(TESBoundAnimObject) == 0x30);
}
