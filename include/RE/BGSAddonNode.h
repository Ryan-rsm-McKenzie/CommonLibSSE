#pragma once

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
		enum { kTypeID = FormType::AddonNode };


		virtual ~BGSAddonNode();							// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		UInt32	nodeIndex;	// 68 - DATA
		UInt32	unk6C;		// 6C
		UInt64	unk70;		// 70
		UInt8	unk78[4];	// 78
		UInt32	unk7C;		// 7C
	};
	STATIC_ASSERT(offsetof(BGSAddonNode, nodeIndex) == 0x68);
	STATIC_ASSERT(sizeof(BGSAddonNode) == 0x80);
}
