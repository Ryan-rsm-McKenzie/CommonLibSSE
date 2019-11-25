#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	struct AnimationVariableData
	{
		union Data
		{
			bool	b;
			SInt32	i;
			float	f;
		};


		BSFixedString	name;	// 00
		Data*			data;	// 04
	};
}
