#include "RE/ActorProcessManager.h"


namespace RE
{
	void ActorProcessManager::SetEquipFlag(Flag a_flag)
	{
		typedef void _SetEquipFlag_t(ActorProcessManager* a_this, Flag a_flag);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ActorProcessManager*>(this)->_SetEquipFlag_GetPtr());
		static _SetEquipFlag_t* _SetEquipFlag = reinterpret_cast<_SetEquipFlag_t*>(*ptr);
		_SetEquipFlag(this, a_flag);
	}


	void ActorProcessManager::UpdateEquipment(Actor* a_actor)
	{
		typedef void _UpdateEquipment_t(ActorProcessManager* a_this, Actor* a_actor);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ActorProcessManager*>(this)->_UpdateEquipment_GetPtr());
		static _UpdateEquipment_t* _UpdateEquipment = reinterpret_cast<_UpdateEquipment_t*>(*ptr);
		_UpdateEquipment(this, a_actor);
	}


	void ActorProcessManager::SetDataFlag(float a_flag)
	{
		typedef void _SetDataFlag_t(ActorProcessManager* a_this, float a_flag);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ActorProcessManager*>(this)->_SetDataFlag_GetPtr());
		static _SetDataFlag_t* _SetDataFlag = reinterpret_cast<_SetDataFlag_t*>(*ptr);
		_SetDataFlag(this, a_flag);
	}


	void ActorProcessManager::UpdateEquipment_Hooked(Actor* a_actor)
	{
		typedef void _UpdateEquipment_Hooked_t(ActorProcessManager* a_this, Actor* a_actor);
		static _UpdateEquipment_Hooked_t* _UpdateEquipment_Hooked = reinterpret_cast<_UpdateEquipment_Hooked_t*>(GetFnAddr(&::ActorProcessManager::UpdateEquipment_Hooked));
		_UpdateEquipment_Hooked(this, a_actor);
	}
}
