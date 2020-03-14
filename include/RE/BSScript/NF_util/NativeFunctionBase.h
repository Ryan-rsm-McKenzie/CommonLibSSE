#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSScript/IFunction.h"
#include "RE/BSScript/Internal/VDescTable.h"
#include "RE/BSScript/TypeInfo.h"


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class VirtualMachine;
		}


		class StackFrame;
		class Variable;


		namespace NF_util
		{
			class NativeFunctionBase : public IFunction
			{
			public:
				inline static constexpr auto RTTI = RTTI_BSScript__NF_util__NativeFunctionBase;


				NativeFunctionBase() = delete;
				explicit NativeFunctionBase(const char* a_fnName, const char* a_className, bool a_isStatic, UInt16 a_numParams);
				virtual ~NativeFunctionBase() = default;  // 00

				// override (IFunction)
				virtual const BSFixedString& GetName() const override;																									// 01
				virtual const BSFixedString& GetObjectTypeName() const override;																						// 02
				virtual const BSFixedString& GetStateName() const override;																								// 03
				virtual TypeInfo			 GetReturnType() const override;																							// 04
				virtual UInt32				 GetParamCount() const override;																							// 05
				virtual void				 GetParam(UInt32 a_idx, BSFixedString& a_nameOut, TypeInfo& a_typeOut) const override;										// 06
				virtual UInt32				 GetStackFrameSize() const override;																						// 07
				virtual bool				 GetIsNative() const override;																								// 08
				virtual bool				 GetIsStatic() const override;																								// 09
				virtual bool				 GetIsEmpty() const override;																								// 0A
				virtual FunctionType		 GetFunctionType() const override;																							// 0B
				virtual UInt32				 GetUserFlags() const override;																								// 0C
				virtual const BSFixedString& GetDocString() const override;																								// 0D
				virtual void				 InsertLocals(StackFrame* a_frame) override;																				// 0E
				virtual CallResult			 Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4) override;	// 0F
				virtual const BSFixedString& GetSourceFilename() const override;																						// 10
				virtual bool				 TranslateIPToLineNumber(UInt32 a_taskletExecutionOffset, UInt32& a_lineNumberOut) const override;							// 11
				virtual bool				 GetVarNameForStackIndex(UInt32 a_idx, BSFixedString& a_nameOut) const override;											// 12
				virtual bool				 CanBeCalledFromTasklets() const override;																					// 13
				virtual void				 SetCallableFromTasklets(bool a_callable) override;																			// 14

				// add
				virtual bool HasStub() const = 0;																																			 // 15
				virtual bool MarshallAndDispatch(Variable& a_baseValue, Internal::VirtualMachine& a_vm, VMStackID a_stackID, Variable& a_resultValue, const StackFrame& a_frame) const = 0;	 // 16

			protected:
				// members
				BSFixedString		 _name;					  // 10
				BSFixedString		 _objName;				  // 18
				BSFixedString		 _stateName;			  // 20
				TypeInfo			 _retType;				  // 28
				Internal::VDescTable _descTable;			  // 30
				bool				 _isStatic;				  // 40
				bool				 _isCallableFromTasklet;  // 41
				bool				 _isLatent;				  // 42
				UInt8				 _pad43;				  // 43
				UInt32				 _userFlags;			  // 44
				BSFixedString		 _docString;			  // 48

			private:
				NativeFunctionBase* Ctor(const char* a_fnName, const char* a_className, bool a_isStatic, UInt32 a_numParams);
				void				Dtor();
			};
			STATIC_ASSERT(sizeof(NativeFunctionBase) == 0x50);
		}
	}
}
