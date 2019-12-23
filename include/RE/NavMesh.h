#pragma once

#include "RE/BSNavmesh.h"
#include "RE/FormTypes.h"
#include "RE/TESChildCell.h"
#include "RE/TESForm.h"


namespace RE
{
	class NavMesh :
		public TESForm,			// 000
		public TESChildCell,	// 020
		public BSNavmesh		// 028
	{
	public:
		inline static const void* RTTI = RTTI_NavMesh;


		enum { kTypeID = FormType::NavMesh };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCompressed = 1 << 18,
				kAutoGen = 1 << 26,
				kNavMeshGenCell = (UInt32)1 << 31
			};
		};


		virtual ~NavMesh();																// 00

		// override (TESForm)
		virtual bool	Load(TESFile* a_mod) override;									// 06
		virtual void	InitItemImpl() override;										// 13
		virtual void	GetFormDetailedString(char* a_buf, UInt32 a_bufLen) override;	// 16
		virtual void	SetDelete(bool a_set) override;									// 23
		virtual void	SetAltered(bool a_set) override;								// 24
		virtual bool	BelongsInGroup(void) override;									// 30
		virtual void	CreateGroupData(void) override;									// 31

		// add
		virtual void	Unk_3B(void);													// 3B - { return; }
		virtual void	Unk_3C(void);													// 3C - { return 0; }
		virtual void	Unk_3D(void);													// 3D - { return 0; }
		virtual void	Unk_3E(void);													// 3E - { return 0; }
	};
	STATIC_ASSERT(sizeof(NavMesh) == 0x140);
}
