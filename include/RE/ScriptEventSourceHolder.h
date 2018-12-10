#pragma once

#include "skse64/GameEvents.h"  // TESActiveEffectApplyRemoveEvent, TESCellAttachDetachEvent, TESCombatEvent, TESContainerChangedEvent, TESDeathEvent, TESInitScriptEvent, TESObjectLoadedEvent, TESUniqueIDChangeEvent

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/TESObjectREFR.h"  // TESObjectREFRPtr


namespace RE
{
	class ScriptEventSourceHolder
	{
	public:
		static ScriptEventSourceHolder*	GetSingleton();

		void							SendActivateEvent(TESObjectREFRPtr& a_target, TESObjectREFRPtr& a_caster);


		// members
		BSTEventSource<void>								unk0000;						// 0000
		BSTEventSource<void>								unk0058;						// 0058 - sink offset 010
		BSTEventSource<TESActiveEffectApplyRemoveEvent>		unk00B0;						// 00B0 - sink offset 018
		BSTEventSource<void>								unk0108;						// 0108 - sink offset 020
		BSTEventSource<void>								unk0160;						// 0160 - sink offset 028
		BSTEventSource<TESCellAttachDetachEvent>			unk01B8;						// 01B8 - sink offset 030
		BSTEventSource<void>								unk0210;						// 0210 - sink offset 038
		BSTEventSource<void>								unk02C0;						// 02C0 - sink offset 040
		BSTEventSource<TESCombatEvent>						combatEventSource;				// 0318 - sink offset 048
		BSTEventSource<TESContainerChangedEvent>			containerChangedEventSource;	// 0370 - sink offset 050
		BSTEventSource<TESDeathEvent>						deathEventSource;				// 03C8 - sink offset 058
		BSTEventSource<void>								unk0420;						// 0420 - sink offset 068
		BSTEventSource<void>								unk0478;						// 0478 - sink offset 070
		BSTEventSource<void>								unk04D0;						// 04D0 - sink offset 078
		BSTEventSource<void>								unk0528;						// 0528 - sink offset 080
		BSTEventSource<void>								unk0580;						// 0580 - sink offset 088
		BSTEventSource<void>								unk05D8;						// 05D8 - sink offset 090
		BSTEventSource<void>								unk0630;						// 0630 - sink offset 098
		BSTEventSource<TESInitScriptEvent>					initScriptEventSource;			// 0688 - sink offset 0A0
		BSTEventSource<void>								unk06E0;						// 06E0 - sink offset 0A8
		BSTEventSource<void>								unk0738;						// 0738 - sink offset 0B0
		BSTEventSource<void>								unk0790;						// 0790 - sink offset 0B8
		BSTEventSource<void>								unk07E8;						// 07E8 - sink offset 0C0
		BSTEventSource<void>								unk0840;						// 0840 - sink offset 0C8
		BSTEventSource<TESObjectLoadedEvent>				objectLoadedEventSource;		// 0898 - sink offset 0D0
		BSTEventSource<void>								unk08F0;						// 08F0 - sink offset 0D8
		BSTEventSource<void>								unk0948;						// 0948 - sink offset 0E0
		BSTEventSource<void>								unk09A0;						// 09A0 - sink offset 0E8
		BSTEventSource<void>								unk09F8;						// 09F8 - sink offset 0F0
		BSTEventSource<void>								unk0A50;						// 0A50 - sink offset 0F8
		BSTEventSource<void>								unk0AA8;						// 0AA8 - sink offset 100
		BSTEventSource<void>								unk0B00;						// 0B00 - sink offset 108
		BSTEventSource<void>								unk0B58;						// 0B58 - sink offset 110
		BSTEventSource<void>								unk0BB0;						// 0BB0 - sink offset 118
		BSTEventSource<void>								unk0C08;						// 0C08 - sink offset 120
		BSTEventSource<void>								unk0C60;						// 0C60 - sink offset 128
		BSTEventSource<void>								unk0CB8;						// 0CB8 - sink offset 130
		BSTEventSource<void>								unk0D10;						// 0D10 - sink offset 138
		BSTEventSource<void>								unk0D68;						// 0D68 - sink offset 140
		BSTEventSource<void>								unk0DC0;						// 0DC0 - sink offset 148
		BSTEventSource<void>								unk0E18;						// 0E18 - sink offset 150
		BSTEventSource<void>								unk0E70;						// 0E70 - sink offset 158
		BSTEventSource<void>								unk0EC8;						// 0EC8 - sink offset 160
		BSTEventSource<void>								unk0F20;						// 0F20 - sink offset 168
		BSTEventSource<void>								unk0F78;						// 0F78 - sink offset 170
		BSTEventSource<void>								unk0FD0;						// 0FD0 - sink offset 178
		BSTEventSource<void>								unk1028;						// 1028 - sink offset 180
		BSTEventSource<void>								unk1080;						// 1080 - sink offset 188
		BSTEventSource<void>								unk10D8;						// 10D8 - sink offset 190
		BSTEventSource<void>								unk1130;						// 1130 - sink offset 198
		BSTEventSource<void>								unk1188;						// 1188 - sink offset 200
		BSTEventSource<void>								unk11E0;						// 11E0 - sink offset 208
		BSTEventSource<void>								unk1238;						// 1238 - sink offset 210
		BSTEventSource<TESUniqueIDChangeEvent>				uniqueIDChangeEventSource;		// 1290 - sink offset 218
	};
}
