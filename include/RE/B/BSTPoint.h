#pragma once

namespace RE
{
	template <class T>
	class BSTPointDefaultOps
	{
	public:
	};
	static_assert(sizeof(BSTPointDefaultOps<float>) == 0x1);

	template <class T>
	class BSTPoint2Base
	{
	public:
		// members
		T x;  // 00
		T y;  // ??
	};
	static_assert(sizeof(BSTPoint2Base<float>) == 0x8);

	template <class T, class Ops = BSTPointDefaultOps<T>>
	class BSTPoint2 :
		public BSTPoint2Base<T>,  // 00
		public Ops                // ??
	{
	public:
	};
	static_assert(sizeof(BSTPoint2<float>) == 0x8);

	template <class T>
	class BSTPoint3Base
	{
	public:
		// members
		T x;  // 00
		T y;  // ??
		T z;  // ??
	};
	static_assert(sizeof(BSTPoint3Base<float>) == 0xC);

	template <class T, class Ops = BSTPointDefaultOps<T>>
	class BSTPoint3 :
		public BSTPoint3Base<T>,  // 00
		public Ops                // ??
	{
	public:
	};
	static_assert(sizeof(BSTPoint3<float>) == 0xC);
}
