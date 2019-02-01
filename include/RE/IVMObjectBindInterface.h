#pragma once

#include "RE/BSTSmartPointer.h"  //


namespace RE
{
	class BSFixedString;


	namespace BSScript
	{
		class BSScriptObject;


		struct IVMObjectBindInterface
		{
		public:
			virtual ~IVMObjectBindInterface();	// 00

			// add
			virtual VMHandle	GetHandle(const BSTSmartPointer<BSScriptObject>& a_objPtr) = 0;															// 01
			virtual void		Unk_02(void);																											// 02 - pure
			virtual void		BindObject(BSTSmartPointer<BSScriptObject>& a_objPtr, VMHandle a_handle, bool a_counditional) = 0;						// 03
			virtual void		RegisterObject(BSTSmartPointer<BSScriptObject>& a_objPtr, VMHandle a_handle, bool a_counditional) = 0;					// 04
			virtual void		Unk_05(void);																											// 05 - pure
			virtual void		Unk_06(void);																											// 06 - pure
			virtual void		Unk_07(void);																											// 07 - pure
			virtual void		Unk_08(void);																											// 08 - pure
			virtual bool		CreateObject(const BSFixedString& a_className, UInt32 a_numProperties, BSTSmartPointer<BSScriptObject>& a_objPtr) = 0;	// 09
			virtual bool		SetProperty(BSTSmartPointer<BSScriptObject>& a_objPtr, void* a_property, bool a_arg3) = 0;								// 0A
		};
		STATIC_ASSERT(sizeof(IVMObjectBindInterface) == 0x8);
	}
}
