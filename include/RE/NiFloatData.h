#pragma once

#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiFloatData : public NiObject
	{
	public:
		struct FloatData
		{
			float	time;	// 0
			float	value;	// 4
		};
		STATIC_ASSERT(sizeof(FloatData) == 0x8);


		virtual ~NiFloatData();										// 00

		// override (NiObject)
		virtual NiRTTI*	GetRTTI() override;							// 02
		virtual void	LoadBinary(NiStream* a_stream) override;	// 18
		virtual void	SaveBinary(NiStream* a_stream) override;	// 1B
		virtual bool	IsEqual(NiObject* a_object) override;		// 1C

		
		// members
		UInt32		count;		// 10
		UInt32		unk14;		// 14
		FloatData*	arr;		// 18
		UInt32		content;	// 20
		UInt8		stride;		// 24
		UInt8		unk25;		// 25
		UInt16		unk26;		// 26
	};
	STATIC_ASSERT(sizeof(NiFloatData) == 0x28);
}
