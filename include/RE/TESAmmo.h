#pragma once

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSMessageIcon.h"  // BGSMessageIcon
#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESValueForm.h"  // TESValueForm
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class TESAmmo :
		public TESBoundObject,				// 000
		public TESFullName,					// 030
		public TESModelTextureSwap,			// 040
		public TESIcon,						// 078
		public BGSMessageIcon,				// 088
		public TESValueForm,				// 0A0
		public TESWeightForm,				// 0B0
		public BGSDestructibleObjectForm,	// 0C0
		public BGSPickupPutdownSounds,		// 0D0
		public TESDescription,				// 0E8
		public BGSKeywordForm				// 0F8
	{
	public:
		enum { kTypeID = FormType::Ammo };


		struct Data	// DATA
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kIgnoresNormalWeaponResistance = 1 << 0,
				kNonPlayable = 1 << 1,
				kNonBolt = 1 << 2
			};


			BGSProjectile*	projectile;	// 00
			Flag			flags;		// 08
			float			damage;		// 0C
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		bool	IgnoresNormalWeaponResistance();
		bool	IsPlayable();
		bool	IsBolt();


		// members
		Data			data;		// 110
		BSFixedString	shortName;	// 120
	};
	STATIC_ASSERT(sizeof(TESAmmo) == 0x128);
}
