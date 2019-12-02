#include "RE/Console.h"

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	NiPointer<TESObjectREFR> Console::GetSelectedRef()
	{
		auto handle = GetSelectedRefHandle();
		return TESObjectREFR::LookupByHandle(handle);
	}


	RefHandle Console::GetSelectedRefHandle()
	{
		REL::Offset<RefHandle*> selectedRef(Offset::Console::SelectedRef);
		return *selectedRef;
	}


	void Console::SetSelectedRef(NiPointer<TESObjectREFR> a_refPtr)
	{
		auto handle = a_refPtr->CreateRefHandle();
		SetSelectedRef_Impl(handle);
	}


	void Console::SetSelectedRef(TESObjectREFR* a_ref)
	{
		auto handle = a_ref->CreateRefHandle();
		SetSelectedRef_Impl(handle);
	}


	void Console::SetSelectedRef(RefHandle a_handle)
	{
		SetSelectedRef_Impl(a_handle);
	}


	void Console::SetSelectedRef_Impl(RefHandle& a_handle)
	{
		using func_t = function_type_t<decltype(&Console::SetSelectedRef_Impl)>;
		REL::Offset<func_t*> func(RE::Offset::Console::SetSelectedRef);
		return func(this, a_handle);
	}
}
