#pragma once

#include "RE/B/BSTextureSet.h"
#include "RE/C/Color.h"
#include "RE/D/DecalData.h"
#include "RE/F/FormTypes.h"
#include "RE/I/ID.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class BGSTextureSet :
		public TESBoundObject,  // 00
		public BSTextureSet     // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSTextureSet;
		inline static constexpr auto VTABLE = VTABLE_BGSTextureSet;
		inline static constexpr auto FORMTYPE = FormType::TextureSet;

		enum class Flag
		{
			kNone = 0,
			kNoSpecularMap = 1 << 0,
			kFacegenTextures = 1 << 1,
			kHasModelSpaceNormalMap = 1 << 2
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSTextureSet() override;  // 00

		// override (TESBoundObject)
		void        InitializeData() override;                            // 04
		void        ClearData() override;                                 // 05
		bool        Load(TESFile* a_mod) override;                        // 06
		NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;  // 40
		void        UnClone3D(TESObjectREFR* a_ref) override;             // 41

		// members
		TESTexture                            textures[Textures::kUsedTotal];        // 040 - TX00 - TX07
		DecalData*                            decalData;                             // 0C0 - DODT
		stl::enumeration<Flag, std::uint16_t> flags;                                 // 0C8 - DNAM
		std::uint16_t                         pad0CA;                                // 0CA
		BSResource::ID                        textureFileIDs[Textures::kUsedTotal];  // 0CC
		std::uint32_t                         pad12C;                                // 12C
	};
	static_assert(sizeof(BGSTextureSet) == 0x130);
}
