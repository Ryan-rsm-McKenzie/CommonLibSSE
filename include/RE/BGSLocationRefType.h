#pragma once

#include "RE/BGSKeyword.h"  // BGSKeyword
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BGSLocationRefType : public BGSKeyword
	{
	public:
		enum { kTypeID = FormType::LocationRef };
	};
	STATIC_ASSERT(sizeof(BGSLocationRefType) == 0x28);
}
