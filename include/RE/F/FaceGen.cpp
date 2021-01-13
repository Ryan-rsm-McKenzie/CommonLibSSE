#include "RE/F/FaceGen.h"

namespace RE
{
	FaceGen* FaceGen::GetSingleton()
	{
		REL::Relocation<NiPointer<FaceGen>*> singleton{ REL::ID(514182) };
		return singleton->get();
	}

	void FaceGen::RegenerateHead(BSFaceGenNiNode* a_headNode, BGSHeadPart* a_head, TESNPC* a_npc)
	{
		using func_t = decltype(&FaceGen::RegenerateHead);
		REL::Relocation<func_t> func{ REL::ID(26259) };
		return func(this, a_headNode, a_head, a_npc);
	}
}
