#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	class hkpMoppCode : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpMoppCode;

		enum class BuildType
		{
			kBuildWithChunkSubdivision = 0,
			kBuildWithoutChunkSubdivision = 1,
			kBuildNotSet = 2
		};

		struct CodeInfo
		{
		public:
			// members
			hkVector4 offset;  // 00
		};
		static_assert(sizeof(CodeInfo) == 0x10);

		~hkpMoppCode() override;  // 00

		// members
		CodeInfo                                 info;       // 10
		hkArray<std::uint8_t>                    data;       // 20
		stl::enumeration<BuildType, std::int8_t> buildType;  // 30
		std::uint8_t                             pad31;      // 31
		std::uint16_t                            pad32;      // 32
		std::uint32_t                            pad34;      // 34
		std::uint64_t                            pad38;      // 38
	};
	static_assert(sizeof(hkpMoppCode) == 0x40);
}
