#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ExtraDataList.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class InventoryEntryData;
	class NewInventoryMenuItemLoadTask;
	class NiAVObject;
	class TESBoundObject;
	class TESObjectREFR;

	struct LoadedInventoryModel
	{
	public:
		// members
		TESForm*              itemBase;  // 00 - smart ptr
		TESBoundObject*       modelObj;  // 08
		NiPointer<NiAVObject> spModel;   // 10
		std::uint64_t         unk18;     // 18
	};
	static_assert(sizeof(LoadedInventoryModel) == 0x20);

	class Inventory3DManager :
		public BSTSingletonSDM<Inventory3DManager>,  // 10
		public MenuEventHandler                      // 00
	{
	public:
		~Inventory3DManager() override;  // 00

		static Inventory3DManager* GetSingleton();

		void          UpdateItem3D(InventoryEntryData* a_objDesc);
		void          UpdateMagic3D(TESForm* a_form, std::uint32_t a_arg2);
		void          Clear3D();
		std::uint32_t Render();

		// members
		std::uint8_t                                  unk011;         // 011
		std::uint16_t                                 unk012;         // 012
		NiPoint3                                      unk014;         // 014
		NiPoint3                                      unk020;         // 020
		float                                         unk02C;         // 02C
		float                                         unk030;         // 030
		std::uint32_t                                 unk034;         // 034
		TESObjectREFR*                                tempRef;        // 038
		ExtraDataList                                 originalExtra;  // 040
		BSTSmallArray<LoadedInventoryModel, 7>        loadedModels;   // 058
		std::uint32_t                                 unk148;         // 148
		float                                         zoomProgress;   // 14C - 1 if zoomed in, 0 if not, in-between during transition
		BSTSmartPointer<NewInventoryMenuItemLoadTask> loadTask;       // 150
		std::uint8_t                                  unk158;         // 158
		std::uint8_t                                  unk159;         // 159
		std::uint8_t                                  unk15A;         // 15A
		std::uint8_t                                  pad15B;         // 15B
		std::uint32_t                                 pad15C;         // 15C
	};
	static_assert(sizeof(Inventory3DManager) == 0x168);
}
