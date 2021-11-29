#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESModelTextureSwap : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelTextureSwap;

		struct AlternateTexture  // MODS
		{
			BGSTextureSet* textureSet;  // 00
			std::uint32_t  index3D;     // 08
			std::uint32_t  unk0C;       // 0C
			BSFixedString  name3D;      // 10
		};
		static_assert(sizeof(AlternateTexture) == 0x18);

		~TESModelTextureSwap() override;  // 00

		// override (TESModel)
		void                 InitializeDataComponent() override;                // 01
		void                 ClearDataComponent() override;                     // 02
		void                 CopyComponent(BaseFormComponent* a_rhs) override;  // 03
		TESModelTextureSwap* GetAsModelTextureSwap() override;                  // 06 - { return this; }

		// members
		AlternateTexture* alternateTextures;     // 28 - MODS
		std::uint32_t     numAlternateTextures;  // 30
		std::uint32_t     pad34;                 // 34
	};
	static_assert(sizeof(TESModelTextureSwap) == 0x38);
}
