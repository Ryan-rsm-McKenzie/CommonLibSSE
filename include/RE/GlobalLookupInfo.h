#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSLock.h"  // BSReadWriteLock
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/FormTypes.h"  // FormType, TESForm


namespace RE
{
	class IFormFactory;


	class GlobalLookupInfo
	{
	public:
		enum { kNumFactories = to_underlying(FormType::Max) };


		static GlobalLookupInfo* GetSingleton();


		// members
		bool									unk000;							// 000
		bool									unk001;							// 001
		bool									unk002;							// 002
		bool									formFactoriesInit;				// 003
		UInt32									lookupTablesSize;				// 004
		BSTHashMap<FormID, TESForm*>*			formIDs;						// 008
		BSTHashMap<BSFixedString, TESForm*>*	editorIDs;						// 010
		void*									unk10;							// 018
		UInt32									unk18;							// 020
		UInt32									unk1C;							// 024
		UInt64									unk20;							// 028
		IFormFactory*							formFactories[kNumFactories];	// 030
		BSFixedString							empty;							// 480
		BSFixedString							state;							// 488
		BSFixedString							self;							// 490
		BSFixedString							frameDuration;					// 498
		BSReadWriteLock							formIDsLock;					// 4A0
		BSReadWriteLock							editorIDsLock;					// 4A8
	};
	STATIC_ASSERT(sizeof(GlobalLookupInfo) == 0x4B0);
}
