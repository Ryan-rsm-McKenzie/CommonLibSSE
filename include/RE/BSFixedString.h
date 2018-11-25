#pragma once

#include "skse64_common/Relocation.h"  // RelocAddr


namespace RE
{
	class BSFixedString
	{
	public:
		BSFixedString();
		BSFixedString(const BSFixedString& a_str);
		BSFixedString(BSFixedString&& a_str);
		BSFixedString(const char* a_str);
		~BSFixedString();

		operator const char*() const;

		BSFixedString&	operator=(const BSFixedString& a_rhs);
		BSFixedString&	operator=(BSFixedString&& a_rhs);
		BSFixedString&	operator=(const char* a_rhs);

		bool			operator==(const char* a_str) const;
		bool			operator!=(const char* a_str) const;
		bool			operator==(const BSFixedString& a_rhs) const;
		bool			operator!=(const BSFixedString& a_rhs) const;

		const char*		c_str(void) const;

	protected:
		const char* data;

	private:
		typedef BSFixedString* _CopyCtor_t(BSFixedString* a_this, const BSFixedString& a_str);
		static RelocAddr<_CopyCtor_t*> _CopyCtor;

		typedef BSFixedString* _SetCopy_t(BSFixedString* a_this, const BSFixedString& a_rhs);
		static RelocAddr<_SetCopy_t*> _SetCopy;
	};
	STATIC_ASSERT(sizeof(BSFixedString) == 0x8);
}
