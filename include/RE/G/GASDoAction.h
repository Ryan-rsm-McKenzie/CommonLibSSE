#pragma once

#include "RE/G/GASExecuteTag.h"

namespace RE
{
	class GASActionBufferData :
		public GRefCountBase<GASActionBufferData, GFxStatMovieData::kGFxStatMD_ActionOps_Mem>
	{
	public:
		~GASActionBufferData() override;  // 00

		// members
		void*         buffer;  // 10
		std::uint64_t size;    // 18
		std::uint64_t unk20;   // 20
	};
	static_assert(sizeof(GASActionBufferData) == 0x28);

	class GASDoAction : public GASExecuteTag
	{
	public:
		~GASDoAction() override;  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;                       // 01
		void Execute2(GFxSprite* a_sprite, std::int32_t a_arg2) override;  // 02
		bool Unk_04() override;                                            // 04 - { return 1; }

		// members
		GPtr<GASActionBufferData> data;  // 08
	};
	static_assert(sizeof(GASDoAction) == 0x10);
}
