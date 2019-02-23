#pragma once

#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSNote :
		public TESBoundObject,			// 00
		public TESModel,				// 30
		public TESFullName,				// 58
		public TESIcon,					// 68
		public BGSPickupPutdownSounds	// 78
	{
	public:
		enum { kTypeID = FormType::Note };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BGSNote();																																	// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;																											// 04
		virtual void	Unk_05(void) override;																												// 05
		virtual bool	LoadForm(TESFile* a_mod) override;																									// 06
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;																						// 0F
		virtual void	Unk_12(void) override;																												// 12
		virtual void	InitItem() override;																												// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, UInt32 a_arg5) override;	// 37


		// members
		UInt64	unk90;	// 90
		UInt64	unk98;	// 98
		UInt64	unkA0;	// A0
		UInt64	unkA8;	// A8
		UInt64	unkB0;	// B0
	};
	STATIC_ASSERT(sizeof(BGSNote) == 0xB8);
}
