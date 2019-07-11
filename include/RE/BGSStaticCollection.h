#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSStaticCollection

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
		inline static const void* RTTI = RTTI_BGSStaticCollection;


		enum { kTypeID = FormType::StaticCollection };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BGSStaticCollection();						// 00

		// override (TESBoundObject)
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13
	};
	STATIC_ASSERT(sizeof(BGSStaticCollection) == 0x68);
}
