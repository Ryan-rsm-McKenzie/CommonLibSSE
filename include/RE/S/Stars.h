#pragma once

#include "RE/N/NiSmartPointer.h"
#include "RE/S/SkyObject.h"

namespace RE
{
	class NiNode;

	class Stars : public SkyObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_Stars;

		virtual ~Stars();  // 00

		// override (SkyObject)
		virtual void Unk_02(void) override;						 // 02
		virtual void Update(Sky* a_sky, float a_arg2) override;	 // 03

		// members
		NiPointer<NiNode> stars;  // 10
		float			  alpha;  // 18
		std::uint32_t	  pad1C;  // 1C
	};
	static_assert(sizeof(Stars) == 0x20);
}
