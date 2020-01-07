#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiNode;


	class ExtraCell3D : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCell3D;


		enum { kExtraTypeID = ExtraDataType::kCell3D };


		virtual ~ExtraCell3D();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCell3D; }


		// members
		NiPointer<NiNode> cellNode;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCell3D) == 0x18);
}
