#include "RE/TESNPC.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	TESNPC::HeadData::HeadData() :
		hairColor(0),
		headTexture(0)
	{}


	void TESNPC::ChangeHeadPart(BGSHeadPart* a_target)
	{
		using func_t = function_type_t<decltype(&TESNPC::ChangeHeadPart)>;
		REL::Offset<func_t*> func(Offset::TESNPC::ChangeHeadPart);
		return func(this, a_target);
	}


	BGSHeadPart** TESNPC::GetBaseOverlays() const
	{
		using func_t = function_type_t<decltype(&TESNPC::GetBaseOverlays)>;
		REL::Offset<func_t*> func(Offset::TESNPC::GetBaseOverlays);
		return func(this);
	}


	TESNPC::Sex TESNPC::GetSex()
	{
		return IsFemale() ? Sex::kFemale : Sex::kMale;
	}


	BGSHeadPart* TESNPC::GetCurrentHeadPartByType(BGSHeadPart::Type a_type)
	{
		return HasOverlays() ? GetHeadPartOverlayByType(a_type) : GetHeadPartByType(a_type);
	}


	BGSHeadPart* TESNPC::GetHeadPartByType(BGSHeadPart::Type a_type)
	{
		if (headparts) {
			for (UInt8 i = 0; i < numHeadParts; ++i) {
				if (headparts[i] && headparts[i]->type == a_type) {
					return headparts[i];
				}
			}
		}
		return 0;
	}


	BGSHeadPart* TESNPC::GetHeadPartOverlayByType(BGSHeadPart::Type a_type)
	{
		auto numOverlays = GetNumBaseOverlays();
		auto overlays = GetBaseOverlays();
		if (overlays) {
			for (UInt8 i = 0; i < numOverlays; ++i) {
				if (overlays[i]->type == a_type) {
					return overlays[i];
				}
			}
		}
		return 0;
	}


	UInt32 TESNPC::GetNumBaseOverlays() const
	{
		using func_t = function_type_t<decltype(&TESNPC::GetNumBaseOverlays)>;
		REL::Offset<func_t*> func(Offset::TESNPC::GetNumBaseOverlays);
		return func(this);
	}


	TESRace* TESNPC::GetRace()
	{
		return race;
	}


	TESNPC* TESNPC::GetRootTemplate()
	{
		auto node = nextTemplate;
		if (node) {
			while (node->nextTemplate) {
				node = node->nextTemplate;
			}
		}
		return node;
	}


	float TESNPC::Layer::GetInterpolationValue() const
	{
		return static_cast<float>(interpolationValue) / 100.0;
	}


	bool TESNPC::HasOverlays()
	{
		using func_t = function_type_t<decltype(&TESNPC::HasOverlays)>;
		REL::Offset<func_t*> func(Offset::TESNPC::HasOverlays);
		return func(this);
	}


	void TESNPC::SetFaceTexture(BGSTextureSet* a_textureSet)
	{
		if (!headData && a_textureSet) {
			headData = new HeadData();
		}

		if (headData) {
			headData->headTexture = a_textureSet;
		}
	}


	void TESNPC::SetHairColor(BGSColorForm* a_hairColor)
	{
		if (!headData && a_hairColor) {
			headData = new HeadData();
		}

		if (headData) {
			headData->hairColor = a_hairColor;
		}
	}


	void TESNPC::SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, bool a_fromTint)
	{
		using func_t = function_type_t<decltype(&TESNPC::SetSkinFromTint)>;
		REL::Offset<func_t*> func(Offset::TESNPC::SetSkinFromTint);
		return func(this, a_result, a_tintMask, a_fromTint);
	}


	void TESNPC::UpdateNeck(BSFaceGenNiNode* a_faceNode)
	{
		using func_t = function_type_t<decltype(&TESNPC::UpdateNeck)>;
		REL::Offset<func_t*> func(Offset::TESNPC::UpdateNeck);
		return func(this, a_faceNode);
	}
}
