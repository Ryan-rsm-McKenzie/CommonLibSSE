#include "RE/NiNode.h"

#include "skse64/NiNodes.h"  // NiNode

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiNode* NiNode::Create(UInt32 a_arrBufLen)
	{
		using func_t = function_type_t<decltype(&NiNode::Create)>;
		func_t* func = unrestricted_cast<func_t*>(&::NiNode::Create);
		return func(a_arrBufLen);
	}


	bool NiNode::SetMotionType(UInt32 a_motionType, UInt8 a_arg2, UInt8 a_arg3, bool a_allowActivate)
	{
		using func_t = function_type_t<decltype(&NiNode::SetMotionType)>;
		func_t* func = REL::Offset<func_t*>(Offset::NiNode::SetMotionType);
		return func(this, a_motionType, a_arg2, a_arg3, a_allowActivate);
	}
}
