#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap


namespace RE
{
	class BGSStaticCollection :
		public TESBoundObject,		// 00
		public TESModelTextureSwap	// 30
	{
	public:
		enum { kTypeID = FormType::StaticCollection };


		struct LocalFlags
		{
			enum LocalFlag : UInt32
			{};
		};


		virtual ~BGSStaticCollection();						// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13
	};
	STATIC_ASSERT(sizeof(BGSStaticCollection) == 0x68);
}
