#pragma once


namespace RE
{
	namespace MagicSystem
	{
		enum class CannotCastReason : UInt32
		{
			kOK = 0,
			kMagicka = 1,
			kPowerUsed = 2,
			kRangedUnderWater = 3,
			kMultipleCast = 4,
			kItemCharge = 5,
			kCastWhileShouting = 6,
			kShoutWhileCasting = 7,
			kShoutWhileRecovering = 8
		};


		enum class CastingSource : UInt32
		{
			kLeftHand = 0,
			kRightHand = 1,
			kOther = 2,
			kInstant = 3
		};


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


		enum class SpellType : UInt32
		{
			kSpell = 0,
			kDisease = 1,
			kPower = 2,
			kLesserPower = 3,
			kAbility = 4,
			kPoison = 5,
			kEnchantment = 6,

			kPotion = 7,
			kAlchemy = kPotion,

			kWortCraft = 8,
			kIngredient = kWortCraft,

			kLeveledSpell = 9,
			kAddiction = 10,
			kVoicePower = 11,
			kStaffEnchantment = 12,
			kScroll = 13
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
