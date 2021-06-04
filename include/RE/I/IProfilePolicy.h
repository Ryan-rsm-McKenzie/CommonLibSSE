#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class IFuncCallQuery;
		}

		class Variable;

		class IProfilePolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IProfilePolicy;

			virtual ~IProfilePolicy();  // 00

			// add
			virtual void StackFramePushQueued(std::uint32_t a_arg1, std::uint32_t a_arg2, const BSTSmartPointer<Internal::IFuncCallQuery>& a_arg3) = 0;                                                       // 01
			virtual void StackFramePushed(std::uint32_t a_arg1, std::uint32_t a_arg2, const Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) = 0;     // 02
			virtual void StackFramePopQueued(std::uint32_t a_arg1, std::uint32_t a_arg2, const Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) = 0;  // 03
			virtual void StackFramePopped(std::uint32_t a_arg1, std::uint32_t a_arg2, const Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) = 0;     // 04
		};
		static_assert(sizeof(IProfilePolicy) == 0x8);
	}
}
