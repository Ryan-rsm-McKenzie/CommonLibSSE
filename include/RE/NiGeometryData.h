#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiGeometryData
#include "skse64/NiRTTI.h"  // NiRTTI_NiGeometryData

#include "RE/NiBound.h"  // NiBound
#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiAdditionalGeometryData;
	class NiColorA;
	class NiPoint2;
	class NiPoint3;


	class NiGeometryData : public NiObject
	{
	public:
		inline static const void* RTTI = RTTI_NiGeometryData;
		inline static const void* Ni_RTTI = NiRTTI_NiGeometryData;


		enum class DataFlag: UInt16
		{
			kNone = 0x0000,
			kNDL = 0x1000,
			kMax = 0x2000,
			kATI = 0x3000,
		};


		enum class DirtyFlag : UInt16
		{
			kVertex = 1 << 0,
			kNormal = 1 << 1,
			kColor = 1 << 2,
			kTexture = 1 << 3,

			kMutable = 0,
			kStatic = 1 << 14,
			kVolatile = 1 << 15
		};


		enum class KeepFlag : UInt8
		{
			kXYZ = 1 << 0,
			kNorm = 1 << 1,
			kColor = 1 << 2,
			kUV = 1 << 3,
			kIndices = 1 << 4,
			kBonedata = 1 << 5,

			kAll = kXYZ | kNorm | kColor | kUV | kIndices | kBonedata
		};


		enum class CompressFlag : UInt8
		{
			kNorm = 1 << 0,
			kColor = 1 << 1,
			kUV = 1 << 2,
			kWeight = 1 << 3,
			kPosition = 1 << 4,

			kAll = kNorm | kColor | kUV | kWeight | kPosition
		};


		virtual ~NiGeometryData();	// 00

		// override (NiObject)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C

		// add
		virtual void			Unk_25(void);										// 25 - { return; }
		virtual UInt16			GetNumVertices();									// 26 - { return vertices; }
		virtual void			Unk_27(void);										// 27 - { return 0; }
		virtual void			Unk_28(void);										// 28 - { return 0; }
		virtual void			Unk_29(void) = 0;									// 29


		// members
		UInt16								vertices;			// 10
		UInt16								id;					// 12
		DirtyFlag							dirtyFlags;			// 14
		DataFlag							dataFlags;			// 16
		NiBound								bound;				// 18
		NiPoint3*							vertex;				// 28
		NiPoint3*							normal;				// 30
		NiColorA*							color;				// 38
		NiPoint2*							texture;			// 40
		UInt32								unk48;				// 48
		UInt32								unk4C;				// 4C
		UInt32								unk50;				// 50
		UInt32								unk54;				// 54
		NiPointer<NiAdditionalGeometryData>	additionalGeomData;	// 58
		UInt32								unk60;				// 60
		KeepFlag							keepFlags;			// 64
		CompressFlag						compressFlags;		// 65
		bool								hasGeoData;			// 66
		UInt8								unk67;				// 67
	};
	STATIC_ASSERT(sizeof(NiGeometryData) == 0x68);
}
