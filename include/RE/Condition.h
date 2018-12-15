#pragma once

#include "RE/FormTypes.h"


namespace RE
{
	class Condition
	{
	private:
		enum class RunOn : UInt32
		{
			kNone = 0,
			kPerkOwner,
			kTarget
		};

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
			kHasBeenEaten = 0x007F,
			kHasMagicEffect = 0x00D6,
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
		STATIC_ASSERT(sizeof(Solution) == 0x30);  // xref 0x00444990 - Condition::Match_Impl - 1_5_53


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


		struct Node
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
		STATIC_ASSERT(offsetof(Node, next) == 0x00);
		STATIC_ASSERT(offsetof(Node, comparisonValue) == 0x08);
		STATIC_ASSERT(offsetof(Node, functionID) == 0x18);
		STATIC_ASSERT(offsetof(Node, param1) == 0x20);
		STATIC_ASSERT(offsetof(Node, param2) == 0x28);
		STATIC_ASSERT(offsetof(Node, comparisonFlags) == 0x30);
		STATIC_ASSERT(offsetof(Node, referenceType) == 0x31);
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
		bool Match(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target);	// Only operates on perkOwner, idk how they evaluate the target


		// members
		Node* perkOwnerNodes;	// 0
		Node* targetNodes;		// 8
	};
}
