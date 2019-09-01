#pragma once

#include <optional>  // optional
#include <string_view>  // string_view

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/FormTypes.h"  // TESForm
#include "RE/NiTArray.h"  // NiTPrimitiveArray


namespace RE
{
	class TESFile;
	class TESRegionDataManager;
	class TESRegionList;


	class TESDataHandler : public BSTSingletonSDM<TESDataHandler>
	{
	public:
		struct ModList
		{
			BSSimpleList<TESFile*>	loadOrder;		// 00 - TESDataHandler D60
			BSTArray<TESFile*>		loadedMods;		// 10 - TESDataHandler D70
			BSTArray<TESFile*>		loadedCCMods;	// 28 - TESDataHandler D88
		};
		STATIC_ASSERT(sizeof(ModList) == 0x40);


		static TESDataHandler*	GetSingleton();
		UInt32					LoadScripts();

		const TESFile*			LookupModByName(std::string_view a_modName);
		std::optional<UInt8>	GetModIndex(std::string_view a_modName);

		const TESFile*			LookupLoadedModByName(std::string_view a_modName);
		const TESFile*			LookupLoadedModByIndex(UInt8 a_index);
		std::optional<UInt8>	GetLoadedModIndex(std::string_view a_modName);

		const TESFile*			LookupLoadedLightModByName(std::string_view a_modName);
		const TESFile*			LookupLoadedLightModByIndex(UInt16 a_index);
		std::optional<UInt16>	GetLoadedLightModIndex(std::string_view a_modName);

		bool	IsGeneratedID(UInt32 a_formID);

		BSTArray<TESForm*>&					GetFormArray(FormType a_formType);
		template <class T> BSTArray<T*>&	GetFormArray();


		// members
		void*								unk008;										// 008
		BSTArray<TESForm*>					formArrays[to_underlying(FormType::Max)];	// 010
		TESRegionList*						regionList;									// D00
		NiTPrimitiveArray<TESObjectCELL*>	cells;										// D08
		NiTPrimitiveArray<BGSAddonNode*>	addonNodes;									// D20
		void*								unkD38;										// D38
		void*								unkD40;										// D40
		void*								unkD48;										// D48
		UInt32								nextBlankID;								// D50 - init'd to 0x800
		UInt32								padD54;										// D54
		void*								unkD58;										// D58
		ModList								modList;									// D60
		UInt8								unkDA0;										// DA0
		UInt8								unkDA1;										// DA1
		UInt8								unkDA2;										// DA2
		UInt8								unkDA3;										// DA3
		UInt8								unkDA4;										// DA4
		UInt8								unkDA5;										// DA5
		UInt8								unkDA6;										// DA6
		UInt8								unkDA7;										// DA7
		UInt8								unkDA8;										// DA8 - isReadingData?
		UInt8								unkDA9;										// DA9
		UInt8								unkDAA;										// DAA
		UInt8								padDAB[5];									// DAB
		TESRegionDataManager*				regionDataManager;							// DB0
		UInt64								unkDB8;										// DB8
	};
	STATIC_ASSERT(offsetof(TESDataHandler, regionList) == 0xD00);
	STATIC_ASSERT(offsetof(TESDataHandler, addonNodes) == 0xD20);
	STATIC_ASSERT(offsetof(TESDataHandler, modList) == 0xD60);
	STATIC_ASSERT(sizeof(TESDataHandler) == 0xDC0);


	template <class T>
	BSTArray<T*>& TESDataHandler::GetFormArray()
	{
		return reinterpret_cast<BSTArray<T*>&>(GetFormArray(static_cast<FormType>(T::kTypeID)));
	}
}
