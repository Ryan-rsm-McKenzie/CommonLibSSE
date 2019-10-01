#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkWorldObject
#include "skse64/NiRTTI.h"  // NiRTTI_bhkWorldObject

#include "RE/bhkSerializable.h"  // bhkSerializable


namespace RE
{
	class bhkWorldObject : public bhkSerializable
	{
	public:
		inline static const void* RTTI = RTTI_bhkWorldObject;
		inline static const void* Ni_RTTI = NiRTTI_bhkWorldObject;


		virtual ~bhkWorldObject();													// 00

		// override (bhkSerializable)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual void			Unk_26(void) override;								// 26
		virtual hkpWorld*		GetWorld() override;								// 27 - { return world; }
		virtual void			Unk_28(void) override;								// 28 - { return world; }
		virtual void			Unk_29(void) override;								// 29


		// add
		virtual void			Unk_32(void);										// 32 - { return Unk_29(); }


		// members
		hkpWorld* world;	// 20
	};
	STATIC_ASSERT(sizeof(bhkWorldObject) == 0x28);
}
