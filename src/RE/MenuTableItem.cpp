#include "RE/MenuTableItem.h"

#include "skse64/GameUtilities.h"  // CalculateCRC32_64

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	bool MenuTableItem::operator==(const MenuTableItem& a_rhs) const
	{
		return name == a_rhs.name;
	}


	bool MenuTableItem::operator==(const BSFixedString& a_name) const
	{
		return name == a_name;
	}


	MenuTableItem::operator UInt64() const
	{
		return (UInt64)name.c_str();
	}


	UInt32 MenuTableItem::GetHash(BSFixedString* a_key)
	{
		UInt32 hash;
		CalculateCRC32_64(&hash, (UInt64)a_key->c_str());
		return hash;
	}


	void MenuTableItem::Dump(void)
	{
		_MESSAGE("\t\tName: %s", name);
		_MESSAGE("\t\tInstance: %08X", menuInstance);
	}
}
