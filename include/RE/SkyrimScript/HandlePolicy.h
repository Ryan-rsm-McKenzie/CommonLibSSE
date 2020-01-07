#pragma once

#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSTHashMap.h"


namespace RE
{
	namespace SkyrimScript
	{
		class HandlePolicy : public BSScript::IObjectHandlePolicy
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__HandlePolicy;


			virtual ~HandlePolicy();																		// 00

			// override (BSScript::IObjectHandlePolicy)
			virtual bool		GetHandleIsType(UInt32 a_typeID, VMHandle a_handle) override;				// 01
			virtual bool		IsHandleObjectAvailable(VMHandle a_handle) override;						// 02
			virtual VMHandle	EmptyHandle() override;														// 03
			virtual VMHandle	GetHandleForObject(UInt32 a_typeID, const void* a_srcData) override;		// 04
			virtual bool		HasParent(VMHandle a_handle) override;										// 05
			virtual void		Unk_06(void) override;														// 06
			virtual void		Unk_07(void) override;														// 07
			virtual void*		GetObjectForHandle(UInt32 a_typeID, VMHandle a_handle) override;			// 08
			virtual void		PersistHandle(VMHandle a_handle) override;									// 09
			virtual void		ReleaseHandle(VMHandle a_handle) override;									// 0A
			virtual void		ConvertHandleToString(VMHandle a_handle, BSFixedString& a_strOut) override;	// 0B


			// members
			UInt64							unk08;	// 08
			BSTHashMap<UnkKey, UnkValue>	unk10;	// 10
			BSTHashMap<UnkKey, UnkValue>	unk40;	// 40
		};
		STATIC_ASSERT(sizeof(HandlePolicy) == 0x70);
	}
}
