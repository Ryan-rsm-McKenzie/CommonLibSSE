#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BeamProjectile

#include "RE/BSTEvent.h"  // BSTEventSource, BSTEventSink
#include "RE/Projectile.h"  // Projectile


namespace RE
{
	class BSProceduralGeomEvent;
	struct BeamProjectileImpactEvent;


	class BeamProjectile :
		public Projectile,									// 000
		public BSTEventSource<BeamProjectileImpactEvent>,	// 1E0
		public BSTEventSink<BSProceduralGeomEvent>			// 1D8
	{
	public:
		inline static const void* RTTI = RTTI_BeamProjectile;


		enum { kTypeID = FormType::ProjectileBeam };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BeamProjectile();																											// 00

		// override (Projectile)
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;																	// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;																	// 0F
		virtual void		Unk_12(void) override;																							// 12
		virtual void		Unk_A5(void) override;																							// A5
		virtual void		Unk_A9(void) override;																							// A9
		virtual void		Unk_AB(void) override;																							// AB
		virtual void		Unk_B8(void) override;																							// B8
		virtual void		Unk_BD(void) override;																							// BD
		virtual void		Unk_C0(void) override;																							// C0
		virtual void		Unk_C1(void) override;																							// C1

		// override (BSTEventSink<BSProceduralGeomEvent>)
		virtual	EventResult	ReceiveEvent(BSProceduralGeomEvent* a_event, BSTEventSource<BSProceduralGeomEvent>* a_eventSource) override;	// 01


		// members
		UInt64 unk238;	// 238
	};
	STATIC_ASSERT(sizeof(BeamProjectile) == 0x240);
}
