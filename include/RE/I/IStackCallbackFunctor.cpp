#include "RE/I/IStackCallbackFunctor.h"

namespace RE
{
	namespace BSScript
	{
		IStackCallbackFunctor::IStackCallbackFunctor() :
			pad0C(0)
		{}

		bool IStackCallbackFunctor::CanSave() const
		{
			return false;
		}
	}
}
