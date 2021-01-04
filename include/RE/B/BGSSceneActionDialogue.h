#pragma once

#include "RE/B/BGSSceneAction.h"

namespace RE
{
	class TESTopic;

	class BGSSceneActionDialogue : public BGSSceneAction
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSceneActionDialogue;
		inline static constexpr auto TYPE = Type::kDialogue;

		virtual ~BGSSceneActionDialogue();	// 00

		// override (BGSSceneAction)
		virtual bool		  LoadSceneAction(TESFile* a_mod) override;						// 01
		virtual void		  Unk_02(void) override;										// 02
		virtual void		  Unk_03(void) override;										// 03
		virtual bool		  Loops() const override;										// 05 - { return (flags >> 16) & 1; }
		virtual bool		  FacesTarget() const override;									// 06 - { return (flags >> 15) & 1; }
		virtual Type		  GetType() const override;										// 07 - { return kDialogue; }
		virtual void		  LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf) override;	// 09
		virtual void		  Unk_0A(void) override;										// 0A
		virtual void		  Unk_0B(void) override;										// 0B
		virtual void		  Unk_0C(void) override;										// 0C
		virtual EmotionType	  GetEmotionType() const override;								// 0E - { return emotionType; }
		virtual std::uint32_t GetEmotionValue() const override;								// 0F - { return emotionValue; }
		virtual void		  Unk_10(void) override;										// 10
		virtual void		  Unk_11(void) override;										// 11
		virtual void		  Unk_13(void) override;										// 13

		// members
		TESTopic*	  topic;			 // 20 - DATA
		std::int32_t  headtrackActorID;	 // 28 - HTID
		float		  loopingMax;		 // 2C - DMAX
		float		  loopingMin;		 // 30 - DMIN
		std::uint32_t unk34;			 // 34
		EmotionType	  emotionType;		 // 38 - DEMO
		std::uint32_t emotionValue;		 // 3C - DEMA
	};
	static_assert(sizeof(BGSSceneActionDialogue) == 0x40);
}
