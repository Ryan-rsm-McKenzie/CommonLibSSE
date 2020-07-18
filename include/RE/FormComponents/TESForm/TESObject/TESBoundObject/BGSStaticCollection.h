#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESModel/TESModelTextureSwap.h"


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
