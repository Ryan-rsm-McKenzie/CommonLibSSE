#pragma once

#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap

namespace RE
{
	class TESObjectSTAT :
		public TESBoundObject,		// 00
		public TESModelTextureSwap	// 30
	{
	public:
		enum { kTypeID = FormType::Static };


		struct DirectionalMaterial	// DNAM
		{
			enum class Flag : UInt32
			{};


			float				maxAngle;	// 68 - init'd to 90 (range 30-120)
			BGSMaterialObject*	material;	// 70
			Flag				flags;		// 78
			UInt32				pad7C;		// 7C
		};


		// members
		DirectionalMaterial directionalMaterial;
	};
	STATIC_ASSERT(sizeof(TESObjectSTAT) == 0x80);
}