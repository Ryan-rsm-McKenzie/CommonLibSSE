#include "RE/TESNPC.h"

#include "skse64/GameObjects.h"  // TESNPC

class TESRace;


namespace RE
{
	float TESNPC::Layer::GetInterpolationValue() const
	{
		return static_cast<float>(interpolationValue) / 100.0;
	}


	TESNPC::Sex TESNPC::GetSex()
	{
		typedef Sex _GetSex_t(TESNPC* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_GetSex_GetPtr());
		_GetSex_t* _GetSex = reinterpret_cast<_GetSex_t*>(*ptr);
		return _GetSex(this);
	}


	bool TESNPC::HasOverlays()
	{
		typedef bool _HasOverlays_t(TESNPC* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_HasOverlays_GetPtr());
		_HasOverlays_t* _HasOverlays = reinterpret_cast<_HasOverlays_t*>(*ptr);
		return _HasOverlays(this);
	}


	void TESNPC::ChangeHeadPart(BGSHeadPart* a_target)
	{
		typedef void _ChangeHeadPart_t(TESNPC* a_this, BGSHeadPart* a_target);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_ChangeHeadPart_GetPtr());
		_ChangeHeadPart_t* _ChangeHeadPart = reinterpret_cast<_ChangeHeadPart_t*>(*ptr);
		_ChangeHeadPart(this, a_target);
	}


	void TESNPC::UpdateNeck(BSFaceGenNiNode* a_faceNode)
	{
		typedef void _UpdateNeck_t(TESNPC* a_this, BSFaceGenNiNode* a_faceNode);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_UpdateNeck_GetPtr());
		_UpdateNeck_t* _UpdateNeck = reinterpret_cast<_UpdateNeck_t*>(*ptr);
		_UpdateNeck(this, a_faceNode);
	}


	void TESNPC::SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, UInt32 a_compute)
	{
		typedef void _SetSkinFromTint_t(TESNPC* a_this, NiColorA* a_result, TintMask* a_tintMask, UInt32 a_compute);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_SetSkinFromTint_GetPtr());
		_SetSkinFromTint_t* _SetSkinFromTint = reinterpret_cast<_SetSkinFromTint_t*>(*ptr);
		_SetSkinFromTint(this, a_result, a_tintMask, a_compute);
	}


	void TESNPC::SetFaceTexture(BGSTextureSet* a_textureSet)
	{
		typedef void _SetFaceTexture_t(TESNPC* a_this, BGSTextureSet* a_textureSet);
		_SetFaceTexture_t* _SetFaceTexture = reinterpret_cast<_SetFaceTexture_t*>(GetFnAddr(&::TESNPC::SetFaceTexture));
		_SetFaceTexture(this, a_textureSet);
	}


	void TESNPC::SetHairColor(BGSColorForm* a_hairColor)
	{
		typedef void _SetHairColor_t(TESNPC* a_this, BGSColorForm* a_hairColor);
		_SetHairColor_t* _SetHairColor = reinterpret_cast<_SetHairColor_t*>(GetFnAddr(&::TESNPC::SetHairColor));
		_SetHairColor(this, a_hairColor);
	}


	BGSHeadPart* TESNPC::GetHeadPartByType(UInt32 a_type)
	{
		typedef BGSHeadPart* _GetHeadPartByType_t(TESNPC* a_this, UInt32 a_type);
		_GetHeadPartByType_t* _GetHeadPartByType = reinterpret_cast<_GetHeadPartByType_t*>(GetFnAddr(&::TESNPC::GetCurrentHeadPartByType));
		return _GetHeadPartByType(this, a_type);
	}


	BGSHeadPart* TESNPC::GetHeadPartOverlayByType(UInt32 a_type)
	{
		typedef BGSHeadPart* _GetHeadPartOverlayByType_t(TESNPC* a_this, UInt32 a_type);
		_GetHeadPartOverlayByType_t* _GetHeadPartOverlayByType = reinterpret_cast<_GetHeadPartOverlayByType_t*>(GetFnAddr(&::TESNPC::GetHeadPartOverlayByType));
		return _GetHeadPartOverlayByType(this, a_type);
	}


	BGSHeadPart* TESNPC::GetCurrentHeadPartByType(UInt32 a_type)
	{
		typedef BGSHeadPart* _GetCurrentHeadPartByType_t(TESNPC* a_this, UInt32 a_type);
		_GetCurrentHeadPartByType_t* _GetCurrentHeadPartByType = reinterpret_cast<_GetCurrentHeadPartByType_t*>(GetFnAddr(&::TESNPC::GetCurrentHeadPartByType));
		return _GetCurrentHeadPartByType(this, a_type);
	}


	TESNPC* TESNPC::GetRootTemplate()
	{
		typedef TESNPC* _GetRootTemplate_t(TESNPC* a_this);
		_GetRootTemplate_t* _GetRootTemplate = reinterpret_cast<_GetRootTemplate_t*>(GetFnAddr(&::TESNPC::GetRootTemplate));
		return _GetRootTemplate(this);
	}


	TESRace* TESNPC::GetRace()
	{
		return race;
	}
}
