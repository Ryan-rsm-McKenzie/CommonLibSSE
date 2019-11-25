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
