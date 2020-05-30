#pragma once

#include "RE/NiSmartPointer.h"
#include "RE/SkyObject.h"


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
		UInt8					 pad31;				 // 31
		UInt16					 pad32;				 // 31
		UInt32					 pad34;				 // 34
	};
	STATIC_ASSERT(sizeof(Atmosphere) == 0x38);
}
