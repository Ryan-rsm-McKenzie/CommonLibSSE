#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/F/FormTypes.h"
#include "RE/P/Projectile.h"

namespace RE
{
	class BSProceduralGeomEvent;
	struct BeamProjectileImpactEvent;

	class BeamProjectile :
		public Projectile,                                 // 000
		public BSTEventSource<BeamProjectileImpactEvent>,  // 1E0
		public BSTEventSink<BSProceduralGeomEvent>         // 1D8
	{
	public:
		inline static constexpr auto RTTI = RTTI_BeamProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileBeam;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~BeamProjectile() override;  // 00

		// override (Projectile)
		void SaveGame(BGSSaveFormBuffer* a_buf) override;        // 0E
		void LoadGame(BGSLoadFormBuffer* a_buf) override;        // 0F
		void InitLoadGame(BGSLoadFormBuffer* a_buf) override;    // 10
		void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;  // 11
		void Revert(BGSLoadFormBuffer* a_buf) override;          // 12
		void Unk_A5(void) override;                              // A5
		void Unk_A9(void) override;                              // A9
		void UpdateImpl(float a_delta) override;                 // AB
		void Unk_B8(void) override;                              // B8
		void Unk_BD(void) override;                              // BD
		void Handle3DLoaded() override;                          // C0
		void Unk_C1(void) override;                              // C1

		// override (BSTEventSink<BSProceduralGeomEvent>)
		BSEventNotifyControl ProcessEvent(const BSProceduralGeomEvent* a_event, BSTEventSource<BSProceduralGeomEvent>* a_eventSource) override;  // 01

		// members
		std::uint64_t unk238;  // 238
	};
	static_assert(sizeof(BeamProjectile) == 0x248);
}
