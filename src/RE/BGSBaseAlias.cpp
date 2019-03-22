#include "RE/BGSBaseAlias.h"


namespace RE
{
	bool BGSBaseAlias::IsQuestObject() const
	{
		return (aliasFlags.flags & AliasFlags::Flag::kQuestObject) != AliasFlags::Flag::kNone;
	}
}
