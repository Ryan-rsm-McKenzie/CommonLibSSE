#pragma once

#include "RE/BSAnimationGraphChannel.h"  // BSAnimationGraphChannel


namespace RE
{
	template <class Ty, class TVal, template<class Ty, class TVal> class TChannel>
	class BSTAnimationGraphDataChannel :
		public BSAnimationGraphChannel,	// 00
		public TChannel<Ty, TVal>		// 20
	{};
}
