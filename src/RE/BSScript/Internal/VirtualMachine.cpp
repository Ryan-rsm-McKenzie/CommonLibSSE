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
				return vm ? static_cast<VirtualMachine*>(vm->virtualMachine.get()) : 0;
			}


			bool VirtualMachine::AllocateArray(const VMTypeID& a_typeID, std::size_t a_size, BSTSmartPointer<Array>& a_array)
			{
				using func_t = function_type_t<decltype(&VirtualMachine::AllocateArray)>;
				REL::Offset<func_t*> func(Offset::BSScript::Internal::VirtualMachine::AllocateArray);
				return func(this, a_typeID, a_size, a_array);
			}
		}
	}
}
