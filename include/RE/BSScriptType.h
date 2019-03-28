#pragma once


namespace RE
{
	namespace BSScript
	{
		class BSScriptClass;


		class BSScriptType
		{
		public:
			BSScriptType();
			explicit BSScriptType(VMTypeID a_type);
			explicit BSScriptType(const BSScriptType& a_rhs);

			VMTypeID		GetTypeID() const;
			void			SetTypeID(VMTypeID a_type);
			VMTypeID		GetUnmangledType() const;
			BSScriptClass*	GetScriptClass() const;
			bool			IsObject(void)	const;
			bool 			IsInt() const;
			bool 			IsFloat() const;
			bool 			IsString() const;
			bool 			IsBool() const;
			bool 			IsObjectArray() const;
			bool 			IsLiteralArray() const;
			bool 			IsArray() const;


		protected:
			// members
			VMTypeID type;	// 00
		};
		STATIC_ASSERT(sizeof(BSScriptType) == 0x8);
	}
}
