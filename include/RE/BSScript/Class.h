#pragma once

#include "RE/BSScript/Type.h"  // BSScript::Type
#include "RE/BSScript/Variable.h"  // BSScript::Variable
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class IFunction;


		class Class : public BSIntrusiveRefCounted
		{
		public:
			struct Function
			{
				// members
				Function*					next;	// 00
				BSTSmartPointer<IFunction>	func;	// 08
			};
			STATIC_ASSERT(sizeof(Function) == 0x10);


			struct ScriptFlag
			{
				enum : std::uintptr_t { kUnkFlag = 1 << 0 };


				BSFixedString GetFlag() const;


				// members
				std::uintptr_t flag;	// 0
			};
			STATIC_ASSERT(sizeof(ScriptFlag) == 0x8);


			struct ScriptVariable
			{
				// members
				BSFixedString	name;	// 00
				VMTypeID		type;	// 08
			};
			STATIC_ASSERT(sizeof(ScriptVariable) == 0x10);


			struct DefaultScriptValue
			{
				// members
				UInt32		varIdx;	// 00
				UInt32		pad04;	// 04
				Variable	value;	// 08
			};
			STATIC_ASSERT(sizeof(DefaultScriptValue) == 0x18);


			struct ScriptProperty
			{
				// members
				BSFixedString							name;		// 00
				BSFixedString							scriptName;	// 08
				BSFixedString							name2;		// 10
				VMTypeID								type;		// 18
				UInt32									unk20;		// 20
				UInt32									unk24;		// 24
				BSTSmartPointer<BSIntrusiveRefCounted>	unk28;		// 28 - virtual
				BSTSmartPointer<BSIntrusiveRefCounted>	unk30;		// 30 - virtual
				UInt32									idx;		// 38
				bool									hidden;		// 38
				UInt8									unk39;		// 39
				UInt16									unk3A;		// 3A
				BSFixedString							unk40;		// 40
			};
			STATIC_ASSERT(sizeof(ScriptProperty) == 0x48);


			struct ScriptGlobalFunc
			{
				// members
				BSTSmartPointer<IFunction> func;	// 00
			};
			STATIC_ASSERT(sizeof(ScriptGlobalFunc) == 0x8);


			struct ScriptMemberFunc
			{
				// members
				BSTSmartPointer<IFunction> func;	// 00
			};
			STATIC_ASSERT(sizeof(ScriptMemberFunc) == 0x8);


			struct ScriptState
			{
				enum : UInt32
				{
					kFuncCountMask = 0x1FF,
					kFuncOffsetShift = 9
				};


				struct Func
				{
					BSTSmartPointer<IFunction> func;	// 00
				};
				STATIC_ASSERT(sizeof(Func) == 0x8);


				UInt32		GetNumFuncs() const;
				Func*		GetFuncIter();
				const Func*	GetFuncIter() const;


				// members
				BSFixedString	name;	// 00
				UInt32			data;	// 08
				UInt32			pad0C;	// 0C
			};
			STATIC_ASSERT(sizeof(ScriptState) == 0x10);


			~Class();

			const char*	GetName() const;
			VMTypeID	GetTypeID() const;
			bool		IsInherited() const;
			bool		IsRemoved() const;

			Function*		GetFunctionIter();
			const Function*	GetFunctionIter() const;

			UInt32				GetNumFlags() const;
			ScriptFlag*			GetFlagIter();
			const ScriptFlag*	GetFlagIter() const;

			UInt32					GetNumVariables() const;
			UInt32					GetTotalNumVariables() const;
			ScriptVariable*			GetVariableIter();
			const ScriptVariable*	GetVariableIter() const;

			UInt32						GetNumDefaultValues() const;
			DefaultScriptValue*			GetDefaultValueIter();
			const DefaultScriptValue*	GetDefaultValueIter() const;

			UInt32					GetNumProperties() const;
			ScriptProperty*			GetPropertyIter();
			const ScriptProperty*	GetPropertyIter() const;

			UInt32					GetNumGlobalFuncs() const;
			ScriptGlobalFunc*		GetGlobalFuncIter();
			const ScriptGlobalFunc*	GetGlobalFuncIter() const;

			UInt32					GetNumMemberFuncs() const;
			ScriptMemberFunc*		GetMemberFuncIter();
			const ScriptMemberFunc*	GetMemberFuncIter() const;

			UInt32				GetNumStates() const;
			ScriptState*		GetStateIter();
			const ScriptState*	GetStateIter() const;

			UInt32 GetPropertyIndex(const BSFixedString& a_name) const;


			// members
			UInt32					unk04;					// 04
			BSFixedString			name;					// 08
			BSTSmartPointer<Class>	parent;					// 10
			BSFixedString			unk18;					// 18

			bool					inherited : 1;			// 20 - 0
			bool					removed : 1;			// 20 - 1 - false -> data == Function*, true -> data == normal progression
			bool					numFlags1 : 1;			// 20 - 2
			bool					numFlags2 : 1;			// 20 - 3
			bool					numFlags3 : 1;			// 20 - 4
			bool					numFlags4 : 1;			// 20 - 5
			bool					numFlags5 : 1;			// 20 - 6
			bool					numFlags6 : 1;			// 20 - 7

			bool					numVariables1 : 1;		// 21 - 0
			bool					numVariables2 : 1;		// 21 - 1
			bool					numVariables3 : 1;		// 21 - 2
			bool					numVariables4 : 1;		// 21 - 3
			bool					numVariables5 : 1;		// 21 - 4
			bool					numVariables6 : 1;		// 21 - 5
			bool					numVariables7 : 1;		// 21 - 6
			bool					numVariables8 : 1;		// 21 - 7

			bool					numVariables9 : 1;		// 22 - 0
			bool					numVariables10 : 1;		// 22 - 1
			bool					unk22_2 : 1;			// 22 - 2
			bool					unk22_3 : 1;			// 22 - 3
			bool					unk22_4 : 1;			// 22 - 4
			bool					unk22_5 : 1;			// 22 - 5
			bool					unk22_6 : 1;			// 22 - 6
			bool					unk22_7 : 1;			// 22 - 7

			bool					unk23_0 : 1;			// 23 - 0
			bool					unk23_1 : 1;			// 23 - 1
			bool					unk23_2 : 1;			// 23 - 2
			bool					unk23_3 : 1;			// 23 - 3
			bool					unk23_4 : 1;			// 23 - 4
			bool					unk23_5 : 1;			// 23 - 5
			bool					unk23_6 : 1;			// 23 - 6
			bool					unk23_7 : 1;			// 23 - 7

			bool					numDefaultValues1 : 1;	// 24 - 0
			bool					numDefaultValues2 : 1;	// 24 - 1
			bool					numDefaultValues3 : 1;	// 24 - 2
			bool					numDefaultValues4 : 1;	// 24 - 3
			bool					numDefaultValues5 : 1;	// 24 - 4
			bool					numDefaultValues6 : 1;	// 24 - 5
			bool					numDefaultValues7 : 1;	// 24 - 6
			bool					numDefaultValues8 : 1;	// 24 - 7

			bool					numDefaultValues9 : 1;	// 25 - 0
			bool					numDefaultValues10 : 1;	// 25 - 1
			bool					numProperties1 : 1;		// 25 - 2
			bool					numProperties2 : 1;		// 25 - 3
			bool					numProperties3 : 1;		// 25 - 4
			bool					numProperties4 : 1;		// 25 - 5
			bool					numProperties5 : 1;		// 25 - 6
			bool					numProperties6 : 1;		// 25 - 7

			bool					numProperties7 : 1;		// 26 - 0
			bool					numProperties8 : 1;		// 26 - 1
			bool					numProperties9 : 1;		// 26 - 2
			bool					numProperties10 : 1;	// 26 - 3
			bool					numGlobalFuncs1 : 1;	// 26 - 4
			bool					numGlobalFuncs2 : 1;	// 26 - 5
			bool					numGlobalFuncs3 : 1;	// 26 - 6
			bool					numGlobalFuncs4 : 1;	// 26 - 7

			bool					numGlobalFuncs5 : 1;	// 27 - 0
			bool					numGlobalFuncs6 : 1;	// 27 - 1
			bool					numGlobalFuncs7 : 1;	// 27 - 2
			bool					numGlobalFuncs8 : 1;	// 27 - 3
			bool					numGlobalFuncs9 : 1;	// 27 - 4
			bool					unk27_5 : 1;			// 27 - 5
			bool					unk27_6 : 1;			// 27 - 6
			bool					unk27_7 : 1;			// 27 - 7

			bool					numMemberFuncs1 : 1;	// 28 - 0
			bool					numMemberFuncs2 : 1;	// 28 - 1
			bool					numMemberFuncs3 : 1;	// 28 - 2
			bool					numMemberFuncs4 : 1;	// 28 - 3
			bool					numMemberFuncs5 : 1;	// 28 - 4
			bool					numMemberFuncs6 : 1;	// 28 - 5
			bool					numMemberFuncs7 : 1;	// 28 - 6
			bool					numMemberFuncs8 : 1;	// 28 - 7

			bool					numMemberFuncs9 : 1;	// 29 - 0
			bool					numMemberFuncs10 : 1;	// 29 - 1
			bool					numMemberFuncs11 : 1;	// 29 - 2
			bool					numStates1 : 1;			// 29 - 3
			bool					numStates2 : 1;			// 29 - 4
			bool					numStates3 : 1;			// 29 - 5
			bool					numStates4 : 1;			// 29 - 6
			bool					numStates5 : 1;			// 29 - 7

			bool					numStates6 : 1;			// 2A - 0
			bool					numStates7 : 1;			// 2A - 1
			bool					unk2A_2 : 1;			// 2A - 2
			bool					unk2A_3 : 1;			// 2A - 3
			bool					unk2A_4 : 1;			// 2A - 4
			bool					unk2A_5 : 1;			// 2A - 5
			bool					unk2A_6 : 1;			// 2A - 6
			bool					unk2A_7 : 1;			// 2A - 7

			bool					unk2B_0 : 1;			// 2B - 0
			bool					unk2B_1 : 1;			// 2B - 1
			bool					unk2B_2 : 1;			// 2B - 2
			bool					unk2B_3 : 1;			// 2B - 3
			bool					unk2B_4 : 1;			// 2B - 4
			bool					unk2B_5 : 1;			// 2B - 5
			bool					unk2B_6 : 1;			// 2B - 6
			bool					unk2B_7 : 1;			// 2B - 7

			UInt32					pad2C;					// 2C
			void*					data;					// 30

		private:
			void Dtor();
		};
		STATIC_ASSERT(sizeof(Class) == 0x38);
	}
}
