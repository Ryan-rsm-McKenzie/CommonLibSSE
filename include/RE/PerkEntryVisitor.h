#pragma once


namespace RE
{
	class BGSPerkEntry;


	class PerkEntryVisitor
	{
	public:
		enum class ReturnType : UInt32
		{
			kBreak,
			kContinue
		};


		virtual ReturnType Visit(BGSPerkEntry* a_perkEntry) = 0;
	};
}
