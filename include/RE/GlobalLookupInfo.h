#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSLock.h"
#include "RE/BSTHashMap.h"
#include "RE/FormTypes.h"


namespace RE
{
	class IFormFactory;


	// This is really just a bunch of grouped static data
	class GlobalLookupInfo
	{
	public:
		enum
		{
			kNumFactories = to_underlying(FormType::Max)
		};


		static GlobalLookupInfo* GetSingleton();


		// members
		bool								 formIDsBashed;					// 000
		bool								 optimizingESM;					// 001
		bool								 unk002;						// 002
		bool								 formFactoriesInitialized;		// 003
		UInt32								 totalFormCount;				// 004
		BSTHashMap<FormID, TESForm*>*		 allForms;						// 008
		BSTHashMap<BSFixedString, TESForm*>* allFormsByEditorID;			// 010
		void*								 formBuffer;					// 018
		UInt32								 bufferSize;					// 020
		bool								 enumStringsChecked;			// 024
		UInt8								 unk25;							// 025
		UInt16								 unk26;							// 026
		UInt64								 unk28;							// 028
		IFormFactory*						 formFactories[kNumFactories];	// 030
		BSFixedString						 emptyIdentifier;				// 480
		BSFixedString						 emptyStateName;				// 488
		BSFixedString						 SelfVarName;					// 490
		BSFixedString						 frameDuration;					// 498
		BSReadWriteLock						 allFormsMapLock;				// 4A0
		BSReadWriteLock						 allFormsEditorIDMapLock;		// 4A8
	};
	STATIC_ASSERT(sizeof(GlobalLookupInfo) == 0x4B0);
}
