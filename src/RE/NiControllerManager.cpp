#include "RE/NiControllerManager.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/Offsets.h"


namespace RE
{
	NiControllerSequence* NiControllerManager::GetSequenceByName(const BSFixedString& a_name)
	{
		typedef NiControllerSequence* _GetSequenceByName_Impl_t(NiControllerManager* a_this, const BSFixedString& a_name);
		static RelocAddr<_GetSequenceByName_Impl_t*> _GetSequenceByName_Impl(NI_CONTROLLER_MANAGER_GET_SEQUENCE_BY_NAME_IMPL);
		return _GetSequenceByName_Impl(this, a_name);
	}
}
