#pragma once

#include "RE/BSScript/BSScriptType.h"  // BSScriptType
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace BSScript
	{
		class BSScriptType;
		class IFunction;


		class BSScriptClass : public BSIntrusiveRefCounted
		{
		public:
			struct BitPun
			{
				struct Bits
				{
					constexpr Bits(bool a_bit00,
								   bool a_bit01,
								   bool a_bit02,
								   bool a_bit03,
								   bool a_bit04,
								   bool a_bit05,
								   bool a_bit06,
								   bool a_bit07,
								   bool a_bit08,
								   bool a_bit09,
								   bool a_bit10,
								   bool a_bit11,
								   bool a_bit12,
								   bool a_bit13,
								   bool a_bit14,
								   bool a_bit15) :
						bit00(a_bit00),
						bit01(a_bit01),
						bit02(a_bit02),
						bit03(a_bit03),
						bit04(a_bit04),
						bit05(a_bit05),
						bit06(a_bit06),
						bit07(a_bit07),
						bit08(a_bit08),
						bit09(a_bit09),
						bit10(a_bit10),
						bit11(a_bit11),
						bit12(a_bit12),
						bit13(a_bit13),
						bit14(a_bit14),
						bit15(a_bit15)
					{}


					bool bit00 : 1;
					bool bit01 : 1;
					bool bit02 : 1;
					bool bit03 : 1;
					bool bit04 : 1;
					bool bit05 : 1;
					bool bit06 : 1;
					bool bit07 : 1;
					bool bit08 : 1;
					bool bit09 : 1;
					bool bit10 : 1;
					bool bit11 : 1;
					bool bit12 : 1;
					bool bit13 : 1;
					bool bit14 : 1;
					bool bit15 : 1;
				};


				union Pun
				{
					constexpr Pun(bool a_bit00,
								  bool a_bit01,
								  bool a_bit02,
								  bool a_bit03,
								  bool a_bit04,
								  bool a_bit05,
								  bool a_bit06,
								  bool a_bit07,
								  bool a_bit08,
								  bool a_bit09,
								  bool a_bit10,
								  bool a_bit11,
								  bool a_bit12,
								  bool a_bit13,
								  bool a_bit14,
								  bool a_bit15) :
						bits(a_bit00, a_bit01, a_bit02, a_bit03, a_bit04, a_bit05, a_bit06, a_bit07, a_bit08, a_bit09, a_bit10, a_bit11, a_bit12, a_bit13, a_bit14, a_bit15)
					{}


					Bits bits;
					UInt16 value;
				};


				constexpr BitPun(const bool a_bit00 = 0,
								 const bool a_bit01 = 0,
								 const bool a_bit02 = 0,
								 const bool a_bit03 = 0,
								 const bool a_bit04 = 0,
								 const bool a_bit05 = 0,
								 const bool a_bit06 = 0,
								 const bool a_bit07 = 0,
								 const bool a_bit08 = 0,
								 const bool a_bit09 = 0,
								 const bool a_bit10 = 0,
								 const bool a_bit11 = 0,
								 const bool a_bit12 = 0,
								 const bool a_bit13 = 0,
								 const bool a_bit14 = 0,
								 const bool a_bit15 = 0) :
					pun(a_bit00, a_bit01, a_bit02, a_bit03, a_bit04, a_bit05, a_bit06, a_bit07, a_bit08, a_bit09, a_bit10, a_bit11, a_bit12, a_bit13, a_bit14, a_bit15)
				{}


				Pun pun;
			};


			~BSScriptClass();

			const char*	GetName() const;
			UInt32		GetFlags() const;
			UInt32		GetNumScriptFlags() const;
			UInt32		GetNumVariables() const;
			UInt32		GetNumDefaultValues() const;
			UInt32		GetNumProperties() const;
			UInt32		GetNumGlobalFuncs() const;
			UInt32		GetNumMemberFuncs() const;
			UInt32		GetNumStates() const;
			VMTypeID	GetTypeID() const;
			SInt32		GetVariableIndex(const BSFixedString& a_name) const;
			IFunction*	GetFunction(const char* a_name) const;


			// members
			UInt32			unk04;					// 04
			BSFixedString	name;					// 08
			BSScriptClass*	parent;					// 10
			BSFixedString	unk18;					// 18

			bool			flag1 : 1;				// 20 - 0
			bool			flag2 : 1;				// 20 - 1
			bool			numScriptFlags1 : 1;	// 20 - 2
			bool			numScriptFlags2 : 1;	// 20 - 3
			bool			numScriptFlags3 : 1;	// 20 - 4
			bool			numScriptFlags4 : 1;	// 20 - 5
			bool			numScriptFlags5 : 1;	// 20 - 6
			bool			numScriptFlags6 : 1;	// 20 - 7

			bool			numVariables1 : 1;		// 21 - 0 - double check
			bool			numVariables2 : 1;		// 21 - 1
			bool			numVariables3 : 1;		// 21 - 2
			bool			numVariables4 : 1;		// 21 - 3
			bool			numVariables5 : 1;		// 21 - 4
			bool			numVariables6 : 1;		// 21 - 5
			bool			numVariables7 : 1;		// 21 - 6
			bool			numVariables8 : 1;		// 21 - 7

			bool			numVariables9 : 1;		// 22 - 0
			bool			numVariables10 : 1;		// 22 - 1
			bool			unk22_2 : 1;			// 22 - 2
			bool			unk22_3 : 1;			// 22 - 3
			bool			unk22_4 : 1;			// 22 - 4
			bool			unk22_5 : 1;			// 22 - 5
			bool			unk22_6 : 1;			// 22 - 6
			bool			unk22_7 : 1;			// 22 - 7

			bool			unk23_0 : 1;			// 23 - 0
			bool			unk23_1 : 1;			// 23 - 1
			bool			unk23_2 : 1;			// 23 - 2
			bool			unk23_3 : 1;			// 23 - 3
			bool			unk23_4 : 1;			// 23 - 4
			bool			unk23_5 : 1;			// 23 - 5
			bool			unk23_6 : 1;			// 23 - 6
			bool			unk23_7 : 1;			// 23 - 7

			bool			numDefaultValues1 : 1;	// 24 - 0
			bool			numDefaultValues2 : 1;	// 24 - 1
			bool			numDefaultValues3 : 1;	// 24 - 2
			bool			numDefaultValues4 : 1;	// 24 - 3
			bool			numDefaultValues5 : 1;	// 24 - 4
			bool			numDefaultValues6 : 1;	// 24 - 5
			bool			numDefaultValues7 : 1;	// 24 - 6
			bool			numDefaultValues8 : 1;	// 24 - 7

			bool			numDefaultValues9 : 1;	// 25 - 0
			bool			numDefaultValues10 : 1;	// 25 - 1
			bool			numProperties1 : 1;		// 25 - 2
			bool			numProperties2 : 1;		// 25 - 3
			bool			numProperties3 : 1;		// 25 - 4
			bool			numProperties4 : 1;		// 25 - 5
			bool			numProperties5 : 1;		// 25 - 6
			bool			numProperties6 : 1;		// 25 - 7

			bool			numProperties7 : 1;		// 26 - 0
			bool			numProperties8 : 1;		// 26 - 1
			bool			numProperties9 : 1;		// 26 - 2
			bool			numProperties10 : 1;	// 26 - 3
			bool			numGlobalFuncs1 : 1;	// 26 - 4
			bool			numGlobalFuncs2 : 1;	// 26 - 5
			bool			numGlobalFuncs3 : 1;	// 26 - 6
			bool			numGlobalFuncs4 : 1;	// 26 - 7

			bool			numGlobalFuncs5 : 1;	// 27 - 0
			bool			numGlobalFuncs6 : 1;	// 27 - 1
			bool			numGlobalFuncs7 : 1;	// 27 - 2
			bool			numGlobalFuncs8 : 1;	// 27 - 3
			bool			numGlobalFuncs9 : 1;	// 27 - 4
			bool			unk27_5 : 1;			// 27 - 5
			bool			unk27_6 : 1;			// 27 - 6
			bool			unk27_7 : 1;			// 27 - 7

			bool			numMemberFuncs1 : 1;	// 28 - 0
			bool			numMemberFuncs2 : 1;	// 28 - 1
			bool			numMemberFuncs3 : 1;	// 28 - 2
			bool			numMemberFuncs4 : 1;	// 28 - 3
			bool			numMemberFuncs5 : 1;	// 28 - 4
			bool			numMemberFuncs6 : 1;	// 28 - 5
			bool			numMemberFuncs7 : 1;	// 28 - 6
			bool			numMemberFuncs8 : 1;	// 28 - 7

			bool			numMemberFuncs9 : 1;	// 29 - 0
			bool			unk29_1 : 1;			// 29 - 1
			bool			unk29_2 : 1;			// 29 - 2
			bool			unk29_3 : 1;			// 29 - 3
			bool			unk29_4 : 1;			// 29 - 4
			bool			unk29_5 : 1;			// 29 - 5
			bool			numStates1 : 1;			// 29 - 6
			bool			numStates2 : 1;			// 29 - 7

			bool			numStates3 : 1;			// 2A - 0
			bool			numStates4 : 1;			// 2A - 1
			bool			numStates5 : 1;			// 2A - 2
			bool			unk2A_3 : 1;			// 2A - 3
			bool			unk2A_4 : 1;			// 2A - 4
			bool			unk2A_5 : 1;			// 2A - 5
			bool			unk2A_6 : 1;			// 2A - 6
			bool			unk2A_7 : 1;			// 2A - 7

			bool			unk2B_0 : 1;			// 2B - 0
			bool			unk2B_1 : 1;			// 2B - 1
			bool			unk2B_2 : 1;			// 2B - 2
			bool			unk2B_3 : 1;			// 2B - 3
			bool			unk2B_4 : 1;			// 2B - 4
			bool			unk2B_5 : 1;			// 2B - 5
			bool			unk2B_6 : 1;			// 2B - 6
			bool			unk2B_7 : 1;			// 2B - 7

			UInt32			pad2C;					// 2C
			void*			dataPtr;				// 30

		private:
			void Dtor();
		};
		STATIC_ASSERT(sizeof(BSScriptClass) == 0x38);
	}
}
