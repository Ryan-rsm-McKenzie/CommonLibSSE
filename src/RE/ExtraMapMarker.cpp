#include "RE/ExtraMapMarker.h"


namespace RE
{
	void MapMarkerData::Enable(bool a_enabled)
	{
		if (a_enabled) {
			flags |= Flag::kVisible;
		} else {
			flags &= Flag::kVisible & Flag::kShowAllHidden & Flag::kUnk3 & Flag::kUnk4 & Flag::kUnk5 & Flag::kUnk6 & Flag::kUnk7;
		}
	}
}
