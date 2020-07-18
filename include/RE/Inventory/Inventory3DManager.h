#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTSingleton.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSDevices/MenuEventHandler/MenuEventHandler.h"
#include "RE/Inventory/ExtraDataList.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class NewInventoryMenuItemLoadTask;
	class NiAVObject;
	class TESBoundObject;
	class TESObjectREFR;


	struct LoadedInventoryModel
	{
	public:
		// members
		TESForm*			  itemBase;	 // 00 - smart ptr
		TESBoundObject*		  modelObj;	 // 08
		NiPointer<NiAVObject> spModel;	 // 10
		std::uint64_t		  unk18;	 // 18
	};
	static_assert(sizeof(LoadedInventoryModel) == 0x20);


	class Inventory3DManager :
		public BSTSingletonSDM<Inventory3DManager>,	 // 10
		public MenuEventHandler						 // 00
	{
	public:
		virtual ~Inventory3DManager();	// 00

		static Inventory3DManager* GetSingleton();


		// members
		std::uint8_t								  unk011;		  // 011
		std::uint16_t								  unk012;		  // 012
		NiPoint3									  unk014;		  // 014
		NiPoint3									  unk020;		  // 020
		float										  unk02C;		  // 02C
		float										  unk030;		  // 030
		std::uint32_t								  unk034;		  // 034
		TESObjectREFR*								  tempRef;		  // 038
		ExtraDataList								  originalExtra;  // 040
		BSTSmallArray<LoadedInventoryModel, 7>		  loadedModels;	  // 058
		std::uint64_t								  unk148;		  // 148
		BSTSmartPointer<NewInventoryMenuItemLoadTask> loadTask;		  // 150
		std::uint8_t								  unk158;		  // 158
		std::uint8_t								  unk159;		  // 159
		std::uint8_t								  unk15A;		  // 15A
		std::uint8_t								  pad15B;		  // 15B
		std::uint32_t								  pad15C;		  // 15C
	};
	static_assert(sizeof(Inventory3DManager) == 0x160);
}
