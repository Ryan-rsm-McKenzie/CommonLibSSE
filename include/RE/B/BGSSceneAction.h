#pragma once

namespace RE
{
	class BGSLoadGameBuffer;
	class TESFile;

	class BGSSceneAction
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSceneAction;

		enum class Type
		{
			kDialogue = 0,
			kPackage = 1,
			kTimer = 2
		};

		enum class EmotionType
		{
			kNeutral = 0,
			kAnger = 1,
			kDisgust = 2,
			kFear = 3,
			kSad = 4,
			kHappy = 5,
			kSurprise = 6,
			kPuzzled = 7,
		};

		enum class Flag
		{
			kNone = 0,
			kFaceTarget = 1 << 15,
			kLooping = 1 << 16,
			kHeadTrackPlayer = 1 << 17
		};

		virtual ~BGSSceneAction();  // 00

		// add
		virtual bool          LoadSceneAction(TESFile* a_mod);                     // 01
		virtual void          Unk_02();                                        // 02
		virtual void          Unk_03();                                        // 03 - { return; }
		virtual void          ClearFlags();                                        // 04 - { flags = kNone; }
		virtual bool          Loops() const;                                       // 05 - { return false; }
		virtual bool          FacesTarget() const;                                 // 06 - { return true; }
		virtual Type          GetType() const = 0;                                 // 07
		virtual void          Unk_08();                                        // 08 - { return 0; }
		virtual void          LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf);  // 09
		virtual void          Unk_0A();                                        // 0A
		virtual void          Unk_0B();                                        // 0B - { unk14 &= 0xFC; }
		virtual void          Unk_0C();                                        // 0C - { return; }
		virtual void          Unk_0D();                                        // 0D
		virtual EmotionType   GetEmotionType() const;                              // 0E - { return kNeutral; }
		virtual std::uint32_t GetEmotionValue() const;                             // 0F - { return 0; }
		virtual void          Unk_10();                                        // 10 - { unk14 |= 1; }
		virtual void          Unk_11();                                        // 11
		virtual void          Unk_12();                                        // 12 - { return; }
		virtual void          Unk_13();                                        // 13 - { return; }

		// members
		std::uint32_t                         actorID;     // 08 - ALID
		std::uint16_t                         startPhase;  // 0C - SNAM
		std::uint16_t                         endPhase;    // 0E - ENAM
		stl::enumeration<Flag, std::uint32_t> flags;       // 10
		std::uint8_t                          unk14;       // 14
		std::uint8_t                          unk15;       // 15
		std::uint16_t                         unk16;       // 16
		std::uint32_t                         index;       // 18 - INAM
		std::uint32_t                         unk1C;       // 1C
	};
	static_assert(sizeof(BGSSceneAction) == 0x20);
}
