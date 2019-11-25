#pragma once

#include "RE/NiRefObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSDynamicTriShape;
	class BSFadeNode;
	class BSGeometry;
	class bhkAttachmentCollisionObject;
	class bhkBlendCollisionObject;
	class bhkLimitedHingeConstraint;
	class bhkNiCollisionObject;
	class bhkRigidBody;
	class BSLines;
	class BSMultiBoundNode;
	class BSSegmentedTriShape;
	class BSSubIndexTriShape;
	class BSTriShape;
	class NiCloningProcess;
	class NiControllerManager;
	class NiGeometry;
	class NiNode;
	class NiObjectGroup;
	class NiParticles;
	class NiRTTI;
	class NiStream;
	class NiSwitchNode;
	class NiTriBasedGeom;
	class NiTriShape;
	class NiTriStrips;


	NiSmartPointer(NiObject);


	class NiObject : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_NiObject;
		inline static const void* Ni_RTTI = NiRTTI_NiObject;


		virtual ~NiObject();																// 00

		// add
		virtual const NiRTTI*					GetRTTI() const;							// 02
		virtual NiNode*							GetAsNiNode();								// 03 - { return 0; }
		virtual NiSwitchNode*					GetAsNiSwitchNode();						// 04 - { return 0; }
		virtual BSFadeNode*						GetAsBSFadeNode();							// 05 - { return 0; }
		virtual BSMultiBoundNode*				GetAsBSMultiBoundNode();					// 06 - { return 0; }
		virtual BSGeometry*						GetAsBSGeometry();							// 07 - { return 0; }
		virtual NiTriStrips*					GetAsNiTriStrips();							// 08 - { return 0; }
		virtual BSTriShape*						GetAsBSTriShape();							// 09 - { return 0; }
		virtual BSSegmentedTriShape*			GetAsBSSegmentedTriShape();					// 0A - { return 0; }
		virtual BSSubIndexTriShape*				GetAsBSSubIndexTriShape();					// 0B - { return 0; }
		virtual BSDynamicTriShape*				GetAsBSDynamicTriShape();					// 0C - { return 0; }
		virtual NiGeometry*						GetAsNiGeometry();							// 0D - { return 0; }
		virtual NiTriBasedGeom*					GetAsNiTriBasedGeom();						// 0E - { return 0; }
		virtual NiTriShape*						GetAsNiTriShape();							// 0F - { return 0; }
		virtual NiParticles*					GetAsNiParticles();							// 10 - { return 0; }
		virtual BSLines*						GetAsBSLines();								// 11 - { return 0; }
		virtual bhkNiCollisionObject*			GetAsBhkNiCollisionObject();				// 12 - { return 0; }
		virtual	bhkBlendCollisionObject*		GetAsBhkBlendCollisionObject();				// 13 - { return 0; }
		virtual bhkAttachmentCollisionObject*	GetAsBhkAttachmentCollisionObject();		// 14 - { return 0; }
		virtual bhkRigidBody*					GetAsBhkRigidBody();						// 15 - { return 0; }
		virtual bhkLimitedHingeConstraint*		GetAsBhkLimitedHingeConstraint();			// 16 - { return 0; }
		virtual NiObject*						CreateClone(NiCloningProcess& a_cloning);	// 17 - { return this; }
		virtual void							LoadBinary(NiStream& a_stream);				// 18 - { return; }
		virtual void							LinkObject(NiStream& a_stream);				// 19 - { return; }
		virtual bool							RegisterStreamables(NiStream& a_stream);	// 1A
		virtual void							SaveBinary(NiStream& a_stream);				// 1B - { return; }
		virtual bool							IsEqual(NiObject* a_object);				// 1C
		virtual void							ProcessClone(NiCloningProcess& a_cloning);	// 1D
		virtual void							PostLinkObject(NiStream& a_stream);			// 1E - { return; }
		virtual bool							StreamCanSkip();							// 1F - { return false; }
		virtual const NiRTTI*					GetStreamableRTTI() const;					// 20 - { return GetRTTI(); }
		virtual UInt32							GetBlockAllocationSize() const;				// 21 - { return 0; }
		virtual NiObjectGroup*					GetGroup() const;							// 22 - { return 0; }
		virtual void							SetGroup(NiObjectGroup* a_group);			// 23 - { return; }
		virtual NiControllerManager*			GetAsNiControllerManager();					// 24 - { return 0; }

		void CreateDeepCopy(NiPointer<NiObject>& a_result);
	};
	STATIC_ASSERT(sizeof(NiObject) == 0x10);
}
