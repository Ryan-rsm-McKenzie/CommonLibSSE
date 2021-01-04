#include "RE/E/ExtraOwnership.h"

namespace RE
{
	ExtraOwnership::ExtraOwnership() :
		ExtraOwnership(nullptr)
	{}

	ExtraOwnership::ExtraOwnership(TESForm* a_owner) :
		BSExtraData(),
		owner(a_owner)
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraOwnership::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraOwnership::GetType() const
	{
		return ExtraDataType::kOwnership;
	}

	bool ExtraOwnership::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraOwnership*>(a_rhs);
		return owner != rhs->owner;
	}
}
