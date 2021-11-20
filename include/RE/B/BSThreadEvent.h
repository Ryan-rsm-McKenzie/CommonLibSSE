#pragma once

namespace RE
{
	struct BSThreadEvent
	{
		static void InitSDM()
		{
			using func_t = decltype(&BSThreadEvent::InitSDM);
			REL::Relocation<func_t> func{ REL::Offset(0xC33500) };
			return func();
		}
	};
}
