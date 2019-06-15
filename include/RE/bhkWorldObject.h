#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkWorldObject

#include "RE/bhkSerializable.h"  // bhkSerializable


namespace RE
{
	class bhkWorldObject : public bhkSerializable
	{
	public:
		inline static const void* RTTI = RTTI_bhkWorldObject;


		virtual ~bhkWorldObject();											// 00

		// override (bhkSerializable)
		virtual NiRTTI*	GetRTTI() override;									// 02
		virtual void	LoadBinary(NiStream* a_stream) override;			// 18
		virtual void	LinkObject(NiStream* a_stream) override;			// 19
		virtual bool	RegisterStreamables(NiStream* a_stream) override;	// 1A
		virtual void	SaveBinary(NiStream* a_stream) override;			// 1B

		// add
		virtual void	Unk_32(void);										// 32


		// members
		void* unk20;	// 20 - hkReferencedObject*?
	};
	STATIC_ASSERT(sizeof(bhkWorldObject) == 0x28);
}
