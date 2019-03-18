#pragma once


namespace RE
{
	class NiAnimationKey
	{
	public:
		enum class KeyContent : UInt32
		{
			kFloat,
			kPos,
			kRot,
			kColor,
			kText,
			kBool,

			kTotal
		};


		enum class KeyType : UInt32
		{
			kNoInterp,
			kLink,
			kBez,
			kTCB,
			kEuler,
			kStrip,

			kTotal
		};


		NiAnimationKey();
		NiAnimationKey(float a_time);
		~NiAnimationKey();

		float			GetTime() const;
		void			SetTime(float a_time);
		NiAnimationKey*	GetKeyAt(UInt32 a_index, UInt8 a_keySize) const;

	protected:
		// members
		float	_time;	// 00
	};
	STATIC_ASSERT(sizeof(NiAnimationKey) == 0x4);
}
