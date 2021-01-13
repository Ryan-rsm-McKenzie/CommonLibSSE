#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSHeadPart;
	class BSFaceGenNiNode;
	class TESNPC;

	class FaceGen : public BSTSingletonSDM<FaceGen>
	{
	public:
		struct Action
		{
			BSFixedString name;
			std::uint32_t unk04;
			float		  delta;
		};

		class MorphDatabase
		{
		public:
			std::uint64_t			unk00;	   // 00
			std::uint32_t			unk08;	   // 08
			std::uint32_t			unk0C;	   // 0C
			std::uint32_t			unk10;	   // 10
			std::uint32_t			unk14;	   // 14
			void*					unk18;	   // 18
			std::uint64_t			unk20;	   // 20
			std::uint64_t			unk28;	   // 28
			mutable BSReadWriteLock lock;	   // 30
			std::uint8_t			unk38;	   // 38
			std::uint8_t			pad39[7];  // 39
		};

		static FaceGen* GetSingleton();

		void RegenerateHead(BSFaceGenNiNode* a_headNode, BGSHeadPart* a_head, TESNPC* a_npc);

		// members
		std::uint32_t numActorsAllowedToMorph;	// 04
		bool		  facialEmotions;			// 08
		std::uint8_t  pad09[7];					// 09
		std::uint64_t unk10;					// 10
		MorphDatabase morphDatabase;			// 18
		std::uint8_t  isReset;					// 58
		std::uint8_t  pad59[3];					// 59
		std::uint32_t unk5C;					// 5C
		std::uint8_t  unk60;					// 60
		std::uint8_t  pad61[7];					// 61
	};
	static_assert(sizeof(FaceGen) == 0x68);
};
