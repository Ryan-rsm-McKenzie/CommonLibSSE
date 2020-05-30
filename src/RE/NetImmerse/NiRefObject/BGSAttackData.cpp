#include "RE/BGSAttackData.h"


namespace RE
{
	bool BGSAttackData::IsLeftAttack() const
	{
		return (data.flags & AttackData::AttackFlag::kChargeAttack) != AttackData::AttackFlag::kNone;
	}
}
