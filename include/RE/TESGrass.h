#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESGrass

#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class TESGrass :
		public TESBoundObject,	// 00
		public TESModel			// 30
	{
	public:
		inline static const void* RTTI = RTTI_TESGrass;


		enum { kTypeID = FormType::Grass };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class UnitsFromWaterType : UInt32
			{
				kAbove_AtLeast = 0,
				kAbove_AtMost = 1,
				kBelow_AtLeast = 2,
				kBelow_AtMost = 3,
				kEither_AtLeast = 4,
				kEither_AtMost = 5,
				kEither_AtMostAbove = 6,
				kEither_AtMostBelow = 7
			};


			enum class Flag : UInt8
			{
				kNone = 0,
				kVertexLighting = 1 << 0,
				kUniformScaling = 1 << 1,
				kFitToSlope = 1 << 2
			};


			UInt8				density;			// 00 - 58
			UInt8				minSlope;			// 01 - 59
			UInt8				maxSlope;			// 02 - 5A
			UInt8				unk03;				// 03 - 5B
			UInt16				unitsFromWater;		// 04 - 5C
			UInt8				unk06;				// 06 - 5E
			UInt8				unk07;				// 06 - 5F
			UnitsFromWaterType	unitsFromWaterType;	// 08 - 60
			float				positionRange;		// 0C - 64
			float				heightRange;		// 10 - 68
			float				colorRange;			// 14 - 6C
			float				wavePeriod;			// 18 - 70
			Flag				flags;				// 1C - 74
			UInt8				unk1D;				// 1D - 75
			UInt8				unk1E;				// 1E - 76
			UInt8				unk1F;				// 1F - 77
		};
		STATIC_ASSERT(sizeof(Data) == 0x20);


		virtual ~TESGrass();																						// 00

		// override (TESBoundObject)
		virtual void						InitDefaults() override;												// 04
		virtual bool						LoadForm(TESFile* a_mod) override;										// 06
		virtual void						InitItem() override;													// 13

		// add
		virtual UInt8						GetDensity() const;														// 53 - { return data.density; }
		virtual bool						SetDensity(UInt8 a_density);											// 54 - { if (a_density > 100) return false; data.density = a_density; return true; }
		virtual UInt8						GetMinSlope() const;													// 55 - { return data.minSlope; }
		virtual bool						SetMinSlope(UInt8 a_minSlope);											// 56 - { if (a_minSlope > 90 || a_minSlope > data.maxSlope) return false; data.minSlope = a_minSlope; return true; }
		virtual UInt8						GetMaxSlope() const;													// 57 - { return data.maxSlope; }
		virtual bool						SetMaxSlope(UInt8 a_maxSlope);											// 58 - { if (a_maxSlope > 90 || a_maxSlope < data.minSlope) return false; data.maxSlope = a_maxSlope; return true; }
		virtual float						GetMinSlopeAngle() const;												// 59 - { return data.minSlope * 1deg; }
		virtual float						GetMaxSlopeAngle() const;												// 5A - { return data.maxSlope * 1deg; }
		virtual UInt16						GetUnitsFromWater() const;												// 5B - { return data.unitsFromWater; }
		virtual void						SetUnitsFromWater(UInt16 a_unitsFromWater);								// 5C - { data.unitsFromWater = a_unitsFromWater; }
		virtual Data::UnitsFromWaterType	GetUnitsFromWaterType() const;											// 5D - { return data.unitsFromWaterType; }
		virtual void						SetUnitsFromWaterType(Data::UnitsFromWaterType a_unitsFromWaterType);	// 5E - { data.unitsFromWaterType = a_unitsFromWaterType; }
		virtual float						GetPositionRange() const;												// 5F - { return data.positionRange; }
		virtual bool						SetPositionRange(float a_positionRange);								// 60 - { if (a_positionRange < 0.0 || a_positionRange > 512.0) return false; data.positionRange = a_positionRange; return true; }
		virtual float						GetHeightRange() const;													// 61 - { return data.heightRange; }
		virtual bool						SetHeightRange(float a_heightRange);									// 62 - { if (a_heightRange < 0.0 || a_heightRange > 1.0) return false; data.heightRange = a_heightRange; return true; }
		virtual float						GetColorRange() const;													// 63 - { return data.colorRange; }
		virtual bool						SetColorRange(float a_colorRange);										// 64 - { if (a_colorRange < 0.0 || a_colorRange > 1.0) return false; data.colorRange = a_colorRange; return true; }
		virtual float						GetWavePeriod() const;													// 65 - { return data.wavePeriod; }
		virtual bool						SetWavePeriod(float a_wavePeriod);										// 66 - { if (a_wavePeriod <= 0.0) return false; data.wavePeriod = a_wavePeriod; return true; }
		virtual bool						HasVertexLighting() const;												// 67 - { return data.flags & 1; }
		virtual void						SetOrInvertVertexLighting(bool a_set);									// 68 - { if (a_set) data.flags |= 0x1; else data.flags &= 0xFE; }
		virtual bool						HasUniformScaling() const;												// 69 - { return (data.flags >> 1) & 1; }
		virtual void						SetOrInvertUniformScaling(bool a_set);									// 6A - { if (a_set) data.flags |= 0x2; else data.flags &= 0xFD; }
		virtual bool						FitsToSlope() const;													// 6B - { return (data.flags >> 2) & 1; }
		virtual void						SetOrInvertFitsToSlope(bool a_set);										// 6C - { if (a_set) data.flags |= 0x4; else data.flags &= 0xFB; }


		// members
		Data data;	// 58 - DATA
	};
	STATIC_ASSERT(sizeof(TESGrass) == 0x78);
}
