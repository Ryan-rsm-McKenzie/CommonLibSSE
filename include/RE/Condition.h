#pragma once


namespace RE
{
	class TESObjectREFR;


	class Condition
	{
	private:
		enum RunOn : UInt32
		{
			kRunOn_None,
			kRunOn_PerkOwner,
			kRunOn_Target
		};

	public:
		enum OpCode : UInt8
		{
			kOpCode_EqualTo,	// ==
			kOpCode_NotEqualTo,	// !=
			kOpCode_GreaterThan,	// >
			kOpCode_GreaterThanOrEqualTo,	// >=
			kOpCode_LessThan,	// <
			kOpCode_LessThanOrEqualTo,	// <=
		};


		enum ReferenceType : UInt8
		{
			kReferenceType_Subject = 0,
			kReferenceType_Target,
			kReferenceType_Reference,
			kReferenceType_CombatTarget,
			kReferenceType_LinkedReference,
			kReferenceType_QuestAlias,
			kReferenceType_PackageData,
			kReferenceType_EventData,
			kReferenceType_Player
		};


		enum FunctionID : UInt16
		{
			kFunctionID_GetLocked = 0x0005,
			kFunctionID_GetLockLevel = 0x0041,
			kFunctionID_GetIsRace = 0x0045,
			//kFunctionID_GetIsRace = 0x007F,
			kFunctionID_HasMagicEffect = 0x00D6,
			kFunctionID_HasPerk = 0x01C0
		};


		struct ComparisonFlags
		{
			bool	isOr : 1;	// false == AND, true == OR
			bool	usesAliases : 1;
			bool	global : 1;
			bool	usePackData : 1;
			bool	swapTarget : 1;
			OpCode	opCode : 3;
		};
		STATIC_ASSERT(sizeof(ComparisonFlags) == 0x1);


		struct Node
		{
			bool Run(TESObjectREFR*& a_refr);


			// members
			Node*			next;				// 00
			float			comparisonValue;	// 08
			UInt32			unk0C;				// 0C
			UInt32			refHandle;			// 10 - kReferenceType_Reference
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


		bool Run(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target);
		bool Match(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target);


		// members
		Node* perkOwnerNodes;	// 0
		Node* targetNodes;		// 8
	};
}
