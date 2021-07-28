#pragma once

namespace RE
{
	class bhkWorld;

	class BSIRagdollDriver
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSIRagdollDriver;

		virtual ~BSIRagdollDriver();  // 00

		virtual void Unk_01() = 0;                 // 01
		virtual void Unk_02() = 0;                 // 02
		virtual void Unk_03() = 0;                 // 03
		virtual void SetWorld(bhkWorld* a_world) = 0;  // 04
		virtual void Unk_05() = 0;                 // 05
		virtual void Unk_06() = 0;                 // 06
		virtual void Unk_07() = 0;                 // 07
		virtual void Unk_08() = 0;                 // 08
		virtual void Unk_09() = 0;                 // 09
		virtual void Unk_0A() = 0;                 // 0A
		virtual void Unk_0B() = 0;                 // 0B
		virtual void Unk_0C() = 0;                 // 0C
		virtual void Unk_0D() = 0;                 // 0D
	};
	static_assert(sizeof(BSIRagdollDriver) == 0x8);
}
