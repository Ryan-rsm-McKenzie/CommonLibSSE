#include "RE/TESNPC.h"

#include "skse64/GameObjects.h"  // TESNPC

class TESRace;


namespace RE
{
	char TESNPC::GetSex()
	{
		typedef char _GetSex_t(TESNPC* a_this);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_GetSex_GetPtr());
		static _GetSex_t* _GetSex = reinterpret_cast<_GetSex_t*>(*ptr);
		return _GetSex(this);
	}


	bool TESNPC::HasOverlays()
	{
		typedef bool _HasOverlays_t(TESNPC* a_this);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_HasOverlays_GetPtr());
		static _HasOverlays_t* _HasOverlays = reinterpret_cast<_HasOverlays_t*>(*ptr);
		return _HasOverlays(this);
	}


	void TESNPC::ChangeHeadPart(BGSHeadPart* a_target)
	{
		typedef void _ChangeHeadPart_t(TESNPC* a_this, BGSHeadPart* a_target);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_ChangeHeadPart_GetPtr());
		static _ChangeHeadPart_t* _ChangeHeadPart = reinterpret_cast<_ChangeHeadPart_t*>(*ptr);
		_ChangeHeadPart(this, a_target);
	}


	void TESNPC::ApplyMorph(MorphAction* a_morphAction)
	{
		typedef void _ApplyMorph_t(TESNPC* a_this, MorphAction* a_morphAction);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_ApplyMorph_GetPtr());
		static _ApplyMorph_t* _ApplyMorph = reinterpret_cast<_ApplyMorph_t*>(*ptr);
		_ApplyMorph(this, a_morphAction);
	}


	void TESNPC::UpdateNeck(BSFaceGenNiNode* a_faceNode)
	{
		typedef void _UpdateNeck_t(TESNPC* a_this, BSFaceGenNiNode* a_faceNode);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_UpdateNeck_GetPtr());
		static _UpdateNeck_t* _UpdateNeck = reinterpret_cast<_UpdateNeck_t*>(*ptr);
		_UpdateNeck(this, a_faceNode);
	}


	void TESNPC::SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, UInt32 a_compute, UInt32 a_unk4)
	{
		typedef void _SetSkinFromTint_t(TESNPC* a_this, NiColorA* a_result, TintMask* a_tintMask, UInt32 a_compute, UInt32 a_unk4);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESNPC*>(this)->_SetSkinFromTint_GetPtr());
		static _SetSkinFromTint_t* _SetSkinFromTint = reinterpret_cast<_SetSkinFromTint_t*>(*ptr);
		_SetSkinFromTint(this, a_result, a_tintMask, a_compute, a_unk4);
	}


	void TESNPC::SetFaceTexture(BGSTextureSet* a_textureSet)
	{
		typedef void _SetFaceTexture_t(TESNPC* a_this, BGSTextureSet* a_textureSet);
		static _SetFaceTexture_t* _SetFaceTexture = reinterpret_cast<_SetFaceTexture_t*>(GetFnAddr(&::TESNPC::SetFaceTexture));
		_SetFaceTexture(this, a_textureSet);
	}


	void TESNPC::SetHairColor(BGSColorForm* a_hairColor)
	{
		typedef void _SetHairColor_t(TESNPC* a_this, BGSColorForm* a_hairColor);
		static _SetHairColor_t* _SetHairColor = reinterpret_cast<_SetHairColor_t*>(GetFnAddr(&::TESNPC::SetHairColor));
		_SetHairColor(this, a_hairColor);
	}


	BGSHeadPart* TESNPC::GetHeadPartByType(UInt32 a_type)
	{
		typedef BGSHeadPart* _GetHeadPartByType_t(TESNPC* a_this, UInt32 a_type);
		static _GetHeadPartByType_t* _GetHeadPartByType = reinterpret_cast<_GetHeadPartByType_t*>(GetFnAddr(&::TESNPC::GetCurrentHeadPartByType));
		return _GetHeadPartByType(this, a_type);
	}


	BGSHeadPart* TESNPC::GetHeadPartOverlayByType(UInt32 a_type)
	{
		typedef BGSHeadPart* _GetHeadPartOverlayByType_t(TESNPC* a_this, UInt32 a_type);
		static _GetHeadPartOverlayByType_t* _GetHeadPartOverlayByType = reinterpret_cast<_GetHeadPartOverlayByType_t*>(GetFnAddr(&::TESNPC::GetHeadPartOverlayByType));
		return _GetHeadPartOverlayByType(this, a_type);
	}


	BGSHeadPart* TESNPC::GetCurrentHeadPartByType(UInt32 a_type)
	{
		typedef BGSHeadPart* _GetCurrentHeadPartByType_t(TESNPC* a_this, UInt32 a_type);
		static _GetCurrentHeadPartByType_t* _GetCurrentHeadPartByType = reinterpret_cast<_GetCurrentHeadPartByType_t*>(GetFnAddr(&::TESNPC::GetCurrentHeadPartByType));
		return _GetCurrentHeadPartByType(this, a_type);
	}


	TESNPC* TESNPC::GetRootTemplate()
	{
		typedef TESNPC* _GetRootTemplate_t(TESNPC* a_this);
		static _GetRootTemplate_t* _GetRootTemplate = reinterpret_cast<_GetRootTemplate_t*>(GetFnAddr(&::TESNPC::GetRootTemplate));
		return _GetRootTemplate(this);
	}


	TESRace* TESNPC::GetRace()
	{
		return race;
	}
}
