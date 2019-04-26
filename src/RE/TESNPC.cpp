#include "RE/TESNPC.h"

#include "skse64/GameObjects.h"  // TESNPC


namespace RE
{
	float TESNPC::Layer::GetInterpolationValue() const
	{
		return static_cast<float>(interpolationValue) / 100.0;
	}


	TESNPC::Sex TESNPC::GetSex()
	{
		using func_t = function_type_t<decltype(&TESNPC::GetSex)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESNPC, GetSex, func_t*);
		return func(this);
	}


	bool TESNPC::HasOverlays()
	{
		using func_t = function_type_t<decltype(&TESNPC::HasOverlays)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESNPC, HasOverlays, func_t*);
		return func(this);
	}


	void TESNPC::ChangeHeadPart(BGSHeadPart* a_target)
	{
		using func_t = function_type_t<decltype(&TESNPC::ChangeHeadPart)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESNPC, ChangeHeadPart, func_t*);
		return func(this, a_target);
	}


	void TESNPC::UpdateNeck(BSFaceGenNiNode* a_faceNode)
	{
		using func_t = function_type_t<decltype(&TESNPC::UpdateNeck)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESNPC, UpdateNeck, func_t*);
		return func(this, a_faceNode);
	}


	void TESNPC::SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, UInt32 a_compute)
	{
		using func_t = function_type_t<decltype(&TESNPC::SetSkinFromTint)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESNPC, SetSkinFromTint, func_t*);
		return func(this, a_result, a_tintMask, a_compute);
	}


	void TESNPC::SetFaceTexture(BGSTextureSet* a_textureSet)
	{
		using func_t = function_type_t<decltype(&TESNPC::SetFaceTexture)>;
		func_t* func = unrestricted_cast<func_t*>(&::TESNPC::SetFaceTexture);
		return func(this, a_textureSet);
	}


	void TESNPC::SetHairColor(BGSColorForm* a_hairColor)
	{
		using func_t = function_type_t<decltype(&TESNPC::SetHairColor)>;
		func_t* func = unrestricted_cast<func_t*>(&::TESNPC::SetHairColor);
		return func(this, a_hairColor);
	}


	BGSHeadPart* TESNPC::GetHeadPartByType(UInt32 a_type)
	{
		using func_t = function_type_t<decltype(&TESNPC::GetHeadPartByType)>;
		func_t* func = unrestricted_cast<func_t*>(&::TESNPC::GetHeadPartByType);
		return func(this, a_type);
	}


	BGSHeadPart* TESNPC::GetHeadPartOverlayByType(UInt32 a_type)
	{
		using func_t = function_type_t<decltype(&TESNPC::GetHeadPartOverlayByType)>;
		func_t* func = unrestricted_cast<func_t*>(&::TESNPC::GetHeadPartOverlayByType);
		return func(this, a_type);
	}


	BGSHeadPart* TESNPC::GetCurrentHeadPartByType(UInt32 a_type)
	{
		using func_t = function_type_t<decltype(&TESNPC::GetCurrentHeadPartByType)>;
		func_t* func = unrestricted_cast<func_t*>(&::TESNPC::GetCurrentHeadPartByType);
		return func(this, a_type);
	}


	TESNPC* TESNPC::GetRootTemplate()
	{
		using func_t = function_type_t<decltype(&TESNPC::GetRootTemplate)>;
		func_t* func = unrestricted_cast<func_t*>(&::TESNPC::GetRootTemplate);
		return func(this);
	}


	TESRace* TESNPC::GetRace()
	{
		return race;
	}
}
