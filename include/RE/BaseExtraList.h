#pragma once

#include "skse64/GameBSExtraData.h"  // BaseExtraList

#include "RE/ExtraContainerChanges.h"  // ExtraContainerChanges::Data
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"


namespace RE
{
	class BaseExtraList
	{
	public:
		BaseExtraList();
		~BaseExtraList();

		bool			HasType(ExtraDataType a_type);
		void			MarkType(ExtraDataType a_type, bool a_bCleared);
		bool			Remove(ExtraDataType a_type, BSExtraData* a_toRemove);
		bool			Add(ExtraDataType a_type, BSExtraData* a_toAdd);
		bool			CheckContainerExtraData(bool a_isEquipped);
		const char*		GetDisplayName(TESForm* a_type);
		BSExtraData*	GetByType(ExtraDataType a_type);

		void			SetInventoryChanges(InventoryChanges* a_changes);
		UInt32			GetAshPileRefHandle(UInt32& a_refHandle);


		BSExtraData*						m_data;		// 00
		::BaseExtraList::PresenceBitfield*	m_presence;	// 08
		BSReadWriteLock						m_lock;		// 10
	};
	STATIC_ASSERT(sizeof(BaseExtraList) == 0x18);
}
