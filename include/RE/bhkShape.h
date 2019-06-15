#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkShape

#include "RE/bhkSerializable.h"  // bhkSerializable


namespace RE
{
	class bhkShape : public bhkSerializable
	{
	public:
		inline static const void* RTTI = RTTI_bhkShape;


		virtual ~bhkShape();										// 00

		// override (bhkSerializable)
		virtual NiRTTI*	GetRTTI() override;							// 02
		virtual void	LoadBinary(NiStream* a_stream) override;	// 18
		virtual void	SaveBinary(NiStream* a_stream) override;	// 1B
		virtual bool	IsEqual(NiObject* a_object) override;		// 1C

		// add
		virtual void	Unk_32(void);								// 32
		virtual void	Unk_33(void);								// 33
		virtual void	Unk_34(void);								// 34 - { return 0; }
		virtual void	Unk_35(void);								// 35


		// members
		UInt64 unk20;	// 20
	};
	STATIC_ASSERT(sizeof(bhkShape) == 0x28);
}
