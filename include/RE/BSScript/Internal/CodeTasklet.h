#pragma once

#include "RE/BSScript/Internal/IFuncCallQuery.h"  // BSScript::Internal::IFuncCallQuery


namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class Stack;


		namespace Internal
		{
			class VirtualMachine;


			class CodeTasklet : public IFuncCallQuery
			{
			public:
				virtual ~CodeTasklet();				// 00

				// override (IFuncCallQuery)
				virtual void Unk_01(void) override;	// 01


				// members
				Stack*			stack;			// 10
				VirtualMachine*	virtualMachine;	// 18
				ErrorLogger*	errorLogger;	// 20
				UInt32			unk28;			// 28
				UInt32			pad2C;			// 2C
				UInt64			unk30;			// 30
				UInt64			unk38;			// 38
				UInt64			unk40;			// 40
				UInt64			unk48;			// 48
			};
			STATIC_ASSERT(sizeof(CodeTasklet) == 0x50);
		}
	}
}
