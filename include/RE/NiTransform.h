#pragma once

#include "RE/NiMatrix3.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class NiTransform
	{
	public:
		NiMatrix3 rotate;	  // 00
		NiPoint3  translate;  // 24
		float	  scale;	  // 30
	};
	STATIC_ASSERT(sizeof(NiTransform) == 0x34);
}
