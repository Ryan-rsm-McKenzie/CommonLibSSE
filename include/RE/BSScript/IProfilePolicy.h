#pragma once

#include "RE/BSTSmartPointer.h"


namespace RE
{
	class BSFixedString;


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


			virtual ~IProfilePolicy();	// 00

			// add
			virtual void StackFramePushQueued(UInt32 a_arg1, UInt32 a_arg2, const BSTSmartPointer<Internal::IFuncCallQuery>& a_arg3) = 0;														// 01
			virtual void StackFramePushed(UInt32 a_arg1, UInt32 a_arg2, const Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) = 0;		// 02
			virtual void StackFramePopQueued(UInt32 a_arg1, UInt32 a_arg2, const Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) = 0;	// 03
			virtual void StackFramePopped(UInt32 a_arg1, UInt32 a_arg2, const Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) = 0;		// 04
		};
		STATIC_ASSERT(sizeof(IProfilePolicy) == 0x8);
	}
}
