#pragma once

#include "RE/N/NiSmartPointer.h"
#include "RE/S/SkyObject.h"

namespace RE
{
	class BSFogProperty;
	class BSTriShape;
	class NiNode;

	class Atmosphere : public SkyObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_Atmosphere;

		virtual ~Atmosphere();	// 00

		// override (SkyObject)
		virtual void Update(Sky* a_sky, float a_arg2) override;	 // 03

		// add
		virtual void Unk_04(void);	// 04

		// members
		NiPointer<BSTriShape>	 atmosphere;		 // 10
		NiPointer<BSFogProperty> fog;				 // 18
		NiPointer<NiNode>		 skyQuadNode;		 // 20
		NiPointer<BSTriShape>	 skyQuad;			 // 28
		bool					 updateFogDistance;	 // 30
		std::uint8_t			 pad31;				 // 31
		std::uint16_t			 pad32;				 // 31
		std::uint32_t			 pad34;				 // 34
	};
	static_assert(sizeof(Atmosphere) == 0x38);
}
