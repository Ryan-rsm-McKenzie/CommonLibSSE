#pragma once

#include "RE/TESBoundObject.h"
#include "RE/TESModelTextureSwap.h"

namespace RE
{
    class BGSAddonNode : public TESBoundObject, 
                         public TESModelTextureSwap  // 30
    {
    public:
        enum { kTypeID = FormType::AddonNode };

        // members
        UInt32	nodeIndex;		// 68 DATA
        UInt64	unk70;		    // 70
        UInt8	unk78[4];	    // 78
        UInt32	unk7C;		    // 7C
    };

    STATIC_ASSERT(offsetof(BGSAddonNode, nodeIndex) == 0x68);
    STATIC_ASSERT(sizeof(BGSAddonNode) == 0x80);

}
