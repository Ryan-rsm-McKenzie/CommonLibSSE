#pragma once

#include "RE/BSScript/Internal/IFuncCallQuery.h"
#include "RE/BSScript/Variable.h"
#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class Class;


		namespace Internal
		{
			class RawFuncCallQuery : public IFuncCallQuery
			{
			public:
				inline static const void* RTTI = RTTI_BSScript__Internal__RawFuncCallQuery;


				virtual ~RawFuncCallQuery();		// 00

				// override (IFuncCallQuery)
				virtual void Unk_01(void) override;	// 01


				// members
				UInt64					unk10;			// 10
				BSTSmartPointer<Class>	scriptClass;	// 18
				BSFixedString			unk20;			// 20
				Variable				unk28;			// 28
				BSTArray<Variable>		unk38;			// 38
			};
			STATIC_ASSERT(sizeof(RawFuncCallQuery) == 0x50);
		}
	}
}
