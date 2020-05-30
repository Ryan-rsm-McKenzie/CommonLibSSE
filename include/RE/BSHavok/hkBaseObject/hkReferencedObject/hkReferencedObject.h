#pragma once

#include "RE/hkBaseObject.h"


namespace RE
{
	class hkClass;
	class hkStatisticsCollector;


	class hkReferencedObject : public hkBaseObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkReferencedObject;


		enum class LockMode : UInt32
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
		virtual ~hkReferencedObject() = default;  // 00

		// add
		virtual const hkClass* GetClassType() const;																	 // 01 - { return 0; }
		virtual void		   CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const;	 // 02

		void   AddReference() const;
		SInt32 GetAllocatedSize() const;
		SInt32 GetReferenceCount() const;
		void   RemoveReference() const;


		// members
		UInt16					memSizeAndFlags;  // 08
		volatile mutable SInt16 referenceCount;	  // 0A
		UInt32					pad0C;			  // 0C
	};
	STATIC_ASSERT(sizeof(hkReferencedObject) == 0x10);
}
