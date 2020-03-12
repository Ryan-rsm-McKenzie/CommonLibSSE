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
		inline static constexpr auto RTTI = RTTI_NiObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiObject;


		virtual ~NiObject();  // 00

		// add
		virtual const NiRTTI*				  GetRTTI() const;							  // 02
		virtual NiNode*						  AsNode();									  // 03 - { return 0; }
		virtual NiSwitchNode*				  AsSwitchNode();							  // 04 - { return 0; }
		virtual BSFadeNode*					  AsFadeNode();								  // 05 - { return 0; }
		virtual BSMultiBoundNode*			  AsMultiBoundNode();						  // 06 - { return 0; }
		virtual BSGeometry*					  AsGeometry();								  // 07 - { return 0; }
		virtual NiTriStrips*				  AsTriStrips();							  // 08 - { return 0; }
		virtual BSTriShape*					  AsTriShape();								  // 09 - { return 0; }
		virtual BSSegmentedTriShape*		  AsSegmentedTriShape();					  // 0A - { return 0; }
		virtual BSSubIndexTriShape*			  AsSubIndexTriShape();						  // 0B - { return 0; }
		virtual BSDynamicTriShape*			  AsDynamicTriShape();						  // 0C - { return 0; }
		virtual NiGeometry*					  AsNiGeometry();							  // 0D - { return 0; }
		virtual NiTriBasedGeom*				  AsNiTriBasedGeom();						  // 0E - { return 0; }
		virtual NiTriShape*					  AsNiTriShape();							  // 0F - { return 0; }
		virtual NiParticles*				  AsParticlesGeom();						  // 10 - { return 0; }
		virtual BSLines*					  AsLinesGeom();							  // 11 - { return 0; }
		virtual bhkNiCollisionObject*		  AsBhkNiCollisionObject();					  // 12 - { return 0; }
		virtual bhkBlendCollisionObject*	  AsBhkBlendCollisionObject();				  // 13 - { return 0; }
		virtual bhkAttachmentCollisionObject* AsBhkAttachmentCollisionObject();			  // 14 - { return 0; }
		virtual bhkRigidBody*				  AsBhkRigidBody();							  // 15 - { return 0; }
		virtual bhkLimitedHingeConstraint*	  AsBhkLimitedHingeConstraint();			  // 16 - { return 0; }
		virtual NiObject*					  CreateClone(NiCloningProcess& a_cloning);	  // 17 - { return this; }
		virtual void						  LoadBinary(NiStream& a_stream);			  // 18 - { return; }
		virtual void						  LinkObject(NiStream& a_stream);			  // 19 - { return; }
		virtual bool						  RegisterStreamables(NiStream& a_stream);	  // 1A
		virtual void						  SaveBinary(NiStream& a_stream);			  // 1B - { return; }
		virtual bool						  IsEqual(NiObject* a_object);				  // 1C
		virtual void						  ProcessClone(NiCloningProcess& a_cloning);  // 1D
		virtual void						  PostLinkObject(NiStream& a_stream);		  // 1E - { return; }
		virtual bool						  StreamCanSkip();							  // 1F - { return false; }
		virtual const NiRTTI*				  GetStreamableRTTI() const;				  // 20 - { return GetRTTI(); }
		virtual UInt32						  GetBlockAllocationSize() const;			  // 21 - { return 0; }
		virtual NiObjectGroup*				  GetGroup() const;							  // 22 - { return 0; }
		virtual void						  SetGroup(NiObjectGroup* a_group);			  // 23 - { return; }
		virtual NiControllerManager*		  AsNiControllerManager();					  // 24 - { return 0; }

		void CreateDeepCopy(NiPointer<NiObject>& a_result);
	};
	STATIC_ASSERT(sizeof(NiObject) == 0x10);
}
