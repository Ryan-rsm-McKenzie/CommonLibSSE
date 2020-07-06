#include "RE/FormComponents/TESForm/TESForm.h"

#include "RE/BSExtraData/ExtraEnchantment.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/FormComponents/Components/FormTraits.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/MagicItem/MagicItem.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"
#include "RE/FormComponents/TESFullName.h"
#include "RE/FormComponents/TESModel/TESModel.h"
#include "RE/FormComponents/TESValueForm.h"


namespace RE
{
	void TESForm::AddCompileIndex(FormID& a_id, TESFile* a_file)
	{
		using func_t = decltype(&TESForm::AddCompileIndex);
		REL::Offset<func_t> func = REL::ID(14509);
		return func(a_id, a_file);
	}


	std::pair<BSTHashMap<FormID, TESForm*>*, std::reference_wrapper<BSReadWriteLock>> TESForm::GetAllForms()
	{
		REL::Offset<BSTHashMap<FormID, TESForm*>**> allForms = REL::ID(514351);
		REL::Offset<BSReadWriteLock*> allFormsMapLock = REL::ID(514360);
		return std::make_pair(*allForms, std::ref(*allFormsMapLock));
	}


	std::pair<BSTHashMap<BSFixedString, TESForm*>*, std::reference_wrapper<BSReadWriteLock>> TESForm::GetAllFormsByEditorID()
	{
		REL::Offset<BSTHashMap<BSFixedString, TESForm*>**> allFormsByEditorID = REL::ID(514352);
		REL::Offset<BSReadWriteLock*> allFormsEditorIDMapLock = REL::ID(514361);
		return std::make_pair(*allFormsByEditorID, std::ref(*allFormsEditorIDMapLock));
	}


	TESForm* TESForm::LookupByID(FormID a_formID)
	{
		auto allForms = GetAllForms();
		BSReadLockGuard locker(allForms.second);
		if (!allForms.first) {
			return nullptr;
		}

		auto& formIDs = *allForms.first;
		auto it = formIDs.find(a_formID);
		return it != formIDs.end() ? it->second : nullptr;
	}


	TESForm* TESForm::LookupByEditorID(const std::string_view& a_editorID)
	{
		auto allFormsByEditorID = GetAllFormsByEditorID();
		BSReadLockGuard locker(allFormsByEditorID.second);
		if (!allFormsByEditorID.first) {
			return nullptr;
		}

		auto& editorIDs = *allFormsByEditorID.first;
		auto it = editorIDs.find(a_editorID);
		return it != editorIDs.end() ? it->second : nullptr;
	}


	TESObjectREFR* TESForm::AsReference()
	{
		return AsReference1();
	}


	const TESObjectREFR* TESForm::AsReference() const
	{
		return AsReference2();
	}


	TESFile* TESForm::GetFile(SInt32 a_idx) const
	{
		auto array = sourceFiles.array;
		if (!array || array->empty()) {
			return nullptr;
		}

		if (a_idx < 0 || a_idx >= array->size()) {
			return array->back();
		} else {
			return (*array)[a_idx];
		}
	}


	SInt32 TESForm::GetGoldValue() const
	{
		SInt32 value = 0;
		auto form = this;
		auto objRef = As<TESObjectREFR>();
		if (objRef) {
			form = objRef->GetBaseObject();
			auto xEnch = objRef->extraList.GetByType<ExtraEnchantment>();
			if (xEnch && xEnch->enchantment) {
				value += static_cast<SInt32>(xEnch->enchantment->CalculateTotalGoldValue());
			}
		}

		auto valueForm = form->As<TESValueForm>();
		if (valueForm) {
			value += valueForm->value;
		} else {
			auto magicItem = form->As<MagicItem>();
			if (magicItem) {
				value += static_cast<SInt32>(magicItem->CalculateTotalGoldValue());
			} else {
				value = -1;
			}
		}

		return value;
	}


	const char* TESForm::GetName() const
	{
		auto fullName = As<TESFullName>();
		if (fullName) {
			auto str = fullName->GetFullName();
			return str ? str : "";
		} else {
			return "";
		}
	}


	float TESForm::GetWeight() const
	{
		auto ref = As<TESObjectREFR>();
		auto baseObj = ref ? ref->GetBaseObject() : nullptr;
		auto form = baseObj ? baseObj : this;
		auto weightForm = form->As<TESWeightForm>();
		if (weightForm) {
			return weightForm->weight;
		} else if (form->Is(FormType::NPC)) {
			auto npc = static_cast<const TESNPC*>(form);
			return npc->weight;
		} else {
			return -1.0;
		}
	}


	bool TESForm::HasVMAD() const
	{
		auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (!vm) {
			return false;
		}

		auto policy = vm->GetObjectHandlePolicy();
		if (!policy) {
			return false;
		}

		const auto handle = policy->GetHandleForObject(GetFormType(), this);
		return handle != policy->EmptyHandle();
	}


	bool TESForm::HasWorldModel() const noexcept
	{
		return As<TESModel>() != nullptr;
	}


	void TESForm::InitItem()
	{
		InitItemImpl();
	}
}
