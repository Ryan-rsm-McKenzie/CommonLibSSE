#pragma once

#include "RE/BSScript/IObjectProcessor.h"
#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTSmartPointer.h"


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
