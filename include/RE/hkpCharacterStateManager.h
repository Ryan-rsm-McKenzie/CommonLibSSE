#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class bhkCharacterStateClimbing;
	class bhkCharacterStateFlying;
	class bhkCharacterStateInAir;
	class bhkCharacterStateJumping;
	class bhkCharacterStateOnGround;
	class bhkCharacterStateSwimming;


	class hkpCharacterStateManager : public hkReferencedObject
	{
	public:
		virtual ~hkpCharacterStateManager();


		// members
		bhkCharacterStateOnGround*	characterStateOnGround;	// 10
		bhkCharacterStateJumping*	characterStateJumping;	// 18
		bhkCharacterStateInAir*		characterStateInAir;	// 20
		bhkCharacterStateClimbing*	characterStateClimbing;	// 28
		bhkCharacterStateFlying*	characterStateFlying;	// 30
		bhkCharacterStateSwimming*	characterStateSwimming;	// 38
		UInt64						unk40;					// 40
		UInt64						unk48;					// 48
		UInt64						unk50;					// 50
		UInt64						unk58;					// 58
		UInt64						unk60;					// 60
	};
	STATIC_ASSERT(sizeof(hkpCharacterStateManager) == 0x68);
}
