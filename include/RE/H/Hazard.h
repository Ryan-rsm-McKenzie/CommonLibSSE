#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class BGSHazard;
	class NiLight;

	class Hazard : public TESObjectREFR
	{
	public:
		inline static constexpr auto RTTI = RTTI_Hazard;
		inline static constexpr auto FORMTYPE = FormType::PlacedHazard;

		enum class Flags
		{
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~Hazard() override;  // 00

		// override (TESObjectREFR)
		void SaveGame(BGSSaveFormBuffer* a_buf) override;                           // 0E
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                           // 0F
		void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;                     // 11
		void Revert(BGSLoadFormBuffer* a_buf) override;                             // 12
		void InitItemImpl() override;                                               // 13
		void SetActorCause(ActorCause* a_cause) override;                           // 50
		void Release3DRelatedData() override;                                       // 6B
		bool OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const override;  // 90 - { return false; }

		// add
		virtual void Unk_A2(void);                // A2
		virtual void Unk_A3(void);                // A3 - { return; }
		virtual bool IsNotGeneratedForm() const;  // A4 - { return TESDataHandler::GetSingleton()->IsGeneratedFormID(formID) == 0; }

		// members
		void*                                  hazardDBHandle;  // 98
		ActorHandle                            ownerActor;      // A0
		float                                  age;             // A4
		float                                  lifetime;        // A8
		float                                  targetTimer;     // AC
		float                                  radius;          // B0
		float                                  magnitude;       // B4
		BGSHazard*                             hazard;          // B8
		NiPointer<NiLight>                     light;           // C0
		BSSoundHandle                          sound;           // C8
		stl::enumeration<Flags, std::uint32_t> flags;           // D4
	};
	static_assert(sizeof(Hazard) == 0xE0);
}
