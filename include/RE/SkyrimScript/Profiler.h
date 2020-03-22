#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSScript/IProfilePolicy.h"
#include "RE/BSTHashMap.h"


namespace RE
{
	namespace SkyrimScript
	{
		class Profiler : public BSScript::IProfilePolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript__Profiler;


			virtual ~Profiler();  // 00

			// override (BSScript::IProfilePolicy)
			virtual void StackFramePushQueued(UInt32 a_arg1, UInt32 a_arg2, const BSTSmartPointer<BSScript::Internal::IFuncCallQuery>& a_arg3) override;													   // 01
			virtual void StackFramePushed(UInt32 a_arg1, UInt32 a_arg2, const BSScript::Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) override;	   // 02
			virtual void StackFramePopQueued(UInt32 a_arg1, UInt32 a_arg2, const BSScript::Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) override;  // 03
			virtual void StackFramePopped(UInt32 a_arg1, UInt32 a_arg2, const BSScript::Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) override;	   // 04


			// members
			mutable BSSpinLock			 unk08;	 // 08
			BSTHashMap<UnkKey, UnkValue> unk10;	 // 10
			BSTHashMap<UnkKey, UnkValue> unk40;	 // 40
			BSTHashMap<UnkKey, UnkValue> unk70;	 // 70
			UInt64						 unkA0;	 // A0
			UInt64						 unkA8;	 // A8
			UInt64						 unkB0;	 // B0
			UInt64						 unkB8;	 // B8
			UInt64						 unkC0;	 // C0
			UInt64						 unkC8;	 // C8
			UInt64						 unkD0;	 // D0
			UInt64						 unkD8;	 // D8
		};
		STATIC_ASSERT(sizeof(Profiler) == 0xE0);
	}
}
