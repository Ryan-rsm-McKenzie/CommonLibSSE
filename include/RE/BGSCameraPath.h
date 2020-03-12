#pragma once

#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESForm.h"


namespace RE
{
	class NiFormArray;


	struct PATH_DATA  // DATA
	{
		enum class PathFlags : UInt8
		{
			kNone = 0,
			kZoomDisable = 1 << 0,
			kZoomShotList = 1 << 1,
			kDynamicTimes = 1 << 2,
			kRandomPaths = 1 << 6,
			kAllowNoShots = 1 << 7
		};


		PathFlags flags;  // 0
	};
	STATIC_ASSERT(sizeof(PATH_DATA) == 0x1);


	class BGSCameraPath : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSCameraPath;
		inline static constexpr auto FORMTYPE = FormType::CameraPath;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
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


		virtual ~BGSCameraPath();  // 00

		// override (TESForm)
		virtual void	 InitializeData() override;											 // 04
		virtual void	 ClearData() override;												 // 05
		virtual bool	 Load(TESFile* a_mod) override;										 // 06
		virtual TESForm* CreateDuplicateForm(bool a_createEditorID, void* a_arg2) override;	 // 09
		virtual void	 InitItemImpl() override;											 // 13


		// members
		TESCondition				 conditions;  // 20
		BSSimpleList<BGSCameraShot*> shots;		  // 28 - SNAM
		PATH_DATA					 data;		  // 38 - DATA
		UInt8						 pad39;		  // 39
		UInt16						 pad3A;		  // 3A
		UInt32						 pad3C;		  // 3C
		NiFormArray*				 childPaths;  // 40
		BGSCameraPath*				 parentPath;  // 48 - ANAM~
		BGSCameraPath*				 prevPath;	  // 48 - ~ANAM
	};
	STATIC_ASSERT(sizeof(BGSCameraPath) == 0x58);
}
