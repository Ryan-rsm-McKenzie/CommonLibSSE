#pragma once

#include "RE/Actor.h"  // Actor


namespace RE
{
	class Character : public Actor
	{
	public:
		enum { kTypeID = FormType::Character };

		// add
		virtual void	Unk_129(void);	// 129
		virtual void	Unk_12A(void);	// 12A
	};
	STATIC_ASSERT(sizeof(Character) == 0x2B0);
}
