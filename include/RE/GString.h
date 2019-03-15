#pragma once


namespace RE
{
	class GStringBuffer;


	class GString
	{
		friend class GStringLH;
		friend class GStringDH;
	public:
		enum class HeapType : UInt32
		{
			kGlobal = 0,	// Global
			kLocal = 1,		// Address-based
			kDynamic = 2,	// Part of class
			kMask = 3
		};


		struct FlagConstants
		{
#pragma warning(push)
#pragma warning(disable: 4293)
			enum FlagConstant : UPInt
			{
				kLengthFlagBit = 1 << (sizeof(UPInt) * 8 - 1)
			};
		};
#pragma warning(pop)


		struct DataDesc
		{
			void	AddRef();
			void	Release();
			UPInt	GetSize() const;
			UPInt	GetLengthFlag() const;
			bool	LengthIsSize() const;


			// members
			UPInt			size;		// 00
			volatile SInt32	refCount;	// 08
			char			data[1];	// 0C
		};
		STATIC_ASSERT(sizeof(DataDesc) == 0x10);


		union DataDescUnion
		{
			DataDescUnion();


			DataDesc*	data;
			HeapType	heapTypeBits;
		};
		STATIC_ASSERT(sizeof(DataDescUnion) == 0x8);


		GString();
		GString(const char* a_s);
		~GString();

	protected:
		GString*	ctor_internal(const char* a_s);
		HeapType	GetHeapType() const;
		DataDesc*	GetData() const;
		void		SetData(DataDesc* a_desc);


		// members
		DataDescUnion _dataDesc;	// 0
	};
	STATIC_ASSERT(sizeof(GString) == 0x8);
}
