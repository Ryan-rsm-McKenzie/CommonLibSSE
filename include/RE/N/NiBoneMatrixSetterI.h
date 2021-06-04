#pragma once

namespace RE
{
	class NiBoneMatrixSetterI
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBoneMatrixSetterI;

		virtual ~NiBoneMatrixSetterI();  // 00

		// add
		virtual void Unk_01(void);  // 01
	};
	static_assert(sizeof(NiBoneMatrixSetterI) == 0x8);
}
