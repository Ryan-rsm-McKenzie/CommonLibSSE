#pragma once

#include "RE/B/BSTPointerAndFlags.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/O/Object.h"

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
