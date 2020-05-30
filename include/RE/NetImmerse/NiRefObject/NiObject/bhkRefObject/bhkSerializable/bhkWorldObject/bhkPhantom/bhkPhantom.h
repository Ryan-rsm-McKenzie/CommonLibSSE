#pragma once

#include "RE/bhkWorldObject.h"


namespace RE
{
	class bhkPhantom : public bhkWorldObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkPhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkPhantom;


		virtual ~bhkPhantom();	// 00

		// override (bhkWorldObject)
		virtual const NiRTTI* GetRTTI() const override;	 // 02
		virtual void		  Unk_2A(void);				 // 2A


		// members
		UInt64 unk28;  // 28
	};
	STATIC_ASSERT(sizeof(bhkPhantom) == 0x30);
}
