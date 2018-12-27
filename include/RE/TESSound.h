#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject


namespace RE
{
	class TESSound : public TESBoundAnimObject
	{
	public:
		enum { kTypeID = FormType::Sound };


		virtual ~TESSound();	// 00


		// members
		BGSSoundDescriptorForm* descriptor;	// 30
	};
	STATIC_ASSERT(sizeof(TESSound) == 0x38);
}
