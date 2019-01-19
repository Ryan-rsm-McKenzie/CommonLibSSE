#pragma once

#include "RE/TESForm.h"
#include "RE/FormTypes.h"

namespace RE
{
    class BGSShaderParticleGeometryData : public TESForm
    {
    public:
        enum { kTypeID = FormType::SPGD };

        tArray<float>   data;	    // 20 "DATA" in form; actually a mixed array of floats/ints, but is primarily floats
        TESTexture	    texture;	// 38
    };
}
