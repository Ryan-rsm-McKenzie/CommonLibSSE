#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectLAND

#include "RE/TESChildCell.h"  // TESChildCell
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class QueuedFile;


	class TESObjectLAND :
		public TESForm,		// 00
		public TESChildCell	// 20
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectLAND;


		enum { kTypeID = FormType::Land };


		enum class Flag : UInt32	// DATA
		{
			kNone = 0,
			kVertexNormals_HeightMap = 1 << 0,
			kVertexColors = 1 << 1,
			kLayers = 1 << 2,
			kMPCD = 1 << 10
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCompressed = 1 << 18
			};
		};


		virtual ~TESObjectLAND();													// 00

		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;						// 06 - { return true; }
		virtual TESForm*	DupulicateForm(void* a_arg1, void* a_arg2) override;	// 09
		virtual void		SetFlag00000002(bool a_set) override;					// 24
		virtual void		Unk_30(void) override;									// 30
		virtual void		Unk_31(void) override;									// 31


		// members
		Flag			flags;	// 28 - DATA
		UInt32			pad2C;	// 2C
		TESObjectCELL*	cell;	// 30
		QueuedFile*		unk38;	// 38
		void*			unk40;	// 40
	};
	STATIC_ASSERT(sizeof(TESObjectLAND) == 0x48);
}
