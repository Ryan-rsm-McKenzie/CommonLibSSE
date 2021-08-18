#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/bhkSerializable.h"
#include "RE/H/hkpWorldRayCastInput.h"
#include "RE/H/hkpWorldRayCastOutput.h"

namespace RE
{
	class BGSAcousticSpaceListener;
	class hkpClosestRayHitCollector;
	class hkpSuspendInactiveAgentsUtil;
	class NiAVObject;

	class bhkWorld : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkWorld;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkWorld;

		class bhkConstraintProjector;
		class hkpClosestRayHitCollector;

		struct RAYCAST_DATA
		{
		public:
			// members
			hkpWorldRayCastInput       rayInput;                      // 00
			hkpWorldRayCastOutput      rayOutput;                     // 30
			hkVector4                  ray;                           // 90
			hkpClosestRayHitCollector* rayHitCollectorA0{ nullptr };  // A0
			hkpClosestRayHitCollector* rayHitCollectorA8{ nullptr };  // A8
			hkpClosestRayHitCollector* rayHitCollectorB0{ nullptr };  // B0
			hkpClosestRayHitCollector* rayHitCollectorB8{ nullptr };  // B8
			bool                       unkC0{ false };                // C0
			std::uint8_t               padC1;                         // C1
			std::uint16_t              padC2;                         // C2
			std::uint32_t              padC4;                         // C4
			std::uint32_t              padC8;                         // C8
		};
		static_assert(sizeof(RAYCAST_DATA) == 0xD0);

		~bhkWorld() override;  // 00

		// override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;                                    // 02
		virtual void          SetReferencedObject(hkReferencedObject* a_object) override;  // 25
		virtual void          AdjustRefCount(bool a_increment) override;                   // 26
		virtual hkpWorld*     GetWorld1() override;                                        // 27 - { return referencedObject.ptr; }
		virtual ahkpWorld*    GetWorld2() override;                                        // 28 - { return referencedObject.ptr; }
		virtual void          Unk_2B(void) override;                                       // 2B
		virtual void          Unk_2C(void) override;                                       // 2C - { return 1; }
		virtual void          Unk_2E(void) override;                                       // 2E
		virtual void          Unk_2F(void) override;                                       // 2F

		// add
		virtual void Unk_32(void);                                              // 32
		virtual bool CastRay(RAYCAST_DATA& a_worldRayCast);                     // 33
		virtual void Unk_34(void);                                              // 34
		virtual void Unk_35(void);                                              // 35
		virtual void InitHavok(NiAVObject* a_sceneObject, NiAVObject* a_root);  // 36

		// members
		std::uint8_t                  unk0020[0x320];             // 0020
		std::uint8_t                  unk0340[0x6400];            // 0340
		std::uint8_t                  unk6740[0x5DC0];            // 6740
		BSTArray<void*>               unkC500;                    // C500
		BSTArray<void*>               unkC518;                    // C518
		BSTArray<void*>               unkC530;                    // C530
		BSTArray<void*>               unkC548;                    // C548
		std::uint64_t                 unkC560;                    // C560
		std::uint32_t                 unkC568;                    // C568
		float                         unkC56C;                    // C56C
		bhkConstraintProjector*       constraintProjector;        // C570
		std::uint64_t                 unkC578;                    // C578
		std::uint32_t                 unkC580;                    // C580
		float                         unkC584;                    // C584
		std::uint64_t                 unkC588;                    // C588
		std::uint64_t                 unkC590;                    // C590
		mutable BSReadWriteLock       worldLock;                  // C598
		mutable BSReadWriteLock       unkC5A0;                    // C5A0
		std::uint64_t                 unkC5A8;                    // C5A8
		hkVector4                     unkC5B0;                    // C5B0
		std::uint64_t                 unkC5C0;                    // C5C0
		BGSAcousticSpaceListener*     acousticSpaceListener;      // C5C8
		hkpSuspendInactiveAgentsUtil* suspendInactiveAgentsUtil;  // C5D0
		std::uint32_t                 unkC5D8;                    // C5D8 - incremented per frame
		std::uint32_t                 unkC5DC;                    // C5DC
		std::uint32_t                 unkC5E0;                    // C5E0
		std::uint32_t                 unkC5E4;                    // C5E4
		std::uint32_t                 unkC5E8;                    // C5E8
		std::uint32_t                 unkC5EC;                    // C5EC
		float                         tau;                        // C5F0
		float                         damping;                    // C5F4
		std::uint8_t                  unkC5F8;                    // C5F8
		bool                          toggleCollision;            // C5F9
		std::uint16_t                 unkC5FA;                    // C5FA
		std::uint16_t                 unkC5FC;                    // C5FC
		std::uint16_t                 unkC5FE;                    // C5FE
	};
	static_assert(sizeof(bhkWorld) == 0xC600);
}
