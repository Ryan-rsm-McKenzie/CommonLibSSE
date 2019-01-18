#pragma once

#include "RE/FormTypes.h"  // Actor, TESForm
#include "RE/NiPoint3.h"  // NiPoint3
#include "RE/NiRect.h"  // NiRect


namespace RE
{
	UInt32 GetPickpocketChance(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_itemWeight, Actor* a_player, Actor* a_target, bool a_isDetected, TESForm* a_item);

	void SendItemsPickPocketedEvent(UInt32 a_numItems);

	void DebugNotification(const char* a_notification, void* a_unk2 = 0, bool a_unk3 = true);

	bool WorldPtToScreenPt3(float a_worldToCamMatrix[4][4], NiRect<float>& a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance);
}
