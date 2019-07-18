#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSResourceNiBinaryStream

#include <string>  // string

#include "RE/NiBinaryStream.h"  // NiBinaryStream


namespace RE
{
	namespace BSResource
	{
		class LooseFileStream;
	}


	class BSResourceNiBinaryStream : public NiBinaryStream
	{
	public:
		inline static const void* RTTI = RTTI_BSResourceNiBinaryStream;


		BSResourceNiBinaryStream();
		BSResourceNiBinaryStream(const char* a_fileName);
		BSResourceNiBinaryStream(const std::string& a_fileName);
		virtual ~BSResourceNiBinaryStream();						// 00

		// override (NiBinaryStream)
		virtual	bool	is_open() const override;					// 01 - { return unk20 != 0; }
		virtual void	seek(SInt32 a_numBytes) override;			// 02
		virtual UInt32	tell() const override;						// 03 - { return unk30; }
		virtual void	copy_from(void* a_rhs) override;			// 04
		virtual void	set_endian_swap(bool a_doSwap) override;	// 05


		// members
		BSResource::LooseFileStream*	unk20;	// 20
		UInt64							unk28;	// 28
		UInt32							unk30;	// 30
		UInt32							unk34;	// 34

	private:
		BSResourceNiBinaryStream* ctor(const char* a_fileName, UInt32 a_arg2 = 0, UInt32 a_arg3 = 0);
		void dtor();
	};
	STATIC_ASSERT(sizeof(BSResourceNiBinaryStream) == 0x38);
}
