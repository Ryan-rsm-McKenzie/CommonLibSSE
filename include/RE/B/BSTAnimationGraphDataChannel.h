#pragma once

#include "RE/B/BSAnimationGraphChannel.h"

namespace RE
{
	template <class T, class Val, template <class T, class Val> class Channel>
	class BSTAnimationGraphDataChannel :
		public BSAnimationGraphChannel,	 // 00
		public Channel<T, Val>			 // 20
	{
	public:
	};
}
