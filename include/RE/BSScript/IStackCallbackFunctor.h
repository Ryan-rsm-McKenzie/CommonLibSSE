#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IStackCallbackFunctor

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace BSScript
	{
		class Variable;


		class IStackCallbackFunctor : public BSIntrusiveRefCounted
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IStackCallbackFunctor;


			IStackCallbackFunctor();
			virtual ~IStackCallbackFunctor() = default;			// 00

			// add
			virtual void	SetResult(Variable* a_result) = 0;	// 01
			virtual bool	CanBeSaved();						// 02 - { return false; }
			virtual void	Unk_03(void) = 0;					// 03


			// members
			UInt32 unk0C;	// 0C
		};
		STATIC_ASSERT(sizeof(IStackCallbackFunctor) == 0x10);
	}
}
