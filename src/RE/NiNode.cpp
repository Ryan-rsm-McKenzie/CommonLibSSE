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


	void NiNode::DetachChild(NiAVObject* a_child)
	{
		return DetachChild2(a_child);
	}


	void NiNode::DetachChild(NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut)
	{
		return DetachChild1(a_child, a_childOut);
	}


	void NiNode::DetachChildAt(UInt32 a_idx)
	{
		return DetachChildAt2(a_idx);
	}


	void NiNode::DetachChildAt(UInt32 a_idx, NiPointer<NiAVObject>& a_childOut)
	{
		return DetachChildAt1(a_idx, a_childOut);
	}


	void NiNode::SetAt(UInt32 a_idx, NiAVObject* a_child)
	{
		return SetAt2(a_idx, a_child);
	}


	void NiNode::SetAt(UInt32 a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut)
	{
		return SetAt1(a_idx, a_child, a_childOut);
	}


	NiNode* NiNode::Ctor(UInt16 a_arrBuffLen)
	{
		using func_t = decltype(&NiNode::Ctor);
		REL::Offset<func_t> func(Offset::NiNode::Ctor);
		return func(this, a_arrBuffLen);
	}
}
