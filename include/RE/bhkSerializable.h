#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkSerializable

#include "RE/bhkRefObject.h"  // bhkRefObject


namespace RE
{
	class bhkSerializable : public bhkRefObject
	{
	public:
		inline static const void* RTTI = RTTI_bhkSerializable;


		virtual ~bhkSerializable();												// 00

		// override (bhkRefObject)
		virtual NiRTTI*		GetRTTI() override;									// 02
		virtual void		LoadBinary(NiStream* a_stream) override;			// 18
		virtual void		LinkObject(NiStream* a_stream) override;			// 19
		virtual bool		RegisterStreamables(NiStream* a_stream) override;	// 1A - { NiObject::RegisterStreamables(a_stream); }
		virtual void		SaveBinary(NiStream* a_stream) override;			// 1B
		virtual void		Unk_25(void) override;								// 25

		// add
		virtual hkpWorld*	GetWorld();											// 27 - { return 0; }
		virtual void		Unk_28(void);										// 28 - { return 0; }
		virtual void		Unk_29(void);										// 29 - { return 0; }
		virtual void		Unk_2A(void);										// 2A - { return 0; }
		virtual void		Unk_2B(void);										// 2B
		virtual void		Unk_2C(void);										// 2C - { return 1; }
		virtual void		Unk_2D(void);										// 2D
		virtual void		Unk_2E(void) = 0;									// 2E
		virtual void		Unk_2F(void) = 0;									// 2F
		virtual void		Unk_30(void);										// 30
		virtual void		Unk_31(void);										// 31


		// members
		bhkSerializable* serializable;	// 18
	};
	STATIC_ASSERT(sizeof(bhkSerializable) == 0x20);
}
