#include "RE/GFxMovieDef.h"


namespace RE
{
	GFxMovieDef::MemoryParams::MemoryParams(UPInt a_memoryArena) :
		heapLimitMultiplier(0.25),
		maxCollectionRoots(std::numeric_limits<UInt32>::max()),
		framesBetweenCollections(std::numeric_limits<UInt32>::max()),
		pad4C(0)
	{
		desc.arena = a_memoryArena;
	}


	GFxMovieDef::MemoryContext::~MemoryContext()
	{}


	GFxMovieDef::ImportVisitor::~ImportVisitor()
	{}


	GFxMovieDef::ResourceVisitor::~ResourceVisitor()
	{}


	GFxMovieView* GFxMovieDef::CreateInstance(bool a_initFirstFrame, UPInt a_memoryArena)
	{
		MemoryParams params(a_memoryArena);
		return CreateInstance(params, a_initFirstFrame);
	}
}
