#pragma once


namespace RE
{
	class hkStringPtr
	{
	public:
		// member types
		using size_type = SInt32;


		// members access
		const char* data() const noexcept;
		const char* c_str() const noexcept;

		// capacity
		[[nodiscard]] bool empty() const noexcept;
		size_type size() const noexcept;
		size_type length() const noexcept;

	protected:
		enum { kManaged = 1 << 0 };


		const char* _data;	// 0
	};
	STATIC_ASSERT(sizeof(hkStringPtr) == 0x8);
}
