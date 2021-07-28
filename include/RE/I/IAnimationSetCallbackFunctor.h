#pragma once

namespace RE
{
	class IAnimationSetCallbackFunctor
	{
	public:
		inline static constexpr auto RTTI = RTTI_IAnimationSetCallbackFunctor;

		virtual ~IAnimationSetCallbackFunctor();  // 00

		// add
		virtual void Unk_01();  // 01
	};
	static_assert(sizeof(IAnimationSetCallbackFunctor) == 0x8);
}
