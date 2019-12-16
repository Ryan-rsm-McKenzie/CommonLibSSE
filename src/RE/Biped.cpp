#include "RE/Biped.h"

#include "RE/NiAVObject.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	Biped::~Biped()
	{
		Dtor();
		memzero(this);
	}


	void Biped::UpdateWeightData()
	{
		using func_t = function_type_t<decltype(&Biped::UpdateWeightData)>;
		REL::Offset<func_t*> func(Offset::Biped::UpdateWeightData);
		return func(this);
	}


	void Biped::Dtor()
	{
		using func_t = function_type_t<decltype(&Biped::Dtor)>;
		REL::Offset<func_t*> func(Offset::Biped::Dtor);
		return func(this);
	}
}
