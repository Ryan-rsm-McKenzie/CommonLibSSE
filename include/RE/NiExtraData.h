#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiExtraData : public NiObject
	{
	public:
		virtual ~NiExtraData();													// 00

		// override (NiObject)
		virtual NiRTTI*		GetRTTI() override;									// 02
		virtual void		LoadBinary(NiStream* a_stream) override;			// 18
		virtual void		LinkObject(NiStream* a_stream) override;			// 19
		virtual bool		RegisterStreamables(NiStream* a_stream) override;	// 1A
		virtual void		SaveBinary(NiStream* a_stream) override;			// 1B
		virtual bool		IsEqual(NiObject* a_object) override;				// 1C

		// add
		virtual void		Unk_25(void);										// 25 - { return 1; }
		virtual void		Unk_26(void);										// 26 - { return 1; }

		static NiExtraData*	Create(UInt32 a_size, uintptr_t a_vtbl);


		// members
		BSFixedString name;	// 10
	};
	STATIC_ASSERT(sizeof(NiExtraData) == 0x18);
}
