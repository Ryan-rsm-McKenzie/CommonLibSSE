#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSSystem/BSIntrusiveRefCounted.h"


namespace RE
{
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


				enum class CallType
				{
				};


				virtual ~IFuncCallQuery();	// 00

				// add
				virtual bool GetFunctionCallInfo(CallType& a_callType, BSTSmartPointer<ObjectTypeInfo>& a_arg2, BSFixedString& a_arg3, Variable& a_arg4, BSScrapArray<Variable>& a_arg5) = 0;  // 01


				// members
				std::uint32_t pad0C;  // 0C
			};
			static_assert(sizeof(IFuncCallQuery) == 0x10);
		}
	}
}
