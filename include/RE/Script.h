#pragma once

#include <string>
#include <string_view>


#include "RE/BSTList.h"
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


		struct ParamData
		{
			const char*	param;	// 00
			UInt64		unk00;	// 08
			TESForm*	form;	// 10
			UInt64		unk18;	// 18
		};
		STATIC_ASSERT(sizeof(ParamData) == 0x20);


		virtual ~Script();									// 00

		// override (TESForm)
		virtual void	InitDefaults();						// 04
		virtual void	ReleaseManagedData();				// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13

		void		ClearCommand();
		std::string	GetCommand() const;
		void		Invoke(TESObjectREFR* a_targetRef, InvokeType a_type = InvokeType::kSysWindowCompileAndRun);
		void		SetCommand(std::string_view a_command);


		// members
		UInt64						unk20;		// 20
		UInt64						unk28;		// 28
		UInt64						unk30;		// 30
		char*						command;	// 38
		CommandInfo::ScriptData*	scriptData;	// 40
		UInt64						unk48;		// 48
		UInt32						unk50;		// 50
		UInt32						pad54;		// 54
		UInt64						unk58;		// 58
		BSSimpleList<ParamData*>	paramData;	// 60
		BSSimpleList<void*>			unk70;		// 70

	private:
		void Invoke_Impl(void* a_arg1, InvokeType a_type, TESObjectREFR* a_targetRef);
	};
	STATIC_ASSERT(sizeof(Script) == 0x80);
}
