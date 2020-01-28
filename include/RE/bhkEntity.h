#pragma once

#include "RE/bhkWorldObject.h"


namespace RE
{
	class bhkEntity : public bhkWorldObject
	{
	public:
		inline static const void* RTTI = RTTI_bhkEntity;
		inline static const void* Ni_RTTI = NiRTTI_bhkEntity;


		virtual ~bhkEntity();												// 00

		// override (bhkEntity)
		virtual const NiRTTI*	GetRTTI() const override;					// 02
		virtual void			LoadBinary(NiStream& a_stream) override;	// 18
		virtual void			SaveBinary(NiStream& a_stream) override;	// 1B
		virtual void			Unk_2A(void) override;						// 2A
		virtual void			Unk_30(void) override;						// 30
	};
	STATIC_ASSERT(sizeof(bhkEntity) == 0x28);
}
