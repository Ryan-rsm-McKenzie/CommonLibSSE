#pragma once

#include "RE/ThirdPersonState.h"


namespace RE
{
	class BleedoutCameraState : public ThirdPersonState
	{
	public:
		inline static const void* RTTI = RTTI_BleedoutCameraState;


		virtual ~BleedoutCameraState();													// 00

		// override (ThirdPersonState)
		virtual void	OnStateStart() override;										// 01
		virtual void	OnStateEnd() override;											// 02
		virtual void	OnUpdate(BSTSmartPointer<TESCameraState>& a_newState) override;	// 03


		// members
		float	unk0E8;	// 0E8
		UInt32	unk0EC;	// 0EC
		UInt64	unk0F0;	// 0F0
		float	unk0F8;	// 0F8
		UInt32	unk0FC;	// 0FC
		UInt64	unk100;	// 100
		float	unk108;	// 108
		float	unk10C;	// 10C
		float	unk110;	// 110
		UInt32	unk114;	// 114
		UInt64	unk118;	// 118
		void*	unk120;	// 120 - smart ptr
		SInt32	unk128;	// 128
		UInt8	unk12C;	// 12C
		UInt8	pad12D;	// 12D
		UInt16	pad12E;	// 12E
		UInt32	unk130;	// 130
		UInt8	unk134;	// 134
		UInt8	pad135;	// 135
		UInt16	pad136;	// 136
	};
	STATIC_ASSERT(sizeof(BleedoutCameraState) == 0x138);
}
