#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiObject

#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
	class BSFadeNode;
	class BSGeometry;
	class BSTriShape;
	class NiCloningProcess;
	class NiGeometry;
	class NiNode;
	class NiObjectGroup;
	class NiRTTI;
	class NiStream;
	class NiSwitchNode;
	class NiTriBasedGeom;
	class NiTriShape;


	class NiObject : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_NiObject;


		virtual ~NiObject();												// 00

		// add
		virtual NiRTTI*			GetRTTI();									// 02
		virtual NiNode*			GetAsNiNode();								// 03 - { return 0; }
		virtual NiSwitchNode*	GetAsNiSwitchNode();						// 04 - { return 0; }
		virtual BSFadeNode*     GetAsBSFadeNode();							// 05 - { return 0; }
		virtual UInt32			Unk_06(void);								// 06 - { return 0; }
		virtual BSGeometry*		GetAsBSGeometry();							// 07 - { return 0; }
		virtual void			Unk_08(void);								// 08 - { return 0; }
		virtual BSTriShape*		GetAsBSTriShape();							// 09 - { return 0; }
		virtual void			Unk_0A(void);								// 0A - { return 0; }
		virtual void			Unk_0B(void);								// 0B - { return 0; }
		virtual void			Unk_0C(void);								// 0C - { return 0; }
		virtual NiGeometry*		GetAsNiGeometry();							// 0D - { return 0; }
		virtual NiTriBasedGeom*	GetAsNiTriBasedGeom();						// 0E - { return 0; }
		virtual NiTriShape*		GetAsNiTriShape();							// 0F - { return 0; }
		virtual void			Unk_10(void);								// 10 - { return 0; }
		virtual void			Unk_11(void);								// 11 - { return 0; }
		virtual void			Unk_12(void);								// 12 - { return 0; }
		virtual	void			Unk_13(void);								// 13 - { return 0; }
		virtual void			Unk_14(void);								// 14 - { return 0; }
		virtual void			Unk_15(void);								// 15 - { return 0; }
		virtual void			Unk_16(void);								// 16 - { return 0; }
		virtual NiObject*		CreateClone(NiCloningProcess a_cloner);		// 17 - { return this; }
		virtual void			LoadBinary(NiStream* a_stream);				// 18 - { return; }
		virtual void			LinkObject(NiStream* a_stream);				// 19 - { return; }
		virtual bool			RegisterStreamables(NiStream* a_stream);	// 1A
		virtual void			SaveBinary(NiStream* a_stream);				// 1B - { return; }
		virtual bool			IsEqual(NiObject* a_object);				// 1C
		virtual void			ProcessClone(NiCloningProcess& a_cloning);	// 1D
		virtual void			PostLinkObject(NiStream& a_stream);			// 1E - { return; }
		virtual bool			StreamCanSkip();							// 1F - { return 0; }
		virtual const NiRTTI*	GetStreamableRTTI() const;					// 20 - { return GetRTTI(); }
		virtual UInt32			GetBlockAllocationSize() const;				// 21 - { return 0; }
		virtual NiObjectGroup*	GetGroup() const;							// 22 - { return 0; }
		virtual void			SetGroup(NiObjectGroup* a_group);			// 23 - { return; }
		virtual void			Unk_24(void);								// 24 - { return 0; }

		NiStream*				DeepCopy(NiObject*& a_result);
	};
	STATIC_ASSERT(sizeof(NiObject) == 0x10);
}
