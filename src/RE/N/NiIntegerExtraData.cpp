#include "RE/N/NiIntegerExtraData.h"

namespace RE
{
	NiIntegerExtraData* NiIntegerExtraData::Create(const BSFixedString& a_name, std::int32_t a_value)
	{
		auto data = NiExtraData::Create<NiIntegerExtraData>();
		if (data) {
			data->name = a_name;
			data->value = a_value;
		}

		return data;
	}
}
