#pragma once

#include "RE/H/hkBaseObject.h"

namespace RE
{
	class hkClass;
	class hkStatisticsCollector;

	class hkReferencedObject : public hkBaseObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkReferencedObject;

		enum class LockMode
		{
			kNone = 0,
			kAuto,
			kManual
		};

		enum
		{
			kMemSize = 0x7FFF
		};

		hkReferencedObject();
		~hkReferencedObject() override = default;  // 00

		// add
		virtual const hkClass* GetClassType() const;                                                                     // 01 - { return 0; }
		virtual void           CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const;  // 02

		void         AddReference() const;
		std::int32_t GetAllocatedSize() const;
		std::int32_t GetReferenceCount() const;
		void         RemoveReference() const;

		// members
		std::uint16_t                 memSizeAndFlags;  // 08
		volatile mutable std::int16_t referenceCount;   // 0A
		std::uint32_t                 pad0C;            // 0C
	};
	static_assert(sizeof(hkReferencedObject) == 0x10);
}
