#pragma once

#include "RE/BSScript/BSScriptType.h"  // BSScriptType
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace BSScript
	{
		class BSScriptType;
		class IFunction;


		class BSScriptClass : public BSIntrusiveRefCounted
		{
		public:
			~BSScriptClass();

			const char*	GetName() const;
			UInt32		GetNumVariables() const;
			UInt32		GetNumMemberFunctions() const;
			UInt32		GetNumGlobalFunctions() const;
			VMTypeID	GetTypeID() const;
			SInt32		GetVariableIndex(const BSFixedString& a_name) const;
			IFunction*	GetFunction(const char* a_name) const;


			// members
			UInt32			unk04;					// 04
			const char*		name;					// 08
			BSScriptClass*	parent;					// 10
			BSFixedString	unk18;					// 18

			UInt32 			flags : 2;				// 20 - 00
			UInt32			numScriptFlags : 6;		// 20 - 02
			UInt32			numVariables : 10;		// 21 - 00
			UInt32			unk12_02 : 14;			// 22 - 02
			UInt32			numDefaultValues : 10;	// 24 - 00
			UInt32			numProperties : 10;		// 25 - 02
			UInt32			numGlobalFuncs : 9;		// 26 - 04
			UInt32			unk17_05 : 3;			// 27 - 05
			UInt32			numMemberFuncs : 9;		// 28 - 00
			UInt32			unk29_01 : 17;			// 29 - 01

			UInt32			pad2C;					// 2C
			void*			dataPtr;				// 30

		private:
			void Dtor();
		};
		STATIC_ASSERT(sizeof(BSScriptClass) == 0x38);
	}
}
