#include "RE/B/BGSColorForm.h"

namespace RE
{
	bool BGSColorForm::IsPlayable() const
	{
		return flags.all(Flag::kPlayable);
	}
}
