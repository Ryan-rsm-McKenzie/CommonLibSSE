#pragma once

#undef LoadIcon

#include "skse64/GameRTTI.h"  // RTTI_TESRegionDataLandscape

#include "RE/TESRegionData.h"  // TESRegionData


namespace RE
{
	class BSString;
	class TESFile;
	class TESTexture;


	class TESRegionDataLandscape : public TESRegionData
	{
	public:
		inline static const void* RTTI = RTTI_TESRegionDataLandscape;


		enum { kTypeID = Type::kLand };


		virtual ~TESRegionDataLandscape();										// 00

		// override (TESRegionData)
		virtual Type	GetType() const override;								// 03 - { return Type::kLand; }
		virtual void	ConstructSelf() override;								// 04
		virtual void	Unk_05(void) override;									// 05
		virtual void	CopyFrom(TESRegionData* a_src, bool a_copy) override;	// 06
		virtual bool	IsLoaded() const override;								// 07

		// add
		virtual bool	LoadIcon(TESFile* a_mod);								// 08
		virtual void	GetIconFileName(BSString* a_dst);						// 09
		virtual bool	SetIconFileName(BSString* a_name);						// 0A


		// members
		TESTexture* icon;	// 10
	};
	STATIC_ASSERT(sizeof(TESRegionDataLandscape) == 0x18);
}
