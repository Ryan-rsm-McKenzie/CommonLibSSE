#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/I/IAIWorldLocationHandle.h"

namespace RE
{
	class TESForm;

	class PackageLocation : public IAIWorldLocationHandle
	{
	public:
		inline static constexpr auto RTTI = RTTI_PackageLocation;

		enum class Type
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

			TESForm*        object;
			ObjectRefHandle refHandle;
		};
		static_assert(sizeof(Data) == 0x8);

		~PackageLocation() override;  // 00

		// override (IAIWorldLocationHandle)
		const IAIWorldLocation* AllocateLocation(AIWorldLocationContext* a_context) override;                       // 01
		PackageLocation*        GetAsPackageLocation() override;                                                    // 02 - { return this; }
		bool                    IsRefAtLocation(AIWorldLocationContext* a_context, TESObjectREFR* a_ref) override;  // 03

		// members
		stl::enumeration<Type, std::uint8_t> locType;  // 08
		std::uint8_t                         pad09;    // 09
		std::uint16_t                        pad0A;    // 0A
		std::uint32_t                        rad;      // 0C
		Data                                 data;     // 10
	};
	static_assert(sizeof(PackageLocation) == 0x18);
}
