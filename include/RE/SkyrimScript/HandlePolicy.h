#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__HandlePolicy

#include "RE/BSScript/IObjectHandlePolicy.h"  // BSScript::IObjectHandlePolicy
#include "RE/BSTHashMap.h"  // BSTHashMap


namespace RE
{
	namespace SkyrimScript
	{
		class HandlePolicy : public BSScript::IObjectHandlePolicy
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__HandlePolicy;


			virtual ~HandlePolicy();																// 00

			// override (BSScript::IObjectHandlePolicy)
			virtual bool		IsType(FormType32 a_typeID, VMHandle a_handle) override;			// 01
			virtual bool		IsValidHandle(VMHandle a_handle) override;							// 02
			virtual VMHandle	GetInvalidHandle() override;										// 03
			virtual VMHandle	GetHandle(FormType32 a_typeID, const TESForm* a_srcData) override;	// 04
			virtual bool		IsREFR(VMHandle a_handle) override;									// 05
			virtual void		Unk_06(void) override;												// 06
			virtual void		Unk_07(void) override;												// 07
			virtual void*		Resolve(FormType32 a_typeID, VMHandle a_handle) override;			// 08
			virtual void		AddRef(VMHandle a_handle) override;									// 09
			virtual void		Release(VMHandle a_handle) override;								// 0A
			virtual void		ToString(VMHandle a_handle, BSFixedString& a_strOut) override;		// 0B


			// members
			UInt64							unk08;	// 08
			BSTHashMap<UnkKey, UnkValue>	unk10;	// 10
			BSTHashMap<UnkKey, UnkValue>	unk40;	// 40
		};
		STATIC_ASSERT(sizeof(HandlePolicy) == 0x70);
	}
}
