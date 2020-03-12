#pragma once


namespace RE
{
	class BSIMusicTrack
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSIMusicTrack;


		enum class TrackType : UInt32
		{
			kSilentTrack = 0xA1A9C4D5,
			kSingleTrack = 0x6ED7E048,
			kPalette = 0x23F678C3
		};


		enum class MUSIC_STATUS : UInt32
		{
			kInactive = 0,
			kPlaying = 1,
			kPaused = 2,
			kFinishing = 3,
			kFinished = 4
		};


		virtual ~BSIMusicTrack();  // 00

		// add
		virtual void		 DoUpdate() = 0;						   // 01
		virtual void		 DoPlay() = 0;							   // 02
		virtual void		 DoPause() = 0;							   // 03
		virtual void		 DoFinish(bool a_arg1, float a_arg2) = 0;  // 04
		virtual float		 GetDurationImpl() const = 0;			   // 05
		virtual TrackType	 GetType() const = 0;					   // 06 - CRC32 hash of class name
		virtual bool		 TestCanPlay() const;					   // 07 - { return true; }
		virtual MUSIC_STATUS GetMusicStatus() const;				   // 08 - { return trackStatus; }
		virtual void		 DoSetDuckingAttenuation(UInt16 a_val);	   // 09 - { return; }
		virtual void		 DoClearDucking();						   // 0A - { return; }


		// members
		MUSIC_STATUS trackStatus;  // 08
		UInt32		 pad0C;		   // 0C
	};
	STATIC_ASSERT(sizeof(BSIMusicTrack) == 0x10);
}
