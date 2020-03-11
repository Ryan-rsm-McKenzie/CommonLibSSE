#pragma once


namespace RE
{
	namespace BSGraphics
	{
		enum class TextureAddressMode : UInt32
		{
			kClampSClampT = 0,
			kClampSWrapT = 1,
			kWrapSClampT = 2,
			kWrapSWrapT = 3
		};
	}
}
