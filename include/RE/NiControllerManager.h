#pragma once

#include "skse64/GameTypes.h"  // BSFixedString
#include "skse64/NiControllers.h"  // NiTimeController


namespace RE
{
	class NiControllerSequence;


	class NiControllerManager : public NiTimeController
	{
	public:
		NiControllerSequence* GetSequenceByName(const BSFixedString& a_name);

		// members
		NiTArray<NiControllerSequence*>	m_sequences;	// 50

	private:
		typedef NiControllerSequence* _GetSequenceByName_Impl_t(NiControllerManager* a_this, const BSFixedString& a_name);
		static RelocAddr<_GetSequenceByName_Impl_t*> _GetSequenceByName_Impl;
	};
}
