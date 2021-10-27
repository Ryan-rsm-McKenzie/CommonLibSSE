#pragma once

#include "RE/G/GFxLoaderTask.h"
#include "RE/G/GFxLogBase.h"
#include "RE/G/GFxMovieDataDef.h"
#include "RE/G/GFxStream.h"

namespace RE
{
	class GASExecuteTag;
	class GFxMovieBindProcess;
	class GFxSpriteDef;

	class GFxLoadProcess :
		public GFxLoaderTask,              // 00
		public GFxLogBase<GFxLoadProcess>  // 20
	{
	public:
		using LoadTaskData = GFxMovieDataDef::LoadTaskData;

		virtual ~GFxLoadProcess();  // 00

		struct TimelineType
		{
			enum
			{
				kMovie,
				kSprite,

				kTotal
			};
		};

		// members
		std::uint32_t          parseFlags;                              // 028
		std::uint32_t          pad02C;                                  // 02C
		GFxMovieBindProcess*   movieBindProcess;                        // 030
		LoadTaskData*          loadTaskData;                            // 038
		GFxMovieDataDef*       movieData;                               // 040
		GFxStream              stream;                                  // 048
		std::uint32_t          unk2B8;                                  // 2B8
		std::uint32_t          endOfFile;                               // 2BC
		std::uint64_t          pad2C0;                                  // 2C0
		GFxMovieLoadInfo       movieInfo;                               // 2C8
		std::uint64_t          unk338;                                  // 338
		std::uint32_t          unk340;                                  // 340
		std::uint32_t          numImportedMovies;                       // 344
		std::uint64_t          unk348;                                  // 348
		std::uint32_t          importInfoCount;                         // 350
		std::uint32_t          pad354;                                  // 354
		std::uint32_t          unk358;                                  // 358
		std::uint32_t          pad35C;                                  // 35C
		std::uint64_t          unk360;                                  // 360
		GFxImportNode*         importInfo;                              // 368
		std::uint64_t          unk370;                                  // 370
		std::uint64_t          unk378;                                  // 378
		std::uint64_t          unk380;                                  // 380
		std::uint64_t          unk388;                                  // 388
		std::int32_t           timelineType;                            // 390
		std::uint32_t          pad394;                                  // 394
		GFxSpriteDef*          loadingSprite;                           // 398
		GArray<GASExecuteTag*> loadingFrameData[TimelineType::kTotal];  // 3A0
		GArray<GASExecuteTag*> importActions;                           // 3D0
		GFxStream*             streamEx;                                // 3E8
	};
	static_assert(sizeof(GFxLoadProcess) == 0x3F0);
}
