#pragma once

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BGSTextureSet;
	class NiAVObject;
	class NiNode;
	class TESForm;
	class TESModelTextureSwap;


	struct Biped : public BSIntrusiveRefCounted
	{
	public:
		struct Data
		{
			TESForm*				item;		// 00
			TESForm*				addon;		// 08
			TESModelTextureSwap*	model;		// 10
			BGSTextureSet*			textureSet;	// 18
			NiPointer<NiAVObject>	object;		// 20
			UInt64					unk28;		// 28 - same as AIProcess::Data0B8
			UInt64					unk30;		// 30
			UInt64					unk38;		// 38
			UInt64					unk40;		// 40
			UInt64					unk48;		// 48
			UInt64					unk50;		// 50
			UInt64					unk58;		// 58
			void*					unk60;		// 60 - smart ptr
			UInt64					unk68;		// 68
			void*					unk70;		// 70
		};
		STATIC_ASSERT(sizeof(Data) == 0x78);


		~Biped();

		void UpdateWeightData();


		UInt32		unk0004;		// 0000
		NiNode*		root;			// 0008
		Data		unk0010[42];	// 0010
		Data		unk13C0[42];	// 13C0
		RefHandle	unk2770;		// 2770
		UInt32		unk2774;		// 2774

	private:
		void Dtor();
	};
	STATIC_ASSERT(sizeof(Biped) == 0x2778);
}
