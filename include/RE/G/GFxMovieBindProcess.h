#pragma once

#include "RE/G/GFxLoaderTask.h"
#include "RE/G/GFxMovieDefImpl.h"

namespace RE
{
	class GFxImagePacker;
	class GFxMovieDataDef;

	class GFxMovieBindProcess : public GFxLoaderTask
	{
	public:
		using BindTaskData = GFxMovieDefImpl::BindTaskData;

		class ImagePackVisitor : public GFxMovieDef::ResourceVisitor
		{
		public:
			void Visit(GFxMovieDef* a_movieDef, GFxResource* a_resource, GFxResourceID a_id, const char* a_exportName) override;  // 01

			// members
			GFxImagePacker* imagePacker;
		};
		static_assert(sizeof(ImagePackVisitor) == 0x10);

		// members
		std::uint64_t    unk20;           // 20
		std::uint32_t    unk28;           // 28
		std::uint32_t    pad2C;           // 2C
		GFxImagePacker*  imagePacker;     // 30
		BindTaskData*    bindTaskData;    // 38
		GFxMovieDataDef* movieData;       // 40
		bool             stripped;        // 48
		std::uint8_t     pad49;           // 49
		std::uint16_t    pad4A;           // 4A
		std::uint32_t    pad4C;           // 4C
		GFxMovieDef*     importingMovie;  // 50
		void*            unk58;           // 58
	};
	static_assert(sizeof(GFxMovieBindProcess) == 0x60);
}
