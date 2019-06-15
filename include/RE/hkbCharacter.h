#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkbCharacter

#include "RE/hkArray.h"  // hkArray
#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkRefVariant.h"  // hkRefVariant
#include "RE/hkStringPtr.h"  // hkStringPtr


namespace RE
{
	class hkbBehaviorGraph;
	class hkbCharacterSetup;
	class hkbProjectData;
	class hkbRagdollDriver;


	class hkbCharacter : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkbCharacter;


		virtual ~hkbCharacter();		// 00

		// add
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04


		// members
		hkArray<hkbCharacter*>		nearbyCharacters;			// 10
		SInt16 						currentLOD;					// 20
		SInt16				 		numTracksInLOD;				// 22
		UInt32				 		pad24;						// 24
		hkStringPtr 				name;						// 28
		hkRefPtr<hkbRagdollDriver>	ragdollDriver;				// 30
		hkRefVariant 				characterControllerDriver;	// 38
		hkRefVariant 				footIkDriver;				// 40
		hkRefVariant 				handIkDriver;				// 48
		hkRefPtr<hkbCharacterSetup>	setup;						// 50
		hkRefPtr<hkbBehaviorGraph>	behaviorGraph;				// 58
		hkRefPtr<hkbProjectData>	projectData;				// 60
		hkRefVariant 				animationBindingSet;		// 68
		hkRefVariant 				raycastInterface;			// 70
		hkRefVariant 				world;						// 78
		hkRefVariant 				eventQueue;					// 80
		hkRefVariant 				worldFromModel;				// 88
		const void** 				poseLocal;					// 90 - hkSimpleArray<hkRefVariant>
		SInt32 						numPoseLocal;				// 98
		bool 						deleteWorldFromModel;		// 9C
		bool 						deletePoseLocal;			// 9D
		UInt16 						pad9E;						// 9E
	};
	STATIC_ASSERT(sizeof(hkbCharacter) == 0xA0);
}
