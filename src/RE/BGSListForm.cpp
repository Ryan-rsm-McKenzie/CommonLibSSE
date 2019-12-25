#include "RE/BGSListForm.h"

#include <algorithm>

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void BGSListForm::AddForm(TESForm* a_form)
	{
		using func_t = function_type_t<decltype(&BGSListForm::AddForm)>;
		REL::Offset<func_t*> func(Offset::BGSListForm::AddForm);
		return func(this, a_form);
	}


	bool BGSListForm::HasForm(const TESForm* a_form) const
	{
		if (!a_form) {
			return false;
		}

		auto ptrIt = std::find(forms.begin(), forms.end(), a_form);
		if (ptrIt != forms.end()) {
			return true;
		}

		if (!formIDs) {
			return false;
		}

		auto idIt = std::find(formIDs->begin(), formIDs->end(), a_form->formID);
		if (idIt != formIDs->end()) {
			return true;
		}

		return false;
	}


	bool BGSListForm::HasForm(FormID a_formID) const
	{
		auto form = RE::TESForm::LookupByID(a_formID);
		return HasForm(form);
	}
}
