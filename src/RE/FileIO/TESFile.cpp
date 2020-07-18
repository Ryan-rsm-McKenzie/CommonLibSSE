#include "RE/FileIO/TESFile.h"


namespace RE
{
	TESFile* TESFile::Duplicate(std::uint32_t a_cacheSize)
	{
		using func_t = decltype(&TESFile::Duplicate);
		REL::Offset<func_t> func(Offset::TESFile::Duplicate);
		return func(this, a_cacheSize);
	}


	std::uint32_t TESFile::GetCurrentSubRecordType()
	{
		using func_t = decltype(&TESFile::GetCurrentSubRecordType);
		REL::Offset<func_t> func(Offset::TESFile::GetCurrentSubRecordType);
		return func(this);
	}


	FormType TESFile::GetFormType()
	{
		using func_t = decltype(&TESFile::GetFormType);
		REL::Offset<func_t> func(Offset::TESFile::GetFormType);
		return func(this);
	}


	void TESFile::ReadData(void* a_buf, std::uint32_t a_size)
	{
		using func_t = decltype(&TESFile::ReadData);
		REL::Offset<func_t> func(Offset::TESFile::ReadData);
		return func(this, a_buf, a_size);
	}


	bool TESFile::Seek(std::uint32_t a_offset)
	{
		using func_t = decltype(&TESFile::Seek);
		REL::Offset<func_t> func(Offset::TESFile::Seek);
		return func(this, a_offset);
	}


	bool TESFile::SeekNextSubrecord()
	{
		using func_t = decltype(&TESFile::SeekNextSubrecord);
		REL::Offset<func_t> func(Offset::TESFile::SeekNextSubrecord);
		return func(this);
	}
}
