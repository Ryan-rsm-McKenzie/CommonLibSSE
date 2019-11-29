#include "RE/NiAVObject.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void NiAVObject::UpdateModelHair(NiColorA** a_color)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateModelHair)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::UpdateModelHair);
		return func(this, a_color);
	}


	void NiAVObject::UpdateModelSkin(NiColorA** a_color)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateModelSkin)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::UpdateModelSkin);
		return func(this, a_color);
	}


	void NiAVObject::UpdateNode(ControllerUpdateContext* a_ctx)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateNode)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::UpdateNode);
		return func(this, a_ctx);
	}
}
