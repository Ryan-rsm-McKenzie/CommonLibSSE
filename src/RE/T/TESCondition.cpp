#include "RE/T/TESCondition.h"

namespace RE
{
	FUNCTION_DATA::FUNCTION_DATA() :
		function(static_cast<FunctionID>(-1)),
		pad02(0),
		pad04(0),
		params{ nullptr }
	{}

	CONDITION_ITEM_DATA::GlobalOrFloat::GlobalOrFloat() :
		g(nullptr)
	{}

	CONDITION_ITEM_DATA::Flags::Flags() :
		isOR(false),
		usesAliases(false),
		global(false),
		usePackData(false),
		swapTarget(false),
		opCode(OpCode::kEqualTo)
	{}

	CONDITION_ITEM_DATA::CONDITION_ITEM_DATA() :
		comparisonValue(),
		runOnRef(),
		dataID(0),
		functionData(),
		flags(),
		object(CONDITIONITEMOBJECT::kSelf),
		pad32(0),
		pad34(0)
	{}

	TESConditionItem::TESConditionItem() :
		next(nullptr),
		data()
	{}

	bool TESConditionItem::operator()(ConditionCheckParams& a_solution) const
	{
		return IsTrue(a_solution);
	}

	bool TESConditionItem::IsTrue(ConditionCheckParams& a_solution) const
	{
		using func_t = decltype(&TESConditionItem::IsTrue);
		REL::Relocation<func_t> func{ REL::ID(29090) };
		return func(this, a_solution);
	}

	TESCondition::TESCondition() :
		head(nullptr)
	{}

	TESCondition::~TESCondition()
	{
		auto cur = head;
		while (cur) {
			auto next = cur->next;
			delete cur;
			cur = next;
		}
		head = nullptr;
	}

	TESCondition::operator bool() const
	{
		return head != nullptr;
	}

	bool TESCondition::operator()(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef) const
	{
		return IsTrue(a_actionRef, a_targetRef);
	}

	bool TESCondition::IsTrue(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef) const
	{
		using func_t = decltype(&TESCondition::IsTrue);
		REL::Relocation<func_t> func{ REL::ID(29074) };
		return func(this, a_actionRef, a_targetRef);
	}
}
