#pragma once


namespace RE
{
	class GFxLogConstants
	{
	public:
		enum class LogMessageType : UInt32
		{
			// *** Channels

			// The idea of message channels is that they correspond to separate
			// logs that can be displayed individually. Several message sub-types
			// can, however, be generated within the same channel. End users may
			// choose to ignore the recommended channel structure and either
			// combine all of the messages (default output), or separate them
			// further into individual logs.

			kChannel_General = 0x10,	// Used for end-user messages about I/O, errors, etc.
			kChannel_Script = 0x20,		// Used for script-related messages (bad function parameters, etc.)
			kChannel_Parse = 0x30,		// Used for parse log generated during loading
			kChannel_Action = 0x40,		// Used for action-script instruction execution log
			kChannel_Debug = 0x50,		// Reserved flag for mapping GDebug messages into single log object.
			kChannel_Mask = 0xF0,
			// Standard channel sub-types
			kMessageType_Error = 0,
			kMessageType_Warning = 1,
			kMessageType_Message = 2,


			// *** Combined Log Message types

			// General I/O errors and warnings
			kError = kChannel_General | kMessageType_Error,
			kWarning = kChannel_General | kMessageType_Warning,
			kMessage = kChannel_General | kMessageType_Message,
			// Script errors and warnings
			kScriptError = kChannel_Script | kMessageType_Error,
			kScriptWarning = kChannel_Script | kMessageType_Warning,
			kScriptMessage = kChannel_Script | kMessageType_Message,
			// Parse log messages (generated based on verbosity settings during loading)
			kParse = kChannel_Parse | 0,
			kParseShape = kChannel_Parse | 1,
			kParseMorphShape = kChannel_Parse | 2,
			kParseAction = kChannel_Parse | 3,
			// Action
			kAction = kChannel_Action | 0
		};
	};
	STATIC_ASSERT(sizeof(GFxLogConstants) == 0x1);
}
