#include "RE/BGSColorForm.h"


namespace RE
{
	bool BGSColorForm::IsPlayable() const
	{
		return (flags & Flag::kPlayable) != Flag::kNone;
	}
}
