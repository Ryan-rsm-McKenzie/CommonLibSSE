#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESKey

#include "RE/FormTypes.h"  // FormType
#include "RE/TESObjectMISC.h"  // TESObjectMISC


namespace RE
{
	class TESKey : public TESObjectMISC
	{
	public:
		inline static const void* RTTI = RTTI_TESKey;


		enum { kTypeID = FormType::KeyMaster };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESKey();	// 00

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() override;	// 05 - { return BGSDefaultObjectManager::GetSingleton()->objects[192]; } - this index is a nullptr
	};
	STATIC_ASSERT(sizeof(TESKey) == 0x100);
}
