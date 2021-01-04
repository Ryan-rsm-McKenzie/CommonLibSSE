#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"
#include "RE/B/BSTSingleton.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiTArray.h"
#include "RE/N/NiTList.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESFile;
	class TESRegionDataManager;
	class TESRegionList;

	struct TESObjectList
	{
	public:
		// members
		std::uint8_t pad0;	// 0
	};
	static_assert(sizeof(TESObjectList) == 0x1);

	struct TESFileCollection
	{
	public:
		// members
		BSTArray<TESFile*> files;		// 00
		BSTArray<TESFile*> smallFiles;	// 18
	};
	static_assert(sizeof(TESFileCollection) == 0x30);

	class TESDataHandler : public BSTSingletonSDM<TESDataHandler>
	{
	public:
		static TESDataHandler* GetSingleton();

		std::uint32_t LoadScripts();
		TESForm*	  LookupForm(FormID a_rawFormID, std::string_view a_modName);
		template <class T>
		T* LookupForm(FormID a_rawFormID, std::string_view a_modName);

		const TESFile*				LookupModByName(std::string_view a_modName);
		std::optional<std::uint8_t> GetModIndex(std::string_view a_modName);

		const TESFile*				LookupLoadedModByName(std::string_view a_modName);
		const TESFile*				LookupLoadedModByIndex(std::uint8_t a_index);
		std::optional<std::uint8_t> GetLoadedModIndex(std::string_view a_modName);

		const TESFile*				 LookupLoadedLightModByName(std::string_view a_modName);
		const TESFile*				 LookupLoadedLightModByIndex(std::uint16_t a_index);
		std::optional<std::uint16_t> GetLoadedLightModIndex(std::string_view a_modName);

		bool IsGeneratedID(FormID a_formID);

		BSTArray<TESForm*>& GetFormArray(FormType a_formType);
		template <class T>
		BSTArray<T*>& GetFormArray();

		// members
		std::uint8_t					  pad001;									 // 001
		std::uint16_t					  pad002;									 // 002
		std::uint32_t					  pad004;									 // 004
		TESObjectList*					  objectList;								 // 008
		BSTArray<TESForm*>				  formArrays[to_underlying(FormType::Max)];	 // 010
		TESRegionList*					  regionList;								 // D00
		NiTPrimitiveArray<TESObjectCELL*> interiorCells;							 // D08
		NiTPrimitiveArray<BGSAddonNode*>  addonNodes;								 // D20
		NiTList<TESForm*>				  badForms;									 // D38
		FormID							  nextID;									 // D50
		std::uint32_t					  padD54;									 // D54
		TESFile*						  activeFile;								 // D58
		BSSimpleList<TESFile*>			  files;									 // D60
		TESFileCollection				  compiledFileCollection;					 // D70
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
		std::uint8_t					  unkDAA;									 // DAA
		std::uint8_t					  padDAB;									 // DAB
		std::uint32_t					  padDAC;									 // DAC
		TESRegionDataManager*			  regionDataManager;						 // DB0
		std::uint64_t					  unkDB8;									 // DB8
	};
	static_assert(sizeof(TESDataHandler) == 0xDC0);

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
