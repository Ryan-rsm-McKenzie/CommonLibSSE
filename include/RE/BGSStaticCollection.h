#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESModelTextureSwap.h"


namespace RE
{
	class BGSStaticCollection :
		public TESBoundObject,		// 00
		public TESModelTextureSwap	// 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStaticCollection;
		inline static constexpr auto FORMTYPE = FormType::StaticCollection;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
			};
		};


		virtual ~BGSStaticCollection();	 // 00

		// override (TESBoundObject)
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13
	};
	STATIC_ASSERT(sizeof(BGSStaticCollection) == 0x68);
}
