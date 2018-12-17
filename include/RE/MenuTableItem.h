#pragma once

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class IMenu;


	class MenuTableItem
	{
	public:
		typedef IMenu* (*CreatorFunc)(void);

		BSFixedString	name;				// 00
		IMenu*			menuInstance;		// 08	0 if the menu is not currently open
		CreatorFunc*	menuConstructor;	// 10

		bool			operator==(const MenuTableItem& a_rhs) const;
		bool			operator==(const BSFixedString& a_name) const;
		operator UInt64() const;
		static UInt32	GetHash(BSFixedString* a_key);
		void			Dump();
	};
	STATIC_ASSERT(sizeof(MenuTableItem) == 0x18);
}
