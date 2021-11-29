#pragma once

#include "RE/N/NiTMap.h"

namespace RE
{
	// 28
	template <class Parent, class T>
	class NiTStringTemplateMap : public Parent
	{
	private:
		using Base = Parent;

	public:
		using key_type = typename Base::key_type;
		using mapped_type = typename Base::mapped_type;
		using value_type = typename Base::value_type;
		using size_type = typename Base::size_type;

		NiTStringTemplateMap(std::uint32_t a_hashSize = 37, bool a_copy = true) :
			Base(a_hashSize),
			_copy(a_copy),
			_pad21(0),
			_pad22(0),
			_pad24(0)
		{}

		virtual ~NiTStringTemplateMap();  // 00

	protected:
		// override (Parent)
		std::uint32_t hash_function(key_type a_key) const override;                                      // 01
		bool          key_eq(key_type a_lhs, key_type a_rhs) const override;                             // 02
		void          assign_value(value_type* a_value, key_type a_key, mapped_type a_mapped) override;  // 03
		void          clear_value(value_type* a_value) override;                                         // 04

		// members
		bool          _copy;   // 20
		std::uint8_t  _pad21;  // 21
		std::uint16_t _pad22;  // 22
		std::uint32_t _pad24;  // 24
	};

	// 28
	template <class T>
	class NiTStringMap : public NiTStringTemplateMap<NiTMap<const char*, T>, T>
	{
	private:
		using Base = NiTStringTemplateMap<NiTMap<const char*, T>, T>;

	public:
		using key_type = typename Base::key_type;
		using mapped_type = typename Base::mapped_type;
		using value_type = typename Base::value_type;
		using size_type = typename Base::size_type;

		virtual ~NiTStringMap();  // 00
	};
}
