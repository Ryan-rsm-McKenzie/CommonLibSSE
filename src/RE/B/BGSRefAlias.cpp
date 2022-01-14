#include "RE/B/BGSRefAlias.h"

#include "RE/A/Actor.h"
#include "RE/T/TESQuest.h"

namespace RE
{
	TESObjectREFR* BGSRefAlias::GetReference() const
	{
		TESObjectREFR* ref = nullptr;
		const auto     owner = owningQuest;
		if (owner) {
			ObjectRefHandle handle{};
			owner->CreateRefHandleByAliasID(handle, aliasID);

			const auto refPtr = handle.get();
			ref = refPtr.get();
		}
		return ref;
	}

	Actor* BGSRefAlias::GetActorReference() const
	{
		const auto ref = GetReference();
		return ref ? ref->As<Actor>() : nullptr;
	}
}
