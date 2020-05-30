#pragma once


namespace RE
{
	class TESForm;
	class TESGlobal;


	struct ContainerItemExtra  // COED
	{
	public:
		union Conditional
		{
			TESGlobal* global;
			SInt32	   rank;
		};
		STATIC_ASSERT(sizeof(Conditional) == 0x8);


		// members
		TESForm*	owner;		  // 00
		Conditional conditional;  // 08
		float		healthMult;	  // 10
		UInt32		pad14;		  // 14
	};
	STATIC_ASSERT(sizeof(ContainerItemExtra) == 0x18);
}
