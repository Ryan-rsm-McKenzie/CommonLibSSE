#pragma once

#include "RE/bhkCharacterPointCollector.h"  // bhkCharacterPointCollector
#include "RE/bhkSerializable.h"  // bhkSerializable


namespace RE
{
	class bhkCharacterProxy : public bhkSerializable
	{
	public:
		virtual ~bhkCharacterProxy();									// 00

		// override (bhkSerializable)
		virtual NiRTTI*		GetRTTI() override;							// 02
		virtual NiObject*	CreateClone(NiCloningProcess a_cloner);		// 17
		virtual void		LoadBinary(NiStream* a_stream);				// 18
		virtual void		LinkObject(NiStream* a_stream);				// 19
		virtual bool		RegisterStreamables(NiStream* a_stream);	// 1A
		virtual void		SaveBinary(NiStream* a_stream);				// 1B


		// members
		bhkCharacterPointCollector characterPointCollector;	// 020
	};
	STATIC_ASSERT(sizeof(bhkCharacterProxy) == 0x260);
}
