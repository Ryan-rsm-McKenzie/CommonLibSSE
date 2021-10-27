#pragma once

#include "RE/G/GEvent.h"
#include "RE/G/GFxResourceKey.h"
#include "RE/G/GHashSet.h"
#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"
#include "RE/G/GString.h"

namespace RE
{
	class GFxResource;
	class GFxResourceWeakLib;

	class GFxResourceLib : public GRefCountBase<GFxResourceLib, GStatGroups::kGStat_Default_Mem>
	{
	public:
		class ResourceSlot : public GRefCountBase<ResourceSlot, GStatGroups::kGStat_Default_Mem>
		{
		public:
			enum class ResolveState
			{
				kInProgress,
				kSuccess,
				kFail,
			};

			const GFxResourceKey& GetKey() const
			{
				return key;
			}

			// members
			GPtr<GFxResourceWeakLib> lib;    // 10
			volatile ResolveState    state;  // 18
			std::uint32_t            pad1C;  // 1C
			GFxResource* volatile resource;  // 20
			GFxResourceKey key;              // 28
			GString        errorMessage;     // 38
			GEvent         resolveComplete;  // 40
		};
		static_assert(sizeof(ResourceSlot) == 0x98);

		struct GFxResourcePtrHashFunc
		{
			UPInt operator()(const GFxResource*& a_data) const
			{
				return (((UPInt)a_data) >> 6) ^ ((UPInt)a_data);
			}
		};
		using PinHashSet = GHashSet<GFxResource*, GFxResourcePtrHashFunc>;

		// members
		GFxResourceWeakLib* weakLib;    // 10
		PinHashSet          pinSet;     // 18
		bool                debugFlag;  // 20
		std::uint8_t        pad21;      // 21
		std::uint16_t       pad22;      // 22
		std::uint32_t       pad24;      // 24
	};
	static_assert(sizeof(GFxResourceLib) == 0x28);
}
