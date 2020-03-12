#pragma once

#include <string>

#include "RE/BSString.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"


namespace RE
{
	class ScriptLocals;
	struct ACTION_OBJECT;
	struct ConditionCheckParams;
	struct ScriptCompileData;
	struct ScriptLineBuffer;
	struct ScriptVariable;
	struct SCRIPT_EFFECT_DATA;
	struct SCRIPT_HEADER;
	struct SCRIPT_LINE;
	struct SCRIPT_LOCAL;
	struct SCRIPT_PARAMETER;
	struct SCRIPT_REFERENCED_OBJECT;


	enum class SCRIPT_PARAM_TYPE : UInt32
	{
		kChar = 0x0,
		kInt = 0x1,
		kFloat = 0x2,
		kInventoryObject = 0x3,
		kObjectRef = 0x4,
		kActorValue = 0x5,
		kActor = 0x6,
		kSpellItem = 0x7,
		kAxis = 0x8,
		kCell = 0x9,
		kAnimGroup = 0x0A,
		kMagicItem = 0x0B,
		kSound = 0x0C,
		kTopic = 0x0D,
		kQuest = 0x0E,
		kRace = 0x0F,
		kClass = 0x10,
		kFaction = 0x11,
		kSex = 0x12,
		kGlobal = 0x13,
		kFurnitureOrFormList = 0x14,
		kObject = 0x15,
		kScriptVar = 0x16,
		kStage = 0x17,
		kMapMarker = 0x18,
		kActorBase = 0x19,
		kCoontainerRef = 0x1A,
		kWorldOrList = 0x1B,
		kCrimeType = 0x1C,
		kPackage = 0x1D,
		kCombatStyle = 0x1E,
		kMagicEffect = 0x1F,
		kFormType = 0x20,
		kWeather = 0x21,
		kNPC = 0x22,
		kOwner = 0x23,
		kShaderEffect = 0x24,
		kFormList = 0x25,
		kMenuIcon = 0x26,
		kPerk = 0x27,
		kNote = 0x28,
		kMiscStat = 0x29,
		kImagespaceMod = 0x2A,
		kImagespace = 0x2B,
		kVATSValue = 0x2C,
		kVATSValueData = 0x2D,
		kEventFunction = 0x2E,
		kEventFunctionMember = 0x2F,
		kEventFunctionData = 0x30,
		kVoiceType = 0x31,
		kEncounterZone = 0x32,
		kIdleForm = 0x33,
		kMessage = 0x34,
		kInvObjectOrFormList = 0x35,
		kAlignment = 0x36,
		kEquipType = 0x37,
		kObjectOrFormList = 0x38,
		kMusic = 0x39,
		kCritStage = 0x3A,
		kKeyword = 0x3B,
		kRefType = 0x3C,
		kLocation = 0x3D,
		kForm = 0x3E,
		kAlias = 0x3F,
		kShout = 0x40,
		kWordOfPower = 0x41,
		kRelationshipRank = 0x42,
		kBGSScene = 0x43,
		kCastingSource = 0x44,
		kAssociationType = 0x45,
		kWardState = 0x46,
		kPackageDataCanBeNull = 0x47,
		kPackageDataNumeric = 0x48,
		kFurnitureAnimType = 0x49,
		kFurnitureEntryType = 0x4A,
		kVMScriptVar = 0x4C,
		kReferenceEffect = 0x4D,
		kPackageData = 0x4E,
		kSoundCategory = 0x50,
		kKnowableForm = 0x51,
		kRegion = 0x52
	};


	// basically the unique id for the function, there's ~5000 of these
	enum class SCRIPT_OUTPUT : UInt32
	{
	};


	enum class SCRIPT_ERROR : UInt32
	{
	};


	struct SCRIPT_HEADER
	{
		UInt32 variableCount;		 // 00
		UInt32 refObjectCount;		 // 04
		UInt32 dataSize;			 // 08
		UInt32 lastID;				 // 0C
		bool   isQuestScript;		 // 10
		bool   isMagicEffectScript;	 // 11
		bool   isCompiled;			 // 12
		UInt8  pad13;				 // 13
	};
	STATIC_ASSERT(sizeof(SCRIPT_HEADER) == 0x14);


	struct SCRIPT_PARAMETER
	{
		const char*		  paramName;  // 00
		SCRIPT_PARAM_TYPE paramType;  // 08
		bool			  optional;	  // 0C
		UInt8			  pad0D;	  // 0D
		UInt16			  pad0E;	  // 0E
	};
	STATIC_ASSERT(sizeof(SCRIPT_PARAMETER) == 0x10);


	struct SCRIPT_REFERENCED_OBJECT
	{
		BSString editorID;	  // 00
		TESForm* form;		  // 10
		UInt32	 variableID;  // 18
		UInt32	 pad1C;		  // 1C
	};
	STATIC_ASSERT(sizeof(SCRIPT_REFERENCED_OBJECT) == 0x20);


	struct ACTION_OBJECT
	{
		TESForm* form;	 // 00
		UInt32	 flags;	 // 08
		UInt32	 pad0C;	 // 0C
	};
	STATIC_ASSERT(sizeof(ACTION_OBJECT) == 0x10);


	struct SCRIPT_LOCAL
	{
		UInt32 id;		   // 0
		float  value;	   // 4
		bool   isInteger;  // 8
		UInt8  pad9;	   // 9
		UInt16 padA;	   // A
	};
	STATIC_ASSERT(sizeof(SCRIPT_LOCAL) == 0xC);


	struct SCRIPT_EFFECT_DATA
	{
		bool   scriptEffectStart;	// 00
		bool   scriptEffectFinish;	// 01
		UInt16 pad02;				// 02
		float  secondsElapsed;		// 04
	};
	STATIC_ASSERT(sizeof(SCRIPT_EFFECT_DATA) == 0x8);


	class ScriptLocals
	{
	public:
		Script*						  masterScript;		 // 00
		char						  flags;			 // 08
		UInt8						  pad09;			 // 09
		UInt16						  pad0A;			 // 0A
		UInt32						  pad0C;			 // 0C
		BSSimpleList<ACTION_OBJECT*>* actionList;		 // 10
		BSSimpleList<SCRIPT_LOCAL*>*  localList;		 // 18
		SCRIPT_EFFECT_DATA*			  scriptEffectData;	 // 20
	};
	STATIC_ASSERT(sizeof(ScriptLocals) == 0x28);


	struct ScriptVariable
	{
		SCRIPT_LOCAL data;	 // 00
		UInt32		 pad0C;	 // 0C
		BSString	 name;	 // 10
	};
	STATIC_ASSERT(sizeof(ScriptVariable) == 0x20);


	struct SCRIPT_LINE
	{
		UInt32		  lineNumber;	   // 000
		char		  line[512];	   // 004
		UInt32		  size;			   // 204
		UInt32		  offset;		   // 208
		char		  output[512];	   // 20C
		UInt32		  outputSize;	   // 40C
		SCRIPT_OUTPUT expression;	   // 410
		UInt32		  refObjectIndex;  // 414
		SCRIPT_ERROR  scriptError;	   // 418
	};
	STATIC_ASSERT(sizeof(SCRIPT_LINE) == 0x41C);


	struct SCRIPT_FUNCTION
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
			StringChunk*  AsString();
			IntegerChunk* AsInteger();
		};


		struct StringChunk : public Chunk
		{
			std::string GetString() const;
			Chunk*		GetNext();


			// members
			UInt16 length;	// 00
			char   str[0];	// 02
		};
		STATIC_ASSERT(sizeof(StringChunk) == 0x2);


#pragma pack(push, 1)
		struct IntegerChunk : public Chunk
		{
			int	   GetInteger() const;
			Chunk* GetNext();


			// members
			char   magic;  // 00
			SInt32 value;  // 01
		};
		STATIC_ASSERT(offsetof(IntegerChunk, value) == 0x1);
		STATIC_ASSERT(sizeof(IntegerChunk) == 0x5);
#pragma pack(pop)


		struct ScriptData
		{
			Chunk*		  GetChunk();
			StringChunk*  GetStringChunk();
			IntegerChunk* GetIntegerChunk();


			// members
			UInt16 opcode;	   // 00
			UInt16 chunkSize;  // 02
			UInt16 numParams;  // 04
		};
		STATIC_ASSERT(sizeof(ScriptData) == 0x6);


		using Execute_t = bool(const SCRIPT_PARAMETER* a_paramInfo, ScriptData* a_scriptData, TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, double& a_result, UInt32& a_opcodeOffsetPtr);
		using Compile_t = bool(UInt16 a_numParams, const SCRIPT_PARAMETER* a_paramInfo, SCRIPT_LINE* a_lineBuf, ScriptCompileData* a_scriptBuf);
		using Condition_t = bool(TESObjectREFR* a_thisObj, void* a_param1, void* a_param2, double& a_result);


		static SCRIPT_FUNCTION* GetFirstScriptCommand();
		static SCRIPT_FUNCTION* LocateScriptCommand(const char* a_longName);

		static SCRIPT_FUNCTION* GetFirstConsoleCommand();
		static SCRIPT_FUNCTION* LocateConsoleCommand(const char* a_longName);

		template <UInt16 SIZE>
		void SetParameters(SCRIPT_PARAMETER (&a_params)[SIZE]);
		void SetParameters();


		// members
		const char*		  functionName;			// 00
		const char*		  shortName;			// 08
		SCRIPT_OUTPUT	  output;				// 10
		UInt32			  pad14;				// 14
		const char*		  helpString;			// 18
		bool			  referenceFunction;	// 20
		UInt8			  pad21;				// 21
		UInt16			  numParams;			// 22
		UInt32			  pad24;				// 24
		SCRIPT_PARAMETER* params;				// 28
		Execute_t*		  executeFunction;		// 30
		Compile_t*		  compileFunction;		// 38
		Condition_t*	  conditionFunction;	// 40
		bool			  editorFilter;			// 48
		bool			  invalidatesCellList;	// 49
		UInt16			  pad4A;				// 4A
		UInt32			  pad4C;				// 4C
	};
	STATIC_ASSERT(sizeof(SCRIPT_FUNCTION) == 0x50);


	template <UInt16 SIZE>
	void SCRIPT_FUNCTION::SetParameters(SCRIPT_PARAMETER (&a_params)[SIZE])
	{
		numParams = SIZE;
		params = a_params;
	}
}
