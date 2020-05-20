#pragma once

#include "RE/BSTSingleton.h"
#include "RE/BSTSmartPointer.h"
#include "RE/ExtraDataList.h"
#include "RE/MenuEventHandler.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


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
		UInt64				  unk18;	 // 18
	};
	STATIC_ASSERT(sizeof(LoadedInventoryModel) == 0x20);


	class Inventory3DManager :
		public BSTSingletonSDM<Inventory3DManager>,	 // 10
		public MenuEventHandler						 // 00
	{
	public:
		virtual ~Inventory3DManager();	// 00

		static Inventory3DManager* GetSingleton();


		// members
		UInt8										  unk011;		  // 011
		UInt16										  unk012;		  // 012
		NiPoint3									  unk014;		  // 014
		NiPoint3									  unk020;		  // 020
		float										  unk02C;		  // 02C
		float										  unk030;		  // 030
		UInt32										  unk034;		  // 034
		TESObjectREFR*								  tempRef;		  // 038
		ExtraDataList								  originalExtra;  // 040
		BSTSmallArray<LoadedInventoryModel, 7>		  loadedModels;	  // 058
		UInt64										  unk148;		  // 148
		BSTSmartPointer<NewInventoryMenuItemLoadTask> loadTask;		  // 150
		UInt8										  unk158;		  // 158
		UInt8										  unk159;		  // 159
		UInt8										  unk15A;		  // 15A
		UInt8										  pad15B;		  // 15B
		UInt32										  pad15C;		  // 15C
	};
	STATIC_ASSERT(sizeof(Inventory3DManager) == 0x160);
}
