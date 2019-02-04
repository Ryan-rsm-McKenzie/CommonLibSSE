#include "RE/Misc.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	UInt32 GetPickpocketChance(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_itemWeight, Actor* a_player, Actor* a_target, bool a_isDetected, TESForm* a_item)
	{
		typedef UInt32 _GetPickPocketChance_t(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_itemWeight, Actor* a_player, Actor* a_target, bool a_isDetected, TESForm* a_item);
		static RelocAddr<_GetPickPocketChance_t*> _GetPickPocketChance(GET_PICK_POCKET_CHANCE);
		return _GetPickPocketChance(a_playerSkill, a_targetSkill, a_totalValue, a_itemWeight, a_player, a_target, a_isDetected, a_item);
	}


	void DebugNotification(const char* a_notification, void* a_unk2, bool a_unk3)
	{
		typedef void _DebugNotification_t(const char* a_notification, void* a_unk2, bool a_unk3);
		static RelocAddr<_DebugNotification_t*> _DebugNotification(DEBUG_NOTIFICATION);
		_DebugNotification(a_notification, a_unk2, a_unk3);
	}


	bool WorldPtToScreenPt3(float a_worldToCamMatrix[4][4], NiRect<float>& a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance)
	{
		typedef bool _WorldPtToScreenPt3_t(float a_worldToCamMatrix[4][4], NiRect<float>& a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance);
		static RelocAddr<_WorldPtToScreenPt3_t*> _WorldPtToScreenPt3(WORLD_PT_TO_SCREEN_PT_3);
		return _WorldPtToScreenPt3(a_worldToCamMatrix, a_port, a_in, a_xOut, a_yOut, a_zOut, a_zeroTolerance);
	}
}
