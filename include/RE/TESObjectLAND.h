#pragma once

#include "RE/BSTriShape.h"
#include "RE/FormTypes.h"
#include "RE/NiPoint2.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESChildCell.h"
#include "RE/TESForm.h"
#include "RE/hkpMoppCode.h"


namespace RE
{
	class NiNode;
	class QueuedFile;


	struct OBJ_LAND
	{
		enum class Flag : UInt32
		{
			kNone = 0,
			kVertexNormals_HeightMap = 1 << 0,
			kVertexColors = 1 << 1,
			kLayers = 1 << 2,
			kMPCD = 1 << 10
		};


		Flag flags;	 // 0
	};
	STATIC_ASSERT(sizeof(OBJ_LAND) == 0x4);


	struct CHAR_NORM
	{
		SInt8 x;  // 0
		SInt8 y;  // 1
		SInt8 z;  // 2
	};
	STATIC_ASSERT(sizeof(CHAR_NORM) == 0x3);


	class TESObjectLAND :
		public TESForm,		 // 00
		public TESChildCell	 // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectLAND;
		inline static constexpr auto FORMTYPE = FormType::Land;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCompressed = 1 << 18
			};
		};


		struct LoadedLandData
		{
			NiNode*				  mesh[4];				// 0000
			float				  heights[4][289];		// 0020
			SInt8				  percents[4][289][6];	// 1230
			SInt8				  colors[4][289][3];	// 2D48
			CHAR_NORM			  normals[4][289];		// 3AD4
			NiPointer<BSTriShape> geom[4];				// 4860
			NiPointer<BSTriShape> border;				// 4880
			NiPoint2			  heightExtents;		// 4888
			TESLandTexture*		  defQuadTextures[4];	// 4890
			TESLandTexture*		  quadTextures[4][6];	// 48B0
			hkpMoppCode			  moppCode;				// 4970
			UInt64				  unk49B0;				// 49B0
			UInt64				  unk49B8;				// 49B8
			UInt64				  unk49C0;				// 49C0
			UInt64				  unk49C8;				// 49C8
		};
		STATIC_ASSERT(sizeof(LoadedLandData) == 0x49D0);


		virtual ~TESObjectLAND();  // 00

		// override (TESForm)
		virtual bool	 Load(TESFile* a_mod) override;														   // 06 - { return true; }
		virtual TESForm* CreateDuplicateForm(bool a_createEditorID, void* a_arg2) override;					   // 09
		virtual void	 SetAltered(bool a_set) override;													   // 24
		virtual bool	 BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly) override;  // 30
		virtual void	 CreateGroupData(FORM* a_form, FORM_GROUP* a_group) override;						   // 31

		// override (TESChildCell)
		virtual TESObjectCELL* GetSaveParentCell() override;  // 01 - { return parentCell; }


		// members
		OBJ_LAND			  data;			   // 28 - DATA
		UInt32				  pad2C;		   // 2C
		TESObjectCELL*		  parentCell;	   // 30
		NiPointer<QueuedFile> queuedTextures;  // 38
		LoadedLandData*		  loadedData;	   // 40
	};
	STATIC_ASSERT(sizeof(TESObjectLAND) == 0x48);
}
