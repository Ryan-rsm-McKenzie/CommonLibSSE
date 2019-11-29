#pragma once

#include "RE/BSFixedString.h"
#include "RE/NiObject.h"


namespace RE
{
	class NiExtraData : public NiObject
	{
	public:
		inline static const void* RTTI = RTTI_NiExtraData;
		inline static const void* Ni_RTTI = NiRTTI_NiExtraData;


		virtual ~NiExtraData();														// 00

		// override (NiObject)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19 - { return; }
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C

		// add
		virtual void			Unk_25(void);										// 25 - { return 1; }
		virtual void			Unk_26(void);										// 26 - { return 1; }

		static NiExtraData* Create(std::size_t a_size, std::uintptr_t a_vtbl);

		const BSFixedString&	GetName() const;
		void					SetName(const BSFixedString& a_name);


		// members
		BSFixedString name;	// 10
	};
	STATIC_ASSERT(sizeof(NiExtraData) == 0x18);
}
