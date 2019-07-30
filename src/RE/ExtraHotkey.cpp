#include "RE/ExtraHotkey.h"

#include "skse64/GameExtraData.h"  // s_ExtraHotkeyVtbl


namespace RE
{
	ExtraHotkey::ExtraHotkey() :
		BSExtraData(),
		hotkey(Hotkey::kUnbound),
		unk11(0),
		unk12(0),
		unk14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraHotkeyVtbl.GetUIntPtr();
	}


	ExtraHotkey::ExtraHotkey(Hotkey a_hotkey) :
		BSExtraData(),
		hotkey(a_hotkey),
		unk11(0),
		unk12(0),
		unk14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraHotkeyVtbl.GetUIntPtr();
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
