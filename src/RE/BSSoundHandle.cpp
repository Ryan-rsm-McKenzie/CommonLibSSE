#include "RE/BSSoundHandle.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


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
		REL::Offset<func_t> func(Offset::BSSoundHandle::IsValid);
		return func(this);
	}


	bool BSSoundHandle::SetPosition(NiPoint3 a_pos)
	{
		using func_t = decltype(&BSSoundHandle::SetPosition);
		REL::Offset<func_t> func(Offset::BSSoundHandle::SetPosition);
		return func(this, a_pos);
	}


	void BSSoundHandle::SetObjectToFollow(NiAVObject* a_node)
	{
		using func_t = decltype(&BSSoundHandle::SetObjectToFollow);
		REL::Offset<func_t> func(Offset::BSSoundHandle::SetObjectToFollow);
		return func(this, a_node);
	}


	bool BSSoundHandle::Stop()
	{
		using func_t = decltype(&BSSoundHandle::Stop);
		REL::Offset<func_t> func(Offset::BSSoundHandle::Stop);
		return func(this);
	}


	bool BSSoundHandle::Play()
	{
		using func_t = decltype(&BSSoundHandle::Play);
		REL::Offset<func_t> func(Offset::BSSoundHandle::Play);
		return func(this);
	}
}
