#pragma once

#include <variant>
#include <vector>

#ifndef XBYAK_NO_OP_NAMES
#define XBYAK_NO_OP_NAMES
#endif

#include "xbyak/xbyak.h"


namespace SKSE
{
	class Trampoline;


	class CodeGenerator : public Xbyak::CodeGenerator
	{
	public:
		CodeGenerator();
		explicit CodeGenerator(Trampoline* a_trampoline);
		explicit CodeGenerator(std::size_t a_size);
		~CodeGenerator();

		void finalize();
		void ready();

	private:
		using Base = Xbyak::CodeGenerator;
		using Persistent_t = Trampoline*;
		using Temporary_t = std::vector<std::uint8_t>;


		enum
		{
			kPersistent,
			kTemporary
		};


		explicit CodeGenerator(Temporary_t a_tmp);
		CodeGenerator(const CodeGenerator&) = delete;
		CodeGenerator(CodeGenerator&&) = delete;

		CodeGenerator& operator=(const CodeGenerator&) = delete;
		CodeGenerator& operator=(CodeGenerator&&) = delete;


		static constexpr auto INT3 = static_cast<std::uint8_t>(0xCC);

		std::variant<Persistent_t, Temporary_t> _buffer;
		bool									_doFinalize;
	};
}
