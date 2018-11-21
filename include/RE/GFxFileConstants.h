#pragma once


namespace RE
{
	class GFxFileConstants
	{
	public:

		// All File formats supported and/or used by GFx.
		enum FileFormatType
		{
			File_Unopened,
			File_Unknown,

			// SWF file formats.
			File_SWF,
			File_GFX,

			// Image formats supported by Flash.
			File_JPEG = 10,
			File_PNG = 11,
			File_GIF = 12,
			// Other image formats.
			File_TGA = 13,
			File_DDS = 14,
			File_HDR = 15,
			File_BMP = 16,
			File_DIB = 17,
			File_PFM = 18,
			File_TIFF = 19,

			// Sound formats
			File_WAVE = 20,

			File_NextAvail,
			File_Original = 65535
		};
	};
}
