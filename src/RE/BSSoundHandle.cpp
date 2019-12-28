#include "RE/BSSoundHandle.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSSoundHandle::BSSoundHandle() :
		unk00(-1),
		unk04(0),
		pad05(0),
		pad06(0),
		unk08(0)
	{}


	bool BSSoundHandle::SetPosition(NiPoint3 a_pos)
	{
		using func_t = function_type_t<decltype(&BSSoundHandle::SetPosition)>;
		REL::Offset<func_t*> func(Offset::BSSoundHandle::SetPosition);
		return func(this, a_pos);
	}


	void BSSoundHandle::SetNode(NiNode* a_node)
	{
		using func_t = function_type_t<decltype(&BSSoundHandle::SetNode)>;
		REL::Offset<func_t*> func(Offset::BSSoundHandle::SetNode);
		return func(this, a_node);
	}


	bool BSSoundHandle::Play()
	{
		using func_t = function_type_t<decltype(&BSSoundHandle::Play)>;
		REL::Offset<func_t*> func(Offset::BSSoundHandle::Play);
		return func(this);
	}
}
