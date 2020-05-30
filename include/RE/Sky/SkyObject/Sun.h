#pragma once

#include "RE/NiSmartPointer.h"
#include "RE/SkyObject.h"


namespace RE
{
	class BSShaderAccumulator;
	class BSTriShape;
	class NiBillboardNode;
	class NiDirectionalLight;


	class Sun : public SkyObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_Sun;


		virtual ~Sun();	 // 00

		// override (SkyObject)
		virtual void Unk_02(void) override;						 // 02
		virtual void Update(Sky* a_sky, float a_arg2) override;	 // 03


		// members
		NiPointer<NiBillboardNode>	   sunBaseNode;		  // 10
		NiPointer<NiBillboardNode>	   sunGlareNode;	  // 18
		NiPointer<BSTriShape>		   sunBase;			  // 20
		NiPointer<BSTriShape>		   sunQuery;		  // 28
		NiPointer<BSTriShape>		   sunGlare;		  // 30
		NiPointer<NiDirectionalLight>  light;			  // 38
		NiPointer<NiDirectionalLight>  cloudLight;		  // 40
		float						   glareScale;		  // 48
		bool						   doOcclusionTests;  // 4C
		UInt8						   pad4D;			  // 4D
		UInt16						   pad4E;			  // 4E
		NiPointer<BSShaderAccumulator> sunAccumulator;	  // 50
	};
	STATIC_ASSERT(sizeof(Sun) == 0x58);
}
