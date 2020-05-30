#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESModelTextureSwap.h"


namespace RE
{
	struct ADDON_DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kAlwaysLoaded = 3
		};


		UInt16 masterParticleCap;  // 0
		Flag   flags;			   // 2
		UInt8  pad3;			   // 3
	};
	STATIC_ASSERT(sizeof(ADDON_DATA) == 0x4);


	class BGSAddonNode :
		public TESBoundObject,		// 00
		public TESModelTextureSwap	// 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAddonNode;
		inline static constexpr auto FORMTYPE = FormType::AddonNode;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSAddonNode();  // 00

		// override (TESBoundObject)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		UInt32					index;	// 68 - DATA
		UInt32					pad6C;	// 6C
		BGSSoundDescriptorForm* sound;	// 70 - SNAM
		ADDON_DATA				data;	// 78 - DNAM
		UInt32					pad7C;	// 7C
	};
	STATIC_ASSERT(sizeof(BGSAddonNode) == 0x80);
}
