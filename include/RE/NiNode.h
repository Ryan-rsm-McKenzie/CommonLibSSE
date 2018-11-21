#pragma once

#include "skse64/NiNodes.h"  // NiNode

#include "RE/NiAVObject.h"  // RE::NiAVObject


namespace RE
{
	class NiNode : public NiAVObject
	{
	public:
		virtual ~NiNode();

		virtual void			AttachChild(NiAVObject* obj, bool firstAvail);
		virtual void			DetachChild(UInt32 unk1, NiAVObject* obj);
		virtual void			Unk_35(void);
		virtual void			RemoveChild(NiAVObject* obj);
		virtual void			Unk_37(void);
		virtual void			RemoveAt(UInt32 i);
		virtual void			Unk_39(void);
		virtual void			Unk_3A(void);
		virtual void			UpdateUpwardPass(void);

		static NiNode*			Create(UInt32 arrBufLen = 0);


		// members
		NiTArray<NiAVObject*>	m_children;	// A8
	};
}
