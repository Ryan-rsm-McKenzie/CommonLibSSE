#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiNode;
	class Sky;

	class SkyObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_SkyObject;

		virtual ~SkyObject();  // 00

		// add
		virtual NiNode* GetRoot();						   // 01 - { return root.get(); }
		virtual void	Unk_02(void);					   // 02
		virtual void	Update(Sky* a_sky, float a_arg2);  // 03 - { return; }

		// members
		NiPointer<NiNode> root;	 // 10
	};
	static_assert(sizeof(SkyObject) == 0x10);
}
