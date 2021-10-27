#pragma once

#include "RE/G/GFxLoaderTask.h"

namespace RE
{
	class GFxMovieImageLoadTask : public GFxLoaderTask
	{
	public:
		~GFxMovieImageLoadTask() override;  // 00

		// members
		void*         unk20;  // 20
		void*         unk28;  // 28
		void*         unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
	};
	static_assert(sizeof(GFxMovieImageLoadTask) == 0x48);
}
