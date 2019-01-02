#pragma once

#include "RE/hkpEntity.h"  // hkpEntity


namespace RE
{
	class hkpRigidBody : public hkpEntity
	{
	public:
		virtual ~hkpRigidBody();	// 00

		// add
		virtual void Unk_07(void);	// 07
	};
	STATIC_ASSERT(sizeof(hkpRigidBody) == 0x2D0);
}
