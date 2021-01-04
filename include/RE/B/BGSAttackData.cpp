#include "RE/B/BGSAttackData.h"

namespace RE
{
	bool BGSAttackData::IsLeftAttack() const
	{
		return data.flags.all(AttackData::AttackFlag::kChargeAttack);
	}
}
