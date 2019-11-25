#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"


namespace RE
{
	struct BSAnimationGraphEvent
	{
		BSFixedString	animName;
		TESObjectREFR*	akTarget;
		BSFixedString	optionalStr;
	};
}
