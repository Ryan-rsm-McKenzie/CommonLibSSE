#include "RE/T/TESNPC.h"

#include "RE/T/TESRace.h"

namespace RE
{
	TESNPC::HeadRelatedData::HeadRelatedData() :
		hairColor(nullptr),
		faceDetails(nullptr)
	{}

	void TESNPC::ChangeHeadPart(BGSHeadPart* a_target)
	{
		using func_t = decltype(&TESNPC::ChangeHeadPart);
		REL::Relocation<func_t> func{ Offset::TESNPC::ChangeHeadPart };
		return func(this, a_target);
	}

	BGSHeadPart** TESNPC::GetBaseOverlays() const
	{
		using func_t = decltype(&TESNPC::GetBaseOverlays);
		REL::Relocation<func_t> func{ Offset::TESNPC::GetBaseOverlays };
		return func(this);
	}

	SEX TESNPC::GetSex() const
	{
		return IsFemale() ? SEX::kFemale : SEX::kMale;
	}

	BGSHeadPart* TESNPC::GetCurrentHeadPartByType(HeadPartType a_type)
	{
		return HasOverlays() ? GetHeadPartOverlayByType(a_type) : GetHeadPartByType(a_type);
	}

	BGSHeadPart* TESNPC::GetHeadPartByType(HeadPartType a_type)
	{
		if (headParts) {
			for (std::int8_t i = 0; i < numHeadParts; ++i) {
				if (headParts[i] && headParts[i]->type == a_type) {
					return headParts[i];
				}
			}
		}
		return nullptr;
	}

	BGSHeadPart* TESNPC::GetHeadPartOverlayByType(HeadPartType a_type)
	{
		const auto numOverlays = GetNumBaseOverlays();
		auto	   overlays = GetBaseOverlays();
		if (overlays) {
			for (std::uint32_t i = 0; i < numOverlays; ++i) {
				if (overlays[i]->type == a_type) {
					return overlays[i];
				}
			}
		}
		return nullptr;
	}

	float TESNPC::GetHeight() const
	{
		if (!race) {
			return height;
		}

		const auto sex = GetSex();
		switch (sex) {
		case SEX::kMale:
		case SEX::kFemale:
			return race->data.height[sex] * height;
		default:
			return 0.0;
		}
	}

	std::uint32_t TESNPC::GetNumBaseOverlays() const
	{
		using func_t = decltype(&TESNPC::GetNumBaseOverlays);
		REL::Relocation<func_t> func{ Offset::TESNPC::GetNumBaseOverlays };
		return func(this);
	}

	TESRace* TESNPC::GetRace()
	{
		return race;
	}

	TESNPC* TESNPC::GetRootFaceNPC()
	{
		auto iter = this;
		while (iter->faceNPC) {
			iter = iter->faceNPC;
		}
		return iter;
	}

	const TESNPC* TESNPC::GetRootFaceNPC() const
	{
		auto iter = this;
		while (iter->faceNPC) {
			iter = iter->faceNPC;
		}
		return iter;
	}

	float TESNPC::Layer::GetInterpolationValue() const
	{
		return static_cast<float>(interpolationValue) / static_cast<float>(100.0);
	}

	bool TESNPC::HasOverlays()
	{
		using func_t = decltype(&TESNPC::HasOverlays);
		REL::Relocation<func_t> func{ Offset::TESNPC::HasOverlays };
		return func(this);
	}

	void TESNPC::SetFaceTexture(BGSTextureSet* a_textureSet)
	{
		if (!headRelatedData && a_textureSet) {
			headRelatedData = new HeadRelatedData();
		}

		if (headRelatedData) {
			headRelatedData->faceDetails = a_textureSet;
		}
	}

	void TESNPC::SetHairColor(BGSColorForm* a_hairColor)
	{
		if (!headRelatedData && a_hairColor) {
			headRelatedData = new HeadRelatedData();
		}

		if (headRelatedData) {
			headRelatedData->hairColor = a_hairColor;
		}
	}

	void TESNPC::SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, bool a_fromTint)
	{
		using func_t = decltype(&TESNPC::SetSkinFromTint);
		REL::Relocation<func_t> func{ Offset::TESNPC::SetSkinFromTint };
		return func(this, a_result, a_tintMask, a_fromTint);
	}

	void TESNPC::UpdateNeck(BSFaceGenNiNode* a_faceNode)
	{
		using func_t = decltype(&TESNPC::UpdateNeck);
		REL::Relocation<func_t> func{ Offset::TESNPC::UpdateNeck };
		return func(this, a_faceNode);
	}
}
