#pragma once


namespace RE
{
	class BGSEntryPointFunctionData
	{
	public:
		enum FunctionType : UInt32
		{
			kFunctionType_Invalid = 0,
			kFunctionType_OneValue,
			kFunctionType_TwoValue,
			kFunctionType_LeveledList,
			kFunctionType_DataActivateChoice,
			kFunctionType_DataSpellItem,
			kFunctionType_DataBooleanGraphVariable,
			kFunctionType_DataText
		};


		virtual ~BGSEntryPointFunctionData();	// 00

		virtual UInt32 GetType() const;			// 01 - Pure
	};
}
