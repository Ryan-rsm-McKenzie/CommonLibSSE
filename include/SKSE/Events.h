#pragma once

#include "RE/A/Actor.h"
#include "RE/B/BSFixedString.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESCameraState.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESObjectREFR.h"

namespace SKSE
{
	struct ModCallbackEvent
	{
	public:
		// members
		RE::BSFixedString eventName;
		RE::BSFixedString strArg;
		float             numArg;
		RE::TESForm*      sender;
	};

	struct CameraEvent
	{
	public:
		// members
		RE::TESCameraState* oldState;
		RE::TESCameraState* newState;
	};

	struct CrosshairRefEvent
	{
	public:
		// members
		RE::NiPointer<RE::TESObjectREFR> crosshairRef;
	};

	struct ActionEvent
	{
	public:
		enum class Type
		{
			kWeaponSwing = 0,
			kSpellCast = 1,
			kSpellFire = 2,
			kVoiceCast = 3,
			kVoiceFire = 4,
			kBowDraw = 5,
			kBowRelease = 6,
			kBeginDraw = 7,
			kEndDraw = 8,
			kBeginSheathe = 9,
			kEndSheathe = 10
		};

		enum class Slot
		{
			kLeft = 0,
			kRight = 1,
			kVoice = 2
		};

		// members
		stl::enumeration<Type, std::uint32_t> type;
		RE::Actor*                            actor;
		RE::TESForm*                          sourceForm;
		stl::enumeration<Slot, std::uint32_t> slot;
	};

	struct NiNodeUpdateEvent
	{
	public:
		// members
		RE::TESObjectREFR* reference;
	};
}
