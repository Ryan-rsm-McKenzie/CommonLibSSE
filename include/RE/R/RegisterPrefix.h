#pragma once

#include "RE/L/LocationTraverser.h"

namespace RE
{
	namespace BSResource
	{
		class Location;

		//void RegisterPrefix(const char*, const char*, Location*)
		//{
		class Traverser : public LocationTraverser
		{
		public:
			inline static constexpr auto RTTI = RTTI__void___cdecl_BSResource__RegisterPrefix_char_const_____ptr64_char_const_____ptr64_BSResource__Location_____ptr64_____2___Traverser;

			// override (LocationTraverser)
			virtual void ProcessName(const char* a_name, Location& a_location) override;  // 00

			// add
			virtual ~Traverser();  // 01

			// members
			std::uint64_t unk08;  // 08
			std::uint64_t unk10;  // 10
			std::uint64_t unk18;  // 18
			std::uint64_t unk20;  // 20
			std::uint64_t unk28;  // 28
			std::uint64_t unk30;  // 30
			std::uint64_t unk38;  // 38
			std::uint64_t unk40;  // 40
			std::uint64_t unk48;  // 48
			std::uint64_t unk50;  // 50
			std::uint64_t unk58;  // 58
			std::uint64_t unk60;  // 60
			std::uint64_t unk68;  // 68
			std::uint64_t unk70;  // 70
			std::uint64_t unk78;  // 78
			std::uint64_t unk80;  // 80
			std::uint64_t unk88;  // 88
			std::uint64_t unk90;  // 90
			std::uint64_t unk98;  // 98
			std::uint64_t unkA0;  // A0
			std::uint64_t unkA8;  // A8
			std::uint64_t unkB0;  // B0
			std::uint64_t unkB8;  // B8
			std::uint64_t unkC0;  // C0
			std::uint64_t unkC8;  // C8
			std::uint64_t unkD0;  // D0
			std::uint64_t unkD8;  // D8
			std::uint64_t unkE0;  // E0
			std::uint64_t unkE8;  // E8
		};
		static_assert(sizeof(Traverser) == 0xF0);
		//}
	}
}
