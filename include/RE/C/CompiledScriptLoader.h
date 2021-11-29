#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/I/ILoader.h"

namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class IStore;

		class CompiledScriptLoader : public ILoader
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__CompiledScriptLoader;

			~CompiledScriptLoader() override;  // 00

			// override (ILoader)
			ILoader* Clone() override;                                                                  // 01
			void     SetScriptStore(const BSTSmartPointer<IStore>& a_store) override;                   // 02
			bool     GetClass(const char* a_name, BSScript::UnlinkedTypes::Object& a_object) override;  // 03

			// members
			ErrorLogger*            errorHandler;  // 08
			BSTSmartPointer<IStore> scriptStore;   // 10
			std::uint64_t           unk18;         // 18
			std::uint64_t           unk20;         // 20
			std::uint64_t           unk28;         // 28
			std::uint64_t           unk30;         // 30
		};
		static_assert(sizeof(CompiledScriptLoader) == 0x38);
	}
}
