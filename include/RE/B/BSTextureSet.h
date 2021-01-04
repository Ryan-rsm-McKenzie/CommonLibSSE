#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	class NiSourceTexture;

	class BSTextureSet : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTextureSet;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTextureSet;

		struct Textures
		{
			enum Texture : std::uint32_t
			{
				kDiffuse = 0,
				kNormal,
				kGloss = kNormal,
				kEnvironmentMask,
				kSubsurfaceTint = kEnvironmentMask,
				kGlowMap,
				kDetailMap = kGlowMap,
				kHeight,
				kEnvironment,
				kMultilayer,
				kBacklightMask,
				kSpecular = kBacklightMask,

				kTotal
			};
		};
		using Texture = Textures::Texture;

		virtual ~BSTextureSet();  // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C

		// add
		virtual const char* GetTexturePath(Texture a_texture) = 0;							   // 25
		virtual void		SetTexture(Texture a_texture, NiSourceTexture* a_srcTexture) = 0;  // 26
		virtual void		SetTexturePath(Texture a_texture, const char* a_path) = 0;		   // 27
	};
	static_assert(sizeof(BSTextureSet) == 0x10);
}
