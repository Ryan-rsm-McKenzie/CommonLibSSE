#include "RE/FormComponents/Components/BGSBaseAlias/BGSBaseAlias.h"


namespace RE
{
	const BSFixedString& BGSBaseAlias::GetTypeString() const
	{
		return QType();
	}


	bool BGSBaseAlias::IsQuestObject() const
	{
		return (flags & FLAGS::kQuestObject) != FLAGS::kNone;
	}
}
