#pragma once

namespace RE
{
	class GRefCountImplCore
	{
	public:
		inline static constexpr auto RTTI = RTTI_GRefCountImplCore;

		virtual ~GRefCountImplCore() = default;  // 00

		static void CheckInvalidDelete(GRefCountImplCore*) {}

		[[nodiscard]] constexpr std::uint32_t GetRefCount() const noexcept { return _refCount; }

	protected:
		// members
		volatile std::uint32_t _refCount{ 1 };  // 08
		std::uint32_t          _pad0C{ 0 };     // 0C
	};
	static_assert(sizeof(GRefCountImplCore) == 0x10);
}
