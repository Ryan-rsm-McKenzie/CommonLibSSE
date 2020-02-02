#include "RE/GFxLoader.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	GFxMovieDef* GFxLoader::CreateMovie(const char* a_filename, LoadConstants a_loadConstants, UPInt a_memoryArena)
	{
		using func_t = decltype(&GFxLoader::CreateMovie);
		REL::Offset<func_t> func(Offset::GFxLoader::CreateMovie);
		return func(this, a_filename, a_loadConstants, a_memoryArena);
	}


	GFxLoaderImpl* GFxLoader::GetLoaderImpl() const
	{
		return impl;
	}
}
