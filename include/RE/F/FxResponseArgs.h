#pragma once

#include "RE/F/FxResponseArgsBase.h"
#include "RE/G/GFxValue.h"

namespace RE
{
	template <std::uint32_t SIZE>
	class FxResponseArgs : public FxResponseArgsBase
	{
	public:
		FxResponseArgs() :
			FxResponseArgsBase(),
			_values{},
			_index(1),
			_pad(0)
		{}

		virtual ~FxResponseArgs() = default;  // 00

		// override (FxResponseArgsBase)
		virtual std::uint32_t GetValues(GFxValue** a_params) override  // 01
		{
			*a_params = _values;
			return _index;
		}

		void Add(const GFxValue& a_val)
		{
			if (_index > SIZE) {
				assert(false);	// insertion out of bounds
				return;
			}
			_values[_index++] = a_val;
		}

	private:
		GFxValue	  _values[SIZE + 1];  // 08 - includes response data
		std::uint32_t _index;			  // ??
		std::uint32_t _pad;				  // ??
	};
	static_assert(sizeof(FxResponseArgs<1>) == 0x40);

	template <std::size_t N>
	class FxResponseArgsEx : public FxResponseArgsBase
	{
	private:
		static constexpr std::size_t O = 1;

		using super = FxResponseArgsBase;
		using container_type = std::array<GFxValue, N + O>;

		static_assert(N + O <= static_cast<std::size_t>(std::numeric_limits<std::uint32_t>::max()));

	public:
		using value_type = typename container_type::value_type;
		using size_type = typename container_type::size_type;
		using difference_type = typename container_type::difference_type;
		using reference = typename container_type::reference;
		using const_reference = typename container_type::const_reference;
		using pointer = typename container_type::pointer;
		using const_pointer = typename container_type::const_pointer;
		using iterator = typename container_type::iterator;
		using const_iterator = typename container_type::const_iterator;
		using reverse_iterator = typename container_type::reverse_iterator;
		using const_reverse_iterator = typename container_type::const_reverse_iterator;

		FxResponseArgsEx() :
			super(),
			_args()
		{}

		FxResponseArgsEx(const FxResponseArgsEx&) = default;
		FxResponseArgsEx(FxResponseArgsEx&&) = default;

		FxResponseArgsEx(const std::array<GFxValue, N>& a_args) :
			super(),
			_args()
		{
			for (std::size_t i = 0; i < N; ++i) {
				_args[i + O] = a_args[i];
			}
		}

		FxResponseArgsEx(std::array<GFxValue, N>&& a_args) :
			super(),
			_args()
		{
			for (std::size_t i = 0; i < N; ++i) {
				_args[i + O] = std::move(a_args[i]);
			}
		}

		virtual ~FxResponseArgsEx() = default;

		FxResponseArgsEx& operator=(const FxResponseArgsEx&) = default;
		FxResponseArgsEx& operator=(FxResponseArgsEx&&) = default;

		[[nodiscard]] constexpr reference		at(size_type a_pos) { return _args.at(a_pos); }
		[[nodiscard]] constexpr const_reference at(size_type a_pos) const { return _args.at(a_pos); }

		[[nodiscard]] constexpr reference		operator[](size_type a_pos) { return _args[a_pos + O]; }
		[[nodiscard]] constexpr const_reference operator[](size_type a_pos) const { return _args[a_pos + O]; }

		[[nodiscard]] constexpr reference		front() { return _args.front(); }
		[[nodiscard]] constexpr const_reference front() const { return _args.front(); }

		[[nodiscard]] constexpr reference		back() { return _args.back(); }
		[[nodiscard]] constexpr const_reference back() const { return _args.back(); }

		[[nodiscard]] constexpr pointer		  data() noexcept { return _args.data(); }
		[[nodiscard]] constexpr const_pointer data() const noexcept { return _args.data(); }

		[[nodiscard]] constexpr iterator	   begin() noexcept { return ++_args.begin(); }
		[[nodiscard]] constexpr const_iterator begin() const noexcept { return ++_args.begin(); }
		[[nodiscard]] constexpr const_iterator cbegin() const noexcept { return ++_args.cbegin(); }

		[[nodiscard]] constexpr iterator	   end() noexcept { return _args.end(); }
		[[nodiscard]] constexpr const_iterator end() const noexcept { return _args.end(); }
		[[nodiscard]] constexpr const_iterator cend() const noexcept { return _args.cend(); }

		[[nodiscard]] constexpr reverse_iterator	   rbegin() noexcept { return _args.rbegin(); }
		[[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept { return _args.rbegin(); }
		[[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept { return _args.crbegin(); }

		[[nodiscard]] constexpr reverse_iterator	   rend() noexcept { return --_args.rend(); }
		[[nodiscard]] constexpr const_reverse_iterator rend() const noexcept { return --_args.rend(); }
		[[nodiscard]] constexpr const_reverse_iterator crend() const noexcept { return --_args.crend(); }

		[[nodiscard]] constexpr bool empty() const noexcept { return begin() == end(); }

		[[nodiscard]] constexpr size_type size() const noexcept { return _args.size() - O; }

		[[nodiscard]] constexpr size_type max_size() const noexcept { return size(); }

	protected:
		virtual std::uint32_t GetValues(GFxValue** a_params) override  // 01
		{
			*a_params = _args.data();
			return static_cast<std::uint32_t>(_args.size());
		}

	private:
		container_type _args;
	};

	template <std::size_t N>
	FxResponseArgsEx(const std::array<GFxValue, N>&) -> FxResponseArgsEx<N>;

	template <std::size_t N>
	FxResponseArgsEx(std::array<GFxValue, N>&&) -> FxResponseArgsEx<N>;
}
