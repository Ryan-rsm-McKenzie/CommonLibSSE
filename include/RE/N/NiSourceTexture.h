#pragma once

#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTexture.h"

namespace RE
{
	namespace BSGraphics
	{
		class Texture;
	}

	namespace BSResource
	{
		class Stream;
	}

	NiSmartPointer(NiSourceTexture);

	class NiSourceTexture : public NiTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiSourceTexture;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiSourceTexture;

		virtual ~NiSourceTexture();	 // 00

		// override (NiTexture)
		virtual const NiRTTI* GetRTTI() const override;	 // 02
		virtual void		  Unk_25(void) override;	 // 25 - { return 0; }
		virtual void		  Unk_26(void) override;	 // 26 - { return 0; }
		virtual void		  Unk_27(void) override;	 // 27
		virtual void		  Unk_28(void) override;	 // 28
		virtual void		  Unk_29(void) override;	 // 29 - { return; }
		virtual void		  Unk_2A(void) override;	 // 2A - { return; }

		// members
		BSResource::Stream*	 unk40;			   // 40
		BSGraphics::Texture* rendererTexture;  // 48
		std::uint8_t		 flags;			   // 50
		std::uint8_t		 pad51;			   // 51
		std::uint16_t		 pad52;			   // 52
		std::uint32_t		 pad54;			   // 54
	};
	static_assert(sizeof(NiSourceTexture) == 0x58);
}
