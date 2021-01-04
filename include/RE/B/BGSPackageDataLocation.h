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

		virtual ~BGSPackageDataLocation();	// 00

		// override (BGSPackageDataPointerTemplate<IPackageDataAIWorldLocationHandle, PackageLocation, kPackageDataLocationTypeName>)
		virtual void Unk_06(void) override;							   // 06
		virtual void Unk_07(void) override;							   // 07
		virtual void LoadBuffer(BGSLoadFormBuffer* a_buf) override;	   // 08
		virtual void Unk_09(void) override;							   // 09 - { return; }
		virtual bool GetDataAsString(BSString* a_dst) const override;  // 0A
		virtual void Unk_0C(void) override;							   // 0C - { return pointer->type == PackageLocation::Type::kNearPackageStartLocation; }
	};
	static_assert(sizeof(BGSPackageDataLocation) == 0x20);
}
