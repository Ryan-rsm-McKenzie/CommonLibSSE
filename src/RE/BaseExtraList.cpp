#include "RE/BaseExtraList.h"

#include "RE/Offsets.h"


namespace RE
{
	bool BaseExtraList::HasType(UInt32 a_type)
	{
		typedef bool _HasType_t(BaseExtraList* a_this, UInt32 a_type);
		static _HasType_t* _HasType = reinterpret_cast<_HasType_t*>(GetFnAddr(&::BaseExtraList::HasType));
		return _HasType(this, a_type);
	}


	void BaseExtraList::MarkType(UInt32 a_type, bool a_bCleared)
	{
		typedef void _MarkType_t(BaseExtraList* a_this, UInt32 a_type, bool a_bCleared);
		static _MarkType_t* _MarkType = reinterpret_cast<_MarkType_t*>(GetFnAddr(&::BaseExtraList::MarkType));
		return _MarkType(this, a_type, a_bCleared);
	}


	bool BaseExtraList::Remove(UInt8 a_type, BSExtraData* a_toRemove)
	{
		typedef bool _Remove_t(BaseExtraList* a_this, UInt8 a_type, BSExtraData* a_toRemove);
		static _Remove_t* _Remove = reinterpret_cast<_Remove_t*>(GetFnAddr(&::BaseExtraList::Remove));
		return _Remove(this, a_type, a_toRemove);
	}


	bool BaseExtraList::Add(UInt8 a_type, BSExtraData* a_toAdd)
	{
		typedef bool _Add_t(BaseExtraList* a_this, UInt8 a_type, BSExtraData* a_toAdd);
		static _Add_t* _Add = reinterpret_cast<_Add_t*>(GetFnAddr(&::BaseExtraList::Add));
		return _Add(this, a_type, a_toAdd);
	}


	bool BaseExtraList::CheckContainerExtraData(bool a_isEquipped)
	{
		typedef bool _CheckContainerExtraData_t(BaseExtraList* a_this, bool a_isEquipped);
		static _CheckContainerExtraData_t* _CheckContainerExtraData = reinterpret_cast<_CheckContainerExtraData_t*>(GetFnAddr(&::BaseExtraList::CheckContainerExtraData));
		return _CheckContainerExtraData(this, a_isEquipped);
	}


	const char* BaseExtraList::GetDisplayName(TESForm* a_type)
	{
		typedef const char* _GetDisplayName_t(BaseExtraList* a_this, TESForm* a_type);
		static _GetDisplayName_t* _GetDisplayName = reinterpret_cast<_GetDisplayName_t*>(GetFnAddr(&::BaseExtraList::GetDisplayName));
		return _GetDisplayName(this, a_type);
	}


	BSExtraData* BaseExtraList::GetByType(UInt32 a_type)
	{
		typedef BSExtraData* _GetByType_t(BaseExtraList* a_this, UInt32 a_type);
		static _GetByType_t* _GetByType = reinterpret_cast<_GetByType_t*>(GetFnAddr(&::BaseExtraList::GetByType));
		return _GetByType(this, a_type);
	}


	void BaseExtraList::SetInventoryChanges(InventoryChanges* a_changes)
	{
		_SetInventoryChanges_Impl(this, a_changes);
	}


	UInt32 BaseExtraList::GetAshPileRefHandle(UInt32& a_refHandle)
	{
		return _GetAshPileRefHandle_Impl(this, a_refHandle);
	}


	RelocAddr<BaseExtraList::_SetInventoryChanges_Impl_t*> BaseExtraList::_SetInventoryChanges_Impl(BASE_EXTRA_LIST_SET_INVENTORY_CHANGES_IMPL);
	RelocAddr<BaseExtraList::_GetAshPileRefHandle_Impl_t*> BaseExtraList::_GetAshPileRefHandle_Impl(BASE_EXTRA_LIST_GET_ASH_PILE_REF_HANDLE_IMPL);
}
