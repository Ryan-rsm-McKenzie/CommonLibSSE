#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	class NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiRefObject;

		NiRefObject();
		virtual ~NiRefObject();  // 00

		// add
		virtual void DeleteThis();  // 01

		void                                  IncRefCount();
		void                                  DecRefCount();
		[[nodiscard]] constexpr std::uint32_t GetRefCount() const noexcept { return _refCount; }

		[[nodiscard]] static volatile std::uint32_t* GetTotalObjectCount();

		TES_HEAP_REDEFINE_NEW();

		// members
		volatile std::uint32_t _refCount{ 0 };  // 08
		std::uint32_t          _pad0C{ 0 };     // 0C
	};
	static_assert(sizeof(NiRefObject) == 0x10);
}
