#pragma once

#include "skse64/NiObjects.h"  // NiObject

#include "RE/BSFixedString.h"  // BSFixedString

namespace RE
{
	class NiControllerSequence : public NiObject
	{
	public:
		virtual bool				Unk_21(UInt32 arg1, UInt32 arg2);

		const BSFixedString&		GetName() const;

		// members
		BSFixedString	name;	// 10
	};
}
