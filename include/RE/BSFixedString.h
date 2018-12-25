#pragma once


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

		UInt32			length() const;
		const char*		c_str() const;

	protected:
		const char* data;
	};
	STATIC_ASSERT(sizeof(BSFixedString) == 0x8);
}
