#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class ExtraRefrPath : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRefrPath;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRefrPath;


		enum class PATH_TYPE : UInt32
		{
		};


		virtual ~ExtraRefrPath();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kRefrPath; }


		// members
		NiPoint3  startPos;			 // 10
		NiPoint3  startTangent;		 // 1C
		NiPoint3  startEuler;		 // 28
		NiPoint3  goalPos;			 // 34
		NiPoint3  goalTangent;		 // 40
		NiPoint3  goalEuler;		 // 4C
		float	  speed;			 // 58
		float	  maxRotSpeed;		 // 5C
		float	  currentParameter;	 // 60
		PATH_TYPE type;				 // 64
	};
	STATIC_ASSERT(sizeof(ExtraRefrPath) == 0x68);
}
