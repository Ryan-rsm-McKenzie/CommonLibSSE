#pragma once

#include "RE/FormTypes.h"


namespace RE
{
	class Condition
	{
	public:
		enum class OpCode : UInt8
		{
			kEqualTo,				// ==
			kNotEqualTo,			// !=
			kGreaterThan,			// >
			kGreaterThanOrEqualTo,	// >=
			kLessThan,				// <
			kLessThanOrEqualTo,		// <=
		};


		enum class ReferenceType : UInt8
		{
			kSubject = 0,
			kTarget,
			kReference,
			kCombatTarget,
			kLinkedReference,
			kQuestAlias,
			kPackageData,
			kEventData,
			kPlayer
		};


		// Betheseda keeps these in a giant lookup table
		// typedef bool(*func)(TESObjectREFR* perkOwnerOrTarget, void* param1, void* param2, float& result);
		enum class FunctionID : UInt16
		{
			kGetLocked = 0x0005,
			kGetDead = 0x002E,
			kGetLockLevel = 0x0041,
			kGetIsRace = 0x0045,
			kGetInFaction = 0x0047,
			kHasBeenEaten = 0x007F,
			kHasMagicEffect = 0x00D6,
			kIsInInterior = 0x012C,
			kHasPerk = 0x01C0
		};


		struct Solution
		{
			constexpr Solution(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target) :
				perkOwner(a_perkOwner),
				target(a_target),
				unk10(0),
				unk18(0),
				unk20(0),
				unk28(0)
			{}


			TESObjectREFR*	perkOwner;	// 00
			TESObjectREFR*	target;		// 08
			void*			unk10;		// 10
			void*			unk18;		// 18
			void*			unk20;		// 20
			void*			unk28;		// 28
		};
		STATIC_ASSERT(sizeof(Solution) == 0x30);  // xref 0x00444990 - Condition::Run - 1_5_53


		struct ComparisonFlags
		{
			bool	isOR : 1;	// false == AND, true == OR
			bool	usesAliases : 1;
			bool	global : 1;
			bool	usePackData : 1;
			bool	swapTarget : 1;
			OpCode	opCode : 3;
		};
		STATIC_ASSERT(sizeof(ComparisonFlags) == 0x1);


		struct Node	// CTDA
		{
			bool Run(Solution& a_solution);


			// members
			Node*			next;				// 00
			float			comparisonValue;	// 08
			UInt32			unk0C;				// 0C
			UInt32			refHandle;			// 10 - kReference
			SInt32			unk14;				// 14
			FunctionID		functionID;			// 18
			UInt8			unk1A;				// 1A
			UInt8			unk1B;				// 1B
			UInt32			pad1C;				// 1C
			void*			param1;				// 20
			void*			param2;				// 28
			ComparisonFlags	comparisonFlags;	// 30
			ReferenceType	referenceType;		// 31
			UInt16			pad32;				// 32
			UInt32			pad34;				// 34
		};
		STATIC_ASSERT(sizeof(Node) == 0x38);


		// Bethesda has a native bug in the IsRunning func available via the CK, it looks like this:
		// bool IsRunning(TESObjectREFR* perkOwnerOrTarget, void* param1, void* param2, float& result)
		// {
		// 	Actor* actor = 0;
		// 	if (perkOwnerOrTarget->formType = kFormType_Character)
		// 		actor = (Actor*)perkOwnerOrTarget;
		// 	if (actor->IsRunning()) {
		// 		// etc
		//  }
		// }
		// Make sure to fix it before you call this func (xref 0x002DB800 - 1_5_53)
		// Perk fragments will short circuit
		bool Run(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target);


		// members
		Node* head;	// 0
	};
	STATIC_ASSERT(sizeof(Condition) == 0x8);
}
