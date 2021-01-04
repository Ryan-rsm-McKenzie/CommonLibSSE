#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;
	class NiAVObject;
	class TESObjectCELL;

	enum class TEMP_EFFECT_TYPE
	{
		kTerrain = 0,
		kWeaponBlood = 1,
		kDecal = 2,
		kGeometryDecal = 3,
		kParticle = 4,
		kDebris = 5,
		kSPG = 6,
		kDefault = 7,
		kRefDefault = 8,
		kRefModel = 9,
		kRefShader = 10,
		kMagicSummon = 11
	};

	class BSTempEffect : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffect;

		virtual ~BSTempEffect();  // 00

		// override (NiObject)
		virtual const NiRTTI*				  GetRTTI() const override;					  // 02
		virtual NiNode*						  AsNode() override;						  // 03 - { return 0; }
		virtual NiSwitchNode*				  AsSwitchNode() override;					  // 04 - { return 0; }
		virtual BSFadeNode*					  AsFadeNode() override;					  // 05 - { return 0; }
		virtual BSMultiBoundNode*			  AsMultiBoundNode() override;				  // 06 - { return 0; }
		virtual BSGeometry*					  AsGeometry() override;					  // 07 - { return 0; }
		virtual NiTriStrips*				  AsTriStrips() override;					  // 08 - { return 0; }
		virtual BSTriShape*					  AsTriShape() override;					  // 09 - { return 0; }
		virtual BSSegmentedTriShape*		  AsSegmentedTriShape() override;			  // 0A - { return 0; }
		virtual BSSubIndexTriShape*			  AsSubIndexTriShape() override;			  // 0B - { return 0; }
		virtual BSDynamicTriShape*			  AsDynamicTriShape() override;				  // 0C - { return 0; }
		virtual NiGeometry*					  AsNiGeometry() override;					  // 0D - { return 0; }
		virtual NiTriBasedGeom*				  AsNiTriBasedGeom() override;				  // 0E - { return 0; }
		virtual NiTriShape*					  AsNiTriShape() override;					  // 0F - { return 0; }
		virtual NiParticles*				  AsParticlesGeom() override;				  // 10 - { return 0; }
		virtual BSLines*					  AsLinesGeom() override;					  // 11 - { return 0; }
		virtual bhkNiCollisionObject*		  AsBhkNiCollisionObject() override;		  // 12 - { return 0; }
		virtual bhkBlendCollisionObject*	  AsBhkBlendCollisionObject() override;		  // 13 - { return 0; }
		virtual bhkAttachmentCollisionObject* AsBhkAttachmentCollisionObject() override;  // 14 - { return 0; }
		virtual bhkRigidBody*				  AsBhkRigidBody() override;				  // 15 - { return 0; }
		virtual bhkLimitedHingeConstraint*	  AsBhkLimitedHingeConstraint() override;	  // 16 - { return 0; }

		// add
		virtual void			 Initialize();									   // 25 - { initialized = true; }
		virtual void			 Attach();										   // 26 - { return; }
		virtual void			 Detach();										   // 27 - { return; }
		virtual bool			 Update(float a_arg1);							   // 28
		virtual NiAVObject*		 Get3D() const;									   // 29 - { return 0; }
		virtual bool			 GetManagerHandlesSaveLoad() const;				   // 2A - { return true; }
		virtual bool			 GetClearWhenCellIsUnloaded() const;			   // 2B - { return true; }
		virtual TEMP_EFFECT_TYPE GetType() const;								   // 2C - { return 7; }
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf);			   // 2D
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf);			   // 2E
		virtual void			 FinishLoadGame(BGSLoadGameBuffer* a_buf);		   // 2F - { return; }
		virtual bool			 IsInterfaceEffect() const;						   // 30 - { return false; }
		virtual void			 SetInterfaceEffect(bool a_set);				   // 31 - { return; }
		virtual bool			 GetStackable() const;							   // 32 - { return false; }
		virtual bool			 GetStackableMatch(BSTempEffect* a_effect) const;  // 33 - { return false; }
		virtual void			 Push();										   // 34 - { return; }
		virtual void			 Pop();											   // 35 - { return; }

		// members
		float		   lifetime;	 // 10
		std::uint32_t  pad14;		 // 14
		TESObjectCELL* cell;		 // 18
		float		   age;			 // 20
		bool		   initialized;	 // 24
		std::uint8_t   pad25;		 // 25
		std::uint16_t  pad26;		 // 26
		std::uint32_t  effectID;	 // 28
		std::uint32_t  pad2C;		 // 2C
	};
	static_assert(sizeof(BSTempEffect) == 0x30);
}
