#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__DelayFunctor

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace BSScript
	{
		class Variable;
	}


	namespace SkyrimScript
	{
		class DelayFunctor : public BSIntrusiveRefCounted
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__DelayFunctor;


			virtual ~DelayFunctor();												// 00

			// add
			virtual RE::BSScript::Variable&	Run(BSScript::Variable& a_result) = 0;	// 01 - probably return by value
			virtual void					Unk_02(void) = 0;						// 02
			virtual void					Unk_03(void);							// 03 - { return 0; }
			virtual void					Unk_04(void);							// 04
			virtual UInt32					GetFactoryType() const = 0;				// 05
			virtual void					Unk_06(void);							// 06


			// members
			UInt32 stackID;	// 0C
		};
		STATIC_ASSERT(sizeof(DelayFunctor) == 0x10);
	}
}
