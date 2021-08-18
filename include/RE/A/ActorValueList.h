#pragma once

#include "RE/A/ActorValues.h"

namespace RE
{
	class ActorValueInfo;

	class ActorValueList
	{
	public:
		[[nodiscard]] static ActorValueList* GetSingleton()
		{
			REL::Relocation<ActorValueList**> singleton{ REL::ID(514139) };
			return *singleton;
		}

		ActorValueInfo* GetActorValue(ActorValue a_actorValue);
		ActorValue      LookupActorValueByName(std::string_view a_enumName);

		// members
		std::uint32_t   unk00;                                                // 00
		std::uint32_t   pad04;                                                // 04
		ActorValueInfo* actorValues[stl::to_underlying(ActorValue::kTotal)];  // 08
	};
}
