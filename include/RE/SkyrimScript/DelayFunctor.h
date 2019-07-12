#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__DelayFunctor

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace BSScript
	{
		class BSScriptVariable;
	}


	namespace SkyrimScript
	{
		class DelayFunctor : public BSIntrusiveRefCounted
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__DelayFunctor;


			virtual ~DelayFunctor();																// 00

			// add
			virtual RE::BSScript::BSScriptVariable&	Run(BSScript::BSScriptVariable& a_result) = 0;	// 01
			virtual void							Unk_02(void) = 0;								// 02
			virtual void							Unk_03(void);									// 03 - { return 0; }
			virtual void							Unk_04(void);									// 04
			virtual void							Unk_05(void) = 0;								// 05
			virtual void							Unk_06(void);									// 06


			// members
			UInt32 stackID;	// 0C
		};
		STATIC_ASSERT(sizeof(DelayFunctor) == 0x10);
	}
}
