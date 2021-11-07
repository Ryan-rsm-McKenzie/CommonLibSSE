#pragma once

#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class NiFormArray;

	struct PATH_DATA  // DATA
	{
		enum class PathFlags
		{
			kNone = 0,
			kZoomDisable = 1 << 0,
			kZoomShotList = 1 << 1,
			kDynamicTimes = 1 << 2,
			kRandomPaths = 1 << 6,
			kAllowNoShots = 1 << 7
		};

		stl::enumeration<PathFlags, std::uint8_t> flags;  // 0
	};
	static_assert(sizeof(PATH_DATA) == 0x1);

	class BGSCameraPath : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSCameraPath;
		inline static constexpr auto VTABLE = VTABLE_BGSCameraPath;
		inline static constexpr auto FORMTYPE = FormType::CameraPath;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct Relatives
		{
			enum Relative
			{
				kParent,
				kPreviousSibling,

				kTotal
			};
		};

		~BGSCameraPath() override;  // 00

		// override (TESForm)
		void     InitializeData() override;                                          // 04
		void     ClearData() override;                                               // 05
		bool     Load(TESFile* a_mod) override;                                      // 06
		TESForm* CreateDuplicateForm(bool a_createEditorID, void* a_arg2) override;  // 09
		void     InitItemImpl() override;                                            // 13

		// members
		TESCondition                 conditions;  // 20
		BSSimpleList<BGSCameraShot*> shots;       // 28 - SNAM
		PATH_DATA                    data;        // 38 - DATA
		std::uint8_t                 pad39;       // 39
		std::uint16_t                pad3A;       // 3A
		std::uint32_t                pad3C;       // 3C
		NiFormArray*                 childPaths;  // 40
		BGSCameraPath*               parentPath;  // 48 - ANAM~
		BGSCameraPath*               prevPath;    // 48 - ~ANAM
	};
	static_assert(sizeof(BGSCameraPath) == 0x58);
}
