#pragma once

#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSCameraPath : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSCameraPath;


		enum { kTypeID = FormType::CameraPath };


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


		struct Data	// DATA
		{
			enum class CameraZoom : UInt32
			{
				kDefault_MustHaveCameraShots = 0,
				kDisable_MustHaveCameraShots = 1,
				kShotList_MustHaveCameraShots = 2,
				kDefault = 128,
				kDisable = 129,
				kShotList = 130
			};


			CameraZoom cameraZoom;	// 0
		};
		STATIC_ASSERT(sizeof(Data) == 0x4);


		virtual ~BGSCameraPath();														// 00

		// override (TESForm)
		virtual void		InitializeData() override;									// 04
		virtual void		ClearData() override;										// 05
		virtual bool		Load(TESFile* a_mod) override;								// 06
		virtual TESForm*	CreateDuplicateForm(void* a_arg1, void* a_arg2) override;	// 09
		virtual void		InitItemImpl() override;									// 13


		// members
		TESCondition					conditions;						// 20
		BSSimpleList<BGSCameraShot*>	cameraShots;					// 28 - SNAM
		Data							data;							// 38 - DATA
		UInt32							unk3C;							// 3C
		UInt64							unk40;							// 40
		BGSCameraPath*					relatives[Relatives::kTotal];	// 48 - ANAM
	};
	STATIC_ASSERT(sizeof(BGSCameraPath) == 0x58);
}
