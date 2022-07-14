#pragma once

#include "RE/B/BSIMusicTrack.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSMusicTrack;

	class BGSMusicTrackFormWrapper :
		public TESForm,       // 00
		public BSIMusicTrack  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicTrackFormWrapper;
		inline static constexpr auto VTABLE = VTABLE_BGSMusicTrackFormWrapper;
		inline static constexpr auto FORMTYPE = FormType::MusicTrack;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSMusicTrackFormWrapper() override;  // 00

		// override (TESForm)
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// override (BSIMusicTrack)
		void         DoUpdate() override;                                    // 01
		void         DoPlay() override;                                      // 02
		void         DoPause() override;                                     // 03
		void         DoFinish(bool a_arg1, float a_arg2) override;           // 04
		float        GetDurationImpl() const override;                       // 05
		TrackType    GetType() const override;                               // 06
		bool         TestCanPlay() const override;                           // 07
		MUSIC_STATUS GetMusicStatus() const override;                        // 08
		void         DoSetDuckingAttenuation(std::uint16_t a_val) override;  // 09
		void         DoClearDucking() override;                              // 0A

		// members
		BGSMusicTrack* track;  // 30
	};
	static_assert(sizeof(BGSMusicTrackFormWrapper) == 0x38);
}
