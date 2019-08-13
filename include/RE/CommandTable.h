#pragma once

#include <string>  // string

#include "RE/FormTypes.h"


namespace RE
{
	class Script;
	class ScriptLocals;
	class ScriptLineBuffer;
	class ScriptBuffer;


	struct SCRIPT_PARAMETER
	{
		enum class Type : UInt32
		{
			kString = 0x0,
			kInteger = 0x1,
			kFloat = 0x2,
			kObjectReference = 0x4,
			kActorValue = 0x5,
			kActor = 0x6,
			kSpellItem = 0x7,
			kAxis = 0x8,
			kCell = 0x9,
			kAnimationGroup = 0x0A,
			kMagicItem = 0x0B,
			kSound = 0x0C,
			kTopic = 0x0D,
			kQuest = 0x0E,
			kRace = 0x0F,
			kClass = 0x10,
			kFaction = 0x11,
			kSex = 0x12,
			kObject = 0x15,
			kVariableName = 0x16,
			kQuestStage = 0x17,
			kMapMarker = 0x18,
			kActorBase = 0x19,
			kCoontainer = 0x1A,
			kWorldSpace = 0x1B,
			kCrimeType = 0x1C,
			kPackage = 0x1D,
			kMagicEffect = 0x1F,
			kWeather = 0x21,
			kOwner = 0x23,
			kEffectShader = 0x24,
			kFormList = 0x25,
			kPerk = 0x27,
			kNote = 0x28,
			kMiscellaneousStat = 0x29,
			kImagespaceModifier = 0x2A,
			kEventFunction = 0x2E,
			kEventMember = 0x2F,
			kEventData = 0x30,
			kVoice = 0x31,
			kEncounterZone = 0x32,
			kMessage = 0x34,
			kObjectID = 0x35,
			kAlignment = 0x36,
			kEquipType = 0x37,
			kMusic = 0x39,
			kKeyword = 0x3B,
			kRefType = 0x3C,
			kLocation = 0x3D,
			kForm = 0x3E,
			kQuestAlias = 0x3F,
			kShout = 0x40,
			kWordOfPower = 0x41,
			kScene = 0x43,
			kHand = 0x44,	// right hand or left hand
			kAssociationType = 0x45,
			kWardState = 0x46,
			kPackageData_PossiblyNull = 0x47,
			kPackageData_Numeric = 0x48,
			kFurnitureAnimType = 0x49,
			kFurnitureEntryType = 0x4A,
			kVMVariableName = 0x4C,
			kPackageData = 0x4E,
			kKnowableForm = 0x51,
			kRegion = 0x52
		};


		const char*	typeStr;	// 00
		Type		typeID;		// 08 - ParamType
		UInt32		isOptional;	// 0C - do other bits do things?
	};
	STATIC_ASSERT(sizeof(SCRIPT_PARAMETER) == 0x10);


	struct CommandInfo
	{
		struct Commands
		{
			enum : UInt32
			{
				kConsoleCommandsEnd = 0x01B4,
				kConsoleOpBase = 0x0100,

				kScriptCommandsEnd = 0x02E0,
				kScriptOpBase = 0x1000
			};
		};


		struct StringChunk;
		struct IntegerChunk;


		struct Chunk
		{
			StringChunk*	AsString();
			IntegerChunk*	AsInteger();
		};


		struct StringChunk : public Chunk
		{
			std::string	GetString() const;
			Chunk*		GetNext();


			// members
			UInt16	length;	// 00
			char	str[0];	// 02
		};


#pragma pack(push, 1)
		struct IntegerChunk : public Chunk
		{
			int		GetInteger() const;
			Chunk*	GetNext();


			// members
			char	unk00;	// 00 - magic val?
			SInt32	value;	// 01
		};
		STATIC_ASSERT(offsetof(IntegerChunk, value) == 0x1);
		STATIC_ASSERT(sizeof(IntegerChunk) == 0x5);
#pragma pack(pop)


		struct ScriptData
		{
			Chunk*			GetChunk();
			StringChunk*	GetStringChunk();
			IntegerChunk*	GetIntegerChunk();


			// members
			UInt16	opcode;		// 00
			UInt16	chunkSize;	// 02
			UInt16	numParams;	// 04
		};


		using FnExecute = bool(const SCRIPT_PARAMETER* a_paramInfo, ScriptData* a_scriptData, TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, double& a_result, UInt32& a_opcodeOffsetPtr);
		using FnParse = bool(UInt32 a_numParams, const SCRIPT_PARAMETER* a_paramInfo, ScriptLineBuffer* a_lineBuf, ScriptBuffer* a_scriptBuf);
		using FnEval = bool(TESObjectREFR* a_thisObj, void* a_arg1, void* a_arg2, double& a_result);


		static CommandInfo*	GetFirstScriptCommand();
		static CommandInfo*	LocateScriptCommand(const char* a_longName);

		static CommandInfo*	GetFirstConsoleCommand();
		static CommandInfo*	LocateConsoleCommand(const char* a_longName);

		template <UInt16 SIZE> void	SetParameters(const SCRIPT_PARAMETER(&a_params)[SIZE]);
		void						SetParameters();


		// members
		const char*				longName;		// 00
		const char*				shortName;		// 08
		UInt32					opcode;			// 10
		UInt32					pad14;			// 14
		const char*				helpText;		// 18
		bool					isRefRequired;	// 20
		UInt8					pad21;			// 21
		UInt16					numParams;		// 22
		UInt32					pad24;			// 24
		const SCRIPT_PARAMETER*	params;			// 28
		FnExecute*				execute;		// 30
		FnParse*				parse;			// 38
		FnEval*					eval;			// 40
		UInt32					flags;			// 48
		UInt32					pad4C;			// 4C
	};
	STATIC_ASSERT(sizeof(CommandInfo) == 0x50);


	template <UInt16 SIZE>
	void CommandInfo::SetParameters(const SCRIPT_PARAMETER(&a_params)[SIZE])
	{
		numParams = SIZE;
		params = a_params;
	}
}
