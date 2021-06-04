#pragma once

namespace RE
{
	class hkpPhantom;

	class hkpPhantomListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpPhantomListener;

		virtual ~hkpPhantomListener();  // 00

		virtual void PhantomAddedCallback(hkpPhantom* a_phantom);     // 01 - { return; }
		virtual void PhantomRemovedCallback(hkpPhantom* a_phantom);   // 02 - { return; }
		virtual void PhantomShapeSetCallback(hkpPhantom* a_phantom);  // 03
		virtual void PhantomDeletedCallback(hkpPhantom* a_phantom);   // 04 - { return; }
	};
	static_assert(sizeof(hkpPhantomListener) == 0x8);
}
