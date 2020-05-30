#pragma once

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSPointerHandle.h"
#include "RE/BipedObjects.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BGSTextureSet;
	class NiAVObject;
	class NiNode;
	class TESForm;
	class TESModel;
	class TESObjectARMA;


	struct BIPOBJECT
	{
	public:
		// members
		TESForm*			  item;			// 00
		TESObjectARMA*		  addon;		// 08
		TESModel*			  part;			// 10
		BGSTextureSet*		  skinTexture;	// 18
		NiPointer<NiAVObject> partClone;	// 20
		UInt64				  unk28;		// 28 - same as AIProcess::Data0B8
		UInt64				  unk30;		// 30
		UInt64				  unk38;		// 38
		UInt64				  unk40;		// 40
		UInt64				  unk48;		// 48
		UInt64				  unk50;		// 50
		UInt64				  unk58;		// 58
		void*				  unk60;		// 60 - smart ptr
		UInt64				  unk68;		// 68
		void*				  unk70;		// 70
	};
	STATIC_ASSERT(sizeof(BIPOBJECT) == 0x78);


	class BipedAnim : public BSIntrusiveRefCounted
	{
	public:
		~BipedAnim();

		void RemoveAllParts();


		UInt32			pad0004;								 // 0004
		NiNode*			root;									 // 0008
		BIPOBJECT		objects[BIPED_OBJECTS::kTotal];			 // 0010
		BIPOBJECT		bufferedObjects[BIPED_OBJECTS::kTotal];	 // 13C0
		ObjectRefHandle actorRef;								 // 2770
		UInt32			pad2774;								 // 2774

	private:
		void Dtor();
	};
	STATIC_ASSERT(sizeof(BipedAnim) == 0x2778);
}
