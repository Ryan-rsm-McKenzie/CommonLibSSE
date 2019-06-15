#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkListShape

#include "RE/bhkShapeCollection.h"  // bhkShapeCollection


namespace RE
{
	class bhkListShape : public bhkShapeCollection
	{
	public:
		inline static const void* RTTI = RTTI_bhkListShape;


		virtual ~bhkListShape();												// 00

		// override (bhkShapeCollection)
		virtual NiRTTI*		GetRTTI() override;									// 02
		virtual NiObject*	CreateClone(NiCloningProcess a_cloner) override;	// 17
		virtual void		LoadBinary(NiStream* a_stream) override;			// 18
		virtual void		LinkObject(NiStream* a_stream) override;			// 19
		virtual bool		RegisterStreamables(NiStream* a_stream) override;	// 1A
		virtual void		SaveBinary(NiStream* a_stream) override;			// 1B


		// members
		UInt64 unk28;	// 28
	};
	STATIC_ASSERT(sizeof(bhkListShape) == 0x30);
}
