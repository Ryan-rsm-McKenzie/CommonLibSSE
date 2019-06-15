#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkReferencedObject

#include "RE/hkBaseObject.h"  // hkBaseObject


namespace RE
{
	class hkClass;
	class hkStatisticsCollector;


	class hkReferencedObject : public hkBaseObject
	{
	public:
		inline static const void* RTTI = RTTI_hkReferencedObject;


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
		virtual ~hkReferencedObject();																					// 00

		// add
		virtual const hkClass*	GetClassType() const;																		// 01 - { return 0; }
		virtual void			CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const;	// 02

		SInt32					GetAllocatedSize() const;
		SInt32					GetReferenceCount() const;
		void					AddReference() const;
		void					RemoveReference() const;


		// members
		UInt16					memSizeAndFlags;	// 08
		volatile mutable SInt16	referenceCount;		// 0A
		UInt32					pad0C;				// 0C
	};
	STATIC_ASSERT(sizeof(hkReferencedObject) == 0x10);
}
