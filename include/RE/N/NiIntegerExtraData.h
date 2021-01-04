#pragma once

#include "RE/N/NiExtraData.h"

namespace RE
{
	class NiIntegerExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiIntegerExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiIntegerExtraData;

		virtual ~NiIntegerExtraData();	// 00

		// override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { NiExtraData::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C - { return object ? value == a_object->value : false; }

		// members
		std::int32_t  value;  // 18
		std::uint32_t pad1C;  // 1C
	};
	static_assert(sizeof(NiIntegerExtraData) == 0x20);
}
