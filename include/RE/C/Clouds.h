#pragma once

#include "RE/N/NiColor.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/S/SkyObject.h"

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
		std::uint64_t		  unk110[kTotalLayers];		   // 110
		NiPointer<NiTexture>  transTexture[kTotalLayers];  // 210
		NiColor				  colors[kTotalLayers];		   // 310
		float				  alphas[kTotalLayers];		   // 490
		std::uint16_t		  numLayers;				   // 510
		bool				  forceUpdate;				   // 512
		std::uint8_t		  pad513;					   // 513
		std::uint32_t		  pad514;					   // 514
		std::uint64_t		  pad520;					   // 520
	};
	static_assert(sizeof(Clouds) == 0x520);
}
