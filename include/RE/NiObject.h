#pragma once

#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
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
		virtual ~NiObject();												// 00

		// add
		virtual NiRTTI*			GetRTTI();									// 02
		virtual NiNode*			GetAsNiNode();								// 03
		virtual NiSwitchNode*	GetAsNiSwitchNode();						// 04
		virtual void*			Unk_05(void);								// 05
		virtual UInt32			Unk_06(void);								// 06
		virtual BSGeometry*		GetAsBSGeometry();							// 07
		virtual void*			Unk_08(void);								// 08
		virtual BSTriShape*		GetAsBSTriShape();							// 09
		virtual void*			Unk_0A(void);								// 0A
		virtual void*			Unk_0B(void);								// 0B
		virtual void*			Unk_0C(void);								// 0C
		virtual NiGeometry*		GetAsNiGeometry();							// 0D
		virtual NiTriBasedGeom*	GetAsNiTriBasedGeom();						// 0E
		virtual NiTriShape*		GetAsNiTriShape();							// 0F
		virtual void*			Unk_10(void);								// 10
		virtual void*			Unk_11(void);								// 11
		virtual void*			Unk_12(void);								// 12
		virtual	UInt32			Unk_13(void);								// 13
		virtual UInt32			Unk_14(void);								// 14
		virtual UInt32			Unk_15(void);								// 15
		virtual UInt32			Unk_16(void);								// 16
		virtual NiObject*		CreateClone(NiCloningProcess a_cloner);		// 17
		virtual void			LoadBinary(NiStream* a_stream);				// 18
		virtual void			LinkObject(NiStream* a_stream);				// 19
		virtual bool			RegisterStreamables(NiStream* a_stream);	// 1A
		virtual void			SaveBinary(NiStream* a_stream);				// 1B
		virtual bool			IsEqual(NiObject* a_object);				// 1C
		virtual void			ProcessClone(NiCloningProcess* a_cloner);	// 1D
		virtual void			PostLinkObject(NiStream* a_stream);			// 1E
		virtual bool			StreamCanSkip();							// 1F
		virtual const void*		GetStreamableRTTI() const;					// 20
		virtual UInt32			GetBlockAllocationSize() const;				// 21
		virtual NiObjectGroup*	GetGroup() const;							// 22
		virtual void			SetGroup(NiObjectGroup* a_group);			// 23
		virtual UInt32			Unk_24(void);								// 24

		NiStream*				DeepCopy(NiObject** a_result);
	};
	STATIC_ASSERT(sizeof(NiObject) == 0x10);
}
