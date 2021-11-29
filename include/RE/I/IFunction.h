#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class VirtualMachine;
		}

		class ErrorLogger;
		class Stack;
		class StackFrame;
		class TypeInfo;
		class VMState;

		class IFunction : public BSIntrusiveRefCounted
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IFunction;

			enum class FunctionType
			{
				kNormal = 0,
				kGetter = 1,
				kSetter = 2
			};

			enum class CallResult
			{
				kCompleted = 0,
				kSetupForVM = 1,
				kInProgress = 2,
				kFailedRetry = 3,
				kFailedAbort = 4
			};

			IFunction();
			virtual ~IFunction() = default;  // 00

			// add
			virtual const BSFixedString& GetName() const = 0;                                                                                                  // 01
			virtual const BSFixedString& GetObjectTypeName() const = 0;                                                                                        // 02
			virtual const BSFixedString& GetStateName() const = 0;                                                                                             // 03
			virtual TypeInfo             GetReturnType() const = 0;                                                                                            // 04
			virtual std::uint32_t        GetParamCount() const = 0;                                                                                            // 05
			virtual void                 GetParam(std::uint32_t a_idx, BSFixedString& a_nameOut, TypeInfo& a_typeOut) const = 0;                               // 06
			virtual std::uint32_t        GetStackFrameSize() const = 0;                                                                                        // 07
			virtual bool                 GetIsNative() const = 0;                                                                                              // 08
			virtual bool                 GetIsStatic() const = 0;                                                                                              // 09
			virtual bool                 GetIsEmpty() const = 0;                                                                                               // 0A
			virtual FunctionType         GetFunctionType() const = 0;                                                                                          // 0B
			virtual std::uint32_t        GetUserFlags() const = 0;                                                                                             // 0C
			virtual const BSFixedString& GetDocString() const = 0;                                                                                             // 0D
			virtual void                 InsertLocals(StackFrame* a_frame) = 0;                                                                                // 0E
			virtual CallResult           Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4) = 0;  // 0F
			virtual const BSFixedString& GetSourceFilename() const = 0;                                                                                        // 10
			virtual bool                 TranslateIPToLineNumber(std::uint32_t a_indexPtr, std::uint32_t& a_lineNumberOut) const = 0;                          // 11
			virtual bool                 GetVarNameForStackIndex(std::uint32_t a_idx, BSFixedString& a_nameOut) const = 0;                                     // 12
			virtual bool                 CanBeCalledFromTasklets() const = 0;                                                                                  // 13
			virtual void                 SetCallableFromTasklets(bool a_callable) = 0;                                                                         // 14

			// members
			std::uint32_t pad0C;  // 0C
		};
		static_assert(sizeof(IFunction) == 0x10);
	}
}
