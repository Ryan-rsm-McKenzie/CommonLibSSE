#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSScript/PropertyTypeInfo.h"
#include "RE/BSScript/TypeInfo.h"
#include "RE/BSScript/Variable.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class IFunction;


		class ObjectTypeInfo : public BSIntrusiveRefCounted
		{
		public:
			struct UnlinkedNativeFunction
			{
			public:
				// members
				UnlinkedNativeFunction*	   next;  // 00
				BSTSmartPointer<IFunction> func;  // 08
			};
			STATIC_ASSERT(sizeof(UnlinkedNativeFunction) == 0x10);


			struct UserFlagInfo
			{
			public:
				enum : std::uintptr_t
				{
					kUnkFlag = 1 << 0
				};


				BSFixedString GetUserFlag() const;


				// members
				std::uintptr_t data;  // 0
			};
			STATIC_ASSERT(sizeof(UserFlagInfo) == 0x8);


			struct VariableInfo
			{
			public:
				// members
				BSFixedString name;	 // 00
				TypeInfo	  type;	 // 08
			};
			STATIC_ASSERT(sizeof(VariableInfo) == 0x10);


			struct InitialValueInfo
			{
			public:
				// members
				UInt32	 variableIndex;	 // 00
				UInt32	 pad04;			 // 04
				Variable initialValue;	 // 08
			};
			STATIC_ASSERT(sizeof(InitialValueInfo) == 0x18);


			struct PropertyInfo
			{
			public:
				// members
				BSFixedString	 name;	// 00
				PropertyTypeInfo info;	// 08
			};
			STATIC_ASSERT(sizeof(PropertyInfo) == 0x48);


			struct GlobalFuncInfo
			{
			public:
				// members
				BSTSmartPointer<IFunction> func;  // 00
			};
			STATIC_ASSERT(sizeof(GlobalFuncInfo) == 0x8);


			struct MemberFuncInfo
			{
			public:
				// members
				BSTSmartPointer<IFunction> func;  // 00
			};
			STATIC_ASSERT(sizeof(MemberFuncInfo) == 0x8);


			struct NamedStateInfo
			{
			public:
				enum : UInt32
				{
					kFuncCountMask = 0x1FF,
					kFuncOffsetShift = 9
				};


				struct Func
				{
				public:
					// members
					BSTSmartPointer<IFunction> func;  // 00
				};
				STATIC_ASSERT(sizeof(Func) == 0x8);


				UInt32		GetNumFuncs() const;
				Func*		GetFuncIter();
				const Func* GetFuncIter() const;


				// members
				BSFixedString name;	  // 00
				UInt32		  data;	  // 08
				UInt32		  pad0C;  // 0C
			};
			STATIC_ASSERT(sizeof(NamedStateInfo) == 0x10);


			~ObjectTypeInfo();

			const char*			  GetName() const;
			ObjectTypeInfo*		  GetParent();
			const ObjectTypeInfo* GetParent() const;
			TypeInfo::RawType	  GetRawType() const;
			bool				  IsInherited() const;
			bool				  IsRemoved() const;

			UnlinkedNativeFunction*		  GetUnlinkedFunctionIter();
			const UnlinkedNativeFunction* GetUnlinkedFunctionIter() const;

			UInt32				GetNumUserFlags() const;
			UserFlagInfo*		GetUserFlagIter();
			const UserFlagInfo* GetUserFlagIter() const;

			UInt32				GetNumVariables() const;
			UInt32				GetTotalNumVariables() const;
			VariableInfo*		GetVariableIter();
			const VariableInfo* GetVariableIter() const;

			UInt32					GetNumInitalValues() const;
			InitialValueInfo*		GetInitialValueIter();
			const InitialValueInfo* GetInitialValueIter() const;

			UInt32				GetNumProperties() const;
			PropertyInfo*		GetPropertyIter();
			const PropertyInfo* GetPropertyIter() const;

			UInt32				  GetNumGlobalFuncs() const;
			GlobalFuncInfo*		  GetGlobalFuncIter();
			const GlobalFuncInfo* GetGlobalFuncIter() const;

			UInt32				  GetNumMemberFuncs() const;
			MemberFuncInfo*		  GetMemberFuncIter();
			const MemberFuncInfo* GetMemberFuncIter() const;

			UInt32				  GetNumNamedStates() const;
			NamedStateInfo*		  GetNamedStateIter();
			const NamedStateInfo* GetNamedStateIter() const;

			UInt32 GetPropertyIndex(const BSFixedString& a_name) const;


			// members
			UInt32							pad04;			 // 04
			BSFixedString					name;			 // 08
			BSTSmartPointer<ObjectTypeInfo> parentTypeInfo;	 // 10
			BSFixedString					docString;		 // 18

			bool inherited : 1;		  // 20 - 0
			bool removed : 1;		  // 20 - 1 - false -> data == UnlinkedNativeFunction*, true -> data == normal progression
			bool userFlagCount1 : 1;  // 20 - 2
			bool userFlagCount2 : 1;  // 20 - 3
			bool userFlagCount3 : 1;  // 20 - 4
			bool userFlagCount4 : 1;  // 20 - 5
			bool userFlagCount5 : 1;  // 20 - 6
			bool userFlagCount6 : 1;  // 20 - 7

			bool variableCount1 : 1;  // 21 - 0
			bool variableCount2 : 1;  // 21 - 1
			bool variableCount3 : 1;  // 21 - 2
			bool variableCount4 : 1;  // 21 - 3
			bool variableCount5 : 1;  // 21 - 4
			bool variableCount6 : 1;  // 21 - 5
			bool variableCount7 : 1;  // 21 - 6
			bool variableCount8 : 1;  // 21 - 7

			bool variableCount9 : 1;		  // 22 - 0
			bool variableCount10 : 1;		  // 22 - 1
			bool variableUserFlagCount1 : 1;  // 22 - 2
			bool variableUserFlagCount2 : 1;  // 22 - 3
			bool variableUserFlagCount3 : 1;  // 22 - 4
			bool variableUserFlagCount4 : 1;  // 22 - 5
			bool variableUserFlagCount5 : 1;  // 22 - 6
			bool variableUserFlagCount6 : 1;  // 22 - 7

			bool unk23_0 : 1;  // 23 - 0
			bool unk23_1 : 1;  // 23 - 1
			bool unk23_2 : 1;  // 23 - 2
			bool unk23_3 : 1;  // 23 - 3
			bool unk23_4 : 1;  // 23 - 4
			bool unk23_5 : 1;  // 23 - 5
			bool unk23_6 : 1;  // 23 - 6
			bool unk23_7 : 1;  // 23 - 7

			bool initialValueCount1 : 1;  // 24 - 0
			bool initialValueCount2 : 1;  // 24 - 1
			bool initialValueCount3 : 1;  // 24 - 2
			bool initialValueCount4 : 1;  // 24 - 3
			bool initialValueCount5 : 1;  // 24 - 4
			bool initialValueCount6 : 1;  // 24 - 5
			bool initialValueCount7 : 1;  // 24 - 6
			bool initialValueCount8 : 1;  // 24 - 7

			bool initialValueCount9 : 1;   // 25 - 0
			bool initialValueCount10 : 1;  // 25 - 1
			bool propertyCount1 : 1;	   // 25 - 2
			bool propertyCount2 : 1;	   // 25 - 3
			bool propertyCount3 : 1;	   // 25 - 4
			bool propertyCount4 : 1;	   // 25 - 5
			bool propertyCount5 : 1;	   // 25 - 6
			bool propertyCount6 : 1;	   // 25 - 7

			bool propertyCount7 : 1;		// 26 - 0
			bool propertyCount8 : 1;		// 26 - 1
			bool propertyCount9 : 1;		// 26 - 2
			bool propertyCount10 : 1;		// 26 - 3
			bool staticFunctionCount1 : 1;	// 26 - 4
			bool staticFunctionCount2 : 1;	// 26 - 5
			bool staticFunctionCount3 : 1;	// 26 - 6
			bool staticFunctionCount4 : 1;	// 26 - 7

			bool staticFunctionCount5 : 1;	// 27 - 0
			bool staticFunctionCount6 : 1;	// 27 - 1
			bool staticFunctionCount7 : 1;	// 27 - 2
			bool staticFunctionCount8 : 1;	// 27 - 3
			bool staticFunctionCount9 : 1;	// 27 - 4
			bool unk27_5 : 1;				// 27 - 5
			bool unk27_6 : 1;				// 27 - 6
			bool unk27_7 : 1;				// 27 - 7

			bool emptyStateMemberFunctionCount1 : 1;  // 28 - 0
			bool emptyStateMemberFunctionCount2 : 1;  // 28 - 1
			bool emptyStateMemberFunctionCount3 : 1;  // 28 - 2
			bool emptyStateMemberFunctionCount4 : 1;  // 28 - 3
			bool emptyStateMemberFunctionCount5 : 1;  // 28 - 4
			bool emptyStateMemberFunctionCount6 : 1;  // 28 - 5
			bool emptyStateMemberFunctionCount7 : 1;  // 28 - 6
			bool emptyStateMemberFunctionCount8 : 1;  // 28 - 7

			bool emptyStateMemberFunctionCount9 : 1;   // 29 - 0
			bool emptyStateMemberFunctionCount10 : 1;  // 29 - 1
			bool emptyStateMemberFunctionCount11 : 1;  // 29 - 2
			bool namedStateCount1 : 1;				   // 29 - 3
			bool namedStateCount2 : 1;				   // 29 - 4
			bool namedStateCount3 : 1;				   // 29 - 5
			bool namedStateCount4 : 1;				   // 29 - 6
			bool namedStateCount5 : 1;				   // 29 - 7

			bool namedStateCount6 : 1;	// 2A - 0
			bool namedStateCount7 : 1;	// 2A - 1
			bool unk2A_2 : 1;			// 2A - 2
			bool unk2A_3 : 1;			// 2A - 3
			bool unk2A_4 : 1;			// 2A - 4
			bool unk2A_5 : 1;			// 2A - 5
			bool unk2A_6 : 1;			// 2A - 6
			bool unk2A_7 : 1;			// 2A - 7

			bool unk2B_0 : 1;  // 2B - 0
			bool unk2B_1 : 1;  // 2B - 1
			bool unk2B_2 : 1;  // 2B - 2
			bool unk2B_3 : 1;  // 2B - 3
			bool unk2B_4 : 1;  // 2B - 4
			bool unk2B_5 : 1;  // 2B - 5
			bool unk2B_6 : 1;  // 2B - 6
			bool unk2B_7 : 1;  // 2B - 7

			UInt32 pad2C;  // 2C
			void*  data;   // 30

		private:
			void ReleaseData();
		};
		STATIC_ASSERT(sizeof(ObjectTypeInfo) == 0x38);
	}
}
