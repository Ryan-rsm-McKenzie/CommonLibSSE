#include "RE/NiControllerManager.h"

#include "skse64/GameTypes.h"  // BSFixedString

#include "RE/Offsets.h"


namespace RE
{
	NiControllerSequence* NiControllerManager::GetSequenceByName(const BSFixedString& a_name)
	{
		return _GetSequenceByName_Impl(this, a_name);
	}


	RelocAddr<NiControllerManager::_GetSequenceByName_Impl_t*> NiControllerManager::_GetSequenceByName_Impl(NI_CONTROLLER_MANAGER_GET_SEQUENCE_BY_NAME_IMPL);
}
