#pragma once

#include <string>

#include "RE/BSResource/ErrorCodes.h"
#include "RE/BSResource/Stream.h"
#include "RE/BSTSmartPointer.h"
#include "RE/NiBinaryStream.h"


namespace RE
{
	namespace BSResource
	{
		class Location;
	}


	class BSResourceNiBinaryStream : public NiBinaryStream
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSResourceNiBinaryStream;


		struct BufferType
		{
		public:
		};


		BSResourceNiBinaryStream();
		BSResourceNiBinaryStream(const char* a_fileName);
		BSResourceNiBinaryStream(const std::string& a_fileName);
		virtual ~BSResourceNiBinaryStream();  // 00

		// override (NiBinaryStream)
		virtual bool   good() const override;					 // 01 - { return static_cast<bool>(stream); }
		virtual void   seek(SInt32 a_numBytes) override;		 // 02
		virtual UInt32 tell() const override;					 // 03 - { return streamPos; }
		virtual void   get_info(BufferInfo& a_buf) override;	 // 04
		virtual void   set_endian_swap(bool a_doSwap) override;	 // 05


		// members
		BSTSmartPointer<BSResource::Stream> stream;		// 20
		BufferType*							buffer;		// 28
		UInt32								streamPos;	// 30
		BSResource::ErrorCode				lastError;	// 34

	private:
		BSResourceNiBinaryStream* ctor(const char* a_name, bool a_writeable = false, BSResource::Location* a_optionalStart = 0);
		void					  dtor();
	};
	STATIC_ASSERT(sizeof(BSResourceNiBinaryStream) == 0x38);
}
