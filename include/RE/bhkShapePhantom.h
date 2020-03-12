#pragma once

#include "RE/bhkPhantom.h"


namespace RE
{
	class bhkShapePhantom : public bhkPhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkShapePhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkShapePhantom;


		virtual ~bhkShapePhantom();	 // 00

		// override (bhkPhantom)
		virtual const NiRTTI* GetRTTI() const override;					// 02
		virtual void		  LinkObject(NiStream& a_stream) override;	// 19 - { bhkWorldObject::LinkObject(a_stream); }
	};
	STATIC_ASSERT(sizeof(bhkShapePhantom) == 0x30);
}
