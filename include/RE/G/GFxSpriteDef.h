#pragma once

#include "RE/G/GArrayLH.h"
#include "RE/G/GFxTimelineDef.h"
#include "RE/G/GStringHash.h"

namespace RE
{
	class GFxCharacter;
	class GFxMovieDataDef;

	class GFxTimelineIODef : public GFxTimelineDef
	{
	public:
		// add
		virtual void SetLoadingExecuteTagList(ExecuteTagList* a_data) = 0;  // 0E
		virtual void AddFrameName(GString* a_name, GFxLog* a_log) = 0;      // 0F
	};
	static_assert(sizeof(GFxTimelineIODef) == 0x20);

	class GFxSpriteDef : public GFxTimelineIODef
	{
	public:
		~GFxSpriteDef() override;  // 00

		// override (GFxResource)
		std::uint32_t GetResourceTypeCode() const override;  // 02

		// override (GFxCharacterDef)
		bool          Unk_05(const GPointF& a_pt, bool a_arg2, void* a_arg3) override;  // 05
		std::uint32_t GetVersion() override;                                            // 08
		GFxCharacter* CreateCharacter() override;                                       // 09

		// override (GFxTimelineDef)
		std::uint32_t   GetFrameCount() override;                                                                          // 0A
		ExecuteTagList* GetMovieTagArray(ExecuteTagList& a_data, std::int32_t a_frameNumber) override;                     // 0B
		ExecuteTagList* GetImportTagArray(ExecuteTagList& a_data, std::int32_t a_frameNumber) override;                    // 0C - { return nullptr; }
		bool            GetLabeledFrame(const char* a_label, std::int32_t& a_frameNumber, bool a_labelIsNumber) override;  // 0D

		// override (GFxTimelineIODef)
		void SetLoadingExecuteTagList(ExecuteTagList* a_data) override;  // 0E
		void AddFrameName(GString* a_name, GFxLog* a_log) override;      // 0F

		// add
		virtual float            GetWidth();                   // 10 - { return 1.0f; }
		virtual float            GetHeight();                  // 11 - { return 1.0f; }
		virtual GFxMovieDataDef* GetMovieData();               // 12
		virtual void             GetBounds(GRectF& a_bounds);  // 13
		virtual std::int32_t     GetLoadingFrame();            // 14
		virtual std::uint32_t    GetSWFFlags();                // 15
		virtual void*            Unk_16();                     // 16 - { return nullptr; }
		virtual void             Unk_17();                     // 17
		virtual const char*      GetFileURL();                 // 18

		// members
		GFxMovieDataDef*          movieData;     // 20
		GStringHash<std::int32_t> frameLabels;   // 28
		std::int32_t              frameCount;    // 30
		std::int32_t              frameLoading;  // 34
		GArrayLH<ExecuteTagList>  frames;        // 38
		void*                     unk50;         // 50
		std::uint8_t              buttonState;   // 58 - 0x1 = up, 0x2 = down, 0x4 = over
		std::uint8_t              pad59;         // 59
		std::uint16_t             pad5A;         // 5A
		std::uint32_t             pad5C;         // 5C
	};
	static_assert(sizeof(GFxSpriteDef) == 0x60);
}
