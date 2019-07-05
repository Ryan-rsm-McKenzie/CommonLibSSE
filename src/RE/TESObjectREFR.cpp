#include "RE/TESObjectREFR.h"

#include "skse64/GameReferences.h"  // TESObjectREFR

#include <limits>  // numeric_limits

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/ExtraContainerChanges.h"  // ExtraContainerChanges
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/ExtraFlags.h"  // ExtraFlags
#include "RE/ExtraLock.h"  // ExtraLock
#include "RE/ExtraOwnership.h"  // ExtraOwnership
#include "RE/ExtraReferenceHandle.h"  // ExtraReferenceHandle
#include "RE/ExtraTextDisplayData.h"  // ExtraTextDisplayData
#include "RE/InventoryChanges.h"  // InventoryChanges
#include "RE/Offsets.h"
#include "RE/TESActorBase.h"  // TESActorBase
#include "RE/TESFaction.h"  // TESFaction
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESNPC.h"  // TESNPC
#include "RE/TESObjectCONT.h"  // TESObjectCONT
#include "REL/Relocation.h"


namespace RE
{
	bool TESObjectREFR::LookupByHandle(RefHandle& a_refHandle, TESObjectREFRPtr& a_refrOut)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::LookupByHandle)>;
		func_t* func = reinterpret_cast<func_t*>(::LookupREFRObjectByHandle.GetUIntPtr());
		return func(a_refHandle, a_refrOut);
	}


	float TESObjectREFR::GetBaseScale() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetBaseScale)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, GetBaseScale, func_t*);
		return func(this);
	}


	bool TESObjectREFR::IsOffLimits() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::IsOffLimits)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, IsOffLimits, func_t*);
		return func(this);
	}


	float TESObjectREFR::GetWeight() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetWeight)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, GetWeight, func_t*);
		return func(this);
	}


	const char* TESObjectREFR::GetReferenceName() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetReferenceName)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, GetReferenceName, func_t*);
		return func(this);
	}


	TESWorldSpace* TESObjectREFR::GetWorldspace() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetWorldspace)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, GetWorldspace, func_t*);
		return func(this);
	}


	RefHandle TESObjectREFR::GetRefHandle() const
	{
		auto xRefHandle = extraData.GetByType<ExtraReferenceHandle>();
		return xRefHandle ? xRefHandle->handle : *g_invalidRefHandle;
	}


	RefHandle TESObjectREFR::CreateRefHandle()
	{
		if (GetRefCount() > 0) {
			RefHandle refHandle = *g_invalidRefHandle;
			CreateRefHandle_Internal(refHandle, this);
			return refHandle;
		} else {
			return *g_invalidRefHandle;
		}
	}


	RefHandle TESObjectREFR::GetOrCreateRefHandle()
	{
		RefHandle refHandle = GetRefHandle();
		if (refHandle == *g_invalidRefHandle) {
			refHandle = CreateRefHandle();
		}
		return refHandle;
	}


	TESNPC* TESObjectREFR::GetActorOwner() const
	{
		auto xOwnership = extraData.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::ActorCharacter)) {
			return static_cast<TESNPC*>(xOwnership->owner);
		} else {
			return 0;
		}
	}


	TESForm* TESObjectREFR::GetBaseObject() const
	{
		return baseForm;
	}


	TESContainer* TESObjectREFR::GetContainer() const
	{
		TESContainer* container = 0;
		if (baseForm) {
			switch (baseForm->formType) {
			case FormType::Container:
				container = static_cast<TESObjectCONT*>(baseForm);
				break;
			case FormType::NPC:
				container = static_cast<TESActorBase*>(baseForm);
				break;
			}
		}
		return container;
	}


	const char* TESObjectREFR::GetFullName() const
	{
		const char* result = 0;
		if (baseForm) {
			auto fullName = skyrim_cast<TESFullName*>(baseForm);
			if (fullName) {
				result = fullName->GetName();
			}
		}
		return result;
	}


	TESFaction* TESObjectREFR::GetFactionOwner() const
	{
		auto xOwnership = extraData.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::Faction)) {
			return static_cast<TESFaction*>(xOwnership->owner);
		} else {
			return 0;
		}
	}


	TESForm* TESObjectREFR::GetOwner() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetOwner)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetOwner);
		return func(this);
	}


	TESObjectCELL* TESObjectREFR::GetParentCell() const
	{
		return parentCell;
	}


	float TESObjectREFR::GetPositionX() const
	{
		return pos.x;
	}


	float TESObjectREFR::GetPositionY() const
	{
		return pos.y;
	}


	float TESObjectREFR::GetPositionZ() const
	{
		return pos.z;
	}


	bool TESObjectREFR::Is3DLoaded() const
	{
		return GetNiNode() != 0;
	}


	bool TESObjectREFR::IsMarkedForDeletion() const
	{
		return (flags & RecordFlags::kDeleted) != 0;
	}


	bool TESObjectREFR::IsDisabled() const
	{
		return (flags & RecordFlags::kInitiallyDisabled) != 0;
	}


	bool TESObjectREFR::IsActivationBlocked() const
	{
		auto xFlags = extraData.GetByType<ExtraFlags>();
		return xFlags && xFlags->IsActivationBlocked();
	}


	void TESObjectREFR::SetActivationBlocked(bool a_blocked)
	{
		extraData.SetExtraFlags(ExtraFlags::Flag::kActivationBlocked, a_blocked);
	}


	bool TESObjectREFR::IsLocked() const
	{
		auto state = GetLockState();
		return state && state->lockLevel > 0;
	}


	LockState* TESObjectREFR::GetLockState() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetLockState)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetLockState);
		return func(this);
	}


	SInt32 TESObjectREFR::GetLockLevel() const
	{
		auto state = GetLockState();
		return state ? state->GetLockLevel(this) : -1 * std::numeric_limits<SInt32>::max();
	}


	UInt32 TESObjectREFR::GetNumItems(bool a_useDataHandlerChanges, bool a_arg2)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetNumItems)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetNumItems);
		return func(this, a_useDataHandlerChanges, a_arg2);
	}


	bool TESObjectREFR::HasInventoryChanges() const
	{
		auto xContainerChanges = extraData.GetByType<ExtraContainerChanges>();
		auto changes = xContainerChanges ? xContainerChanges->changes : 0;
		return changes != 0;
	}


	InventoryChanges* TESObjectREFR::GetInventoryChanges()
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetInventoryChanges)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetInventoryChanges);

		auto xContainerChanges = extraData.GetByType<ExtraContainerChanges>();
		auto changes = xContainerChanges ? xContainerChanges->changes : 0;
		if (!changes) {
			changes = func(this);
			if (changes) {
				changes->InitContainer();
				changes->GenerateLeveledListChanges();
			}
		}
		return changes;
	}


	bool TESObjectREFR::SetDisplayName(const BSFixedString& name, bool force)
	{
		bool renamed = false;

		auto xTextData = extraData.GetByType<ExtraTextDisplayData>();
		if (xTextData) {
			bool inUse = (xTextData->message || xTextData->owner);
			if (inUse && force) {
				xTextData->message = 0;
				xTextData->owner = 0;
			}
			renamed = (!inUse || force);
			xTextData->SetName(name.c_str());
		} else {
			xTextData = new ExtraTextDisplayData(name.c_str());
			extraData.Add(xTextData);
			renamed = true;
		}

		return renamed;
	}


	UInt32 TESObjectREFR::ActivateRefChildren(TESObjectREFR* a_activator)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::ActivateRefChildren)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::ActivateRefChildren);
		return func(this, a_activator);
	}


	void TESObjectREFR::PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::PlayAnimation)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::PlayAnimation);
		return func(this, a_manager, a_toSeq, a_fromSeq, a_arg4);
	}


	void TESObjectREFR::CreateRefHandle_Internal(UInt32& a_refHandle, TESObjectREFR* a_refrTo)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::CreateRefHandle_Internal)>;
		func_t* func = reinterpret_cast<func_t*>(::CreateRefHandleByREFR.GetUIntPtr());
		return func(a_refHandle, a_refrTo);
	}
}
