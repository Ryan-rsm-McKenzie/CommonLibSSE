#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESModelTextureSwap.h"

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
			enum RecordFlag : std::uint32_t
			{
			};
		};

		virtual ~BGSStaticCollection();	 // 00

		// override (TESBoundObject)
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13
	};
	static_assert(sizeof(BGSStaticCollection) == 0x68);
}
