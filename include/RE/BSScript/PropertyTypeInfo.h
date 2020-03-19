#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSScript/TypeInfo.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class IFunction;


		struct PropertyTypeInfo
		{
		public:
			enum class Permissions : UInt32
			{
			};


			// members
			BSFixedString			   parentObjName;  // 00
			BSFixedString			   propertyName;   // 08
			TypeInfo				   type;		   // 10
			Permissions				   permissions;	   // 18
			UInt32					   pad1C;		   // 1C
			BSTSmartPointer<IFunction> getFunction;	   // 20
			BSTSmartPointer<IFunction> setFunction;	   // 28
			UInt32					   autoVarIndex;   // 30
			UInt32					   userFlags;	   // 34
			BSFixedString			   docString;	   // 38
		};
		STATIC_ASSERT(sizeof(PropertyTypeInfo) == 0x40);
	}
}
