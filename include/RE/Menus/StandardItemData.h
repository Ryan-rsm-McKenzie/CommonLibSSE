#pragma once


namespace RE
{
	class InventoryEntryData;


	class StandardItemData
	{
	public:
		inline static constexpr auto RTTI = RTTI_StandardItemData;


		virtual ~StandardItemData();  // 00

		virtual const char* GetName();		  // 01 - { return objDesc->GenerateName(); }
		virtual UInt32		GetCount();		  // 02 - { return objDesc->GetCount(); }
		virtual UInt32		GetEquipState();  // 03
		virtual UInt32		GetFilterFlag();  // 04
		virtual UInt32		GetFavorite();	  // 05
		virtual bool		GetEnabled();	  // 06 - { return true; }


		// members
		InventoryEntryData* objDesc;  // 08
		RefHandle			owner;	  // 10
		UInt32				pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(StandardItemData) == 0x18);
}
