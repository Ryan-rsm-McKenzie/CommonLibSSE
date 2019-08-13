#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Setting

#include "RE/Color.h"


namespace RE
{
	class Setting
	{
	public:
		inline static const void* RTTI = RTTI_Setting;


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
			bool	b;
			float	f;
			SInt32	i;
			Color	r;
			char*	s;
			UInt32	u;
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		virtual ~Setting();			// 00

		// add
		virtual bool Unk_01(void);	// 01 - { return false; }

		bool		IsManaged() const;
		Type		GetType() const;
		const char*	GetName() const;

		bool		GetBool() const;
		float		GetFloat() const;
		SInt32		GetSInt() const;
		Color		GetColor() const;
		const char*	GetString() const;
		UInt32		GetUInt() const;


		// members
		Data	data;	// 08
		char*	name;	// 10
	};
	STATIC_ASSERT(sizeof(Setting) == 0x18);
}
