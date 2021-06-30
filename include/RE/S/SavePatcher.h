#pragma once

#include "RE/I/ISavePatcherInterface.h"

namespace RE
{
	namespace SkyrimScript
	{
		class SavePatcher : public BSScript::ISavePatcherInterface
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript__SavePatcher;

			~SavePatcher() override;  // 00

			// override (BSScript::ISavePatcherInterface)
			void PatchStackFrame(BSScript::StackFrame* a_stackFrame, BSScript::IVirtualMachine* a_vm) override;  // 01
		};
		static_assert(sizeof(SavePatcher) == 0x8);
	}
}
