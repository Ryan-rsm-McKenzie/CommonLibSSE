#pragma once


namespace REL
{
	// represents the exe product version
	class Version
	{
	public:
		constexpr Version() noexcept :
			Version(0, 0, 0, 0)
		{}

		constexpr Version(std::uint16_t a_major, std::uint16_t a_minor, std::uint16_t a_revision, std::uint16_t a_build) noexcept :
			_buf{ a_major, a_minor, a_revision, a_build }
		{}

		template <class T, typename std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
		constexpr Version(const T a_versions[4]) noexcept :
			Version(static_cast<std::uint16_t>(a_versions[0]),
				static_cast<std::uint16_t>(a_versions[1]),
				static_cast<std::uint16_t>(a_versions[2]),
				static_cast<std::uint16_t>(a_versions[3]))
		{}

		[[nodiscard]] friend constexpr bool operator==(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.Compare(a_rhs) == 0; }
		[[nodiscard]] friend constexpr bool operator!=(const Version& a_lhs, const Version& a_rhs) noexcept { return !(a_lhs == a_rhs); }

		[[nodiscard]] friend constexpr bool operator<(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.Compare(a_rhs) < 0; }
		[[nodiscard]] friend constexpr bool operator>(const Version& a_lhs, const Version& a_rhs) noexcept { return a_rhs < a_lhs; }
		[[nodiscard]] friend constexpr bool operator<=(const Version& a_lhs, const Version& a_rhs) noexcept { return !(a_lhs > a_rhs); }
		[[nodiscard]] friend constexpr bool operator>=(const Version& a_lhs, const Version& a_rhs) noexcept { return !(a_lhs < a_rhs); }

		[[nodiscard]] constexpr std::uint16_t& operator[](std::size_t a_idx) noexcept
		{
			assert(a_idx < kTotal);
			return _buf[a_idx];
		}

		[[nodiscard]] constexpr const std::uint16_t& operator[](std::size_t a_idx) const noexcept
		{
			assert(a_idx < kTotal);
			return _buf[a_idx];
		}

		[[nodiscard]] constexpr int Compare(const Version& a_rhs) const noexcept
		{
			if ((*this)[kMajor] != a_rhs[kMajor]) {
				return (*this)[kMajor] < a_rhs[kMajor] ? -1 : 1;
			} else if ((*this)[kMinor] != a_rhs[kMinor]) {
				return (*this)[kMinor] < a_rhs[kMinor] ? -1 : 1;
			} else if ((*this)[kRevision] != a_rhs[kRevision]) {
				return (*this)[kRevision] < a_rhs[kRevision] ? -1 : 1;
			} else if ((*this)[kBuild] != a_rhs[kBuild]) {
				return (*this)[kBuild] < a_rhs[kBuild] ? -1 : 1;
			} else {
				return 0;
			}
		}

		[[nodiscard]] inline std::string GetString() const
		{
			std::string result;
			result += std::to_string(_buf[kMajor]);
			result += '.';
			result += std::to_string(_buf[kMinor]);
			result += '.';
			result += std::to_string(_buf[kRevision]);
			result += '.';
			result += std::to_string(_buf[kBuild]);
			return result;
		}

		[[nodiscard]] constexpr std::uint16_t GetMajor() const noexcept { return _buf[kMajor]; }
		[[nodiscard]] constexpr std::uint16_t GetMinor() const noexcept { return _buf[kMinor]; }
		[[nodiscard]] constexpr std::uint16_t GetRevision() const noexcept { return _buf[kRevision]; }
		[[nodiscard]] constexpr std::uint16_t GetBuild() const noexcept { return _buf[kBuild]; }

		constexpr void SetMajor(std::uint16_t a_major) noexcept { _buf[kMajor] = a_major; }
		constexpr void SetMinor(std::uint16_t a_minor) noexcept { _buf[kMinor] = a_minor; }
		constexpr void SetRevision(std::uint16_t a_revision) noexcept { _buf[kRevision] = a_revision; }
		constexpr void SetBuild(std::uint16_t a_build) noexcept { _buf[kBuild] = a_build; }

	private:
		enum : std::size_t
		{
			kMajor,
			kMinor,
			kRevision,
			kBuild,
			kTotal
		};


		std::array<std::uint16_t, 4> _buf;
	};


	static constexpr Version RUNTIME_1_1_47(1, 1, 47, 0);
	static constexpr Version RUNTIME_1_1_51(1, 1, 51, 0);
	static constexpr Version RUNTIME_1_2_36(1, 2, 36, 0);
	static constexpr Version RUNTIME_1_2_39(1, 2, 39, 0);
	static constexpr Version RUNTIME_1_3_5(1, 3, 5, 0);
	static constexpr Version RUNTIME_1_3_9(1, 3, 9, 0);
	static constexpr Version RUNTIME_1_4_2(1, 4, 2, 0);
	static constexpr Version RUNTIME_1_5_3(1, 5, 3, 0);
	static constexpr Version RUNTIME_1_5_16(1, 5, 16, 0);
	static constexpr Version RUNTIME_1_5_23(1, 5, 23, 0);
	static constexpr Version RUNTIME_1_5_39(1, 5, 39, 0);
	static constexpr Version RUNTIME_1_5_50(1, 5, 50, 0);
	static constexpr Version RUNTIME_1_5_53(1, 5, 53, 0);
	static constexpr Version RUNTIME_1_5_62(1, 5, 62, 0);
	static constexpr Version RUNTIME_1_5_73(1, 5, 73, 0);
	static constexpr Version RUNTIME_1_5_80(1, 5, 80, 0);
	static constexpr Version RUNTIME_1_5_97(1, 5, 97, 0);
}
