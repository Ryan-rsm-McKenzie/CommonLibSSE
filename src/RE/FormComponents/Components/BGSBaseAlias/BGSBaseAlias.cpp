#include "RE/FormComponents/Components/BGSBaseAlias/BGSBaseAlias.h"

#include "RE/FormComponents/Components/BGSBaseAlias/BGSLocAlias.h"
#include "RE/FormComponents/Components/BGSBaseAlias/BGSRefAlias.h"


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
