#pragma once

namespace RE
{
	namespace BSGraphics
	{
		enum class DepthStencilDepthMode
		{
			kDisabled = 0,
			kTest = 1,
			kWrite = 2,
			kTestWrite = 3,
			kTestEqual = 4,
			kTestGreaterEqual = 5,
			kTestGreater = 6
		};
	}
}
