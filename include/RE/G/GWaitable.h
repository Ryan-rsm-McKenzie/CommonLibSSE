#pragma once

#include "RE/G/GArray.h"
#include "RE/G/GArrayConstPolicy.h"
#include "RE/G/GAtomic.h"
#include "RE/G/GNewOverrideBase.h"
#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GWaitable : public GRefCountBase<GWaitable, GStatGroups::kGStat_Default_Mem>
	{
	public:
		using WaitHandler = void (*)(void* a_data);

		class HandlerStruct
		{
		public:
			// members
			WaitHandler handler;
			void*       userData;
		};

		struct HandlerArray : public GNewOverrideBase<GStatGroups::kGStat_Default_Mem>
		{
			using SizePolicyType = GArrayConstPolicy<0, 16, true>;
			using HandlerArrayType = GArray<HandlerStruct, GStatGroups::kGStat_Default_Mem, SizePolicyType>;

			// members
			GAtomicInt<std::int32_t> refCount;
			HandlerArrayType         handlers;
			GLock                    handlersLock;
		};

		~GWaitable() override;

		HandlerArray* handlers;
	};
	static_assert(sizeof(GWaitable) == 0x18);
}
