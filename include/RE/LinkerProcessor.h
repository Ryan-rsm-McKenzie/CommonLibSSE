#pragma once

#include "RE/IObjectProcessor.h"  // BSScript::IObjectProcessor


namespace RE
{
	namespace BSScript
	{
		class CompiledScriptLoader;
		class ErrorLogger;


		namespace Internal
		{
			class VirtualMachine;
		}


		class LinkerProcessor : public IObjectProcessor
		{
		public:
			virtual ~LinkerProcessor();	// 00


			// members
			Internal::VirtualMachine*	virtualMachine;			// 08
			ErrorLogger*				errorLogger;			// 10
			CompiledScriptLoader*		compiledScriptLoader;	// 18
			UInt64						unk20;					// 20
			UInt64						unk28;					// 28
			UInt64						unk30;					// 30
			UInt64						unk38;					// 38
			UInt64						unk40;					// 40
			UInt64						unk48;					// 48
			UInt64						unk50;					// 50
			UInt64						unk58;					// 58
			UInt64						unk60;					// 60
			UInt64						unk68;					// 68
			UInt64						unk70;					// 70
			UInt64						unk78;					// 78
			UInt64						unk80;					// 80
			UInt64						unk88;					// 88
		};
		STATIC_ASSERT(sizeof(LinkerProcessor) == 0x90);
	}
}
