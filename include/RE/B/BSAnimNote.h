#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	class BSAnimNote : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSAnimNote;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSAnimNote;

		enum class AnimNoteType
		{
			kInvalid = 0,
			kGrabIK = 1,
			kLookIK = 2
		};

		virtual ~BSAnimNote() = 0;	// 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17 - { return this; }
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { NiObject::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return NiObject::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C

		// add
		virtual void Unk_25(void);	// 25
	};
	//static_assert(sizeof(BSAnimNote) == 0x);
}
