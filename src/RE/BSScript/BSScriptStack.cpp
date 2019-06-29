#include "RE/BSScript/BSScriptStack.h"

#include "skse64/PapyrusArgs.h"  // VMArgList


namespace RE
{
	namespace BSScript
	{
		UInt32 BSScriptStack::GetOffset(StackFrame* a_frame)
		{
			using func_t = function_type_t<decltype(&BSScriptStack::GetOffset)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMArgList, GetOffset, func_t*);
			return func(this, a_frame);
		}


		BSScriptVariable* BSScriptStack::Get(StackFrame* a_frame, UInt32 a_idx, UInt32 a_offset)
		{
			using func_t = function_type_t<decltype(&BSScriptStack::Get)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMArgList, Get, func_t*);
			return func(this, a_frame, a_idx, a_offset);
		}
	}
}
