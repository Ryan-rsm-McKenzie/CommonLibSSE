#include "RE/B/BSSoundHandle.h"

namespace RE
{
	BSSoundHandle::BSSoundHandle() :
		soundID(kInvalidID),
		assumeSuccess(false),
		pad05(0),
		pad06(0),
		state(AssumedState::kInitialized)
	{}

	bool BSSoundHandle::IsValid() const
	{
		using func_t = decltype(&BSSoundHandle::IsValid);
		REL::Relocation<func_t> func{ Offset::BSSoundHandle::IsValid };
		return func(this);
	}

	bool BSSoundHandle::SetPosition(NiPoint3 a_pos)
	{
		using func_t = decltype(&BSSoundHandle::SetPosition);
		REL::Relocation<func_t> func{ Offset::BSSoundHandle::SetPosition };
		return func(this, a_pos);
	}

	void BSSoundHandle::SetObjectToFollow(NiAVObject* a_node)
	{
		using func_t = decltype(&BSSoundHandle::SetObjectToFollow);
		REL::Relocation<func_t> func{ Offset::BSSoundHandle::SetObjectToFollow };
		return func(this, a_node);
	}

	bool BSSoundHandle::Stop()
	{
		using func_t = decltype(&BSSoundHandle::Stop);
		REL::Relocation<func_t> func{ Offset::BSSoundHandle::Stop };
		return func(this);
	}

	bool BSSoundHandle::Play()
	{
		using func_t = decltype(&BSSoundHandle::Play);
		REL::Relocation<func_t> func{ Offset::BSSoundHandle::Play };
		return func(this);
	}
}
