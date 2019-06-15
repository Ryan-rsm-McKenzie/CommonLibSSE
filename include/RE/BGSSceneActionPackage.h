#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSSceneActionPackage

#include "RE/BGSSceneAction.h"  // BGSSceneAction
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // TESPackage


namespace RE
{
	class BGSSceneActionPackage : public BGSSceneAction
	{
	public:
		inline static const void* RTTI = RTTI_BGSSceneActionPackage;


		enum { kTypeID = Type::kPackage };


		virtual ~BGSSceneActionPackage();												// 00

		// override (BGSSceneAction)
		virtual bool	LoadSceneAction(TESFile* a_mod) override;						// 01
		virtual void	Unk_02(void) override;											// 02
		virtual Type	GetType() const override;										// 07 - { return kPackage; }
		virtual void	Unk_08(void) override;											// 08
		virtual void	LoadBuffer(void* a_arg1, BGSLoadGameBuffer*  a_buf) override;	// 09
		virtual void	Unk_0A(void) override;											// 0A
		virtual void	Unk_0B(void) override;											// 0B
		virtual void	Unk_10(void) override;											// 10
		virtual void	Unk_11(void) override;											// 11
		virtual void	Unk_12(void) override;											// 12
		virtual void	Unk_13(void) override;											// 13


		// members
		UInt64					unk20;		// 20
		BSTArray<TESPackage*>	packages;	// 28 - PNAM
	};
	STATIC_ASSERT(sizeof(BGSSceneActionPackage) == 0x40);
}
