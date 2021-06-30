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

		~BSAnimNote() override = 0;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17 - { return this; }
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19 - { NiObject::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A - { return NiObject::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		// add
		virtual void Unk_25(void);  // 25
	};
	//static_assert(sizeof(BSAnimNote) == 0x);
}
