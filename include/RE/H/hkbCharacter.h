#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefVariant.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkStringPtr.h"

namespace RE
{
	class hkbBehaviorGraph;
	class hkbCharacterSetup;
	class hkbProjectData;
	class hkbRagdollDriver;

	class hkbCharacter : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbCharacter;

		~hkbCharacter() override;  // 00

		// add
		virtual void Unk_03(void);  // 03
		virtual void Unk_04(void);  // 04

		// members
		hkArray<hkbCharacter*>      nearbyCharacters;           // 10
		std::int16_t                currentLOD;                 // 20
		std::int16_t                numTracksInLOD;             // 22
		std::uint32_t               pad24;                      // 24
		hkStringPtr                 name;                       // 28
		hkRefPtr<hkbRagdollDriver>  ragdollDriver;              // 30
		hkRefVariant                characterControllerDriver;  // 38
		hkRefVariant                footIkDriver;               // 40
		hkRefVariant                handIkDriver;               // 48
		hkRefPtr<hkbCharacterSetup> setup;                      // 50
		hkRefPtr<hkbBehaviorGraph>  behaviorGraph;              // 58
		hkRefPtr<hkbProjectData>    projectData;                // 60
		hkRefVariant                animationBindingSet;        // 68
		hkRefVariant                raycastInterface;           // 70
		hkRefVariant                world;                      // 78
		hkRefVariant                eventQueue;                 // 80
		hkRefVariant                worldFromModel;             // 88
		const void**                poseLocal;                  // 90 - hkSimpleArray<hkRefVariant>
		std::int32_t                numPoseLocal;               // 98
		bool                        deleteWorldFromModel;       // 9C
		bool                        deletePoseLocal;            // 9D
		std::uint16_t               pad9E;                      // 9E
	};
	static_assert(sizeof(hkbCharacter) == 0xA0);
}
