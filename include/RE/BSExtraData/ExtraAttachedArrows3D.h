#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiSmartPointer.h"


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
			std::uint64_t		  timeStamp;  // 08
			BGSProjectile*		  source;	  // 10
		};
		static_assert(sizeof(DataItem) == 0x18);


		virtual ~ExtraAttachedArrows3D();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kAttachedArrows3D; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTArray<DataItem> data;		   // 10
		std::uint16_t	   nextStorage;	   // 28
		std::uint16_t	   oldestStorage;  // 2A
		std::uint32_t	   pad2C;		   // 2C
	};
	static_assert(sizeof(ExtraAttachedArrows3D) == 0x30);
}
