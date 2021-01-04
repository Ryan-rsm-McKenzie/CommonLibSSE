#pragma once

#include "RE/N/NiExtraData.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSBound : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSBound;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSBound;

		virtual ~BSBound();	 // 00

		// override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17 - { return this; }
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { NiExtraData::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return NiExtraData::RegisterStreamables(a_stream) == false; }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C

		// members
		NiPoint3 center;   // 18
		NiPoint3 extents;  // 24
	};
	static_assert(sizeof(BSBound) == 0x30);
}
