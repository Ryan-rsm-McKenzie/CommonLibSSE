#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // TESObjectREFR


namespace RE
{
	struct BSAnimationGraphEvent
	{
		BSFixedString	animName;
		TESObjectREFR*	akTarget;
		BSFixedString	optionalStr;
	};
}
