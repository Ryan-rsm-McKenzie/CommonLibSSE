#include "RE/NiNode.h"

#include <cstring>

#include "RE/MemoryManager.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiNode* NiNode::Create(UInt16 a_arrBufLen)
	{
		auto node = malloc<NiNode>();
		std::memset(node, 0, sizeof(NiNode));
		node->Ctor(a_arrBufLen);
		return node;
	}


	NiNode* NiNode::Ctor(UInt16 a_arrBuffLen)
	{
		using func_t = function_type_t<decltype(&NiNode::Ctor)>;
		REL::Offset<func_t*> func(Offset::NiNode::Ctor);
		return func(this, a_arrBuffLen);
	}
}
