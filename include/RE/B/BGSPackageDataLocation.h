#pragma once

#include "RE/B/BGSPackageDataPointerTemplate.h"
#include "RE/I/IPackageDataAIWorldLocationHandle.h"

namespace RE
{
	class PackageLocation;

	//const BSFixedString kPackageDataLocationTypeName("Location");

	class BGSPackageDataLocation : public BGSPackageDataPointerTemplate<IPackageDataAIWorldLocationHandle, PackageLocation /*, kPackageDataLocationTypeName*/>
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSPackageDataLocation;

		~BGSPackageDataLocation() override;  // 00

		// override (BGSPackageDataPointerTemplate<IPackageDataAIWorldLocationHandle, PackageLocation, kPackageDataLocationTypeName>)
		void Unk_06() override;                            // 06
		void Unk_07() override;                            // 07
		void LoadBuffer(BGSLoadFormBuffer* a_buf) override;    // 08
		void Unk_09() override;                            // 09 - { return; }
		bool GetDataAsString(BSString* a_dst) const override;  // 0A
		void Unk_0C() override;                            // 0C - { return pointer->type == PackageLocation::Type::kNearPackageStartLocation; }
	};
	static_assert(sizeof(BGSPackageDataLocation) == 0x20);
}
