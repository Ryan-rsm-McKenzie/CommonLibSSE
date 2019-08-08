#include "RE/BGSAttackData.h"


namespace RE
{
	bool BGSAttackData::IsLeftAttack() const
	{
		return (attackData.attackFlags & AttackData::AttackFlag::kLeftAttack) != AttackData::AttackFlag::kNone;
	}
}
