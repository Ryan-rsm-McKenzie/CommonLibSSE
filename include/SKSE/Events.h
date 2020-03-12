#pragma once

#include "RE/Actor.h"
#include "RE/BSFixedString.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESCameraState.h"
#include "RE/TESForm.h"
#include "RE/TESObjectREFR.h"


namespace SKSE
{
	struct ModCallbackEvent
	{
		inline ModCallbackEvent(RE::BSFixedString a_eventName, RE::BSFixedString a_strArg, float a_numArg, RE::TESForm* a_sender) :
			eventName(a_eventName),
			strArg(a_strArg),
			numArg(a_numArg),
			sender(a_sender)
		{}


		RE::BSFixedString eventName;
		RE::BSFixedString strArg;
		float			  numArg;
		RE::TESForm*	  sender;
	};


	struct CameraEvent
	{
		constexpr CameraEvent(RE::TESCameraState* a_oldState, RE::TESCameraState* a_newState) :
			oldState(a_oldState),
			newState(a_newState)
		{}


		RE::TESCameraState* oldState;
		RE::TESCameraState* newState;
	};


	struct CrosshairRefEvent
	{
		explicit inline CrosshairRefEvent(RE::NiPointer<RE::TESObjectREFR> a_crosshairRef) :
			crosshairRef(a_crosshairRef)
		{}


		RE::NiPointer<RE::TESObjectREFR> crosshairRef;
	};


	struct ActionEvent
	{
		enum class Type : UInt32
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


		enum class Slot : UInt32
		{
			kLeft = 0,
			kRight = 1,
			kVoice = 2
		};


		constexpr ActionEvent(Type a_type, RE::Actor* a_actor, RE::TESForm* a_sourceForm, Slot a_slot) :
			type(a_type),
			actor(a_actor),
			sourceForm(a_sourceForm),
			slot(a_slot)
		{}


		Type		 type;
		RE::Actor*	 actor;
		RE::TESForm* sourceForm;
		Slot		 slot;
	};


	struct NiNodeUpdateEvent
	{
		explicit constexpr NiNodeUpdateEvent(RE::TESObjectREFR* a_reference) :
			reference(a_reference)
		{}


		RE::TESObjectREFR* reference;
	};
}
