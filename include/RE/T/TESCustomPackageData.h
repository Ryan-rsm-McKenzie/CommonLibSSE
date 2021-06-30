#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TESPackageData.h"

namespace RE
{
	class IPackageData;
	class IProcedureTreeItem;
	class TESPackage;

	struct BGSPackageDataList
	{
		IPackageData** data;      // 00
		std::int8_t*   uids;      // 08
		std::uint16_t  dataSize;  // 10
		std::int8_t    nextUID;   // 12 - XNAM
		std::uint8_t   pad13;     // 13
		std::uint32_t  pad14;     // 14
	};
	static_assert(sizeof(BGSPackageDataList) == 0x18);

	struct BGSPackageDataNameMap : public BSIntrusiveRefCounted
	{
	public:
		struct NameMapData
		{
		public:
			enum class Flag
			{
				kNone = 0,
				kPublic = 1 << 0
			};

			// members
			BSFixedString name;      // 00 - BNAM
			std::int8_t   uid;       // 08 - UNAM
			bool          isPublic;  // 09 - PNAM
			std::uint8_t  pad0A;     // 0A
			std::uint8_t  pad0B;     // 0B
			std::uint32_t pad0C;     // 0C
		};
		static_assert(sizeof(NameMapData) == 0x10);

		// members
		std::uint32_t         pad04;    // 04
		BSTArray<NameMapData> nameMap;  // 08
	};
	static_assert(sizeof(BGSPackageDataNameMap) == 0x20);

	class TESCustomPackageData : public TESPackageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESCustomPackageData;

		~TESCustomPackageData() override;  // 00

		// override (TESPackageData)
		void Copy(TESPackageData* a_package, TESForm* a_form) override;  // 01
		void InitItem(TESForm* a_form) override;                         // 03
		void SaveGame(BGSSaveFormBuffer* a_buf) override;                // 04 - { return; }
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                // 05 - { return; }

		// members
		BGSPackageDataList                     data;                     // 08
		IProcedureTreeItem*                    procedureTree;            // 20
		BSTSmartPointer<BGSPackageDataNameMap> nameMap;                  // 28
		TESPackage*                            templateParent;           // 30
		std::uint16_t                          version;                  // 38
		bool                                   alwaysRecheckConditions;  // 3A
		std::uint8_t                           pad3B;                    // 3B
		std::uint32_t                          pad3C;                    // 3C
	};
	static_assert(sizeof(TESCustomPackageData) == 0x40);
}
