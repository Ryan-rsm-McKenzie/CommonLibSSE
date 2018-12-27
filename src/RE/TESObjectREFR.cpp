#include "RE/TESObjectREFR.h"

#undef min
#undef max

#include "skse64/GameFormComponents.h"  // TESContainer
#include "skse64/GameReferences.h"  // TESObjectREFR
#include "skse64/GameRTTI.h"  // DYNAMIC_CAST

#include <limits>  // numeric_limits

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/ExtraContainerChanges.h"  // ExtraContainerChanges
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/ExtraLock.h"  // ExtraLock
#include "RE/ExtraOwnership.h"  // ExtraOwnership
#include "RE/ExtraReferenceHandle.h"  // ExtraReferenceHandle
#include "RE/ExtraTextDisplayData.h"  // ExtraTextDisplayData
#include "RE/Offsets.h"
#include "RE/TESActorBase.h"  // TESActorBase
#include "RE/TESFaction.h"  // TESFaction
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESNPC.h"  // TESNPC
#include "RE/TESObjectCONT.h"  // TESObjectCONT


namespace RE
{
	float TESObjectREFR::GetBaseScale()
	{
		typedef float _GetBaseScale_t(TESObjectREFR* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESObjectREFR*>(this)->_GetBaseScale_GetPtr());
		_GetBaseScale_t* _GetBaseScale = reinterpret_cast<_GetBaseScale_t*>(*ptr);
		return _GetBaseScale(this);
	}


	bool TESObjectREFR::IsOffLimits()
	{
		typedef bool _IsOffLimits_t(TESObjectREFR* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESObjectREFR*>(this)->_IsOffLimits_GetPtr());
		_IsOffLimits_t* _IsOffLimits = reinterpret_cast<_IsOffLimits_t*>(*ptr);
		return _IsOffLimits(this);
	}


	float TESObjectREFR::GetWeight()
	{
		typedef float _GetWeight_t(TESObjectREFR* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESObjectREFR*>(this)->_GetWeight_GetPtr());
		_GetWeight_t* _GetWeight = reinterpret_cast<_GetWeight_t*>(*ptr);
		return _GetWeight(this);
	}


	const char* TESObjectREFR::GetReferenceName()
	{
		typedef const char* _GetReferenceName_t(TESObjectREFR* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESObjectREFR*>(this)->_GetReferenceName_GetPtr());
		_GetReferenceName_t* _GetReferenceName = reinterpret_cast<_GetReferenceName_t*>(*ptr);
		return _GetReferenceName(this);
	}


	TESWorldSpace* TESObjectREFR::GetWorldspace()
	{
		typedef TESWorldSpace* _GetWorldspace_t(TESObjectREFR* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESObjectREFR*>(this)->_GetWorldspace_GetPtr());
		_GetWorldspace_t* _GetWorldspace = reinterpret_cast<_GetWorldspace_t*>(*ptr);
		return _GetWorldspace(this);
	}


	UInt32 TESObjectREFR::GetRefHandle()
	{
		ExtraReferenceHandle* xRefHandle = extraData.GetByType<ExtraReferenceHandle>();
		return xRefHandle ? xRefHandle->handle : *g_invalidRefHandle;
	}


	UInt32 TESObjectREFR::CreateRefHandle()
	{
		typedef void _CreateRefHandleByREFR_t(UInt32& a_refHandleOut, TESObjectREFR* a_refr);
		_CreateRefHandleByREFR_t* _CreateRefHandleByREFR = reinterpret_cast<_CreateRefHandleByREFR_t*>(::CreateRefHandleByREFR.GetUIntPtr());

		if (GetRefCount() > 0) {
			UInt32 refHandle = 0;
			_CreateRefHandleByREFR(refHandle, this);
			return refHandle;
		} else {
			return *g_invalidRefHandle;
		}
	}


	UInt32 TESObjectREFR::GetOrCreateRefHandle()
	{
		UInt32 refHandle = GetRefHandle();
		if (refHandle == *g_invalidRefHandle) {
			refHandle = CreateRefHandle();
		}
		return refHandle;
	}


	TESNPC* TESObjectREFR::GetActorOwner()
	{
		ExtraOwnership* exOwnership = static_cast<ExtraOwnership*>(extraData.GetByType(ExtraDataType::kOwnership));
		if (exOwnership && exOwnership->owner && exOwnership->owner->formType == FormType::Character) {
			return static_cast<TESNPC*>(exOwnership->owner);
		} else {
			return 0;
		}
	}


	TESForm* TESObjectREFR::GetBaseObject()
	{
		return baseForm;
	}


	TESContainer* TESObjectREFR::GetContainer()
	{
		TESContainer* container = 0;
		if (baseForm) {
			switch (baseForm->formType) {
			case FormType::Container:
			{
				TESObjectCONT* cont = static_cast<TESObjectCONT*>(baseForm);
				container = static_cast<TESContainer*>(cont);
				break;
			}
			case FormType::NPC:
			{
				TESActorBase* actorBase = static_cast<TESActorBase*>(baseForm);
				container = actorBase;
				break;
			}
			}
		}
		return container;
	}


	const char* TESObjectREFR::GetFullName()
	{
		const char* result = 0;
		if (baseForm) {
			TESFullName* fullName = 0;
			fullName = DYNAMIC_CAST(baseForm, TESForm, TESFullName);
			if (fullName) {
				result = fullName->GetName();
			}
		}
		return result;
	}


	TESFaction* TESObjectREFR::GetFactionOwner()
	{
		ExtraOwnership* exOwnership = static_cast<ExtraOwnership*>(extraData.GetByType(ExtraDataType::kOwnership));
		if (exOwnership && exOwnership->owner && exOwnership->owner->formType == FormType::Faction) {
			return static_cast<TESFaction*>(exOwnership->owner);
		} else {
			return 0;
		}
	}


	TESForm* TESObjectREFR::GetOwner()
	{
		typedef TESForm* _GetOwner_Impl_t(TESObjectREFR* a_this);
		RelocAddr<_GetOwner_Impl_t*> _GetOwner_Impl(TES_OBJECT_REFR_GET_OWNER_IMPL);
		return _GetOwner_Impl(this);
	}


	TESObjectCELL* TESObjectREFR::GetParentCell()
	{
		return parentCell;
	}


	float TESObjectREFR::GetPositionX()
	{
		return pos.x;
	}


	float TESObjectREFR::GetPositionY()
	{
		return pos.y;
	}


	float TESObjectREFR::GetPositionZ()
	{
		return pos.z;
	}


	bool TESObjectREFR::Is3DLoaded()
	{
		return GetNiNode() != 0;
	}


	bool TESObjectREFR::IsMarkedForDeletion()
	{
		return flags.markedForDeletion;
	}


	bool TESObjectREFR::IsDisabled()
	{
		return flags.disabled;
	}


	bool TESObjectREFR::IsIgnoringFriendlyHits()
	{
		return flags.ignoreFriendlyHits;
	}


	bool TESObjectREFR::SetDisplayName(const BSFixedString& name, bool force)
	{
		bool renamed = false;

		ExtraTextDisplayData* xTextData = reinterpret_cast<ExtraTextDisplayData*>(extraData.GetByType(ExtraDataType::kTextDisplayData));
		if (xTextData) {
			bool inUse = (xTextData->message || xTextData->owner);
			if (inUse && force) {
				xTextData->message = nullptr;
				xTextData->owner = nullptr;
			}
			renamed = (!inUse || force);
			xTextData->SetName(name.c_str());
		} else {
			ExtraTextDisplayData* newTextData = ExtraTextDisplayData::Create();
			newTextData->SetName(name.c_str());
			extraData.Add(ExtraDataType::kTextDisplayData, newTextData);
			renamed = true;
		}

		return renamed;
	}


	bool TESObjectREFR::LookupByHandle(UInt32& a_refHandle, TESObjectREFRPtr& a_refrOut)
	{
		typedef bool _Lookup_t(const UInt32& a_refHandle, TESObjectREFRPtr& a_refrOut);
		static _Lookup_t* _Lookup = reinterpret_cast<_Lookup_t*>(::LookupREFRObjectByHandle.GetUIntPtr());

		return _Lookup(a_refHandle, a_refrOut);
	}


	LockState* TESObjectREFR::GetLockState()
	{
		typedef LockState* _GetLockState_Impl_t(TESObjectREFR* a_this);
		RelocAddr<_GetLockState_Impl_t*> _GetLockState_Impl(TES_OBJECT_REFR_GET_LOCK_STATE_IMPL);
		return _GetLockState_Impl(this);
	}


	bool TESObjectREFR::IsLocked()
	{
		LockState* state = GetLockState();
		return (state && state->isLocked);
	}


	SInt32 TESObjectREFR::GetLockLevel()
	{
		LockState* state = GetLockState();
		return state ? state->GetLockLevel(this) : -1 * std::numeric_limits<SInt32>::max();
	}


	UInt32 TESObjectREFR::GetNumItems(bool a_unk1, bool a_unk2)
	{
		typedef UInt32 _GetNumItems_t(TESObjectREFR* a_this, bool a_unk1, bool a_unk2);
		RelocAddr<_GetNumItems_t*> _GetNumItems(TES_OBJECT_REFR_GET_NUM_ITEMS);
		return _GetNumItems(this, a_unk1, a_unk2);
	}


	UInt32 TESObjectREFR::ActivateRefChildren(TESObjectREFR* a_activator)
	{
		typedef UInt32 _ActivateRefChildren_t(TESObjectREFR* a_this, TESObjectREFR* a_activator);
		RelocAddr<_ActivateRefChildren_t*> _ActivateRefChildren(TES_OBJECT_REFR_ACTIVATE_REF_CHILDREN);
		return _ActivateRefChildren(this, a_activator);
	}


	void TESObjectREFR::PlayAnimation(RE::NiControllerManager* a_manager, RE::NiControllerSequence* a_toSeq, RE::NiControllerSequence* a_fromSeq, bool a_unk)
	{
		typedef void _PlayAnimation_t(TESObjectREFR* a_this, NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_unk);
		RelocAddr<_PlayAnimation_t*> _PlayAnimation(TES_OBJECT_REFR_PLAY_ANIMATION);
		_PlayAnimation(this, a_manager, a_toSeq, a_fromSeq, a_unk);
	}


	bool TESObjectREFR::HasInventoryChanges()
	{
		ExtraContainerChanges* xContainerChanges = extraData.GetByType<ExtraContainerChanges>();
		InventoryChanges* changes = xContainerChanges ? xContainerChanges->changes : 0;
		return changes != 0;
	}


	InventoryChanges* TESObjectREFR::GetInventoryChanges()
	{
		typedef InventoryChanges* _GetInventoryChanges_t(TESObjectREFR* a_this);
		RelocAddr<_GetInventoryChanges_t*> _GetInventoryChanges(TES_OBJECT_REFR_GET_INVENTORY_CHANGES);

		ExtraContainerChanges* xContainerChanges = extraData.GetByType<ExtraContainerChanges>();
		InventoryChanges* changes = xContainerChanges ? xContainerChanges->changes : 0;
		if (!changes) {
			changes = _GetInventoryChanges(this);
			if (changes) {
				changes->InitContainer();
				changes->GenerateLeveledListChanges();
			}
		}
		return changes;
	}
}
