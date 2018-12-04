#pragma once

#include "skse64/NiNodes.h"  // NiNode

#include "RE/NiAVObject.h"  // RE::NiAVObject


namespace RE
{
	class NiNode : public NiAVObject
	{
	public:
		virtual ~NiNode();

		virtual void			AttachChild(NiAVObject* a_obj, bool a_firstAvail);
		virtual void			DetachChild(UInt32 a_unk1, NiAVObject* a_obj);
		virtual void			Unk_35(void);
		virtual void			RemoveChild(NiAVObject* a_obj);
		virtual void			Unk_37(void);
		virtual void			RemoveAt(UInt32 a_index);
		virtual void			Unk_39(void);
		virtual void			Unk_3A(void);
		virtual void			UpdateUpwardPass(void);

		static NiNode*			Create(UInt32 a_arrBufLen = 0);


		// members
		NiTArray<NiAVObject*>	m_children;	// A8
	};
}
