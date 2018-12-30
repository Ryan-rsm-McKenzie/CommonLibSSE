#pragma once


namespace RE
{
	class BSString;


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

		friend bool		operator==(const BSFixedString& a_lhs, const char* a_rhs) { return (a_lhs.data == a_rhs || _stricmp(a_lhs.data, a_rhs) == 0); }
		friend bool		operator!=(const BSFixedString& a_lhs, const char* a_rhs) { return !(a_lhs == a_rhs); }
		friend bool		operator==(const char* a_lhs, const BSFixedString& a_rhs) { return (a_rhs == a_lhs); }
		friend bool		operator!=(const char* a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		friend bool		operator==(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return (a_lhs == a_rhs.data); }
		friend bool		operator!=(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		bool			operator==(const BSString& a_rhs) const;
		bool			operator!=(const BSString& a_rhs) const;

		UInt32			length() const;
		const char*		c_str() const;

	protected:
		const char* data;
	};
	STATIC_ASSERT(sizeof(BSFixedString) == 0x8);
}
