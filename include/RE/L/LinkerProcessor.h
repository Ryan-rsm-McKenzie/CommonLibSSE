#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IObjectProcessor.h"

namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class IVirtualMachine;
		class ObjectTypeInfo;

		class LinkerProcessor : public IObjectProcessor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__LinkerProcessor;

			virtual ~LinkerProcessor();	 // 00

			// override (IObjectProcessor)
			virtual IObjectProcessor* Clone() override;									   // 01
			virtual void			  SetLoader(ILoader* a_loader) override;			   // 02 - { loader = a_loader; }
			virtual bool			  Process(const BSFixedString& a_className) override;  // 03

			// members
			IVirtualMachine*											vm;					 // 08
			ErrorLogger*												errorHandler;		 // 10
			ILoader*													loader;				 // 18
			std::uint64_t												unk20;				 // 20
			BSScrapArray<BSFixedString>									loadedParents;		 // 28
			BSScrapArray<BSFixedString>									objectsToTypecheck;	 // 48
			BSScrapArray<BSFixedString>									processQueue;		 // 68
			BSTHashMap<BSFixedString, BSTSmartPointer<ObjectTypeInfo>>* classMap;			 // 88
		};
		static_assert(sizeof(LinkerProcessor) == 0x90);
	}
}
