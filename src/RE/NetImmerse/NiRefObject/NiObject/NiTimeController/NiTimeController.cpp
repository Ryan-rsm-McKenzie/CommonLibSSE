#include "RE/NetImmerse/NiRefObject/NiObject/NiTimeController/NiTimeController.h"


namespace RE
{
	const NiRTTI* NiTimeController::GetRTTI() const
	{
		REL::Offset<const NiRTTI*> rtti = NiTimeController::Ni_RTTI;
		return rtti.type();
	}


	void NiTimeController::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::LoadBinary);
		REL::Offset<func_t> func = REL::ID(69433);
		return func(this, a_stream);
	}


	void NiTimeController::LinkObject(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::LinkObject);
		REL::Offset<func_t> func = REL::ID(69434);
		return func(this, a_stream);
	}


	bool NiTimeController::RegisterStreamables(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::RegisterStreamables);
		REL::Offset<func_t> func = REL::ID(69435);
		return func(this, a_stream);
	}


	void NiTimeController::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::SaveBinary);
		REL::Offset<func_t> func = REL::ID(69436);
		return func(this, a_stream);
	}


	bool NiTimeController::IsEqual(NiObject* a_object)
	{
		using func_t = decltype(&NiTimeController::IsEqual);
		REL::Offset<func_t> func = REL::ID(69437);
		return func(this, a_object);
	}


	void NiTimeController::ProcessClone(NiCloningProcess& a_cloning)
	{
		using func_t = decltype(&NiTimeController::ProcessClone);
		REL::Offset<func_t> func = REL::ID(69449);
		return func(this, a_cloning);
	}

	void NiTimeController::Start(float a_time)
	{
		using func_t = decltype(&NiTimeController::Start);
		REL::Offset<func_t> func = REL::ID(69440);
		return func(this, a_time);
	}


	void NiTimeController::Stop()
	{
		using func_t = decltype(&NiTimeController::Stop);
		REL::Offset<func_t> func = REL::ID(69441);
		return func(this);
	}


	void NiTimeController::SetTarget(NiObjectNET* a_target)
	{
		using func_t = decltype(&NiTimeController::SetTarget);
		REL::Offset<func_t> func = REL::ID(69442);
		return func(this, a_target);
	}


	float NiTimeController::ComputeScaledTime(float a_time)
	{
		using func_t = decltype(&NiTimeController::ComputeScaledTime);
		REL::Offset<func_t> func = REL::ID(69447);
		return func(this, a_time);
	}


	NiTimeController* NiTimeController::ctor()
	{
		using func_t = decltype(&NiTimeController::ctor);
		REL::Offset<func_t> func = REL::ID(69438);
		return func(this);
	}


	void NiTimeController::dtor()
	{
		using func_t = decltype(&NiTimeController::dtor);
		REL::Offset<func_t> func = REL::ID(69439);
		return func(this);
	}
}
