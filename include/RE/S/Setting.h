#pragma once

#include "RE/C/Color.h"

namespace RE
{
	class Setting
	{
	public:
		inline static constexpr auto RTTI = RTTI_Setting;

		enum class Type
		{
			kUnknown = 0,
			kBool,
			kFloat,
			kSignedInteger,
			kColor,
			kString,
			kUnsignedInteger
		};

		union Data
		{
			bool		  b;
			float		  f;
			std::int32_t  i;
			Color		  r;
			char*		  s;
			std::uint32_t u;
		};
		static_assert(sizeof(Data) == 0x8);

		virtual ~Setting();	 // 00

		// add
		virtual bool Unk_01(void);	// 01 - { return false; }

		bool		IsManaged() const;
		Type		GetType() const;
		const char* GetName() const;

		bool		  GetBool() const;
		float		  GetFloat() const;
		std::int32_t  GetSInt() const;
		Color		  GetColor() const;
		const char*	  GetString() const;
		std::uint32_t GetUInt() const;

		// members
		Data  data;	 // 08
		char* name;	 // 10
	};
	static_assert(sizeof(Setting) == 0x18);
}
