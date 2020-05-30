#pragma once

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	class BSFixedString;


	namespace BSScript
	{
		class ObjectTypeInfo;
		class Variable;


		namespace Internal
		{
			class IFuncCallQuery : public BSIntrusiveRefCounted
			{
			public:
				inline static constexpr auto RTTI = RTTI_BSScript__Internal__IFuncCallQuery;


				enum class CallType : UInt32
				{
				};


				virtual ~IFuncCallQuery();	// 00

				// add
				virtual bool GetFunctionCallInfo(CallType& a_callType, BSTSmartPointer<ObjectTypeInfo>& a_arg2, BSFixedString& a_arg3, Variable& a_arg4, BSScrapArray<Variable>& a_arg5) = 0;  // 01


				// members
				UInt32 pad0C;  // 0C
			};
			STATIC_ASSERT(sizeof(IFuncCallQuery) == 0x10);
		}
	}
}
