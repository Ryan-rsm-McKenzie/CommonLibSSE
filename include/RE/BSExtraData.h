#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSExtraData

#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_BSExtraData;


		enum { kExtraTypeID = ExtraDataType::kNone };


		BSExtraData();
		virtual ~BSExtraData() = default;									// 00

		// add
		virtual ExtraDataType	GetType() const = 0;						// 01
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const;	// 02 - { return false; }

		static BSExtraData*				Create(std::size_t a_size, std::uintptr_t a_vtbl);
		template <class T> static T*	Create(std::uintptr_t a_vtbl);

		bool operator==(const BSExtraData& a_rhs) const;
		bool operator!=(const BSExtraData& a_rhs) const;

		TES_HEAP_REDEFINE_NEW();


		// members
		BSExtraData* next;	// 08
	};
	STATIC_ASSERT(sizeof(BSExtraData) == 0x10);


	template <class T>
	T* BSExtraData::Create(std::uintptr_t a_vtbl)
	{
		return static_cast<T*>(Create(sizeof(T), a_vtbl));
	}
}
