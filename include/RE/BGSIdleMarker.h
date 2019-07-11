#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSIdleMarker

#include "RE/BGSIdleCollection.h"  // BGSIdleCollection
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSIdleMarker :
		public TESBoundObject,		// 00
		public TESModel,			// 30
		public BGSIdleCollection	// 58
	{
	public:
		inline static const void* RTTI = RTTI_BGSIdleMarker;


		enum { kTypeID = FormType::IdleMarker };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kChildCanUse = 1 << 29
			};
		};


		virtual ~BGSIdleMarker();							// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13
		virtual bool	IgnoredBySandbox() const override;	// 22 - { return (BGSIdleCollection::flags >> 4) & 1; }
		virtual void	Unk_41(void) override;				// 41
		virtual void	Unk_4A(void) override;				// 4A - returns BSFadeNode*
	};
	STATIC_ASSERT(sizeof(BGSIdleMarker) == 0x78);
}
