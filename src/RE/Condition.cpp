#include "RE/Condition.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	Condition::ComparisonFlags::ComparisonFlags() :
		isOR(false),
		usesAliases(false),
		global(false),
		usePackData(false),
		swapTarget(false),
		opCode(OpCode::kEqualTo)
	{}


	Condition::Node::Node() :
		next(0),
		comparisonValue(0.0),
		unk0C(0),
		handle(0),
		unk14(0),
		functionID(static_cast<FunctionID>(-1)),
		unk1A(0),
		unk1B(0),
		pad1C(0),
		param1(0),
		param2(0),
		comparisonFlags(),
		referenceType(ReferenceType::kSubject),
		pad32(0),
		pad34(0)
	{}


	Condition::Condition() :
		head(0)
	{}


	Condition::~Condition()
	{
		auto cur = head;
		while (cur) {
			auto next = cur->next;
			delete cur;
			cur = next;
		}
		head = 0;
	}


	bool Condition::Node::Run(Solution& a_solution)
	{
		using func_t = function_type_t<decltype(&Condition::Node::Run)>;
		REL::Offset<func_t*> func(Offset::Condition::Node::Run);
		return func(this, a_solution);
	}


	Condition::operator bool() const
	{
		return head != 0;
	}


	bool Condition::Run(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target)
	{
		using func_t = function_type_t<decltype(&Condition::Run)>;
		REL::Offset<func_t*> func(Offset::Condition::Run);
		return func(this, a_perkOwner, a_target);
	}
}
