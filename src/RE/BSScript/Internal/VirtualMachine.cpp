#include "RE/BSScript/Internal/VirtualMachine.h"

#include "RE/SkyrimVM.h"


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
