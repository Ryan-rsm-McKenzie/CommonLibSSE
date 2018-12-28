#pragma once

#include "RE/BGSKeyword.h"  // BGSKeyword
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BGSLocationRefType : public BGSKeyword
	{
	public:
		enum { kTypeID = FormType::LocationRef };


		virtual ~BGSLocationRefType();			// 00

		// override (BGSKeyword)
		virtual void	InitItem() override;	// 13
	};
	STATIC_ASSERT(sizeof(BGSLocationRefType) == 0x28);
}
