#pragma once


namespace RE
{
    namespace MagicSystem
    {
        enum class CastingType : UInt32
        {
            kConstantEffect = 1,
            kFireAndForget = 2,
            kConcentration = 3,
            kScroll = 4
        };


        enum class CastingType16 : UInt16
        {
            kConstantEffect = 0,
            kFireAndForget = 1,
            kConcentration = 3,
            kScroll = 4
        };


        enum class Delivery : UInt32
        {
            kSelf = 0,
            kTouch = 1,
            kAimed = 2,
            kTargetActor = 3,
            kTargetLocation = 4
        };


        enum class SoundID : UInt32
        {
            kDrawSheatheLPM = 0,
            kCharge = 1,
            kReadyLoop = 2,
            kRelease = 3,
            kCastLoop = 4,
            kHit = 5
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
