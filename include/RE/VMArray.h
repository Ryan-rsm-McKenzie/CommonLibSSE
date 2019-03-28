#pragma once

#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class BSScriptArray;


		template <class T>
		class VMArray
		{
		public:
			using value_type = T;


			// members
			BSTSmartPointer<BSScriptArray> data;	// 00
		};
	}
}
