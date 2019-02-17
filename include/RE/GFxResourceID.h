#pragma once


namespace RE
{
	class GFxResourceID
	{
	public:
		struct IDTypeConstants
		{
			enum IDTypeConstant : UInt32
			{
				kIndexMask = 0x0000FFFF,
				kTypeMask = 0x0FFF0000,
				kGenMask = 0x00030000,

				kSWF = 0,
				kStatic = 1 << 12,
				kExport = 1 << 13,

				kTypeShift = 18,

				kInvalidID = (1 << kTypeShift) | kSWF
			};
		};


		struct IDTypes
		{
			enum IDType : UInt32
			{
				kNone = IDTypeConstants::kSWF,
				kInternalConstant = (0 << IDTypeConstants::kTypeShift) | IDTypeConstants::kStatic,
				kGradientImage = (1 << IDTypeConstants::kTypeShift) | IDTypeConstants::kStatic,
				kDynFontImage = (2 << IDTypeConstants::kTypeShift) | IDTypeConstants::kStatic,
				kFontImage = (1 << IDTypeConstants::kTypeShift) | IDTypeConstants::kStatic
			};
		};


		class HashOp
		{
		public:
			UPInt operator()(const GFxResourceID& a_idRef);
		};


		GFxResourceID();
		explicit GFxResourceID(UInt32 a_resID);
		GFxResourceID(const GFxResourceID& a_rhs);

		GFxResourceID&	operator=(const GFxResourceID& a_rhs);
		bool			operator==(const GFxResourceID& a_rhs) const;
		bool			operator!=(const GFxResourceID& a_rhs) const;
		bool			operator==(UInt32 a_idVal) const;
		bool			operator!=(UInt32 a_idVal) const;

		UInt32			GetIDValue() const;
		UInt32			GetIDIndex() const;
		IDTypes::IDType	GetIDType() const;
		GFxResourceID	GenerateNextID();

	protected:
		// members
		UInt32	id;		// 0
		UInt32	pad4;	// 4
	};
	STATIC_ASSERT(sizeof(GFxResourceID) == 0x8);
}
