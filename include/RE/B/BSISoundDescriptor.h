#pragma once

namespace RE
{
	class BSISoundDescriptor
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSISoundDescriptor;

		class BSIPlaybackCharacteristics
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSISoundDescriptor__BSIPlaybackCharacteristics;

			virtual ~BSIPlaybackCharacteristics();  // 00

			// add
			virtual std::uint8_t  GetFrequencyShift() = 0;     // 01
			virtual std::uint8_t  GetFrequencyVariance() = 0;  // 02
			virtual std::uint8_t  GetPriority() = 0;           // 03
			virtual std::uint16_t GetStaticAttenuation() = 0;  // 04
			virtual std::uint8_t  GetDBVariance() = 0;         // 05
		};
		static_assert(sizeof(BSIPlaybackCharacteristics) == 0x8);

		virtual ~BSISoundDescriptor();  // 00

		// add
		virtual void Unk_01(void) = 0;  // 01
		virtual void Unk_02(void) = 0;  // 02
	};
	static_assert(sizeof(BSISoundDescriptor) == 0x8);
}
