#pragma once

#include "RE/TESObjectREFR.h"
#include "RE/InventoryEntryData.h"
#include "RE/ExtraDataList.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	class TESObjectREFR;
	class InventoryEntryData;

	
	class Inventory3DManager : public BSTSingletonSDM<Inventory3DManager>
	{
	public:
		inline static constexpr auto RTTI = RTTI_Inventory3DManager;

		static Inventory3DManager* GetSingleton();
		virtual ~Inventory3DManager();

		
		// 20
		struct ItemData
		{
			TESForm*	form1;
			TESForm*	form2;
			NiNode*		node;
			UInt32		unk18;
			float		unk1C;
		};

		
		// add
		void	UpdateItem3D(InventoryEntryData* a_obj);
		void	UpdateMagic3D(TESForm* a_form, UInt32 a_unk1);
		void	Clear3D();
		UInt32	Render();
		void	Unk1(UInt32 a_unk1);
		void	Unk2();
		bool	Unk3();
		double	Unk4();
		bool	Unk5();
		int		Unk6();
		
		
		// members
		//void**			vtbl;			// 00
		UInt32			unk08;			// 08
		UInt8			unk0C;			// 0C - This appears to be 1 when a menu is open
		UInt8			unk0D;			// 0D
		UInt16			pad0E;			// 0E
		UInt32			unk10;			// 10
		float			unk14[8];		// 14
		UInt32			pad34;			// 34
		TESObjectREFR*	object;			// 38
		ExtraDataList	extraDataList;	// 40 - Only valid when NewInventoryMenuItemLoadTask is pending
		UInt32			unk58;			// 58
		UInt32			pad5C;			// 5C
		ItemData		itemData[7];	// 60
		UInt32			meshCount;		// 140 - Number of ItemData where there is a valid BSFadeNode
		UInt32			pad144;			// 144
		UInt32			unk148;			// 148
		UInt32			unk14C;			// 14C
		void*			unk150;			// 150 - Pointer to NewInventoryMenuItemLoadTask when loading
		UInt8			unk158;
		UInt8			unk159;			// Somekind of mode (0 for MagicMenu)
		UInt8			unk15A;
		UInt8			pad15B[5];
	};
	STATIC_ASSERT(sizeof(Inventory3DManager) == 0x160);
}