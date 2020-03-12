#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSLines;
	class NiAVObject;


	class ExtraEditorRef3DData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEditorRef3DData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEditorRef3DData;


		virtual ~ExtraEditorRef3DData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kEditorRef3DData; }


		// members
		NiPointer<NiAVObject> data3D;	  // 10
		NiPointer<BSLines>	  dataBound;  // 18
	};
	STATIC_ASSERT(sizeof(ExtraEditorRef3DData) == 0x20);
}
