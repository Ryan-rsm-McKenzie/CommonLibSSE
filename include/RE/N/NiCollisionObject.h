#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	class NiAVObject;

	class NiCollisionObject : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiCollisionObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiCollisionObject;

		virtual ~NiCollisionObject() = 0;  // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C

		// add
		virtual void Unk_25(void);		// 25
		virtual void Unk_26(void) = 0;	// 26
		virtual void Unk_27(void) = 0;	// 27
		virtual void Unk_28(void);		// 28 - { return; }
		virtual void Unk_29(void);		// 29 - { return; }

		// members
		NiAVObject* sceneObject;  // 10
	};
	static_assert(sizeof(NiCollisionObject) == 0x18);
}
