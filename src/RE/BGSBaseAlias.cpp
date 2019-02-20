#include "RE/BGSBaseAlias.h"


namespace RE
{
	bool BGSBaseAlias::IsQuestObject() const
	{
		return (flags & Flag::kQuestObject) != Flag::kNone;
	}
}
