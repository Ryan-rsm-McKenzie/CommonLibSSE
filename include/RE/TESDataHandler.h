#pragma once

#include <optional>
#include <string_view>

#include "RE/BSTArray.h"
#include "RE/BSTList.h"
#include "RE/BSTSingleton.h"
#include "RE/FormTypes.h"
#include "RE/NiTArray.h"
#include "RE/NiTList.h"
#include "RE/TESForm.h"


namespace RE
{
	class TESFile;
	class TESRegionDataManager;
	class TESRegionList;


	struct TESObjectList
	{
	public:
		// members
		UInt8 pad0;	 // 0
	};
	STATIC_ASSERT(sizeof(TESObjectList) == 0x1);


	struct TESFileCollection
	{
	public:
		// members
		BSTArray<TESFile*> files;		// 00
		BSTArray<TESFile*> smallFiles;	// 18
	};
	STATIC_ASSERT(sizeof(TESFileCollection) == 0x30);


	class TESDataHandler : public BSTSingletonSDM<TESDataHandler>
	{
	public:
		static TESDataHandler* GetSingleton();

		UInt32	 LoadScripts();
		TESForm* LookupForm(FormID a_rawFormID, std::string_view a_modName);
		template <class T>
		T* LookupForm(FormID a_rawFormID, std::string_view a_modName);

		const TESFile*		 LookupModByName(std::string_view a_modName);
		std::optional<UInt8> GetModIndex(std::string_view a_modName);

		const TESFile*		 LookupLoadedModByName(std::string_view a_modName);
		const TESFile*		 LookupLoadedModByIndex(UInt8 a_index);
		std::optional<UInt8> GetLoadedModIndex(std::string_view a_modName);

		const TESFile*		  LookupLoadedLightModByName(std::string_view a_modName);
		const TESFile*		  LookupLoadedLightModByIndex(UInt16 a_index);
		std::optional<UInt16> GetLoadedLightModIndex(std::string_view a_modName);

		bool IsGeneratedID(FormID a_formID);

		BSTArray<TESForm*>& GetFormArray(FormType a_formType);
		template <class T>
		BSTArray<T*>& GetFormArray();


		// members
		UInt8							  pad001;									 // 001
		UInt16							  pad002;									 // 002
		UInt32							  pad004;									 // 004
		TESObjectList*					  objectList;								 // 008
		BSTArray<TESForm*>				  formArrays[to_underlying(FormType::Max)];	 // 010
		TESRegionList*					  regionList;								 // D00
		NiTPrimitiveArray<TESObjectCELL*> interiorCells;							 // D08
		NiTPrimitiveArray<BGSAddonNode*>  addonNodes;								 // D20
		NiTList<TESForm*>				  badForms;									 // D38
		FormID							  nextID;									 // D50
		UInt32							  padD54;									 // D54
		TESFile*						  activeFile;								 // D58
		BSSimpleList<TESFile*>			  files;									 // D60
		TESFileCollection				  compiledFileCollection;					 // D60
		bool							  masterSave;								 // DA0
		bool							  blockSave;								 // DA1
		bool							  saveLoadGame;								 // DA2
		bool							  autoSaving;								 // DA3
		bool							  exportingPlugin;							 // DA4
		bool							  clearingData;								 // DA5
		bool							  hasDesiredFiles;							 // DA6
		bool							  checkingModels;							 // DA7
		bool							  loadingFiles;								 // DA8
		bool							  dontRemoveIDs;							 // DA9
		UInt8							  unkDAA;									 // DAA
		UInt8							  padDAB;									 // DAB
		UInt32							  padDAC;									 // DAC
		TESRegionDataManager*			  regionDataManager;						 // DB0
		UInt64							  unkDB8;									 // DB8
	};
	STATIC_ASSERT(sizeof(TESDataHandler) == 0xDC0);


	template <class T>
	T* TESDataHandler::LookupForm(FormID a_rawFormID, std::string_view a_modName)
	{
		auto form = LookupForm(a_rawFormID, a_modName);
		if (!form) {
			return 0;
		}

		return form->Is(T::FORMTYPE) ? static_cast<T*>(form) : 0;
	}


	template <class T>
	BSTArray<T*>& TESDataHandler::GetFormArray()
	{
		return reinterpret_cast<BSTArray<T*>&>(GetFormArray(T::FORMTYPE));
	}
}
