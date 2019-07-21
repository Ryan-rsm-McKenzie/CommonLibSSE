#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__Internal__RawFuncCallQuery

#include "RE/BSScript/Internal/IFuncCallQuery.h"  // BSScript::Internal::IFuncCallQuery
#include "RE/BSScript/Variable.h"  // BSScript::Variable
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


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
