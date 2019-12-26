#include "RE/TESObjectREFR.h"

#include "skse64/GameReferences.h"

#include <cassert>
#include <limits>

#include "RE/BSFixedString.h"
#include "RE/ExtraContainerChanges.h"
#include "RE/ExtraDroppedItemList.h"
#include "RE/ExtraFlags.h"
#include "RE/ExtraLock.h"
#include "RE/ExtraOwnership.h"
#include "RE/ExtraReferenceHandle.h"
#include "RE/ExtraTextDisplayData.h"
#include "RE/FormTraits.h"
#include "RE/InventoryChanges.h"
#include "RE/InventoryEntryData.h"
#include "RE/Misc.h"
#include "RE/NiAVObject.h"
#include "RE/NiControllerManager.h"
#include "RE/NiControllerSequence.h"
#include "RE/NiTimeController.h"
#include "RE/Offsets.h"
#include "RE/TESContainer.h"
#include "RE/TESFaction.h"
#include "RE/TESNPC.h"
#include "REL/Relocation.h"


namespace RE
{
	NiPointer<TESObjectREFR> TESObjectREFR::LookupByHandle(RefHandle a_refHandle)
	{
		NiPointer<TESObjectREFR> ref;
		LookupReferenceByHandle(a_refHandle, ref);
		return ref;
	}


	bool TESObjectREFR::LookupByHandle(RefHandle a_refHandle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		return LookupReferenceByHandle(a_refHandle, a_refrOut);
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
			RE::CreateRefHandle(refHandle, this);
		}
		return refHandle;
	}


	TESNPC* TESObjectREFR::GetActorOwner()
	{
		auto xOwnership = extraData.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::ActorCharacter)) {
			return static_cast<TESNPC*>(xOwnership->owner);
		} else {
			return 0;
		}
	}


	NiPoint3 TESObjectREFR::GetAngle() const
	{
		return data.angle;
	}


	float TESObjectREFR::GetAngleX() const
	{
		return data.angle.x;
	}


	float TESObjectREFR::GetAngleY() const
	{
		return data.angle.y;
	}


	float TESObjectREFR::GetAngleZ() const
	{
		return data.angle.z;
	}


	TESBoundObject* TESObjectREFR::GetBaseObject()
	{
		return data.objectReference;
	}


	const TESBoundObject* TESObjectREFR::GetBaseObject() const
	{
		return data.objectReference;
	}


	float TESObjectREFR::GetBaseScale() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetBaseScale)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetBaseScale);
		return func(this);
	}


	TESContainer* TESObjectREFR::GetContainer()
	{
		auto obj = GetBaseObject();
		return obj ? obj->As<TESContainer*>() : 0;
	}


	auto TESObjectREFR::GetDroppedInventory()
		-> DroppedInventoryMap
	{
		return GetDroppedInventory([]([[maybe_unused]] TESBoundObject*) -> bool
		{
			return true;
		});
	}


	auto TESObjectREFR::GetDroppedInventory(llvm::function_ref<bool(TESBoundObject*)> a_filter)
		-> DroppedInventoryMap
	{
		using mapped_type = typename DroppedInventoryMap::mapped_type;

		DroppedInventoryMap results;

		auto droppedList = extraData.GetByType<ExtraDroppedItemList>();
		if (!droppedList) {
			return results;
		}

		for (auto& handle : droppedList->handles) {
			auto ref = LookupByHandle(handle);
			if (!ref) {
				continue;
			}

			auto object = ref->GetBaseObject();
			if (!object || !a_filter(object)) {
				continue;
			}

			auto count = ref->extraData.GetCount();
			auto entry = std::make_unique<InventoryEntryData>(object, count);
			entry->AddExtraList(&ref->extraData);
			auto it = results.insert(std::make_pair(object, mapped_type(count, std::move(entry))));
			assert(it.second);
		}

		return results;
	}


	TESFaction* TESObjectREFR::GetFactionOwner()
	{
		auto xOwnership = extraData.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::Faction)) {
			return static_cast<TESFaction*>(xOwnership->owner);
		} else {
			return 0;
		}
	}


	auto TESObjectREFR::GetInventory()
		-> InventoryMap
	{
		return GetInventory([]([[maybe_unused]] TESBoundObject*) -> bool
		{
			return true;
		});
	}


	auto TESObjectREFR::GetInventory(llvm::function_ref<bool(TESBoundObject*)> a_filter)
		-> InventoryMap
	{
		using mapped_type = typename InventoryMap::mapped_type;

		InventoryMap results;

		auto invChanges = GetInventoryChanges();
		if (invChanges->entryList) {
			for (auto& entry : *invChanges->entryList) {
				if (entry && entry->object && a_filter(entry->object)) {
					auto it = results.insert(std::make_pair(entry->object, mapped_type(entry->countDelta, entry)));
					assert(it.second);
				}
			}
		}

		auto container = GetContainer();
		if (container) {
			container->ForEach([&](TESContainer::Entry* a_entry) -> bool
			{
				if (a_entry->object && a_filter(a_entry->object)) {
					auto it = results.find(a_entry->object);
					if (it == results.end()) {
						auto entryData = new InventoryEntryData(a_entry->object, 0);
						invChanges->AddEntryData(entryData);
						auto insIt = results.insert(std::make_pair(a_entry->object, mapped_type(a_entry->count, entryData)));
						assert(insIt.second);
					} else {
						it->second.first += a_entry->count;
					}
				}
				return true;
			});
		}

		return results;
	}


	InventoryChanges* TESObjectREFR::GetInventoryChanges()
	{
		auto xContChanges = extraData.GetByType<ExtraContainerChanges>();
		if (!xContChanges) {
			xContChanges = new ExtraContainerChanges();
			extraData.Add(xContChanges);
		}

		auto invChanges = xContChanges->changes;
		if (!invChanges) {
			invChanges = new InventoryChanges(this);
			invChanges->InitContainer();
			invChanges->GenerateLeveledListChanges();
			xContChanges->changes = invChanges;
		}

		return invChanges;
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


	LockState* TESObjectREFR::GetLockState()
	{
		return const_cast<LockState*>(GetLockState_Impl());
	}


	const LockState* TESObjectREFR::GetLockState() const
	{
		return GetLockState_Impl();
	}


	const char* TESObjectREFR::GetName() const
	{
		auto obj = GetBaseObject();
		return obj ? obj->GetName() : "";
	}


	NiAVObject* TESObjectREFR::GetNodeByName(const BSFixedString& a_nodeName)
	{
		auto node = Get3D();
		return node ? node->GetObjectByName(a_nodeName) : 0;
	}


	UInt32 TESObjectREFR::GetNumItems(bool a_useDataHandlerChanges, bool a_arg2)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetNumItems)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetNumItems);
		return func(this, a_useDataHandlerChanges, a_arg2);
	}


	TESForm* TESObjectREFR::GetOwner()
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetOwner)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetOwner);
		return func(this);
	}


	TESObjectCELL* TESObjectREFR::GetParentCell()
	{
		return parentCell;
	}


	NiPoint3 TESObjectREFR::GetPosition() const
	{
		return data.location;
	}


	float TESObjectREFR::GetPositionX() const
	{
		return data.location.x;
	}


	float TESObjectREFR::GetPositionY() const
	{
		return data.location.y;
	}


	float TESObjectREFR::GetPositionZ() const
	{
		return data.location.z;
	}


	UInt32 TESObjectREFR::GetRefCount() const
	{
		return BSHandleRefObject::GetRefCount();
	}


	const char* TESObjectREFR::GetReferenceName() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetReferenceName)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetReferenceName);
		return func(this);
	}


	float TESObjectREFR::GetWeight() const
	{
		auto obj = GetBaseObject();
		return obj->GetWeight();
	}


	TESWorldSpace* TESObjectREFR::GetWorldspace() const
	{
		auto cell = parentCell;
		if (!cell) {
			cell = GetParentOrPersistentCell();
		}

		if (cell && cell->IsExteriorCell()) {
			return cell->worldSpace;
		} else {
			return 0;
		}
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
		return Get3D() != 0;
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
		REL::Offset<func_t*> func(Offset::TESObjectREFR::IsOffLimits);
		return func(this);
	}


	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, const BSFixedString& a_nodeName)
	{
		auto node = a_target->Get3D();
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


	void TESObjectREFR::PlayAnimation(std::string_view a_from, std::string_view a_to)
	{
		auto node = Get3D();
		if (!node) {
			return;
		}

		auto controller = node->GetControllers();
		if (!controller) {
			return;
		}

		auto manager = controller->GetAsNiControllerManager();
		if (!manager) {
			return;
		}

		auto fromSeq = manager->GetSequenceByName(a_from);
		auto toSeq = manager->GetSequenceByName(a_to);
		if (!fromSeq || !toSeq) {
			return;
		}

		PlayAnimation(manager, toSeq, fromSeq);
	}


	void TESObjectREFR::PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq)
	{
		PlayAnimation_Impl(a_manager, a_toSeq, a_fromSeq);
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
		auto node = Get3D();
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
		MoveTo_Impl(*g_invalidRefHandle, GetParentCell(), GetWorldspace(), a_pos, data.location);
	}


	const LockState* TESObjectREFR::GetLockState_Impl() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetLockState_Impl)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetLockState);
		return func(this);
	}


	void TESObjectREFR::MoveTo_Impl(RefHandle& a_targetHandle, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, NiPoint3& a_position, NiPoint3& a_rotation)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::MoveTo_Impl)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::MoveTo);
		return func(this, a_targetHandle, a_targetCell, a_selfWorldSpace, a_position, a_rotation);
	}


	void TESObjectREFR::PlayAnimation_Impl(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::PlayAnimation_Impl)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::PlayAnimation);
		return func(this, a_manager, a_toSeq, a_fromSeq, a_arg4);
	}
}
