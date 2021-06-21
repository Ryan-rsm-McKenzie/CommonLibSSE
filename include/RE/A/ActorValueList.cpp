#include "RE/A/ActorValueList.h"

#include "RE/A/ActorValueInfo.h"
#include <boost/algorithm/string.hpp>

namespace RE
{
	ActorValueInfo* ActorValueList::GetActorValue(ActorValue a_actorValue)
	{
		return actorValues && (a_actorValue < ActorValue::kTotal) ? actorValues[stl::to_underlying(a_actorValue)] : nullptr;
	}

	ActorValue ActorValueList::LookupActorValueByName(std::string_view a_enumName)
	{
		ActorValue AV = ActorValue::kNone;
		if (actorValues) {
			for (auto i = 0; i < 164; i++) {
				if (boost::icontains(actorValues[i]->enumName, a_enumName)) {
					AV = static_cast<ActorValue>(i);
					break;
				}
			}
		}
		return AV;
	}
}
