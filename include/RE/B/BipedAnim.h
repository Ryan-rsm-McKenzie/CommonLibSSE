#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BipedObjects.h"
#include "RE/N/NiSmartPointer.h"

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
		std::uint64_t		  unk28;		// 28 - same as AIProcess::Data0B8
		std::uint64_t		  unk30;		// 30
		std::uint64_t		  unk38;		// 38
		std::uint64_t		  unk40;		// 40
		std::uint64_t		  unk48;		// 48
		std::uint64_t		  unk50;		// 50
		std::uint64_t		  unk58;		// 58
		void*				  unk60;		// 60 - smart ptr
		std::uint64_t		  unk68;		// 68
		void*				  unk70;		// 70
	};
	static_assert(sizeof(BIPOBJECT) == 0x78);

	class BipedAnim : public BSIntrusiveRefCounted
	{
	public:
		~BipedAnim();

		void RemoveAllParts();

		std::uint32_t	pad0004;								 // 0004
		NiNode*			root;									 // 0008
		BIPOBJECT		objects[BIPED_OBJECTS::kTotal];			 // 0010
		BIPOBJECT		bufferedObjects[BIPED_OBJECTS::kTotal];	 // 13C0
		ObjectRefHandle actorRef;								 // 2770
		std::uint32_t	pad2774;								 // 2774

	private:
		void Dtor();
	};
	static_assert(sizeof(BipedAnim) == 0x2778);
}
