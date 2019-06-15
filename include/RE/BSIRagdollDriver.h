#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSIRagdollDriver

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	class bhkWorld;


	class BSIRagdollDriver
	{
	public:
		inline static const void* RTTI = RTTI_BSIRagdollDriver;


		virtual void	Unk_01(void) = 0;					// 01
		virtual void	Unk_02(void) = 0;					// 02
		virtual void	Unk_03(void) = 0;					// 03
		virtual void	SetWorld(bhkWorld* a_world) = 0;	// 04
		virtual void	Unk_05(void) = 0;					// 05
		virtual void	Unk_06(void) = 0;					// 06
		virtual void	Unk_07(void) = 0;					// 07
		virtual void	Unk_08(void) = 0;					// 08
		virtual void	Unk_09(void) = 0;					// 09
		virtual void	Unk_0A(void) = 0;					// 0A
		virtual void	Unk_0B(void) = 0;					// 0B
		virtual void	Unk_0C(void) = 0;					// 0C
		virtual void	Unk_0D(void) = 0;					// 0D
	};
	STATIC_ASSERT(sizeof(BSIRagdollDriver) == 0x8);
}
