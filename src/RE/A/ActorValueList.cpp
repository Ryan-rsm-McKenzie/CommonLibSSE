#include "RE/A/ActorValueList.h"

#include "RE/A/ActorValueInfo.h"

namespace RE
{
	ActorValueInfo* ActorValueList::GetActorValue(ActorValue a_actorValue)
	{
		return actorValues && a_actorValue < ActorValue::kTotal ?
                   actorValues[stl::to_underlying(a_actorValue)] :
                   nullptr;
	}

	ActorValue ActorValueList::LookupActorValueByName(std::string_view a_enumName)
	{
		ActorValue value = ActorValue::kNone;

		if (actorValues) {
			for (std::uint32_t i = 0; i < 164; i++) {
				if (stl::string::iequals(actorValues[i]->enumName, a_enumName)) {
					value = static_cast<ActorValue>(i);
					break;
				}
			}
		}

		return value;
	}
}
