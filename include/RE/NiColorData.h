#pragma once

#include "RE/NiColors.h"  // NiColorA
#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiColorData : public NiObject
	{
	public:
		struct ColorData
		{
			float		time;	// 00
			NiColorA	color;	// 04
		};
		STATIC_ASSERT(sizeof(ColorData) == 0x14);


		virtual ~NiColorData();										// 00

		// override (NiObject)
		virtual NiRTTI*	GetRTTI() override;							// 02
		virtual void	LoadBinary(NiStream* a_stream) override;	// 18
		virtual void	SaveBinary(NiStream* a_stream) override;	// 1B
		virtual bool	IsEqual(NiObject* a_object) override;		// 1C


		// members
		UInt32		count;		// 10
		UInt32		unk14;		// 14
		ColorData*	arr;		// 18
		UInt32		content;	// 20
		UInt8		stride;		// 24
		UInt8		unk25;		// 25
		UInt16		unk26;		// 26
	};
	STATIC_ASSERT(sizeof(NiColorData) == 0x28);
}
