#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSAddonNode

#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap


namespace RE
{
	class BGSAddonNode :
		public TESBoundObject,		// 00
		public TESModelTextureSwap  // 30
	{
	public:
		inline static const void* RTTI = RTTI_BGSAddonNode;


		enum { kTypeID = FormType::AddonNode };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DNAM
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kAlwaysLoaded = 3
			};


			UInt16	masterParticleSystemCap;	// 0
			Flag	flags;						// 2
			UInt8	unk3;						// 3
			UInt32	unk4;						// 4
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		virtual ~BGSAddonNode();							// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		UInt32					nodeIndex;	// 68 - DATA
		UInt32					pad6C;		// 6C
		BGSSoundDescriptorForm*	sound;		// 70 - SNAM
		Data					data;		// 78 - DNAM
	};
	STATIC_ASSERT(sizeof(BGSAddonNode) == 0x80);
}
