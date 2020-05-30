#pragma once

#include "RE/NiColor.h"
#include "RE/NiSmartPointer.h"
#include "RE/SkyObject.h"


namespace RE
{
	class BSGeometry;
	class NiTexture;


	class Clouds : public SkyObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_Clouds;


		enum
		{
			kTotalLayers = 32
		};


		virtual ~Clouds();	// 00

		// override (SkyObject)
		virtual void Unk_02(void) override;						 // 02
		virtual void Update(Sky* a_sky, float a_arg2) override;	 // 03


		// members
		NiPointer<BSGeometry> clouds[kTotalLayers];		   // 010
		UInt64				  unk110[kTotalLayers];		   // 110
		NiPointer<NiTexture>  transTexture[kTotalLayers];  // 210
		NiColor				  colors[kTotalLayers];		   // 310
		float				  alphas[kTotalLayers];		   // 490
		UInt16				  numLayers;				   // 510
		bool				  forceUpdate;				   // 512
		UInt8				  pad513;					   // 513
		UInt32				  pad514;					   // 514
		UInt64				  pad520;					   // 520
	};
	STATIC_ASSERT(sizeof(Clouds) == 0x520);
}
