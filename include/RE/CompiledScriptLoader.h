#pragma once

#include "RE/ILoader.h"  // BSScript::ILoader


namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class IStore;


		class CompiledScriptLoader : public ILoader
		{
		public:
			virtual ~CompiledScriptLoader();	// 00


			// members
			ErrorLogger*	errorLogger;	// 08
			IStore*			store;	// 10
			UInt64			unk18;	// 18
			UInt64			unk20;	// 20
			UInt64			unk28;	// 28
		};
		STATIC_ASSERT(sizeof(CompiledScriptLoader) == 0x38);
	}
}
