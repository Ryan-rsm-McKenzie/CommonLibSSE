#pragma once

#include "skse64/GameForms.h"  // kFormType

#include "RE/MagicItem.h"  // MagicItem::EffectItem

class MagicItem;
class TESForm;


namespace RE
{
	class EffectSetting;
	class MagicItem;
	class TESObjectREFR;


	class ActiveEffect
	{
	public:
		enum { kTypeID = kFormType_ActiveMagicEffect };


		enum Flag
		{
			kFlag_Inactive	= 0x08000,
			kFlag_Dispelled	= 0x40000
		};


		virtual ~ActiveEffect();

		EffectSetting*	GetBaseObject() const;
		bool			Dispell(bool a_force);


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
		MagicItem::EffectItem*					effect;				// 48 - init'd to ctor argumet
		TESObjectREFR*							magicTarget;		// 50
		TESForm*								sourceItem;			// 58
		void*									unk60;				// 60
		void*									un68;				// 68
		float									elapsed;			// 70
		float									duration;			// 74
		float									magnitude;			// 78
		UInt32									flags;				// 7C
		UInt32									unk80;				// 80 - init'd to 1
		UInt32									effectNum;			// 84 - Somekind of counter used to determine whether the ActiveMagicEffect handle is valid
		UInt32									unk88;				// 88 - init'd to 4
		UInt32									pad8C;				// 8C
		UInt32									actorValue;			// 90 - Only seems to appear on value modifiers
		UInt32									unk94;				// 94
		UInt64									unk98;				// 98


	private:
		typedef bool _Dispell_t(ActiveEffect* a_this, bool a_force);  // Returns success?
		static RelocAddr<_Dispell_t*> _Dispell;
	};
}
