#include "RE/N/NiFloatExtraData.h"

namespace RE
{
	NiFloatExtraData* NiFloatExtraData::Create(const BSFixedString& a_name, float a_value)
	{
		auto data = NiExtraData::Create<NiFloatExtraData>();
		if (data) {
			data->name = a_name;
			data->data = a_value;
		}

		return data;
	}
}
