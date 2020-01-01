#pragma once


namespace RE
{
    namespace MagicSystem
    {
        enum class CastingType : UInt32
        {
            kConstantEffect = 0x0,
            kFireAndForget = 0x1,
            kConcentration = 0x2
        };


        enum class CastingType16 : UInt16
        {
            kConstantEffect = 0x0,
            kFireAndForget = 0x1,
            kConcentration = 0x2
        };


        enum class WardState : UInt32
        {
            kNone = 0,
            kAbsorb = 1,
            kBreak = 2,

            kTotal
        };
    }
}
