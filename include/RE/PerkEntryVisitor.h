#pragma once


namespace RE
{
	class BGSPerkEntry;


	class PerkEntryVisitor
	{
	public:
		enum ReturnType : UInt32
		{
			kReturnType_Break,
			kReturnType_Continue
		};


		virtual ReturnType Visit(BGSPerkEntry* a_perkEntry) = 0;
	};
}
