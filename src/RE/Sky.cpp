#include "RE/Sky.h"

#include "skse64_common/Relocation.h"  // RelocPtr

#include "RE/Offsets.h"  // SKY_SINGLETON


namespace RE
{
	Sky* Sky::GetSingleton()
	{
		static RelocPtr<Sky> singleton(SKY_SINGLETON);
		return singleton;
	}
}
