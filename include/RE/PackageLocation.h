#pragma once

#include <type_traits>

#include "RE/BSPointerHandle.h"
#include "RE/IAIWorldLocationHandle.h"


namespace RE
{
	class TESForm;


	class PackageLocation : public IAIWorldLocationHandle
	{
	public:
		inline static constexpr auto RTTI = RTTI_PackageLocation;


		enum class Type : UInt8
		{
			kNone = static_cast<std::underlying_type_t<Type>>(-1),
			kNearReference = 0,
			kInCell = 1,
			kNearPackageStartLocation = 2,
			kNearEditorLocation = 3,
			kObjectID = 4,
			kObjectType = 5,
			kNearLinkedReference = 6,
			kAtPackagelocation = 7,
			kAlias_Reference = 8,
			kAlias_Location = 9,
			kNearSelf = 12,
		};


		union Data
		{
			~Data() {}


			TESForm*		object;
			ObjectRefHandle refHandle;
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		virtual ~PackageLocation();	 // 00

		// override (IAIWorldLocationHandle)
		virtual const IAIWorldLocation* AllocateLocation(AIWorldLocationContext* a_context) override;						// 01
		virtual PackageLocation*		GetAsPackageLocation() override;													// 02 - { return this; }
		virtual bool					IsRefAtLocation(AIWorldLocationContext* a_context, TESObjectREFR* a_ref) override;	// 03


		// members
		Type   locType;	 // 08
		UInt8  pad09;	 // 09
		UInt16 pad0A;	 // 0A
		UInt32 rad;		 // 0C
		Data   data;	 // 10
	};
	STATIC_ASSERT(sizeof(PackageLocation) == 0x18);
}
