#pragma once


namespace RE
{
	class hkpLinkedCollidable;
	class TESObjectREFR;


	namespace TESHavokUtilities
	{
		TESObjectREFR* FindCollidableRef(const hkpLinkedCollidable& a_linkedCollidable);
	}
}
