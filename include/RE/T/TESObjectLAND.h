#pragma once

#include "RE/B/BSTriShape.h"
#include "RE/F/FormTypes.h"
#include "RE/H/hkpMoppCode.h"
#include "RE/N/NiPoint2.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESChildCell.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class NiNode;
	class QueuedFile;

	struct OBJ_LAND
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kVertexNormals_HeightMap = 1 << 0,
			kVertexColors = 1 << 1,
			kLayers = 1 << 2,
			kMPCD = 1 << 10
		};

		// members
		stl::enumeration<Flag, std::uint32_t> flags;  // 0
	};
	static_assert(sizeof(OBJ_LAND) == 0x4);

	struct CHAR_NORM
	{
	public:
		// members
		std::int8_t x;	// 0
		std::int8_t y;	// 1
		std::int8_t z;	// 2
	};
	static_assert(sizeof(CHAR_NORM) == 0x3);

	class TESObjectLAND :
		public TESForm,		 // 00
		public TESChildCell	 // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectLAND;
		inline static constexpr auto FORMTYPE = FormType::Land;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCompressed = 1 << 18
			};
		};

		struct LoadedLandData
		{
		public:
			// members
			NiNode*				  mesh[4];				// 0000
			float				  heights[4][289];		// 0020
			std::int8_t			  percents[4][289][6];	// 1230
			std::int8_t			  colors[4][289][3];	// 2D48
			CHAR_NORM			  normals[4][289];		// 3AD4
			NiPointer<BSTriShape> geom[4];				// 4860
			NiPointer<BSTriShape> border;				// 4880
			NiPoint2			  heightExtents;		// 4888
			TESLandTexture*		  defQuadTextures[4];	// 4890
			TESLandTexture*		  quadTextures[4][6];	// 48B0
			hkpMoppCode			  moppCode;				// 4970
			std::uint64_t		  unk49B0;				// 49B0
			std::uint64_t		  unk49B8;				// 49B8
			std::uint64_t		  unk49C0;				// 49C0
			std::uint64_t		  unk49C8;				// 49C8
		};
		static_assert(sizeof(LoadedLandData) == 0x49D0);

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
		std::uint32_t		  pad2C;		   // 2C
		TESObjectCELL*		  parentCell;	   // 30
		NiPointer<QueuedFile> queuedTextures;  // 38
		LoadedLandData*		  loadedData;	   // 40
	};
	static_assert(sizeof(TESObjectLAND) == 0x48);
}
