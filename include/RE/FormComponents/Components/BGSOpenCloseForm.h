#pragma once


namespace RE
{
	class Actor;
	class TESObjectREFR;


	class BGSOpenCloseForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSOpenCloseForm;


		virtual ~BGSOpenCloseForm();  // 00

		// add
		virtual void HandleOpen(TESObjectREFR* a_target, TESObjectREFR* a_activator);	// 01 - { return; }
		virtual void HandleClose(TESObjectREFR* a_target, TESObjectREFR* a_activator);	// 02 - { return; }
		virtual void Unk_03(void);														// 03 - { return 0; }
	};
	STATIC_ASSERT(sizeof(BGSOpenCloseForm) == 0x8);
}
