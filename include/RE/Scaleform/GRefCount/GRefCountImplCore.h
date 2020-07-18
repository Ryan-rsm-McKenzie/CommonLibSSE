#pragma once


namespace RE
{
	class GRefCountImplCore
	{
	public:
		inline static constexpr auto RTTI = RTTI_GRefCountImplCore;


		GRefCountImplCore();
		virtual ~GRefCountImplCore() = default;	 // 00

		static void CheckInvalidDelete(GRefCountImplCore*);

		std::int32_t GetRefCount() const;

	protected:
		// members
		volatile std::uint32_t _refCount;  // 08
		std::uint32_t		   _pad0C;	   // 0C
	};
	static_assert(sizeof(GRefCountImplCore) == 0x10);
}
