#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSKeyword;
	class TESObjectREFR;

	class ExtraMissingLinkedRefIDs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMissingLinkedRefIDs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMissingLinkedRefIDs;

		struct Entry
		{
		public:
			// members
			BGSKeyword*	  keyword;		// 00
			FormID		  linkedRefID;	// 08
			std::uint32_t pad0C;		// 0C
		};
		static_assert(sizeof(Entry) == 0x10);

		// a variation of a small array
		struct Array
		{
		public:
			using value_type = Entry;
			using size_type = std::uint32_t;
			using reference = value_type&;
			using iterator = Entry*;

			union Data
			{
				Entry* entryPtr;
				Entry  entry[1];
			};
			static_assert(sizeof(Data) == 0x10);

			reference operator[](size_type a_pos);
			iterator  begin() noexcept;
			iterator  end() noexcept;
			size_type size() const noexcept;

			// members
			Data		  _data;   // 00
			std::uint32_t _size;   // 10
			std::uint32_t _pad14;  // 14
		};
		static_assert(sizeof(Array) == 0x18);

		virtual ~ExtraMissingLinkedRefIDs();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kMissingLinkedRefIDs; }

		TESObjectREFR* GetLinkedRef(BGSKeyword* a_keyword);

		// members
		Array entries;	// 10
	};
	static_assert(sizeof(ExtraMissingLinkedRefIDs) == 0x28);
}
