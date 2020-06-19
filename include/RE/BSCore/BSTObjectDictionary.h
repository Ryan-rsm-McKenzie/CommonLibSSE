#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/BSCore/BSTSingleton.h"


namespace RE
{
	template <
		class T,
		class Key,
		template <class, class> class MissPolicy,
		template <class, class> class InitializationPolicy>
	class BSTObjectDictionary :
		public MissPolicy<T, Key>,															   // 00
		public InitializationPolicy<T, Key>,												   // 08
		public BSTSingletonSDM<BSTObjectDictionary<T, Key, MissPolicy, InitializationPolicy>>  // 10
	{
	public:
		UInt8			   pad11;			   // 11
		UInt16			   pad12;			   // 12
		UInt32			   pad14;			   // 14
		BSTHashMap<Key, T> objectDefinitions;  // 18
		BSSpinLock		   definitionLock;	   // 48
	};
	//STATIC_ASSERT(sizeof(BSTObjectDictionary) == 0x50);
}
