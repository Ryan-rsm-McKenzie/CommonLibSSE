#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSLocationRefType

#include "RE/BGSKeyword.h"  // BGSKeyword
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BGSLocationRefType : public BGSKeyword
	{
	public:
		inline static const void* RTTI = RTTI_BGSLocationRefType;


		enum { kTypeID = FormType::LocationRefType };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSLocationRefType();		// 00

		// override (BGSKeyword)
		virtual void InitItem() override;	// 13
	};
	STATIC_ASSERT(sizeof(BGSLocationRefType) == 0x28);
}
