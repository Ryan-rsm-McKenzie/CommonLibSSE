#pragma once

#include "RE/BSHavok/hkArray.h"
#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkReferencedObject.h"
#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkpMoppCode : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpMoppCode;


		enum class BuildType : SInt8
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
		STATIC_ASSERT(sizeof(CodeInfo) == 0x10);


		virtual ~hkpMoppCode();	 // 00


		// members
		CodeInfo	   info;	   // 10
		hkArray<UInt8> data;	   // 20
		BuildType	   buildType;  // 30
		UInt8		   pad31;	   // 31
		UInt16		   pad32;	   // 32
		UInt32		   pad34;	   // 34
		UInt64		   pad38;	   // 38
	};
	STATIC_ASSERT(sizeof(hkpMoppCode) == 0x40);
}
