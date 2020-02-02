#include "RE/TESFile.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	TESFile* TESFile::Duplicate(UInt32 a_cacheSize)
	{
		using func_t = decltype(&TESFile::Duplicate);
		REL::Offset<func_t> func(Offset::TESFile::Duplicate);
		return func(this, a_cacheSize);
	}


	UInt32 TESFile::GetCurrentSubRecordType()
	{
		using func_t = decltype(&TESFile::GetCurrentSubRecordType);
		REL::Offset<func_t> func(Offset::TESFile::GetCurrentSubRecordType);
		return func(this);
	}


	UInt32 TESFile::GetCurrentSubRecordSize() const
	{
		return actualChunkSize;
	}


	FormType TESFile::GetFormType()
	{
		using func_t = decltype(&TESFile::GetFormType);
		REL::Offset<func_t> func(Offset::TESFile::GetFormType);
		return func(this);
	}


	bool TESFile::IsLoaded() const
	{
		return true;
	}


	bool TESFile::IsLocalized() const
	{
		return (recordFlags & RecordFlag::kDelocalized) != RecordFlag::kNone;
	}


	void TESFile::ReadData(void* a_buf, UInt32 a_size)
	{
		using func_t = decltype(&TESFile::ReadData);
		REL::Offset<func_t> func(Offset::TESFile::ReadData);
		return func(this, a_buf, a_size);
	}


	bool TESFile::Seek(UInt32 a_offset)
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
