#pragma once

#include "RE/BSIMusicTrack.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSMusicTrack;


	class BGSMusicTrackFormWrapper :
		public TESForm,		  // 00
		public BSIMusicTrack  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicTrackFormWrapper;
		inline static constexpr auto FORMTYPE = FormType::MusicTrack;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMusicTrackFormWrapper();  // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		// override (BSIMusicTrack)
		virtual void		 DoUpdate() override;							  // 01
		virtual void		 DoPlay() override;								  // 02
		virtual void		 DoPause() override;							  // 03
		virtual void		 DoFinish(bool a_arg1, float a_arg2) override;	  // 04
		virtual float		 GetDurationImpl() const override;				  // 05
		virtual TrackType	 GetType() const override;						  // 06
		virtual bool		 TestCanPlay() const override;					  // 07
		virtual MUSIC_STATUS GetMusicStatus() const override;				  // 08
		virtual void		 DoSetDuckingAttenuation(UInt16 a_val) override;  // 09
		virtual void		 DoClearDucking() override;						  // 0A


		// members
		BGSMusicTrack* track;  // 30
	};
	STATIC_ASSERT(sizeof(BGSMusicTrackFormWrapper) == 0x38);
}
