#include "RE/VirtualMachine.h"

#include "skse64/PapyrusVM.h"  // g_skyrimVM


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			VirtualMachine* VirtualMachine::GetSingleton()
			{
				return *reinterpret_cast<VirtualMachine**>(*reinterpret_cast<std::uintptr_t*>(g_skyrimVM.GetUIntPtr()) + 0x200);
			}
		}
	}
}
