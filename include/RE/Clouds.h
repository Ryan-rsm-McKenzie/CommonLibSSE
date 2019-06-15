#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Clouds

#include "RE/SkyObject.h"  // SkyObject


namespace RE
{
	class BSTriShape;


	class Clouds : public SkyObject
	{
	public:
		inline static const void* RTTI = RTTI_Clouds;


		enum
		{
			kTotalLayers = 32
		};


		virtual ~Clouds();						// 00

		// override (SkyObject)
		virtual void	Unk_02(void) override;	// 02
		virtual void	Unk_03(void) override;	// 03


		// members
		BSTriShape*	unk010[kTotalLayers];	// 010
		UInt64		unk110[kTotalLayers];	// 110
		UInt64		unk210[kTotalLayers];	// 210
		float		xSpeed[kTotalLayers];	// 310 - might actually be structs of 3 floats, idk
		float		ySpeed[kTotalLayers];	// 390
		float		zSpeed[kTotalLayers];	// 410
		float		alphas[kTotalLayers];	// 490
		UInt32		numLayers;				// 510
		UInt32		unk514;					// 514
		UInt64		unk520;					// 520
	};
	STATIC_ASSERT(sizeof(Clouds) == 0x520);
}
