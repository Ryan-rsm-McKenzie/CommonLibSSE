#pragma once

namespace RE
{
	struct FORM
	{
	public:
		// members
		char		  form[4];		   // 00
		std::uint32_t length;		   // 04
		std::uint32_t flags;		   // 08
		FormID		  formID;		   // 0C
		std::uint32_t versionControl;  // 10
		std::uint16_t formVersion;	   // 14
		std::uint16_t vcVersion;	   // 16
	};
	static_assert(sizeof(FORM) == 0x18);

	struct FORM_GROUP
	{
	public:
		// members
		FORM		  groupData;	// 00
		std::uint64_t groupOffset;	// 18
	};
	static_assert(sizeof(FORM_GROUP) == 0x20);
}
