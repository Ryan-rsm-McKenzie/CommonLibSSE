#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__LinkerProcessor

#include "RE/BSScript/IObjectProcessor.h"  // BSScript::IObjectProcessor
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSScrapArray
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class Class;
		class ErrorLogger;


		namespace Internal
		{
			class VirtualMachine;
		}


		class LinkerProcessor : public IObjectProcessor
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__LinkerProcessor;


			virtual ~LinkerProcessor();														// 00

			// override (IObjectProcessor)
			virtual IObjectProcessor*	Duplicate() override;								// 01
			virtual void				SetLoader(ILoader* a_loader) override;				// 02 - { loader = a_loader; }
			virtual bool				Link(const BSFixedString& a_className) override;	// 03


			// members
			Internal::VirtualMachine*							virtualMachine;	// 08
			ErrorLogger*										errorLogger;	// 10
			ILoader*											loader;			// 18
			UInt64												unk20;			// 20
			BSScrapArray<BSFixedString>							unk28;			// 28
			BSScrapArray<BSFixedString>							unk48;			// 48
			BSScrapArray<BSFixedString>							unk68;			// 68
			BSTHashMap<BSFixedString, BSTSmartPointer<Class>>*	classMap;		// 88
		};
		STATIC_ASSERT(sizeof(LinkerProcessor) == 0x90);
	}
}
