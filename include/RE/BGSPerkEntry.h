#pragma once


namespace RE
{
	class BGSEntryPointFunctionData;


	class BGSPerkEntry
	{
	public:
		virtual ~BGSPerkEntry();														// 0

		virtual bool						CanProcess(UInt32 a_numArgs, void* a_args);	// 1
		virtual UInt8						GetType() const;							// 2 { return 0; }
		virtual BGSEntryPointFunctionData*	GetFunctionData() const;					// 3 { return 0; }
		// more


		// members
		UInt8	rank;		// 8
		UInt8	priority;	// 9
		UInt16	type;		// A
		UInt32	padC;		// C
	};
}
