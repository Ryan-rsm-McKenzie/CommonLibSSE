#pragma once

#include "RE/ExtraDataTypes.h"  // ExtraDataType

#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kNone };


		virtual ~BSExtraData();												// 00

		// add
		virtual ExtraDataType	GetType() const = 0;						// 01
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const;	// 02 - { return false; }

		static BSExtraData*		Create(std::size_t a_size, std::uintptr_t a_vtbl);

		TES_HEAP_REDEFINE_NEW();


		// members
		BSExtraData* next;	// 08
	};
	STATIC_ASSERT(sizeof(BSExtraData) == 0x10);
}
