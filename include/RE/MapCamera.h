#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MapCamera

#include "RE/TESCamera.h"  // TESCamera


namespace RE
{
	class MapCamera : public TESCamera
	{
	public:
		inline static const void* RTTI = RTTI_MapCamera;


		virtual ~MapCamera();		// 00

		// add
		virtual void Unk_03(void);	// 03


		// members
		float	unk38;		// 38
		float	unk3C;		// 3C
		float	unk40;		// 40
		float	unk44;		// 44
		float	unk48;		// 48
		UInt32	unk4C;		// 4C
		UInt32	unk50;		// 50
		UInt32	unk54;		// 54
		UInt64	unk58;		// 58
		UInt32	unk60;		// 60
		UInt32	unk64;		// 64
		UInt64	unk68;		// 68
		UInt64	unk70;		// 70
		UInt64	unk78;		// 78
		UInt64	unk80;		// 80
		UInt8	unk88;		// 88
		UInt8	pad89;		// 89
		UInt16	pad8A;		// 8A
		UInt32	pad8C;		// 8C
	};
	STATIC_ASSERT(sizeof(MapCamera) == 0x90);
}
