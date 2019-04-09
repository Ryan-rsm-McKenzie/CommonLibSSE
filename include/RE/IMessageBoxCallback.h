#pragma once


namespace RE
{
	class IMessageBoxCallback
	{
	public:
		virtual ~IMessageBoxCallback();			// 00

		// add
		virtual void Run(bool a_cancel) = 0;	// 01


		// members
		UInt32	unk08;	// 08
		UInt32	pad0C;	// 0C
	};
	STATIC_ASSERT(sizeof(IMessageBoxCallback) == 0x10);
}
