#pragma once

#include "skse64/GameObjects.h"  // ActiveEffectReferenceEffectController

#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class EffectSetting;
	class MagicItem;
	class TESForm;
	class TESObjectREFR;
	struct EffectItem;


	class ActiveEffect
	{
	public:
		enum { kTypeID = FormType::ActiveMagicEffect };


		enum Flag : UInt32
		{
			kInactive	= 0x08000,
			kDispelled	= 0x40000
		};


		// add
		virtual ~ActiveEffect();	// 00

		EffectSetting*	GetBaseObject() const;
		bool			Dispell(bool a_force);	// Returns success?


		ActiveEffectReferenceEffectController	controller;			// 08
		UInt32									unk18;				// 18
		float									unk1C;				// 1C
		float									unk20;				// 20
		float									unk24;				// 24
		UInt32									unk28;				// 28 - init'd to FFFFFFFF
		UInt8									unk2C;				// 2C
		UInt8									pad2D[3];			// 2D
		UInt32									unk30;				// 30
		UInt32									casterRefhandle;	// 34
		void*									niNode;				// 38
		MagicItem*								item;				// 40 - init'd to ctor argument
		EffectItem*								effect;				// 48 - init'd to ctor argumet
		TESObjectREFR*							magicTarget;		// 50
		TESForm*								sourceItem;			// 58
		void*									unk60;				// 60
		void*									un68;				// 68
		float									elapsed;			// 70
		float									duration;			// 74
		float									magnitude;			// 78
		Flag									flags;				// 7C
		UInt32									unk80;				// 80 - init'd to 1
		UInt32									effectNum;			// 84 - Somekind of counter used to determine whether the ActiveMagicEffect handle is valid
		UInt32									unk88;				// 88 - init'd to 4
		UInt32									pad8C;				// 8C
		UInt32									actorValue;			// 90 - Only seems to appear on value modifiers
		UInt32									unk94;				// 94
		UInt64									unk98;				// 98
	};
}
