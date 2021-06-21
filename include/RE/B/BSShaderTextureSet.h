#pragma once

#include "RE/B/BSTextureSet.h"

namespace RE
{
	class BSShaderTextureSet : public BSTextureSet
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShaderTextureSet;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSShaderTextureSet;
		inline static constexpr auto VTABLE = VTABLE_BSShaderTextureSet;

		virtual ~BSShaderTextureSet();  // 00

		// override (BSTextureSet)
		virtual const NiRTTI* GetRTTI() const override;                                               // 02
		virtual void          LoadBinary(NiStream& a_stream) override;                                // 18
		virtual void          LinkObject(NiStream& a_stream) override;                                // 19
		virtual bool          RegisterStreamables(NiStream& a_stream) override;                       // 1A
		virtual void          SaveBinary(NiStream& a_stream) override;                                // 1B
		virtual bool          IsEqual(NiObject* a_object) override;                                   // 1C
		virtual const char*   GetTexturePath(Texture a_texture) override;                             // 25
		virtual void          SetTexture(Texture a_texture, NiSourceTexture* a_srcTexture) override;  // 26
		virtual void          SetTexturePath(Texture a_texture, const char* a_path) override;         // 27

		static BSShaderTextureSet* Create();

		// members
		const char* textures[Texture::kTotal];

	private:
		BSShaderTextureSet* ctor();
	};
	static_assert(sizeof(BSShaderTextureSet) == 0x58);
}
