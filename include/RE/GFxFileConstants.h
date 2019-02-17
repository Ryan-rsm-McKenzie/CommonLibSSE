#pragma once


namespace RE
{
	class GFxFileConstants
	{
	public:
		// FileFormatType is an enumeration including all file formats supported and/or used by GFx.
		enum class FileFormatType
		{
			kUnopened,				// No attempt was made to open file, so its format is not yet determined
			kUnknown,				// The file was opened, but its format is unknown

			// Swf file formats
			kSWF,					// SWF file formats
			kGFX,					// GFX file format (extracted SWF)

			// Image formats supported by swf
			kJPEG = 10,				// JPEG image file format
			kPNG = 11,				// PNG image file format
			kGIF = 12,				// GIF image file format
			// Other image formats
			kTGA = 13,				// TGA image file format
			kDDS = 14,				// DDS compressed texture file format
			kHDR = 15,				// HDR image file format
			kBMP = 16,				// BMP image file format
			kDIB = 17,				// DIB image file format
			kPFM = 18,				// PFM image file format
			kTIFF = 19,				// TIFF image file format

			// Sound formats
			kWAVE = 20,				// WAVE image file format

			kNextAvail,
			kOriginal = 65535
		};
	};
}
