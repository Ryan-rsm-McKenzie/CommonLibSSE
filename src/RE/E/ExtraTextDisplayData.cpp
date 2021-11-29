#include "RE/E/ExtraTextDisplayData.h"

namespace RE
{
	ExtraTextDisplayData::ExtraTextDisplayData() :
		BSExtraData(),
		displayName(""),
		displayNameText(nullptr),
		ownerQuest(nullptr),
		ownerInstance(DisplayDataType::kUninitialized),
		temperFactor(1.0F),
		customNameLength(0),
		pad32(0),
		pad34(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ REL::ID(229625) };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraTextDisplayData::ExtraTextDisplayData(const char* a_name) :
		BSExtraData(),
		displayName(""),
		displayNameText(nullptr),
		ownerQuest(nullptr),
		ownerInstance(DisplayDataType::kUninitialized),
		temperFactor(1.0F),
		customNameLength(0),
		pad32(0),
		pad34(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ REL::ID(229625) };
		((std::uintptr_t*)this)[0] = vtbl.address();
		SetName(a_name);
	}

	ExtraTextDisplayData::ExtraTextDisplayData(TESBoundObject* a_baseObject, float a_temperFactor) :
		BSExtraData(),
		displayName(""),
		displayNameText(nullptr),
		ownerQuest(nullptr),
		ownerInstance(DisplayDataType::kUninitialized),
		temperFactor(1.0F),
		customNameLength(0),
		pad32(0),
		pad34(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ REL::ID(229625) };
		((std::uintptr_t*)this)[0] = vtbl.address();
		GetDisplayName(a_baseObject, a_temperFactor);
	}

	ExtraDataType ExtraTextDisplayData::GetType() const
	{
		return ExtraDataType::kTextDisplayData;
	}

	const char* ExtraTextDisplayData::GetDisplayName(TESBoundObject* a_baseObject, float a_temperFactor)
	{
		using func_t = decltype(&ExtraTextDisplayData::GetDisplayName);
		REL::Relocation<func_t> func{ REL::ID(12626) };
		return func(this, a_baseObject, a_temperFactor);
	}

	bool ExtraTextDisplayData::IsPlayerSet() const
	{
		return ownerInstance == DisplayDataType::kCustomName;
	}

	void ExtraTextDisplayData::SetName(const char* a_name)
	{
		if (displayNameText) {
			return;
		}

		displayName = a_name;
		customNameLength = static_cast<std::uint16_t>(displayName.length());
		ownerInstance = DisplayDataType::kCustomName;
		temperFactor = 1.0F;
	}
}
