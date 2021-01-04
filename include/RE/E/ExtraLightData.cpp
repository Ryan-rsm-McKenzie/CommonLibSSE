#include "RE/E/ExtraLightData.h"

namespace RE
{
	ExtraLightDataStruct::ExtraLightDataStruct() :
		fov(0.0),
		fade(0.0),
		endDistanceCap(0.0),
		shadowDepthBias(0.0),
		unk10(0),
		pad11(0),
		pad12(0)
	{}

	ExtraLightData::ExtraLightData() :
		BSExtraData(),
		data(),
		pad24(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraLightData::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraLightData::GetType() const
	{
		return ExtraDataType::kLightData;
	}

	bool ExtraLightData::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraLightData*>(a_rhs);
		return data.fov != rhs->data.fov ||
			   data.fade != rhs->data.fade ||
			   data.endDistanceCap != rhs->data.endDistanceCap ||
			   data.shadowDepthBias != rhs->data.shadowDepthBias ||
			   data.unk10 != rhs->data.unk10;
	}
}
