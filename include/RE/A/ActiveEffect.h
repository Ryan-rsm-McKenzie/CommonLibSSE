#pragma once

#include "RE/A/ActiveEffectReferenceEffectController.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTList.h"
#include "RE/M/MagicSystem.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class EffectSetting;
	class MagicItem;
	class MagicTarget;
	class NiNode;
	class ReferenceEffect;
	class TESBoundObject;
	struct Effect;

	class ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActiveEffect;
		inline static constexpr auto VMTYPEID = static_cast<VMTypeID>(142);

		enum class Flag
		{
			kHasConditions = 1 << 7,
			kRecovers = 1 << 9,
			kInactive = 1 << 15,
			kDispelled = 1 << 18
		};

		enum class ConditionStatus
		{
			kNA = static_cast<std::underlying_type_t<ConditionStatus>>(-1),
			kFalse = 0,
			kTrue = 1,
		};

		// add
		virtual void		   Unk_00(void);		// 00
		virtual void		   Unk_01(void);		// 01
		virtual void		   Unk_02(void);		// 02 - { return; }
		virtual TESObjectREFR* GetVisualsTarget();	// 03 - { return target ? target->GetTargetStatsObject() : 0; }
		virtual void		   Unk_04(void);		// 04 - { return; }
		virtual void		   Unk_05(void);		// 05
		virtual void		   Unk_06(void);		// 06 - { return 0; }
		virtual void		   Unk_07(void);		// 07 - { return; }
		virtual void		   Unk_08(void);		// 08
		virtual void		   Unk_09(void);		// 09
		virtual void		   Unk_0A(void);		// 0A
		virtual void		   Unk_0B(void);		// 0B - { unk88 = 4; }
		virtual void		   Unk_0C(void);		// 0C
		virtual void		   Unk_0D(void);		// 0D - { return; }
		virtual void		   Unk_0E(void);		// 0E - { return; }
		virtual void		   Unk_0F(void);		// 0F - { return; }
		virtual void		   Unk_10(void);		// 10
		virtual void		   Unk_11(void);		// 11 - { return 0; }
		virtual void		   Unk_12(void);		// 12 - { return; }

		virtual ~ActiveEffect();  // 13

		virtual void Unk_14(void);	// 14 - { return; }
		virtual void Unk_15(void);	// 15 - { return; }
		virtual void Unk_16(void);	// 16
		virtual void Unk_17(void);	// 17 - { return 1; }
		virtual void Unk_18(void);	// 18 - { return 1.0; }

		void							   Dispel(bool a_force);
		[[nodiscard]] EffectSetting*	   GetBaseObject() noexcept;
		[[nodiscard]] const EffectSetting* GetBaseObject() const noexcept;
		NiPointer<Actor>				   GetCasterActor() const;
		Actor*							   GetTargetActor();
		const Actor*					   GetTargetActor() const;

		ActiveEffectReferenceEffectController			 hitEffectController;  // 08
		BSSoundHandle									 persistentSound;	   // 28
		ActorHandle										 caster;			   // 34
		NiPointer<NiNode>								 sourceNode;		   // 38
		MagicItem*										 spell;				   // 40
		Effect*											 effect;			   // 48
		MagicTarget*									 target;			   // 50
		TESBoundObject*									 source;			   // 58
		BSSimpleList<ReferenceEffect*>*					 hitEffects;		   // 60
		MagicItem*										 displacementSpell;	   // 68
		float											 elapsedSeconds;	   // 70
		float											 duration;			   // 74
		float											 magnitude;			   // 78
		stl::enumeration<Flag, std::uint32_t>			 flags;				   // 7C
		stl::enumeration<ConditionStatus, std::uint32_t> conditionStatus;	   // 80
		std::uint16_t									 usUniqueID;		   // 84
		std::uint16_t									 pad86;				   // 86
		MagicSystem::CastingSource						 castingSource;		   // 88
		std::uint32_t									 pad8C;				   // 8C
	};
	static_assert(sizeof(ActiveEffect) == 0x90);
}
