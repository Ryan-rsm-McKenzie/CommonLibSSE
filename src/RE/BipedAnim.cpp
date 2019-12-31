#include "RE/BipedAnim.h"

#include "RE/NiAVObject.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BipedAnim::~BipedAnim()
	{
		Dtor();
		memzero(this);
	}


	void BipedAnim::UpdateWeightData()
	{
		using func_t = function_type_t<decltype(&BipedAnim::UpdateWeightData)>;
		REL::Offset<func_t*> func(Offset::BipedAnim::UpdateWeightData);
		return func(this);
	}


	void BipedAnim::Dtor()
	{
		using func_t = function_type_t<decltype(&BipedAnim::Dtor)>;
		REL::Offset<func_t*> func(Offset::BipedAnim::Dtor);
		return func(this);
	}
}
