#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class BGSImpactData;
	class BGSImpactDataSet;
	class NiAVObject;
	class TESObjectREFR;

	struct BSSoundHandle;

	struct IMPACT_SOUND_DATA
	{
	public:
		// members
		BGSImpactData* impactData;				   // 00
		NiPoint3*	   position;				   // 08
		NiAVObject*	   objectToFollow{ nullptr };  // 10
		BSSoundHandle* sound1{ nullptr };		   // 18
		BSSoundHandle* sound2{ nullptr };		   // 20
		bool		   playSound1{ false };		   // 28
		bool		   playSound2{ false };		   // 29
		bool		   unk2A{ false };			   // 2A
		void*		   unk30{ nullptr };		   // 30
	};
	static_assert(sizeof(IMPACT_SOUND_DATA) == 0x38);

	class BGSImpactManager
	{
	public:
		static BGSImpactManager* GetSingleton();

		bool PlayImpactEffect(TESObjectREFR* a_objectReference, BGSImpactDataSet* a_impactEffect, const char* a_nodeName = "", NiPoint3 a_pickDirection = NiPoint3(0.0F, 0.0F, -1.0F), float a_pickLength = 512.0F, bool a_applyNodeRotation = false, bool a_useNodeLocalRotation = false);
		bool PlaySound(IMPACT_SOUND_DATA& a_impactSoundData);
	};
}
