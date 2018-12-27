#pragma once

#include "RE/Actor.h"  // Actor


namespace RE
{
	class Character : public Actor
	{
	public:
		enum { kTypeID = FormType::Character };

		// add
		virtual void	Unk_128(void);	// 128
		virtual void	Unk_129(void);	// 129
	};
	STATIC_ASSERT(sizeof(Character) == 0x2B0);
}
