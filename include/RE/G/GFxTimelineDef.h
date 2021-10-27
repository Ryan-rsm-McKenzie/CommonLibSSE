#pragma once

#include "RE/G/GFxCharacterDef.h"

namespace RE
{
	class GASExecuteTag;

	class GFxTimelineDef : public GFxCharacterDef
	{
	public:
		struct ExecuteTagList
		{
			GASExecuteTag** data;  // 00
			std::uint32_t   size;  // 08
		};

		// add
		virtual std::uint32_t   GetFrameCount() = 0;                                                                          // 0A
		virtual ExecuteTagList* GetMovieTagArray(ExecuteTagList& a_data, std::int32_t a_frameNumber) = 0;                     // 0B
		virtual ExecuteTagList* GetImportTagArray(ExecuteTagList& a_data, std::int32_t a_frameNumber) = 0;                    // 0C
		virtual bool            GetLabeledFrame(const char* a_label, std::int32_t& a_frameNumber, bool a_labelIsNumber) = 0;  // 0D
	};
	static_assert(sizeof(GFxTimelineDef) == 0x20);
}
