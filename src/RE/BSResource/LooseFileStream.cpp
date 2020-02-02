#include "RE/BSResource/LooseFileStream.h"

#include "RE/MemoryManager.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSResource
	{
		LooseFileStream* LooseFileStream::Create(BSFixedString a_prefix, BSFixedString a_dirName, BSFixedString a_fileName, UInt32 a_fileSize, bool a_readOnly, Location* a_location)
		{
			auto mem = malloc<LooseFileStream>();
			return mem->Ctor(a_prefix, a_dirName, a_fileName, a_fileSize, a_readOnly, a_location);
		}


		LooseFileStream* LooseFileStream::Ctor(const BSFixedString& a_prefix, const BSFixedString& a_dirName, const BSFixedString& a_fileName, UInt32 a_fileSize, bool a_readOnly, Location* a_location)
		{
			using func_t = decltype(&LooseFileStream::Ctor);
			REL::Offset<func_t> func(Offset::LooseFileStream::Ctor);
			return func(this, a_prefix, a_dirName, a_fileName, a_fileSize, a_readOnly, a_location);
		}
	}
}
