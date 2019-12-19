#pragma once

#include "RE/BSScript/Type.h"
#include "RE/BSFixedString.h"
#include "RE/MemoryManager.h"


namespace RE
{
	namespace BSScript
	{
		struct VariableInfo
		{
			struct Variable
			{
				// members
				BSFixedString	name;	// 00
				Type			type;	// 08
			};
			STATIC_ASSERT(sizeof(Variable) == 0x10);


			explicit VariableInfo(UInt16 a_numParams, UInt16 a_numLocals);


			// members
			SimpleArray<Variable>	variables;	// 00
			UInt16					numParams;	// 08
			UInt16					numVars;	// 0A
			UInt32					pad0C;		// 0C
		};
		STATIC_ASSERT(sizeof(VariableInfo) == 0x10);
	}
}
