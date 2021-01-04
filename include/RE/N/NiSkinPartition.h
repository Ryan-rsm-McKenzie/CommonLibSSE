#pragma once

#include "RE/M/MemoryManager.h"
#include "RE/N/NiGeometryData.h"
#include "RE/N/NiObject.h"

namespace RE
{
	struct ID3D11Buffer;

	class NiSkinPartition : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiSkinPartition;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiSkinPartition;

		struct TriShape
		{
			ID3D11Buffer*		   vertexBuffer;   // 00
			ID3D11Buffer*		   indexBuffer;	   // 08
			std::uint64_t		   vertexDesc;	   // 10
			volatile std::uint32_t refCount;	   // 18
			std::uint32_t		   pad1C;		   // 1C
			std::uint8_t*		   rawVertexData;  // 20
			std::uint16_t*		   rawIndexData;   // 28
		};
		static_assert(sizeof(TriShape) == 0x30);

		class Partition
		{
		public:
			std::uint64_t  vertexDesc;		// 00
			std::uint16_t* bones;			// 08
			float*		   weights;			// 10
			std::uint16_t* vertexMap;		// 18
			std::uint8_t*  bonePalette;		// 20
			std::uint16_t* triList;			// 28
			std::uint16_t* stripLengths;	// 30
			std::uint16_t  vertices;		// 38
			std::uint16_t  triangles;		// 3A
			std::uint16_t  numBones;		// 3C
			std::uint16_t  strips;			// 3E
			std::uint16_t  bonesPerVertex;	// 40
			std::uint16_t  pad42;			// 42
			float		   unk44;			// 44
			TriShape*	   buffData;		// 48
		};
		static_assert(sizeof(Partition) == 0x50);

		virtual ~NiSkinPartition();	 // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { NiObject::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { return NiObject::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C

		// add
		virtual void Unk_25(void);	// 25

		// members
		std::uint32_t		   numPartitions;  // 10
		std::uint32_t		   pad14;		   // 14
		SimpleArray<Partition> partitions;	   // 18
		std::uint64_t		   unk20;		   // 20
	};
	static_assert(sizeof(NiSkinPartition) == 0x28);
}
