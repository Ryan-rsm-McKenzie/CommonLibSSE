#pragma once

#include "RE/B/BSNavmesh.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESChildCell.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class NavMesh :
		public TESForm,       // 000
		public TESChildCell,  // 020
		public BSNavmesh      // 028
	{
	public:
		inline static constexpr auto RTTI = RTTI_NavMesh;
		inline static constexpr auto VTABLE = VTABLE_NavMesh;
		inline static constexpr auto FORMTYPE = FormType::NavMesh;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCompressed = 1 << 18,
				kAutoGen = 1 << 26,
				kNavMeshGenCell = (std::uint32_t)1 << 31
			};
		};

		~NavMesh() override;  // 00

		// override (TESForm)
		bool Load(TESFile* a_mod) override;                                                        // 06
		void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;                                    // 11
		void InitItemImpl() override;                                                              // 13
		void GetFormDetailedString(char* a_buf, std::uint32_t a_bufLen) override;                  // 16
		void SetDelete(bool a_set) override;                                                       // 23
		void SetAltered(bool a_set) override;                                                      // 24
		bool BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly) override;  // 30
		void CreateGroupData(FORM* a_form, FORM_GROUP* a_group) override;                          // 31

		// add
		virtual void Save();                        // 3B - { return; }
		virtual bool SavesBefore(FORM* a_form);     // 3C - { return fa;se; }
		virtual bool SavesBefore(TESForm* a_form);  // 3D - { return false; }
		virtual bool ProcessBeforeSave();           // 3E - { return false; }
	};
	static_assert(sizeof(NavMesh) == 0x140);
}
