#pragma once

#include "RE/BSCore/BSTPointerAndFlags.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSScript/Object.h"


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
			static_assert(sizeof(AttachedScript) == 0x8);
		}
	}
}
