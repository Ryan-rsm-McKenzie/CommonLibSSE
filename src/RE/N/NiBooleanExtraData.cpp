#include "RE/N/NiBooleanExtraData.h"

namespace RE
{
	NiBooleanExtraData* NiBooleanExtraData::Create(const BSFixedString& a_name, bool a_value)
	{
		auto data = NiExtraData::Create<NiBooleanExtraData>();
		if (data) {
			data->name = a_name;
			data->data = a_value;
		}

		return data;
	}
}
