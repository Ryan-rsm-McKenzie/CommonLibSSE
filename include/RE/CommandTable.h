#pragma once

#include <string>  // string

#include "RE/FormTypes.h"

class Script;
class ScriptLocals;
class ScriptLineBuffer;
class ScriptBuffer;


namespace RE
{
	struct SCRIPT_PARAMETER
	{
		enum Type : UInt32
		{
			kType_String = 0,
			kType_Integer = 1,
			kType_Float = 2,
			kType_ObjectReference = 4,
			kType_ActorValue = 5,
			kType_Actor = 6,
			kType_SpellItem = 7,
			kType_Axis = 8,
			kType_Cell = 9,
			kType_AnimationGroup = 0x0A,
			kType_MagicItem = 0x0B,
			kType_Sound = 0x0C,
			kType_Topic = 0x0D,
			kType_Quest = 0x0E,
			kType_Race = 0x0F,
			kType_Class = 0x10,
			kType_Faction = 0x11,
			kType_Sex = 0x12,
			kType_Object = 0x15,
			kType_VariableName = 0x16,
			kType_QuestStage = 0x17,
			kType_MapMarker = 0x18,
			kType_ActorBase = 0x19,
			kType_Coontainer = 0x1A,
			kType_WorldSpace = 0x1B,
			kType_CrimeType = 0x1C,
			kType_Package = 0x1D,
			kType_MagicEffect = 0x1F,
			kType_Weather = 0x21,
			kType_Owner = 0x23,
			kType_EffectShader = 0x24,
			kType_FormList = 0x25,
			kType_Perk = 0x27,
			kType_Note = 0x28,
			kType_MiscellaneousStat = 0x29,
			kType_ImagespaceModifier = 0x2A,
			kType_EventFunction = 0x2E,
			kType_EventMember = 0x2F,
			kType_EventData = 0x30,
			kType_Voice = 0x31,
			kType_EncounterZone = 0x32,
			kType_Message = 0x34,
			kType_ObjectID = 0x35,
			kType_Alignment = 0x36,
			kType_EquipType = 0x37,
			kType_Music = 0x39,
			kType_Keyword = 0x3B,
			kType_RefType = 0x3C,
			kType_Location = 0x3D,
			kType_Form = 0x3E,
			kType_QuestAlias = 0x3F,
			kType_Shout = 0x40,
			kType_WordOfPower = 0x41,
			kType_Scene = 0x43,
			kType_Hand = 0x44,	// right hand or left hand
			kType_AssociationType = 0x45,
			kType_WardState = 0x46,
			kType_PackageData_PossiblyNull = 0x47,
			kType_PackageData_Numeric = 0x48,
			kType_FurnitureAnimType = 0x49,
			kType_FurnitureEntryType = 0x4A,
			kType_VMVariableName = 0x4C,
			kType_PackageData = 0x4E,
			kType_KnowableForm = 0x51,
			kType_Region = 0x52
		};


		const char*	typeStr;	// 00
		Type		typeID;		// 08 - ParamType
		UInt32		isOptional;	// 0C - do other bits do things?
	};


	struct CommandInfo
	{
		enum
		{
			kCommand_ConsoleCommandsBegin = 0x0000,
			kCommand_ConsoleCommandsend = 0x01B3,
			kCommand_ConsoleOpBase = 0x0100,

			kCommand_ScriptCommandsBegin = 0x01B4,
			kCommand_ScriptCommandsEnd = 0x02DF,
			kCommand_ScriptOpBase = 0x1000
		};


#pragma pack(push, 1)
		struct Chunk
		{};


		struct StringChunk : public Chunk
		{
			std::string	GetString() const;
			Chunk*		GetNext();


			// members
			UInt16	length;	// 00
			char	str[1];	// 02
		};


		struct IntegerChunk : public Chunk
		{
			int		GetInteger() const;
			Chunk*	GetNext();


			// members
			char	unk00;	// 00
			int		value;	// 01
		};
#pragma pack(pop)


		struct ScriptData
		{
			Chunk*	GetChunk();


			// members
			UInt16	opcode;		// 00
			UInt16	chunkSize;	// 02
			UInt16	numParams;	// 04
			UInt16	strLen;		// 06
			char	str[1];		// 08
		};


		typedef bool(*FnExecute)(const SCRIPT_PARAMETER* a_paramInfo, ScriptData* a_scriptData, TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, double& a_result, UInt32& a_opcodeOffsetPtr);
		typedef bool(*FnParse)(UInt32 a_numParams, const SCRIPT_PARAMETER* a_paramInfo, ScriptLineBuffer* a_lineBuf, ScriptBuffer* a_scriptBuf);
		typedef bool(*FnEval)(TESObjectREFR* a_thisObj, void* a_arg1, void* a_arg2, double& a_result);


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

		// handlers
		FnExecute				execute;		// 30
		FnParse					parse;			// 38
		FnEval					eval;			// 40

		UInt32					flags;			// 48
		UInt32					pad4C;			// 4C

		template <std::size_t SIZE>
		void				SetParameters(const SCRIPT_PARAMETER(&a_params)[SIZE])
		{
			numParams = SIZE;
			params = a_params;
		}
		void					SetParameters();
		static CommandInfo*		GetFirstScriptCommand();
		static CommandInfo*		GetFirstConsoleCommand();
		static CommandInfo*		Locate(const char* a_longName);
		static bool				ExtractArgs(SCRIPT_PARAMETER* a_paramInfo, void* a_scriptData, UInt32* a_arg2, TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_script, ScriptLocals* a_eventList, ...);
		static bool				Cmd_Default_Execute(const SCRIPT_PARAMETER* a_paramInfo, const char* a_scriptData, TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, double& a_result, UInt32& a_opcodeOffsetPtr);
		static bool				Cmd_Default_Parse(UInt32 a_numParams, const SCRIPT_PARAMETER* a_paramInfo, ScriptLineBuffer* a_lineBuf, ScriptBuffer* a_scriptBuf);
		static bool				Cmd_Default_Eval(TESObjectREFR* a_thisObj, void* a_arg1, void* a_arg2, double* a_result);
	};
	STATIC_ASSERT(sizeof(CommandInfo) == 0x50);
}
