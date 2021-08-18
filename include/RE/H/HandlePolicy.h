#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/I/IObjectHandlePolicy.h"

namespace RE
{
	namespace SkyrimScript
	{
		class HandlePolicy : public BSScript::IObjectHandlePolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript__HandlePolicy;

			~HandlePolicy() override;  // 00

			// override (BSScript::IObjectHandlePolicy)
			bool     HandleIsType(VMTypeID a_typeID, VMHandle a_handle) const override;                 // 01
			bool     IsHandleObjectAvailable(VMHandle a_handle) const override;                         // 02
			VMHandle EmptyHandle() const override;                                                      // 03
			VMHandle GetHandleForObject(VMTypeID a_typeID, const void* a_srcData) const override;       // 04
			bool     HasParent(VMHandle a_handle) const override;                                       // 05
			VMHandle GetParentHandle(VMHandle a_handle) const override;                                 // 06
			VMHandle GetHandleScriptsMovedFrom(VMHandle a_handle) const override;                       // 07
			void*    GetObjectForHandle(VMTypeID a_typeID, VMHandle a_handle) const override;           // 08
			void     PersistHandle(VMHandle a_handle) override;                                         // 09
			void     ReleaseHandle(VMHandle a_handle) override;                                         // 0A
			void     ConvertHandleToString(VMHandle a_handle, BSFixedString& a_strOut) const override;  // 0B

			// members
			std::uint64_t                unk08;  // 08
			BSTHashMap<UnkKey, UnkValue> unk10;  // 10
			BSTHashMap<UnkKey, UnkValue> unk40;  // 40
		};
		static_assert(sizeof(HandlePolicy) == 0x70);
	}
}
