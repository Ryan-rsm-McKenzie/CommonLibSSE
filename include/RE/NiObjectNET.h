#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiExtraData;
	class NiTimeController;

	class NiObjectNET : public NiObject
	{
	public:
		virtual ~NiObjectNET();													// 00

		// override (NiObject)
		virtual NiRTTI*		GetRTTI() override;									// 02
		virtual void		LoadBinary(NiStream* a_stream) override;			// 18
		virtual void		LinkObject(NiStream* a_stream) override;			// 19
		virtual bool		RegisterStreamables(NiStream* a_stream) override;	// 1A
		virtual void		SaveBinary(NiStream* a_stream) override;			// 1B
		virtual bool		IsEqual(NiObject* a_object) override;				// 1C
		virtual void		ProcessClone(NiCloningProcess& a_cloning) override;	// 1D
		virtual void		PostLinkObject(NiStream& a_stream) override;		// 1E

		void				AddExtraData(NiExtraData* a_extraData);
		bool				RemoveExtraData(NiExtraData* a_extraData);
		SInt32				GetIndexOf(NiExtraData* a_extraData);
		NiExtraData*		GetExtraData(BSFixedString a_name);
		NiTimeController*	GetController() const;


		// members
		const char*			name;				// 10
		NiTimeController*	controller;			// 18 next pointer at +0x30
		NiExtraData**		extraData;			// 20 extra data
		UInt16				extraDataLen;		// 28 max valid entry
		UInt16				extraDataCapacity;	// 2A array len
		UInt32				pad2C;				// 2C
	};
	STATIC_ASSERT(sizeof(NiObjectNET) == 0x30);
}
