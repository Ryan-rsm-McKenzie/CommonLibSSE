#include "RE/N/NiTimeController.h"

namespace RE
{
	const NiRTTI* NiTimeController::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiTimeController::Ni_RTTI };
		return rtti.get();
	}

	void NiTimeController::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::LoadBinary);
		REL::Relocation<func_t> func{ REL::Offset(0xC953B0) };
		return func(this, a_stream);
	}

	void NiTimeController::LinkObject(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::LinkObject);
		REL::Relocation<func_t> func{ REL::Offset(0xC95500) };
		return func(this, a_stream);
	}

	bool NiTimeController::RegisterStreamables(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::RegisterStreamables);
		REL::Relocation<func_t> func{ REL::Offset(0xC95570) };
		return func(this, a_stream);
	}

	void NiTimeController::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::SaveBinary);
		REL::Relocation<func_t> func{ REL::Offset(0xC955C0) };
		return func(this, a_stream);
	}

	bool NiTimeController::IsEqual(NiObject* a_object)
	{
		using func_t = decltype(&NiTimeController::IsEqual);
		REL::Relocation<func_t> func{ REL::Offset(0xC95720) };
		return func(this, a_object);
	}

	void NiTimeController::ProcessClone(NiCloningProcess& a_cloning)
	{
		using func_t = decltype(&NiTimeController::ProcessClone);
		REL::Relocation<func_t> func{ REL::Offset(0xC95E80) };
		return func(this, a_cloning);
	}

	void NiTimeController::Start(float a_time)
	{
		using func_t = decltype(&NiTimeController::Start);
		REL::Relocation<func_t> func{ REL::Offset(0xC958A0) };
		return func(this, a_time);
	}

	void NiTimeController::Stop()
	{
		using func_t = decltype(&NiTimeController::Stop);
		REL::Relocation<func_t> func{ REL::Offset(0xC958C0) };
		return func(this);
	}

	void NiTimeController::SetTarget(NiObjectNET* a_target)
	{
		using func_t = decltype(&NiTimeController::SetTarget);
		REL::Relocation<func_t> func{ REL::Offset(0xC958F0) };
		return func(this, a_target);
	}

	float NiTimeController::ComputeScaledTime(float a_time)
	{
		using func_t = decltype(&NiTimeController::ComputeScaledTime);
		REL::Relocation<func_t> func{ REL::Offset(0xC95C50) };
		return func(this, a_time);
	}

	NiTimeController* NiTimeController::ctor()
	{
		using func_t = decltype(&NiTimeController::ctor);
		REL::Relocation<func_t> func{ REL::Offset(0xC957B0) };
		return func(this);
	}

	void NiTimeController::dtor()
	{
		using func_t = decltype(&NiTimeController::dtor);
		REL::Relocation<func_t> func{ REL::Offset(0xC95840) };
		return func(this);
	}
}
