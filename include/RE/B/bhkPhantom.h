#pragma once

#include "RE/B/bhkWorldObject.h"

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
		std::uint64_t unk28;  // 28
	};
	static_assert(sizeof(bhkPhantom) == 0x30);
}
