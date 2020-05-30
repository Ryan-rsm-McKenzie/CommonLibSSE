#pragma once

#include "RE/Animation/BSAnimationGraphChannel/BSAnimationGraphChannel.h"


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
