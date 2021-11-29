#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IFuncCallQuery.h"
#include "RE/V/Variable.h"

namespace RE
{
	namespace BSScript
	{
		class ObjectTypeInfo;

		namespace Internal
		{
			class RawFuncCallQuery : public IFuncCallQuery
			{
			public:
				inline static constexpr auto RTTI = RTTI_BSScript__Internal__RawFuncCallQuery;

				~RawFuncCallQuery() override;  // 00

				// override (IFuncCallQuery)
				bool GetFunctionCallInfo(CallType& a_callType, BSTSmartPointer<ObjectTypeInfo>& a_arg2, BSFixedString& a_arg3, Variable& a_arg4, BSScrapArray<Variable>& a_arg5) override;  // 01

				// members
				CallType                        callType;  // 10
				std::uint32_t                   pad14;     // 14
				BSTSmartPointer<ObjectTypeInfo> objType;   // 18
				BSFixedString                   name;      // 20
				Variable                        self;      // 28
				BSTArray<Variable>              args;      // 38
			};
			static_assert(sizeof(RawFuncCallQuery) == 0x50);
		}
	}
}
