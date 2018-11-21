#pragma once

#include "skse64/GameEvents.h"  // EventDispatcher, TESActiveEffectApplyRemoveEvent, TESCellAttachDetachEvent, TESCombatEvent, TESContainerChangedEvent, TESDeathEvent, TESInitScriptEvent, TESObjectLoadedEvent, TESUniqueIDChangeEvent


namespace RE
{
	class EventDispatcherList
	{
	public:
		static EventDispatcherList* GetEventDispatcherList();


		EventDispatcher<void>								unk0000;					//	00
		EventDispatcher<void>								unk0058;					//  58  - sink offset 010
		EventDispatcher<TESActiveEffectApplyRemoveEvent>	unk00B0;					//  B0  - sink offset 018
		EventDispatcher<void>								unk0108;					//  108 - sink offset 020
		EventDispatcher<void>								unk0160;					//  160 - sink offset 028
		EventDispatcher<TESCellAttachDetachEvent>			unk01B8;					//  1B8 - sink offset 030
		EventDispatcher<void>								unk0210;					//  210 - sink offset 038
		EventDispatcher<void>								unk02C0;					//  2C0 - sink offset 040
		EventDispatcher<TESCombatEvent>						combatDispatcher;			//  318 - sink offset 048
		EventDispatcher<TESContainerChangedEvent>			containerChangedDispatcher;	//  370 - sink offset 050
		EventDispatcher<TESDeathEvent>						deathDispatcher;			//  3C8 - sink offset 058
		EventDispatcher<void>								unk0420;					//  420 - sink offset 068
		EventDispatcher<void>								unk0478;					//  478 - sink offset 070
		EventDispatcher<void>								unk04D0;					//  4D0 - sink offset 078
		EventDispatcher<void>								unk0528;					//  528 - sink offset 080
		EventDispatcher<void>								unk0580;					//  580 - sink offset 088
		EventDispatcher<void>								unk05D8;					//  5D8 - sink offset 090
		EventDispatcher<void>								unk0630;					//  630 - sink offset 098
		EventDispatcher<TESInitScriptEvent>					initScriptDispatcher;		//  688 - sink offset 0A0
		EventDispatcher<void>								unk06E0;					//  6E0 - sink offset 0A8
		EventDispatcher<void>								unk0738;					//  738 - sink offset 0B0
		EventDispatcher<void>								unk0790;					//  790 - sink offset 0B8
		EventDispatcher<void>								unk07E8;					//  7E8 - sink offset 0C0
		EventDispatcher<void>								unk0840;					//  840 - sink offset 0C8
		EventDispatcher<TESObjectLoadedEvent>				objectLoadedDispatcher;		//  898 - sink offset 0D0
		EventDispatcher<void>								unk08F0;					//  8F0 - sink offset 0D8
		EventDispatcher<void>								unk0948;					//  948 - sink offset 0E0
		EventDispatcher<void>								unk09A0;					//  9A0 - sink offset 0E8
		EventDispatcher<void>								unk09F8;					//  9F8 - sink offset 0F0
		EventDispatcher<void>								unk0A50;					//  A50 - sink offset 0F8
		EventDispatcher<void>								unk0AA8;					//  AA8 - sink offset 100
		EventDispatcher<void>								unk0B00;					//  B00 - sink offset 108
		EventDispatcher<void>								unk0B58;					//  B58 - sink offset 110
		EventDispatcher<void>								unk0BB0;					//  BB0 - sink offset 118
		EventDispatcher<void>								unk0C08;					//  C08 - sink offset 120
		EventDispatcher<void>								unk0C60;					//  C60 - sink offset 128
		EventDispatcher<void>								unk0CB8;					//  CB8 - sink offset 130
		EventDispatcher<void>								unk0D10;					//  D10 - sink offset 138
		EventDispatcher<void>								unk0D68;					//  D68 - sink offset 140
		EventDispatcher<void>								unk0DC0;					//  DC0 - sink offset 148
		EventDispatcher<void>								unk0E18;					//  E18 - sink offset 150
		EventDispatcher<void>								unk0E70;					//  E70 - sink offset 158
		EventDispatcher<void>								unk0EC8;					//  EC8 - sink offset 160
		EventDispatcher<void>								unk0F20;					//  F20 - sink offset 168
		EventDispatcher<void>								unk0F78;					//  F78 - sink offset 170
		EventDispatcher<void>								unk0FD0;					//  FD0 - sink offset 178
		EventDispatcher<void>								unk1028;					// 1028 - sink offset 180
		EventDispatcher<void>								unk1080;					// 1080 - sink offset 188
		EventDispatcher<void>								unk10D8;					// 10D8 - sink offset 190
		EventDispatcher<void>								unk1130;					// 1130 - sink offset 198
		EventDispatcher<void>								unk1188;					// 1188 - sink offset 200
		EventDispatcher<void>								unk11E0;					// 11E0 - sink offset 208
		EventDispatcher<void>								unk1238;					// 1238 - sink offset 210
		EventDispatcher<TESUniqueIDChangeEvent>				uniqueIdChangeDispatcher;	// 1290 - sink offset 218
	};
}
