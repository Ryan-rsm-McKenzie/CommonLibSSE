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
			kSWF,					// SWF file formats
			kGFX,					// GFX file format (extracted SWF)
			kJPEG = 10,				// JPEG image file format
			kPNG = 11,				// PNG image file format
			kGIF = 12,				// GIF image file format
			kTGA = 13,				// TGA image file format
			kDDS = 14,				// DDS compressed texture file format
			kHDR = 15,				// HDR image file format
			kBMP = 16,				// BMP image file format
			kDIB = 17,				// DIB image file format
			kPFM = 18,				// PFM image file format
			kTIFF = 19,				// TIFF image file format
			kWAVE = 20,				// WAVE image file format
			kPVR = 21,				// PVR image file format
			kETC = 22,				// ETC image file format
			kSIF = 23,
			kGXT = 24,
			kGTX = 25,
			kGNF = 26,
			kKTX = 27,
			kNextAvail,
			kDDSBC = 65533,
			kMultiFormat = 65534,
			kOriginal = 65535
		};
	};
}
