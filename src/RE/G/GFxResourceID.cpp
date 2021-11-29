#include "RE/G/GFxResourceID.h"

namespace RE
{
	GFxResourceID::GFxResourceID() :
		id(IDTypeConstants::kInvalidID)
	{}

	GFxResourceID::GFxResourceID(std::uint32_t a_resID) :
		id(a_resID)
	{}

	GFxResourceID::GFxResourceID(const GFxResourceID& a_rhs) :
		id(a_rhs.id)
	{}

	GFxResourceID& GFxResourceID::operator=(const GFxResourceID& a_rhs)
	{
		id = a_rhs.id;
		return *this;
	}

	bool GFxResourceID::operator==(const GFxResourceID& a_rhs) const
	{
		return id == a_rhs.id;
	}

	bool GFxResourceID::operator!=(const GFxResourceID& a_rhs) const
	{
		return !operator==(a_rhs);
	}

	bool GFxResourceID::operator==(std::uint32_t a_idVal) const
	{
		return id == a_idVal;
	}

	bool GFxResourceID::operator!=(std::uint32_t a_idVal) const
	{
		return !operator==(a_idVal);
	}

	std::uint32_t GFxResourceID::GetIDValue() const
	{
		return id;
	}

	std::uint32_t GFxResourceID::GetIDIndex() const
	{
		return id & IDTypeConstants::kIndexMask;
	}

	GFxResourceID::IDTypes::IDType GFxResourceID::GetIDType() const
	{
		return static_cast<IDTypes::IDType>(id & IDTypeConstants::kTypeMask);
	}

	GFxResourceID GFxResourceID::GenerateNextID()
	{
		assert(id & IDTypeConstants::kGenMask);
		assert((id & IDTypeConstants::kIndexMask) != IDTypeConstants::kIndexMask);
		GFxResourceID tmp(*this);
		++id;
		return tmp;
	}

	UPInt GFxResourceID::HashOp::operator()(const GFxResourceID& a_idRef)
	{
		return (a_idRef.id ^ (a_idRef.id >> (16 - 8)));
	}
}
