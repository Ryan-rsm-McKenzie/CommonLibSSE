#pragma once


namespace RE
{
	using hkObjectIndex = UInt16;
	using hkTime = float;


	enum class hkResult : UInt32
	{
		kSuccess = 0,
		kFailure = 1
	};


	// 16-bit float with 7-bit precision
	class hkHalf
	{
	public:
		hkHalf();
		explicit hkHalf(const float& a_val);

		hkHalf& operator=(const float& a_val);
		operator float() const;

	protected:
		void SetFloat(const float& a_val);
		float GetFloat() const;

		SInt16 _value;	// 0
	};
	STATIC_ASSERT(sizeof(hkHalf) == 0x2);


	// 8-bit float ranging [0.01, 1000000.0]
	// value is an index in a lookup table
	class hkUFloat8
	{
	public:
		UInt8 value;	// 0
	};
	STATIC_ASSERT(sizeof(hkUFloat8) == 0x1);
}
