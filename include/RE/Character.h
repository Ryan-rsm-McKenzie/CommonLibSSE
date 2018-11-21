#pragma once

#include "RE/Actor.h"  // Actor


namespace RE
{
	class Character : public Actor
	{
	public:
		enum { kTypeID = kFormType_Character };
	};
}
