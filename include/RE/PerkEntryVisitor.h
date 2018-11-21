#pragma once


namespace RE
{
	class BGSPerkEntry;


	class PerkEntryVisitor
	{
	public:
		virtual UInt32 Visit(BGSPerkEntry* perkEntry) = 0;
	};
}
