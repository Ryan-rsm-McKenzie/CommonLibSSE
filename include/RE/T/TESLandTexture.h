#pragma once

#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct TEXTURE_HAVOK_DATA  // HNAM
	{
		std::int32_t friction;     // 0
		std::int32_t restitution;  // 4
	};
	static_assert(sizeof(TEXTURE_HAVOK_DATA) == 0x8);

	class TESLandTexture : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESLandTexture;
		inline static constexpr auto VTABLE = VTABLE_TESLandTexture;
		inline static constexpr auto FORMTYPE = FormType::LandTexture;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~TESLandTexture() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		BGSTextureSet*          textureSet;          // 20 - TNAM
		TEXTURE_HAVOK_DATA      havokData;           // 28 - HNAM
		BGSMaterialType*        materialType;        // 30 - MNAM
		std::int8_t             specularExponent;    // 38 - SNAM
		std::uint8_t            pad39;               // 39
		std::uint16_t           pad3A;               // 3A
		std::int32_t            shaderTextureIndex;  // 3C - INAM
		BSSimpleList<TESGrass*> textureGrassList;    // 40 - GNAM
	};
	static_assert(sizeof(TESLandTexture) == 0x50);
}
