#pragma once

#include "RE/BSScript/ILoader.h"
#include "RE/BSTSmartPointer.h"


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


			virtual ~CompiledScriptLoader();  // 00

			// override (ILoader)
			virtual ILoader* Clone() override;																	// 01
			virtual void	 SetScriptStore(const BSTSmartPointer<IStore>& a_store) override;					// 02
			virtual bool	 GetClass(const char* a_name, BSScript::UnlinkedTypes::Object& a_object) override;	// 03


			// members
			ErrorLogger*			errorHandler;  // 08
			BSTSmartPointer<IStore> scriptStore;   // 10
			UInt64					unk18;		   // 18
			UInt64					unk20;		   // 20
			UInt64					unk28;		   // 28
			UInt64					unk30;		   // 30
		};
		STATIC_ASSERT(sizeof(CompiledScriptLoader) == 0x38);
	}
}
