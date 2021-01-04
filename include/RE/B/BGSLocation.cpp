#include "RE/B/BGSLocation.h"

namespace RE
{
	bool BGSLocation::IsCleared() const
	{
		return cleared;
	}

	bool BGSLocation::IsChild(const BGSLocation* a_possibleChild) const
	{
		if (a_possibleChild) {
			for (auto it = a_possibleChild->parentLoc; it; it = it->parentLoc) {
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
			for (auto it = parentLoc; it; it = it->parentLoc) {
				if (a_possibleParent == it) {
					return true;
				}
			}
		}
		return false;
	}

	bool BGSLocation::IsLoaded() const
	{
		return loadedCount > 0;
	}
}
