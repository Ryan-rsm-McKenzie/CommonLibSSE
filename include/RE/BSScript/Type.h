#pragma once


namespace RE
{
	namespace BSScript
	{
		class Class;


		class Type
		{
		public:
			Type();
			explicit Type(VMTypeID a_type);
			Type(const Type& a_rhs);
			Type(Type&& a_rhs);

			Type&	operator=(const Type& a_rhs);
			Type&	operator=(Type&& a_rhs);

			Class*		GetClass() const;
			VMTypeID	GetTypeID() const;
			VMTypeID	GetUnmangledType() const;
			bool 		IsArray() const;
			bool 		IsBool() const;
			bool 		IsFloat() const;
			bool 		IsInt() const;
			bool 		IsLiteralArray() const;
			bool		IsNoneArray() const;
			bool		IsNoneObject() const;
			bool		IsObject(void)	const;
			bool 		IsObjectArray() const;
			bool 		IsString() const;
			void		SetTypeID(VMTypeID a_type);


		protected:
			// members
			VMTypeID type;	// 00
		};
		STATIC_ASSERT(sizeof(Type) == 0x8);
	}
}
