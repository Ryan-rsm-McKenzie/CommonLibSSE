#include "RE/E/ExtraHotkey.h"

namespace RE
{
	ExtraHotkey::ExtraHotkey() :
		ExtraHotkey(Hotkey::kUnbound)
	{}

	ExtraHotkey::ExtraHotkey(Hotkey a_hotkey) :
		BSExtraData(),
		hotkey(a_hotkey),
		unk11(0),
		unk12(0),
		unk14(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraHotkey::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraHotkey::GetType() const
	{
		return ExtraDataType::kHotkey;
	}

	bool ExtraHotkey::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraHotkey*>(a_rhs);
		return hotkey != rhs->hotkey;
	}
}
