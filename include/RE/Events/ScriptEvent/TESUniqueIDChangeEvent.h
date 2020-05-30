#pragma once


namespace RE
{
	struct TESUniqueIDChangeEvent
	{
	public:
		// members
		FormID oldBaseID;	 // 00
		FormID newBaseID;	 // 04
		FormID objectID;	 // 08
		UInt16 oldUniqueID;	 // 0C
		UInt16 newUniqueID;	 // 0E
	};
	STATIC_ASSERT(sizeof(TESUniqueIDChangeEvent) == 0x10);
}
