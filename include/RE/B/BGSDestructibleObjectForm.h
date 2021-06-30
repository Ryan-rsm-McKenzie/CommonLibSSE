#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class QueuedFile;
	class TESModelTextureSwap;

	struct DestructibleObjectStage
	{
	public:
		enum class DESTRUCTIBLE_OBJECT_STAGE_FLAGS
		{
			kNone = 0,
			kCapDamage = 1 << 0,
			kDisableObject = 1 << 1,
			kDestroyObject = 1 << 2,
			kIgnoreExternalDamage = 1 << 3,
			kBecomesDynamic = 1 << 4
		};

		// members
		std::int8_t                                                     modelDamageStage;     // 00 - DSTD~
		std::int8_t                                                     healthPercentage;     // 01
		stl::enumeration<DESTRUCTIBLE_OBJECT_STAGE_FLAGS, std::uint8_t> flags;                // 02
		std::uint8_t                                                    pad03;                // 03
		std::uint32_t                                                   selfDamagePerSecond;  // 04
		BGSExplosion*                                                   explosion;            // 08
		BGSDebris*                                                      debris;               // 10
		std::uint32_t                                                   debrisCount;          // 18 - ~DSTD
		std::uint32_t                                                   pad1C;                // 1C
		TESModelTextureSwap*                                            replacementModel;     // 20 - DMD*
	};
	static_assert(sizeof(DestructibleObjectStage) == 0x28);

	struct DestructibleObjectData
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kVatsTargetable = 1 << 0
		};

		// members
		std::uint32_t                        health;                      // 00 - DEST~
		std::int8_t                          numStages;                   // 04
		stl::enumeration<Flag, std::uint8_t> flags;                       // 05 - ~DEST
		std::uint16_t                        pad06;                       // 06
		DestructibleObjectStage**            stages;                      // 08
		volatile std::int32_t                replacementModelRefCount;    // 10
		std::uint32_t                        pad14;                       // 14
		NiPointer<QueuedFile>                preloadedReplacementModels;  // 18
	};
	static_assert(sizeof(DestructibleObjectData) == 0x20);

	class BGSDestructibleObjectForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDestructibleObjectForm;

		~BGSDestructibleObjectForm() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01
		void ClearDataComponent() override;                     // 02
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		DestructibleObjectData* data;  // 08
	};
	static_assert(sizeof(BGSDestructibleObjectForm) == 0x10);
}
