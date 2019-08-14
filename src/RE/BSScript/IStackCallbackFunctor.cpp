#include "RE/BSScript/IStackCallbackFunctor.h"


namespace RE
{
	namespace BSScript
	{
		IStackCallbackFunctor::IStackCallbackFunctor() :
			unk0C(0)
		{}


		bool IStackCallbackFunctor::CanBeSaved()
		{
			return false;
		}
	}
}
