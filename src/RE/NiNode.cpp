#include "RE/NiNode.h"

#include "skse64/NiObjects.h"  // NiAVObject


namespace RE
{
	NiNode* NiNode::Create(UInt32 arrBufLen)
	{
		typedef NiNode* _Create_t();
		static _Create_t* _Create = reinterpret_cast<_Create_t*>(GetFnAddr(&::NiNode::Create));
		return _Create();
	}
}
