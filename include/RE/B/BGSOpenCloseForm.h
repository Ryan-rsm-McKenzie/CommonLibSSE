#pragma once

namespace RE
{
	class Actor;
	class TESObjectREFR;

	class BGSOpenCloseForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSOpenCloseForm;

		enum class OPEN_STATE
		{
			kNone = 0,
			kOpen = 1,
			kOpening = 2,
			kClosed = 3,
			kClosing = 4
		};

		virtual ~BGSOpenCloseForm();  // 00

		// add
		virtual void HandleOpen(TESObjectREFR* a_target, TESObjectREFR* a_activator);   // 01 - { return; }
		virtual void HandleClose(TESObjectREFR* a_target, TESObjectREFR* a_activator);  // 02 - { return; }
		virtual void Unk_03(void);                                                      // 03 - { return 0; }

		[[nodiscard]] static OPEN_STATE GetOpenState(const TESObjectREFR* a_ref);
		static void                     SetOpenState(TESObjectREFR* a_ref, bool a_open, bool a_snap);
	};
	static_assert(sizeof(BGSOpenCloseForm) == 0x8);
}
