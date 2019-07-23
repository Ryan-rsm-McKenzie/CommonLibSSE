#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IVMObjectBindInterface

#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	class BSFixedString;


	namespace BSScript
	{
		class Object;


		struct IVMObjectBindInterface
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IVMObjectBindInterface;


			virtual ~IVMObjectBindInterface();																									// 00

			// add
			virtual VMHandle	GetHandle(const BSTSmartPointer<Object>& a_objPtr) = 0;															// 01
			virtual void		Unk_02(void) = 0;																								// 02
			virtual void		BindObject(BSTSmartPointer<Object>& a_objPtr, VMHandle a_handle, bool a_conditional) = 0;						// 03
			virtual void		RegisterObject(BSTSmartPointer<Object>& a_objPtr, VMHandle a_handle, bool a_conditional) = 0;					// 04
			virtual void		Unk_05(void) = 0;																								// 05
			virtual void		Unk_06(void) = 0;																								// 06
			virtual void		Unk_07(void) = 0;																								// 07
			virtual void		Unk_08(void) = 0;																								// 08
			virtual bool		CreateObject(const BSFixedString& a_className, UInt32 a_numProperties, BSTSmartPointer<Object>& a_objPtr) = 0;	// 09
			virtual bool		SetProperty(BSTSmartPointer<Object>& a_objPtr, void* a_property, bool a_arg3) = 0;								// 0A
		};
		STATIC_ASSERT(sizeof(IVMObjectBindInterface) == 0x8);
	}
}
