#pragma once


namespace RE
{
	struct FORM
	{
	public:
		// members
		char   form[4];			// 00
		UInt32 length;			// 04
		UInt32 flags;			// 08
		FormID formID;			// 0C
		UInt32 versionControl;	// 10
		UInt16 formVersion;		// 14
		UInt16 vcVersion;		// 16
	};
	STATIC_ASSERT(sizeof(FORM) == 0x18);


	struct FORM_GROUP
	{
	public:
		// members
		FORM   groupData;	 // 00
		UInt64 groupOffset;	 // 18
	};
	STATIC_ASSERT(sizeof(FORM_GROUP) == 0x20);
}
