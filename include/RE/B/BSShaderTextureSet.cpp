#include "RE/B/BSShaderTextureSet.h"

namespace RE
{
	BSShaderTextureSet* BSShaderTextureSet::ctor()
	{
		using func_t = decltype(&BSShaderTextureSet::ctor);
		REL::Relocation<func_t> func{ REL::ID(99886) };
		return func(this);
	}

	BSShaderTextureSet* BSShaderTextureSet::Create()
	{
		auto textureset = malloc<BSShaderTextureSet>();
		if (textureset) {
			std::memset(textureset, 0, sizeof(BSShaderTextureSet));
			textureset->ctor();
		}
		return textureset;
	}
}
