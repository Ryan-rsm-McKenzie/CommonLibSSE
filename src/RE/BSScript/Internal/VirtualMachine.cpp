#include "RE/BSScript/Internal/VirtualMachine.h"

#include "RE/Offsets.h"
#include "RE/SkyrimVM.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			VirtualMachine* VirtualMachine::GetSingleton()
			{
				auto vm = SkyrimVM::GetSingleton();
				return vm ? static_cast<VirtualMachine*>(vm->impl.get()) : nullptr;
			}
		}
	}
}
