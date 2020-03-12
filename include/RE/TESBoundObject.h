#pragma once

#include "RE/BSString.h"
#include "RE/FormTypes.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESObject.h"


namespace RE
{
	class NiAVObject;
	class TESObjectREFR;


	class NiNPShortPoint3
	{
	public:
		SInt16 x;  // 0
		SInt16 y;  // 2
		SInt16 z;  // 4
	};
	STATIC_ASSERT(sizeof(NiNPShortPoint3) == 0x6);


	class TESBoundObject : public TESObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESBoundObject;


		struct BOUND_DATA  // OBND
		{
			NiNPShortPoint3 boundMin;  // 0
			NiNPShortPoint3 boundMax;  // 6
		};
		STATIC_ASSERT(sizeof(BOUND_DATA) == 0xC);


		virtual ~TESBoundObject();	// 00

		// override (TESObject)
		virtual void		LoadObjectBound(TESFile* a_mod) override;																									 // 26
		virtual bool		IsBoundObject() const override;																												 // 27 - { return true; }
		virtual bool		Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, TESBoundObject* a_object, SInt32 a_targetCount) override;	 // 37
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;																						 // 40
		virtual bool		ReplaceModel() override;																													 // 44

		// add
		virtual void		  SetObjectVoiceType(BGSVoiceType* a_voiceType);												 // 48 - { return; }
		virtual BGSVoiceType* GetObjectVoiceType() const;																	 // 49 - { return 0; }
		virtual NiAVObject*	  Clone3D(TESObjectREFR* a_ref);																 // 4A - { Clone3D(a_ref, false); }
		virtual bool		  ReplaceModel(const char* a_str);																 // 4B
		virtual bool		  GetActivateText(TESObjectREFR* a_activator, BSString& a_dst);									 // 4C
		virtual bool		  CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3);	 // 4D
		virtual void		  HandleRemoveItemFromContainer(TESObjectREFR* a_container);									 // 4E - { return; }
		virtual void		  OnRemove3D(NiAVObject* a_obj3D);																 // 4F - { return; }
		virtual void		  OnCheckModels();																				 // 50 - { return; }
		virtual void		  OnCopyReference();																			 // 51 - { return; }
		virtual void		  OnFinishScale();																				 // 52 - { return; }


		// members
		BOUND_DATA boundData;  // 20 - OBND
		UInt32	   pad2C;	   // 2C
	};
	STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);
}
