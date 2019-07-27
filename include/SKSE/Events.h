#pragma once

#include "skse64/PapyrusEvents.h"  // SKSEModCallbackEvent, SKSECameraEvent, SKSECrosshairRefEvent, SKSEActionEvent, SKSENiNodeUpdateEvent

#include "RE/Actor.h"  // Actor
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/NiSmartPointer.h"  // NiPointer
#include "RE/TESCameraState.h"  // TESCameraState
#include "RE/TESForm.h"  // TESForm
#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace SKSE
{
	struct ModCallbackEvent
	{
		ModCallbackEvent(RE::BSFixedString a_eventName, RE::BSFixedString a_strArg, float a_numArg, RE::TESForm* a_sender) :
			eventName(a_eventName),
			strArg(a_strArg),
			numArg(a_numArg),
			sender(a_sender)
		{}


		RE::BSFixedString	eventName;
		RE::BSFixedString	strArg;
		float				numArg;
		RE::TESForm*		sender;
	};
	STATIC_ASSERT(offsetof(ModCallbackEvent, eventName) == offsetof(SKSEModCallbackEvent, eventName));
	STATIC_ASSERT(offsetof(ModCallbackEvent, strArg) == offsetof(SKSEModCallbackEvent, strArg));
	STATIC_ASSERT(offsetof(ModCallbackEvent, numArg) == offsetof(SKSEModCallbackEvent, numArg));
	STATIC_ASSERT(offsetof(ModCallbackEvent, sender) == offsetof(SKSEModCallbackEvent, sender));
	STATIC_ASSERT(sizeof(ModCallbackEvent) == sizeof(SKSEModCallbackEvent));


	struct CameraEvent
	{
		CameraEvent(RE::TESCameraState* a_oldState, RE::TESCameraState* a_newState) :
			oldState(a_oldState),
			newState(a_newState)
		{}


		RE::TESCameraState*	oldState;
		RE::TESCameraState*	newState;
	};
	STATIC_ASSERT(offsetof(CameraEvent, oldState) == offsetof(SKSECameraEvent, oldState));
	STATIC_ASSERT(offsetof(CameraEvent, newState) == offsetof(SKSECameraEvent, newState));
	STATIC_ASSERT(sizeof(CameraEvent) == sizeof(SKSECameraEvent));


	struct CrosshairRefEvent
	{
		explicit CrosshairRefEvent(RE::NiPointer<RE::TESObjectREFR> a_crosshairRef) :
			crosshairRef(a_crosshairRef)
		{}


		RE::NiPointer<RE::TESObjectREFR> crosshairRef;
	};
	STATIC_ASSERT(offsetof(CrosshairRefEvent, crosshairRef) == offsetof(SKSECrosshairRefEvent, crosshairRef));
	STATIC_ASSERT(sizeof(CrosshairRefEvent) == sizeof(SKSECrosshairRefEvent));


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


		ActionEvent(Type a_type, RE::Actor* a_actor, RE::TESForm* a_sourceForm, Slot a_slot) :
			type(a_type),
			actor(a_actor),
			sourceForm(a_sourceForm),
			slot(a_slot)
		{}


		Type			type;
		RE::Actor*		actor;
		RE::TESForm*	sourceForm;
		Slot			slot;
	};
	STATIC_ASSERT(offsetof(ActionEvent, type) == offsetof(SKSEActionEvent, type));
	STATIC_ASSERT(offsetof(ActionEvent, actor) == offsetof(SKSEActionEvent, actor));
	STATIC_ASSERT(offsetof(ActionEvent, sourceForm) == offsetof(SKSEActionEvent, sourceForm));
	STATIC_ASSERT(offsetof(ActionEvent, slot) == offsetof(SKSEActionEvent, slot));
	STATIC_ASSERT(sizeof(ActionEvent) == sizeof(SKSEActionEvent));


	struct NiNodeUpdateEvent
	{
		explicit NiNodeUpdateEvent(RE::TESObjectREFR* a_reference) :
			reference(a_reference)
		{}


		RE::TESObjectREFR* reference;
	};
	STATIC_ASSERT(offsetof(NiNodeUpdateEvent, reference) == offsetof(SKSENiNodeUpdateEvent, reference));
	STATIC_ASSERT(sizeof(NiNodeUpdateEvent) == sizeof(SKSENiNodeUpdateEvent));
}
