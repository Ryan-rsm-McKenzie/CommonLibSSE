#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IFormFactory

#include "RE/FormTypes.h"  // FormType, TESForm


namespace RE
{
	template <class T, FormType> class ConcreteFormFactory;


	class IFormFactory
	{
	public:
		inline static const void* RTTI = RTTI_IFormFactory;


		virtual ~IFormFactory();							// 00

	protected:
		// add
		virtual TESForm*	CreateImpl() const = 0;			// 01

	public:
		virtual const char*	GetName() const = 0;			// 02

	protected:
		virtual UInt32		GetFormTypeImpl() const = 0;	// 03

	public:
		virtual const char*	GetObjectName() const;			// 04 - { return 0; }
		virtual UInt32		GetNum1() const;				// 05 - { return 106; }
		virtual UInt32		GetNum2() const;				// 06 - { return 9; }

		static IFormFactory*																	GetFormFactoryByType(FormType a_formType);
		template <class T> static ConcreteFormFactory<T, static_cast<FormType>(T::kTypeID)>*	GetConcreteFormFactoryByType();

		FormType	GetFormType() const;
		TESForm*	Create() const;
	};
	STATIC_ASSERT(sizeof(IFormFactory) == 0x8);
}
