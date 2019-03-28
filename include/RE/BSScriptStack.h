#pragma once


namespace RE
{
	namespace BSScript
	{
		class BSScriptVariable;
		class StackFrame;


		class BSScriptStack
		{
		public:
			UInt32				GetOffset(StackFrame* a_frame);
			BSScriptVariable*	Get(StackFrame* a_frame, UInt32 a_idx, UInt32 a_offset);
		};
	}
}
