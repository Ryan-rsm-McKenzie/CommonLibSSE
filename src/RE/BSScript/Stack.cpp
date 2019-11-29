#include "RE/BSScript/Stack.h"

#include "RE/BSScript/Internal/CodeTasklet.h"
#include "RE/BSScript/IStackCallbackFunctor.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		Stack::~Stack()
		{
			Dtor();
			memzero(this);
		}


		void* Stack::Chunk::GetHead()
		{
			return GetStackFrame();
		}


		StackFrame* Stack::Chunk::GetStackFrame()
		{
			return reinterpret_cast<StackFrame*>(buf);
		}


		void* Stack::Chunk::GetTail()
		{
			auto head = reinterpret_cast<std::uintptr_t>(GetHead());
			return reinterpret_cast<void*>(head + stackFrameSize);
		}


		bool Stack::Chunk::IsInRange(void* a_ptr)
		{
			return a_ptr <= GetHead() && a_ptr < GetTail();
		}


		UInt32 Stack::GetChunkIdx(StackFrame* a_frame)
		{
			for (UInt32 i = 0; i < chunks.size(); ++i) {
				auto& pair = chunks[i];
				if (pair.chunk->IsInRange(a_frame)) {
					return i;
				}
			}
			assert(false);
			return static_cast<UInt32>(-1);
		}


		void Stack::Dtor()
		{
			using func_t = function_type_t<decltype(&Stack::Dtor)>;
			REL::Offset<func_t*> func(Offset::BSScript::Stack::Dtor);
			return func(this);
		}
	}
}
