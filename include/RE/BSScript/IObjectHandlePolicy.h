#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IObjectHandlePolicy

#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BSFixedString;
	class TESForm;


	namespace BSScript
	{
		struct IObjectHandlePolicy
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IObjectHandlePolicy;


			virtual ~IObjectHandlePolicy();														// 00

			// add
			virtual bool		IsType(FormType32 a_typeID, VMHandle a_handle) = 0;				// 01
			virtual bool		IsValidHandle(VMHandle a_handle) = 0;							// 02
			virtual VMHandle	GetInvalidHandle() = 0;											// 03
			virtual VMHandle	GetHandle(FormType32 a_typeID, const TESForm* a_srcData) = 0;	// 04
			virtual bool		IsREFR(VMHandle a_handle) = 0;									// 05
			virtual void		Unk_06(void) = 0;												// 06
			virtual void		Unk_07(void) = 0;												// 07
			virtual void*		Resolve(FormType32 a_typeID, VMHandle a_handle) = 0;			// 08
			virtual void		AddRef(VMHandle a_handle) = 0;									// 09
			virtual void		Release(VMHandle a_handle) = 0;									// 0A
			virtual void		ToString(VMHandle a_handle, BSFixedString& a_strOut) = 0;		// 0B

			bool		IsType(FormType a_typeID, VMHandle a_handle);
			VMHandle	GetHandle(FormType a_typeID, const TESForm* a_srcData);
			void*		Resolve(FormType a_typeID, VMHandle a_handle);
		};
		STATIC_ASSERT(sizeof(IObjectHandlePolicy) == 0x8);
	}
}
