#pragma once

#include "RE/B/BSString.h"
#include "RE/T/TESRegionData.h"

namespace RE
{
	class TESFile;
	class TESTexture;

	class TESRegionDataLandscape : public TESRegionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRegionDataLandscape;
		inline static constexpr auto TYPE = Type::kLand;

		virtual ~TESRegionDataLandscape();	// 00

		// override (TESRegionData)
		virtual Type GetType() const override;								// 03 - { return Type::kLand; }
		virtual void ConstructSelf() override;								// 04
		virtual void Unk_05(void) override;									// 05
		virtual void CopyFrom(TESRegionData* a_src, bool a_copy) override;	// 06
		virtual bool IsLoaded() const override;								// 07

		// add
		virtual bool LoadIcon(TESFile* a_mod);			 // 08
		virtual void GetIconFileName(BSString* a_dst);	 // 09
		virtual bool SetIconFileName(BSString* a_name);	 // 0A

		// members
		TESTexture* icon;  // 10
	};
	static_assert(sizeof(TESRegionDataLandscape) == 0x18);
}
