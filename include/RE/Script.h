#pragma once

#include <string>
#include <string_view>

#include "RE/CommandTable.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class Script : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_Script;


		enum { kTypeID = FormType::Script };


		enum class InvokeType : std::size_t
		{
			kDefaultCompiler,
			kSysWindowCompileAndRun,
			kDialogueCompileAndRun
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~Script();								// 00

		// override (TESForm)
		virtual void	InitializeData() override;		// 04
		virtual void	ClearData() override;			// 05
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13

		void		ClearCommand();
		std::string	GetCommand() const;
		void		Invoke(TESObjectREFR* a_targetRef, InvokeType a_type = InvokeType::kSysWindowCompileAndRun);
		void		SetCommand(std::string_view a_command);


		// members
		SCRIPT_HEADER 							header;							// 20
		UInt32									pad34;							// 34
		char*									text;							// 38
		SCRIPT_FUNCTION::ScriptData*			data;							// 40
		float									profilerTimer;					// 48
		float									questScriptDelay;				// 4C
		float									questScriptGetSecondsBuffer;	// 50
		UInt32									pad54;							// 54
		TESQuest*								parentQuest;					// 58
		BSSimpleList<SCRIPT_REFERENCED_OBJECT*>	refObjects;						// 60
		BSSimpleList<ScriptVariable*>			variables;						// 70

	private:
		void Invoke_Impl(void* a_arg1, InvokeType a_type, TESObjectREFR* a_targetRef);
	};
	STATIC_ASSERT(sizeof(Script) == 0x80);
}
