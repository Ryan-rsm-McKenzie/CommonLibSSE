#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSScriptType.h"  // BSScriptType
#include "RE/IFunction.h"  // IFunction


namespace RE
{
	namespace BSScript
	{
		class BSScriptVariable;
		class StackFrame;
		class VMClassInfo;


		namespace NF_util
		{
			class NativeFunctionBase : public IFunction
			{
			public:
				struct ParameterInfo
				{
					struct Entry
					{
						// members
						BSFixedString	name;	// 00
						BSScriptType	type;	// 08
					};
					STATIC_ASSERT(sizeof(Entry) == 0x10);


					// members
					Entry*	data;		// 00 length = numParams + unk0A
					UInt16	numParams;	// 08
					UInt16	unk0A;		// 0A
					UInt32	pad0C;		// 0C
				};
				STATIC_ASSERT(sizeof(ParameterInfo) == 0x10);


				NativeFunctionBase() = delete;
				explicit NativeFunctionBase(const char* a_fnName, const char* a_className, bool a_isStatic, UInt32 a_numParams);
				virtual ~NativeFunctionBase();																																					// 00

				// override (IFunction)
				virtual const BSFixedString&	GetFunctionName() const override;																												// 01
				virtual const BSFixedString&	GetScriptName() const override;																													// 02
				virtual const BSFixedString&	GetStateName() const override;																													// 03
				virtual void					GetReturnType(BSScriptType& a_dst) const override;																								// 04
				virtual UInt32					GetNumParams() const override;																													// 05
				virtual BSScriptType&			GetParam(UInt32 a_idx, BSFixedString& a_nameOut, BSScriptType& a_typeOut) const override;														// 06
				virtual UInt32					GetNumParams2() const override;																													// 07
				virtual bool					IsNative() const override;																														// 08
				virtual bool					IsStatic() const override;																														// 09
				virtual bool					IsEvent() const override;																														// 0A
				virtual UInt32					Unk_0B() override;																																// 0B
				virtual UInt32					GetUnk44() const override;																														// 0C
				virtual const BSFixedString&	GetStr48() const override;																														// 0D
				virtual void					Unk_0E(UInt32 a_arg1) override;																													// 0E
				virtual UInt32					Invoke(BSScriptStackPtr& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, UInt32 a_arg4) override;								// 0F
				virtual const BSFixedString&	GetSource() const override;																														// 10
				virtual bool					Unk_11(UInt32 a_arg1, UInt32* a_arg2) override;																									// 11
				virtual bool					GetParamName(UInt32 a_idx, BSFixedString& a_out) const override;																				// 12
				virtual bool					GetUnk41() const override;																														// 13
				virtual void					SetUnk41(bool a_arg) override;																													// 14

				// add
				virtual bool					HasCallback() const = 0;																														// 15
				virtual bool					Run(BSScriptVariable* a_baseValue, Internal::VirtualMachine* a_vm, UInt32 a_stackID, BSScriptVariable* a_resultValue, StackFrame* a_frame) = 0;	// 16

			protected:
				// members
				BSFixedString	_fnName;		// 10
				BSFixedString	_scriptName;	// 18
				BSFixedString	_stateName;		// 20
				VMTypeID		_returnType;	// 28
				ParameterInfo	_params;		// 30
				bool			_isStatic;		// 40
				bool			_unk41;			// 41
				bool			_isLatent;		// 42
				UInt8			_pad43;			// 43
				UInt32			_unk44;			// 44
				BSFixedString	_unk48;			// 48

			private:
				NativeFunctionBase* Ctor(const char* a_fnName, const char* a_className, bool a_isStatic, UInt32 a_numParams);
				void				Dtor();
			};
			STATIC_ASSERT(sizeof(NativeFunctionBase) == 0x50);
		}
	}
}
