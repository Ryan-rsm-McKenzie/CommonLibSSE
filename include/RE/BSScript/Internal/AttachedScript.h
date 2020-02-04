#pragma once

#include "RE/BSScript/Object.h"
#include "RE/BSTPointerAndFlags.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class AttachedScript : public BSTPointerAndFlags<BSTSmartPointer<Object>, 1>
			{
			public:
			};
			STATIC_ASSERT(sizeof(AttachedScript) == 0x8);
		}
	}
}
