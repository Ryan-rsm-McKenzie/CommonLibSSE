#pragma once

#include "RE/Actor.h"  // Actor


namespace RE
{
	class Character : public Actor
	{
	public:
		enum { kTypeID = FormType::ActorCharacter };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kStartsDead = 1 << 9,
				kPersistent = 1 << 10,
				kInitiallyDisabled = 1 << 11,
				kIgnored = 1 << 12,
				kNoAIAcquire = 1 << 25,
				kDontHavokSettle = 1 << 29
			};
		};


		virtual ~Character();			// 000

		// add
		virtual void	Unk_128(void);	// 128
		virtual void	Unk_129(void);	// 129
	};
	STATIC_ASSERT(sizeof(Character) == 0x2B0);
}
