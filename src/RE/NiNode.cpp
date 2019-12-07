#include "RE/NiNode.h"

#include <cstring>

#include "RE/Offsets.h"
#include "RE/TESMemoryManager.h"
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


	bool NiNode::SetMotionType(UInt32 a_motionType, UInt8 a_arg2, UInt8 a_arg3, bool a_allowActivate)
	{
		using func_t = function_type_t<decltype(&NiNode::SetMotionType)>;
		REL::Offset<func_t*> func(Offset::NiNode::SetMotionType);
		return func(this, a_motionType, a_arg2, a_arg3, a_allowActivate);
	}


	NiNode* NiNode::Ctor(UInt16 a_arrBuffLen)
	{
		using func_t = function_type_t<decltype(&NiNode::Ctor)>;
		REL::Offset<func_t*> func(Offset::NiNode::Ctor);
		return func(this, a_arrBuffLen);
	}
}
