#pragma once

#include "RE/I/ImageSpaceModifierInstance.h"

namespace RE
{
	class ImageSpaceModifierInstanceTemp : public ImageSpaceModifierInstance
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceModifierInstanceTemp;

		virtual ~ImageSpaceModifierInstanceTemp();	// 00

		// override (ImageSpaceModifierInstance)
		virtual void Unk_25(void) override;	 // 25
		virtual void Unk_28(void) override;	 // 28

		// members
		float		  duration;	 // 28
		std::uint32_t pad3C;	 // 2C
	};
	static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 0x30);
}
