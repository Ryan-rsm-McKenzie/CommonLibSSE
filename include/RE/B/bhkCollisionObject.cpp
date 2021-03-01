#include "RE/B/bhkCollisionObject.h"

namespace RE
{
	bhkRigidBody* bhkCollisionObject::GetRigidBody() const
	{
		using func_t = decltype(&bhkCollisionObject::GetRigidBody);
		REL::Relocation<func_t> func{ Offset::bhkCollisionObject::GetRigidBody };
		return func(this);
	}
}
