#pragma once

#include "RE/BSTArray.h"

namespace RE
{
    class BGSDistantTreeBlock/* : public BSResourceEntry */
    {
    public:
        struct LODGroupInstance
        {
            UInt32 FormId;	// Only the lower 24 bits used
            char _pad[0xA];
            UInt16 Alpha;		// This is Float2Word(fAlpha)
            bool Hidden;		// Alpha <= 0.0f or set by object flags
        };

        struct LODGroup
        {
            char _pad[8];
            BSTArray<LODGroupInstance> m_LODInstances;
            char _pad2[4];
            bool m_UnkByte24;
        };

        struct ResourceData
        {
            BSTArray<LODGroup *> m_LODGroups;
            char _pad[106];
            bool m_UnkByte82;
        };

        // struct ResourceData @ 0x28
    };
}
