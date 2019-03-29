#include "RE/VirtualMachine.h"

#include "skse64/PapyrusVM.h"  // g_skyrimVM

#include "RE/Offsets.h"


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


			bool VirtualMachine::AllocateArray(const VMTypeID& a_typeID, std::size_t a_size, BSTSmartPointer<BSScriptArray>& a_array)
			{
				using func_t = function_type_t<decltype(&VirtualMachine::AllocateArray)>;
				RelocUnrestricted<func_t*> func(Offset::VirtualMachine::AllocateArray);
				return func(this, a_typeID, a_size, a_array);
			}
		}
	}
}
