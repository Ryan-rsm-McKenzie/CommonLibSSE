#pragma once

#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class NiTransform
	{
	public:
		NiMatrix3 rotate;	  // 00
		NiPoint3  translate;  // 24
		float	  scale;	  // 30
	};
	static_assert(sizeof(NiTransform) == 0x34);
}
