#pragma once

namespace RE
{
	class TESObjectREFR;

	struct BGSDecalGroup;
	struct DECAL_CREATION_DATA;

	class BGSDecalManager
	{
	public:
		static BGSDecalManager* GetSingleton();

		static bool IsApplyingDecal();
		static void SetApplyingDecal(bool a_isApplyingDecal);
		static bool ShouldApplyDecal(TESObjectREFR* a_objectReference);

		void ApplyDecal(DECAL_CREATION_DATA& a_decalCreationData, bool a_forceDecal, BGSDecalGroup* a_decalGroup);

		// members
		std::uint32_t unk00;					   // 00
		std::uint32_t decalCountCurrentFrame;	   // 04
		std::uint32_t skinDecalCountCurrentFrame;  // 08
		std::uint32_t decalCount;				   // 0C
		std::uint32_t skinDecalCount;			   // 10
		bool		  unk14;					   // 14
	};
	static_assert(sizeof(BGSDecalManager) == 0x18);
}
