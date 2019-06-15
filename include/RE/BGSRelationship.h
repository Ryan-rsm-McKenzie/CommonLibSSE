#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSRelationship

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSRelationship : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSRelationship;


		enum { kTypeID = FormType::Relationship };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kSecret = 1 << 6,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class Rank : UInt8
			{
				kLover = 0,
				kAlly = 1,
				kConfidant = 2,
				kFriend = 3,
				kAcquaintance = 4,
				kRival = 5,
				kFoe = 6,
				kEnemy = 7,
				kArchnemesis = 8
			};


			enum class Flag : UInt8
			{
				kNone = 0,
				kSecret = 1 << 7
			};


			TESNPC*				parent;				// 00
			TESNPC*				child;				// 08
			BGSAssociationType*	associationType;	// 10
			Rank				rank;				// 18
			UInt8				unk19;				// 19
			UInt8				unk1A;				// 1A
			Flag				flags;				// 1B
			UInt32				pad1C;				// 1C
		};
		STATIC_ASSERT(sizeof(Data) == 0x20);


		virtual ~BGSRelationship();										// 00

		// override (TESForm)
		virtual void	InitDefaults() override;						// 04
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_10(void) override;							// 10
		virtual void	InitItem() override;							// 13


		// members
		Data data;	// 20 - DATA
	};
	STATIC_ASSERT(sizeof(BGSRelationship) == 0x40);
}
