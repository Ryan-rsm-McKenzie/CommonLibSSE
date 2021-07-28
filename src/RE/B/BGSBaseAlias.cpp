#include "RE/B/BGSBaseAlias.h"

#include "RE/B/BGSLocAlias.h"
#include "RE/B/BGSRefAlias.h"

namespace RE
{
	const BSFixedString& BGSBaseAlias::GetTypeString() const
	{
		return QType();
	}

	VMTypeID BGSBaseAlias::GetVMTypeID() const
	{
		const auto& TYPE = GetTypeString();
		if (TYPE == "Loc"sv) {
			return BGSLocAlias::VMTYPEID;
		} else if (TYPE == "Ref"sv) {
			return BGSRefAlias::VMTYPEID;
		} else {
			return BGSBaseAlias::VMTYPEID;
		}
	}

	bool BGSBaseAlias::IsQuestObject() const
	{
		return flags.all(FLAGS::kQuestObject);
	}
}
