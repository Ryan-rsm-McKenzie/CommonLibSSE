#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IObjectProcessor


namespace RE
{
	class BSFixedString;


	namespace BSScript
	{
		struct ILoader;


		class IObjectProcessor
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IObjectProcessor;


			virtual ~IObjectProcessor();											// 00

			// add
			virtual IObjectProcessor*	Duplicate() = 0;							// 01
			virtual void				SetLoader(ILoader* a_loader) = 0;			// 02
			virtual bool				Link(const BSFixedString& a_className) = 0;	// 03
		};
		STATIC_ASSERT(sizeof(IObjectProcessor) == 0x8);
	}
}
