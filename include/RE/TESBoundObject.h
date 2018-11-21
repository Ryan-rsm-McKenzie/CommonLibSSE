#pragma once

#include "skse64/GameObjects.h"  // TESObject

class BGSVoiceType;
class BSString;


namespace RE
{
	class TESObjectREFR;


	class TESBoundObject : public TESObject
	{
	public:
		struct Bound
		{
			UInt16	x;
			UInt16	y;
			UInt16	z;
		};


		// parents (TESObject)
		virtual void			Unk_47(void);

		// add
		virtual void			Unk_48(void);
		virtual BGSVoiceType*	GetVoiceType() const;
		virtual void			Unk_4A(void);
		virtual void			Unk_4B(void);
		virtual bool			GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk);
		virtual void			Unk_4D(void);
		virtual void			OnRemovedFrom(TESObjectREFR* a_ref);
		virtual void			Unk_4F(void);
		virtual void			Unk_50(void);
		virtual void			Unk_51(void);


		Bound	bounds;		// 20
		Bound	bounds2;	// 26  (not 28!)
	};
}
