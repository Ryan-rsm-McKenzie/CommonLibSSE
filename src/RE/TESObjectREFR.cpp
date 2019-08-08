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
#include "RE/FormTraits.h"  // As
#include "RE/InventoryChanges.h"  // InventoryChanges
#include "RE/NiNode.h"  // NiNode
#include "RE/Offsets.h"
#include "RE/TESActorBase.h"  // TESActorBase
#include "RE/TESFaction.h"  // TESFaction
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESNPC.h"  // TESNPC
#include "RE/TESObjectCONT.h"  // TESObjectCONT
#include "REL/Relocation.h"


namespace RE
{
	bool TESObjectREFR::LookupByHandle(const RefHandle& a_refHandle, TESObjectREFRPtr& a_refrOut)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::LookupByHandle)>;
		func_t* func = reinterpret_cast<func_t*>(::LookupREFRObjectByHandle.GetUIntPtr());
		return func(a_refHandle, a_refrOut);
	}


	void TESObjectREFR::ActivateRefChildren(TESObjectREFR* a_activator)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::ActivateRefChildren)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::ActivateRefChildren);
		return func(this, a_activator);
	}


	RefHandle TESObjectREFR::CreateRefHandle()
	{
		RefHandle refHandle = *g_invalidRefHandle;
		if (GetRefCount() > 0) {
			CreateRefHandle_Impl(refHandle, this);
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


	TESBoundObject* TESObjectREFR::GetBaseObject() const
	{
		return baseForm;
	}


	float TESObjectREFR::GetBaseScale() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetBaseScale)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, GetBaseScale, func_t*);
		return func(this);
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


	TESFaction* TESObjectREFR::GetFactionOwner() const
	{
		auto xOwnership = extraData.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::Faction)) {
			return static_cast<TESFaction*>(xOwnership->owner);
		} else {
			return 0;
		}
	}


	const char* TESObjectREFR::GetFullName() const
	{
		const char* result = 0;
		if (baseForm) {
			auto fullName = baseForm->As<TESFullName*>();
			if (fullName) {
				result = fullName->GetName();
			}
		}
		return result;
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


	TESObjectREFR* TESObjectREFR::GetLinkedRef(BGSKeyword* a_keyword)
	{
		return extraData.GetLinkedRef(a_keyword);
	}


	SInt32 TESObjectREFR::GetLockLevel() const
	{
		auto state = GetLockState();
		return state ? state->GetLockLevel(this) : -1 * std::numeric_limits<SInt32>::max();
	}


	LockState* TESObjectREFR::GetLockState() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetLockState)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetLockState);
		return func(this);
	}


	NiAVObject* TESObjectREFR::GetNodeByName(const BSFixedString& a_nodeName)
	{
		auto node = GetNiNode();
		return node ? node->GetObjectByName(a_nodeName) : 0;
	}


	UInt32 TESObjectREFR::GetNumItems(bool a_useDataHandlerChanges, bool a_arg2)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetNumItems)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetNumItems);
		return func(this, a_useDataHandlerChanges, a_arg2);
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


	const char* TESObjectREFR::GetReferenceName() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetReferenceName)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, GetReferenceName, func_t*);
		return func(this);
	}


	float TESObjectREFR::GetWeight() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetWeight)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, GetWeight, func_t*);
		return func(this);
	}


	TESWorldSpace* TESObjectREFR::GetWorldspace() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetWorldspace)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, GetWorldspace, func_t*);
		return func(this);
	}


	bool TESObjectREFR::HasCollision() const
	{
		return (flags & RecordFlags::kCollisionsDisabled) == 0;
	}


	bool TESObjectREFR::HasInventoryChanges() const
	{
		auto xContainerChanges = extraData.GetByType<ExtraContainerChanges>();
		auto changes = xContainerChanges ? xContainerChanges->changes : 0;
		return changes != 0;
	}


	bool TESObjectREFR::Is3DLoaded() const
	{
		return GetNiNode() != 0;
	}


	bool TESObjectREFR::IsActivationBlocked() const
	{
		auto xFlags = extraData.GetByType<ExtraFlags>();
		return xFlags && xFlags->IsActivationBlocked();
	}


	bool TESObjectREFR::IsDisabled() const
	{
		return (flags & RecordFlags::kInitiallyDisabled) != 0;
	}


	bool TESObjectREFR::IsLocked() const
	{
		auto state = GetLockState();
		return state && state->lockLevel > 0;
	}


	bool TESObjectREFR::IsMarkedForDeletion() const
	{
		return (flags & RecordFlags::kDeleted) != 0;
	}


	bool TESObjectREFR::IsOffLimits() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::IsOffLimits)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectREFR, IsOffLimits, func_t*);
		return func(this);
	}


	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, const BSFixedString& a_nodeName)
	{
		auto node = a_target->GetNiNode();
		if (!node) {
			_DMESSAGE("Cannot move the target because it does not have 3D");
			return false;
		}

		auto object = node->GetObjectByName(a_nodeName);
		if (!object) {
			_DMESSAGE("Target does not have a node named %s", a_nodeName.c_str());
			return false;
		}

		return MoveToNode(a_target, object);
	}


	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, NiAVObject* a_node)
	{
		auto& position = a_node->worldTransform.translate;
		NiPoint3 rotation;
		a_node->worldTransform.rotate.ToEulerAnglesXYZ(rotation);
		RefHandle handle = a_target->CreateRefHandle();
		MoveTo_Impl(handle, a_target->GetParentCell(), GetWorldspace(), position, rotation);
		return true;
	}


	void TESObjectREFR::PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::PlayAnimation)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::PlayAnimation);
		return func(this, a_manager, a_toSeq, a_fromSeq, a_arg4);
	}


	void TESObjectREFR::SetActivationBlocked(bool a_blocked)
	{
		extraData.SetExtraFlags(ExtraFlags::Flag::kActivationBlocked, a_blocked);
	}


	void TESObjectREFR::SetCollision(bool a_enable)
	{
		if (a_enable) {
			flags &= ~RecordFlags::kCollisionsDisabled;
		} else {
			flags |= RecordFlags::kCollisionsDisabled;
		}
	}


	bool TESObjectREFR::SetDisplayName(const BSFixedString& a_name, bool a_force)
	{
		bool renamed = false;

		auto xTextData = extraData.GetByType<ExtraTextDisplayData>();
		if (xTextData) {
			bool inUse = xTextData->message || xTextData->owner;
			if (inUse && a_force) {
				xTextData->message = 0;
				xTextData->owner = 0;
			}
			renamed = !inUse || a_force;
			xTextData->SetName(a_name.c_str());
		} else {
			xTextData = new ExtraTextDisplayData(a_name.c_str());
			extraData.Add(xTextData);
			renamed = true;
		}

		return renamed;
	}


	bool TESObjectREFR::SetMotionType(MotionType a_motionType, bool a_allowActivate)
	{
		auto node = GetNiNode();
		if (!node) {
			_DMESSAGE("Target does not have 3D");
			return false;
		}

		return node->SetMotionType(static_cast<UInt32>(a_motionType), true, false, a_allowActivate);
	}


	void TESObjectREFR::SetPosition(float a_x, float a_y, float a_z)
	{
		return SetPosition(NiPoint3(a_x, a_y, a_z));
	}


	void TESObjectREFR::SetPosition(NiPoint3 a_pos)
	{
		MoveTo_Impl(*g_invalidRefHandle, GetParentCell(), GetWorldspace(), a_pos, rot);
	}


	void TESObjectREFR::CreateRefHandle_Impl(RefHandle& a_refHandle, TESObjectREFR* a_refrTo)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::CreateRefHandle_Impl)>;
		func_t* func = unrestricted_cast<func_t*>(::CreateRefHandleByREFR.GetUIntPtr());
		return func(a_refHandle, a_refrTo);
	}


	void TESObjectREFR::MoveTo_Impl(RefHandle& a_targetHandle, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, NiPoint3& a_position, NiPoint3& a_rotation)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::MoveTo_Impl)>;
		func_t* func = unrestricted_cast<func_t*>(::MoveRefrToPosition.GetUIntPtr());
		return func(this, a_targetHandle, a_targetCell, a_selfWorldSpace, a_position, a_rotation);
	}
}
