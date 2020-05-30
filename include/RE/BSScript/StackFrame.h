#pragma once

#include "RE/BSScript/Variable.h"
#include "RE/BSCore/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class IFunction;
		class ObjectTypeInfo;
		class Stack;


		class StackFrame
		{
		public:
			UInt32	  GetPageForFrame() const;
			Variable& GetStackFrameVariable(UInt32 a_index, UInt32 a_pageHint) const;


			// members
			Stack*							parent;				 // 00
			StackFrame*						previousFrame;		 // 08
			BSTSmartPointer<IFunction>		owningFunction;		 // 10
			BSTSmartPointer<ObjectTypeInfo> owningObjectType;	 // 18
			UInt32							instructionPointer;	 // 20
			UInt32							pad24;				 // 24
			Variable						self;				 // 28
			UInt32							size;				 // 38
			bool							instructionsValid;	 // 3C
			UInt8							pad3D;				 // 3D
			UInt16							pad3E;				 // 3E

			//Variable args[4];	40 - minimum space for 4 args is allocated
		};
		STATIC_ASSERT(sizeof(StackFrame) == 0x40);	// frames can be larger
	}
}
