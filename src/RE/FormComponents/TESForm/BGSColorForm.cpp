#include "RE/FormComponents/TESForm/BGSColorForm.h"


namespace RE
{
	bool BGSColorForm::IsPlayable() const
	{
		return flags.all(Flag::kPlayable);
	}
}
