#pragma once

#include "skse64_common/Utilities.h"  // MEMBER_FN_PREFIX, DEFINE_MEMBER_FN

#include "RE/EffectSetting.h"  // EffectSetting::Properties::ActorValue


namespace RE
{
	class ActorValueOwner
	{
	private:
		using ActorValue = EffectSetting::Data::ActorValue;

	public:
		virtual ~ActorValueOwner();

		virtual float	GetActorValueCurrent(ActorValue a_akValue);
		virtual float	GetActorValueMaximum(ActorValue a_akValue);
		virtual float	GetActorValueBase(ActorValue a_akValue);
		virtual void	SetActorValueBase(ActorValue a_akValue, float value);
		virtual void	ModActorValueBase(ActorValue a_akValue, float value);
		virtual void	Unk_06(UInt32 arg0, UInt32 arg1, UInt32 arg2);
		virtual void	SetActorValueCurrent(ActorValue a_akValue, float value);
		virtual bool	Unk_08(void);

		float			GetPlayerActorValueCurrent(ActorValue a_akValue);

	private:
		typedef float _GetPlayerActorValueCurrent_t(ActorValueOwner* a_this, ActorValue a_akValue);
		static RelocAddr<_GetPlayerActorValueCurrent_t*> _GetPlayerActorValueCurrent;
	};
	STATIC_ASSERT(sizeof(ActorValueOwner) == 0x8);
}
