#pragma once

#include "RE/BGSIdleCollection.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESModel.h"


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


		virtual ~BGSIdleMarker();								// 00

		// override (TESBoundObject)
		virtual bool	Load(TESFile* a_mod) override;			// 06
		virtual void	InitItemImpl() override;				// 13
		virtual bool	GetIgnoredBySandbox() const override;	// 22 - { return (BGSIdleCollection::flags >> 4) & 1; }
		virtual void	Unk_41(void) override;					// 41
		virtual void	Unk_4A(void) override;					// 4A - returns BSFadeNode*
	};
	STATIC_ASSERT(sizeof(BGSIdleMarker) == 0x78);
}
