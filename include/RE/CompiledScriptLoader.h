#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__CompiledScriptLoader

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
			inline static const void* RTTI = RTTI_BSScript__CompiledScriptLoader;


			virtual ~CompiledScriptLoader();	// 00


			// members
			ErrorLogger*	errorLogger;	// 08
			IStore*			store;			// 10
			UInt64			unk18;			// 18
			UInt64			unk20;			// 20
			UInt64			unk28;			// 28
			UInt64			unk30;			// 30
		};
		STATIC_ASSERT(sizeof(CompiledScriptLoader) == 0x38);
	}
}
