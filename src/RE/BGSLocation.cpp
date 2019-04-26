#include "RE/BGSLocation.h"


namespace RE
{
	bool BGSLocation::IsCleared() const
	{
		return isCleared;
	}


	bool BGSLocation::IsChild(const BGSLocation* a_possibleChild) const
	{
		if (a_possibleChild) {
			for (auto it = a_possibleChild->parentLocation; it; it = it->parentLocation) {
				if (this == it) {
					return true;
				}
			}
		}
		return false;
	}


	bool BGSLocation::IsParent(const BGSLocation* a_possibleParent) const
	{
		if (a_possibleParent) {
			for (auto it = parentLocation; it; it = it->parentLocation) {
				if (a_possibleParent == it) {
					return true;
				}
			}
		}
		return false;
	}


	bool BGSLocation::IsLoaded() const
	{
		return loadedState > 0;
	}
}
