#include "RE/T/TESFile.h"

namespace RE
{
	TESFile* TESFile::Duplicate(std::uint32_t a_cacheSize)
	{
		using func_t = decltype(&TESFile::Duplicate);
		REL::Relocation<func_t> func{ Offset::TESFile::Duplicate };
		return func(this, a_cacheSize);
	}

	std::uint32_t TESFile::GetCurrentSubRecordType()
	{
		using func_t = decltype(&TESFile::GetCurrentSubRecordType);
		REL::Relocation<func_t> func{ Offset::TESFile::GetCurrentSubRecordType };
		return func(this);
	}

	constexpr FormID TESFile::GetFormID(std::uint32_t a_formLower) const noexcept
	{
		return !IsLight() ? std::uint32_t(compileIndex) << 24 | (a_formLower & 0xFFFFFF) : 0xFE000000 | (std::uint32_t(smallFileCompileIndex) << 12) | (a_formLower & 0xFFF);
	}

	FormType TESFile::GetFormType()
	{
		using func_t = decltype(&TESFile::GetFormType);
		REL::Relocation<func_t> func{ Offset::TESFile::GetFormType };
		return func(this);
	}

	void TESFile::ReadData(void* a_buf, std::uint32_t a_size)
	{
		using func_t = decltype(&TESFile::ReadData);
		REL::Relocation<func_t> func{ Offset::TESFile::ReadData };
		return func(this, a_buf, a_size);
	}

	bool TESFile::Seek(std::uint32_t a_offset)
	{
		using func_t = decltype(&TESFile::Seek);
		REL::Relocation<func_t> func{ Offset::TESFile::Seek };
		return func(this, a_offset);
	}

	bool TESFile::SeekNextSubrecord()
	{
		using func_t = decltype(&TESFile::SeekNextSubrecord);
		REL::Relocation<func_t> func{ Offset::TESFile::SeekNextSubrecord };
		return func(this);
	}
}
