#include "RE/NiNode.h"

#include "skse64/NiNodes.h"  // NiNode


namespace RE
{
	NiNode* NiNode::Create(UInt32 a_arrBufLen)
	{
		using func_t = function_type_t<decltype(&NiNode::Create)>;
		func_t* func = unrestricted_cast<func_t*>(&::NiNode::Create);
		return func(a_arrBufLen);
	}
}
