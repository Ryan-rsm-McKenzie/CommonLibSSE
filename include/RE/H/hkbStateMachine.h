#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkbBindable.h"
#include "RE/H/hkbEvent.h"
#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbStateChooser;

	class hkbStateMachine : public hkbGenerator
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbStateMachine;

		enum class StartStateMode
		{
			kDefault = 0,
			kSync = 1,
			kRandom = 2,
			kChooser = 3
		};

		enum class StateMachineSelfTransitionMode
		{
			kNoTransition = 0,
			kTransitionToStartState = 1,
			kForceTransitionToStartState = 2
		};

		class StateInfo : public hkbBindable
		{
		public:
			inline static constexpr auto RTTI = RTTI_hkbStateMachine__StateInfo;

			virtual ~StateInfo();  // 00

			// members
			std::uint64_t unk30;  // 30
			std::uint64_t unk38;  // 38
			std::uint64_t unk40;  // 40
			std::uint64_t unk48;  // 48
			std::uint64_t unk50;  // 50
			std::uint64_t unk58;  // 58
			std::uint64_t unk60;  // 60
			std::uint64_t unk68;  // 68
			std::uint64_t unk70;  // 70
		};
		static_assert(sizeof(StateInfo) == 0x78);

		class TransitionInfoArray : public hkReferencedObject
		{
		public:
			inline static constexpr auto RTTI = RTTI_hkbStateMachine__TransitionInfoArray;

			virtual ~TransitionInfoArray();	 // 00

			// members
			std::uint64_t unk10;  // 10
			std::uint64_t unk18;  // 18
		};
		static_assert(sizeof(TransitionInfoArray) == 0x20);

		virtual ~hkbStateMachine();	 // 00

		// override (hkbGenerator)
		virtual hkClass* GetClassType() const override;																		// 01
		virtual void	 CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02
		virtual void	 Unk_03(void) override;																				// 03
		virtual void	 Unk_04(void) override;																				// 04
		virtual void	 Unk_05(void) override;																				// 05
		virtual void	 Unk_06(void) override;																				// 06
		virtual void	 Unk_07(void) override;																				// 07
		virtual void	 Unk_08(void) override;																				// 08
		virtual void	 Unk_09(void) override;																				// 09
		virtual void	 Unk_0A(void) override;																				// 0A
		virtual void	 Unk_0C(void) override;																				// 0C
		virtual void	 Unk_0D(void) override;																				// 0D
		virtual void	 Unk_0E(void) override;																				// 0E
		virtual void	 Unk_0F(void) override;																				// 0F
		virtual void	 Unk_10(void) override;																				// 10
		virtual void	 Unk_11(void) override;																				// 11
		virtual void	 Unk_12(void) override;																				// 12
		virtual void	 Unk_14(void) override;																				// 14
		virtual void	 Unk_17(void) override;																				// 17
		virtual void	 Unk_18(void) override;																				// 18 - { return 1; }
		virtual void	 Unk_19(void) override;																				// 19
		virtual void	 Unk_1B(void) override;																				// 1B - { echoNextUpdate = true; }

		// members
		hkbEvent													   eventToSendWhenStateOrTransitionChanges;	 // 048
		hkRefPtr<hkbStateChooser>									   startStateChooser;						 // 060
		std::int32_t												   startStateID;							 // 068
		std::int32_t												   returnToPreviousStateEventID;			 // 06C
		std::int32_t												   randomTransitionEventID;					 // 070
		std::int32_t												   transitionToNextHigherStateEventID;		 // 074
		std::int32_t												   transitionToNextLowerStateEventID;		 // 078
		std::int32_t												   syncVariableIndex;						 // 07C
		std::int32_t												   currentStateID;							 // 080
		bool														   wrapAroundStateID;						 // 084
		std::int8_t													   maxSimultaneousTransitions;				 // 085
		stl::enumeration<StartStateMode, std::uint8_t>				   startStateMode;							 // 086
		stl::enumeration<StateMachineSelfTransitionMode, std::uint8_t> selfTransitionMode;						 // 087
		bool														   isActive;								 // 088
		std::uint8_t												   pad41;									 // 089
		std::uint16_t												   pad42;									 // 08A
		std::uint32_t												   pad44;									 // 08C
		hkArray<StateInfo*>											   states;									 // 090
		hkRefPtr<TransitionInfoArray>								   wildcardTransitions;						 // 0A0
		hkRefVariant												   stateIDToIndexMap;						 // 0A8
		hkArray<hkRefVariant>										   activeTransitions;						 // 0B0
		hkArray<hkRefVariant>										   transitionFlags;							 // 0C0
		hkArray<hkRefVariant>										   wildcardTransitionFlags;					 // 0D0
		hkArray<hkRefVariant>										   delayedTransitions;						 // 0E0
		float														   timeInState;								 // 0F0
		float														   lastLocalTime;							 // 0F4
		std::int32_t												   previousStateID;							 // 0F8
		std::int32_t												   nextStartStateIndexOverride;				 // 0FC
		bool														   stateOrTransitionChanged;				 // 100
		bool														   echoNextUpdate;							 // 101
		std::uint16_t												   currentStateIndexAndEntered;				 // 102
		std::uint32_t												   pad0BC;									 // 104
	};
	static_assert(sizeof(hkbStateMachine) == 0x108);
}
