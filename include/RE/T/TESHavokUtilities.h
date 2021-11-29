#pragma once

namespace RE
{
	class hkpCollidable;
	class TESObjectREFR;

	namespace TESHavokUtilities
	{
		TESObjectREFR* FindCollidableRef(const hkpCollidable& a_linkedCollidable);
	}
}
