#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BGSProjectile;
	class NiAVObject;


	class ExtraAttachedArrows3D : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAttachedArrows3D;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAttachedArrows3D;


		struct DataItem
		{
			NiPointer<NiAVObject> arrow3D;	  // 00
			UInt64				  timeStamp;  // 08
			BGSProjectile*		  source;	  // 10
		};
		STATIC_ASSERT(sizeof(DataItem) == 0x18);


		virtual ~ExtraAttachedArrows3D();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kAttachedArrows3D; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTArray<DataItem> data;		   // 10
		UInt16			   nextStorage;	   // 28
		UInt16			   oldestStorage;  // 2A
		UInt32			   pad2C;		   // 2C
	};
	STATIC_ASSERT(sizeof(ExtraAttachedArrows3D) == 0x30);
}
