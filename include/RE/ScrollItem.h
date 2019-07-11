#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ScrollItem

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/SpellItem.h"  // SpellItem
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESValueForm.h"  // TESValueForm
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class ScrollItem :
		public SpellItem,					// 000
		public TESModelTextureSwap,			// 0E8
		public BGSDestructibleObjectForm,	// 120
		public BGSPickupPutdownSounds,		// 130
		public TESWeightForm,				// 148
		public TESValueForm					// 158
	{
	public:
		inline static const void* RTTI = RTTI_ScrollItem;


		enum { kTypeID = FormType::Scroll };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~ScrollItem();														// 00

		// override (SpellItem)
		virtual void		InitItem() override;									// 13
		virtual MagicType	GetMagicType() const override;							// 53 - { return MagicType::kScroll; }
		virtual CastType	GetCastType() const override;							// 55 - { return CastType::kFireAndForget; }
		virtual void		Unk_60(void) override;									// 60 - { return 0; }
		virtual ActorValue	GetActorValueType() const override;						// 66 - { return ActorValue::kNone; }
		virtual void		LoadData(TESFile* a_mod, UInt32 a_signature) override;	// 6A
	};
	STATIC_ASSERT(sizeof(ScrollItem) == 0x168);
}
