#pragma once

namespace SKSE
{
	namespace stl
	{
		class RNG
		{
		public:
			static RNG* GetSingleton()
			{
				static RNG singleton;
				return &singleton;
			}

			template <class T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
			T Generate(T a_min, T a_max)
			{
				if constexpr (std::is_integral_v<T>) {
					std::uniform_int_distribution<T> distr(a_min, a_max);
					return distr(twister);
				} else {
					std::uniform_real_distribution<T> distr(a_min, a_max);
					return distr(twister);
				}
			}

		private:
			RNG() :
				twister(std::random_device{}())
			{}
			RNG(RNG const&) = delete;
			RNG(RNG&&) = delete;
			~RNG() = default;

			RNG& operator=(RNG const&) = delete;
			RNG& operator=(RNG&&) = delete;

			std::mt19937 twister;
		};

		// https://stackoverflow.com/questions/48896142
		namespace hash
		{
			template <typename Str>
			constexpr size_t hash_string(const Str& toHash)
			{
				static_assert(sizeof(size_t) == 8);
				// fnv-1 64 bit
				size_t result = 0xcbf29ce484222325;

				for (char c : toHash) {
					result *= 1099511628211;
					result ^= c;
				}

				return result;
			}
		}

		// https://stackoverflow.com/a/253874
		namespace numeric
		{
			constexpr float EPSILON = std::numeric_limits<float>::epsilon();

			inline bool approximately_equal(float a, float b)
			{
				return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPSILON);
			}

			inline bool essentially_equal(float a, float b)
			{
				return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * EPSILON);
			}

			inline bool definitely_greater_than(float a, float b)
			{
				return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPSILON);
			}

			inline bool definitely_less_than(float a, float b)
			{
				return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPSILON);
			}
		}

		namespace string
		{
			namespace detail
			{
				// trim from left
				inline std::string& ltrim(std::string& a_str)
				{
					a_str.erase(0, a_str.find_first_not_of(" \t\n\r\f\v"));
					return a_str;
				}

				// trim from right
				inline std::string& rtrim(std::string& a_str)
				{
					a_str.erase(a_str.find_last_not_of(" \t\n\r\f\v") + 1);
					return a_str;
				}
			}

			inline std::string& trim(std::string& a_str)
			{
				return detail::ltrim(detail::rtrim(a_str));
			}

			inline std::string trim_copy(std::string a_str)
			{
				return trim(a_str);
			}

			inline constexpr size_t const_hash(std::string_view toHash)
			{
				return hash::hash_string(toHash);
			}

			inline bool is_empty(const char* a_char)
			{
				return a_char == nullptr || a_char[0] == '\0';
			}

			inline bool is_only_digit(std::string_view a_str)
			{
				return std::ranges::all_of(a_str, [](char c) {
					return std::isdigit(static_cast<unsigned char>(c));
				});
			}

			inline bool is_only_hex(std::string_view a_str)
			{
				if (a_str.compare(0, 2, "0x") == 0 || a_str.compare(0, 2, "0X") == 0) {
					return a_str.size() > 2 && std::all_of(a_str.begin() + 2, a_str.end(), [](char c) {
						return std::isxdigit(static_cast<unsigned char>(c));
					});
				}
				return std::ranges::all_of(a_str, [](char c) {
					return std::isxdigit(static_cast<unsigned char>(c));
				});
			}

			inline bool is_only_letter(std::string_view a_str)
			{
				return std::ranges::all_of(a_str, [](char c) {
					return std::isalpha(static_cast<unsigned char>(c));
				});
			}

			inline bool is_only_space(std::string_view a_str)
			{
				return std::ranges::all_of(a_str, [](char c) {
					return std::isspace(static_cast<unsigned char>(c));
				});
			}

			inline bool icontains(std::string_view a_str1, std::string_view a_str2)
			{
				if (a_str2.length() > a_str1.length())
					return false;

				auto found = std::ranges::search(a_str1, a_str2,
					[](char ch1, char ch2) {
						return std::toupper(static_cast<unsigned char>(ch1)) == std::toupper(static_cast<unsigned char>(ch2));
					});

				return !found.empty();
			}

			inline bool iequals(std::string_view a_str1, std::string_view a_str2)
			{
				return std::ranges::equal(a_str1, a_str2,
					[](char ch1, char ch2) {
						return std::toupper(static_cast<unsigned char>(ch1)) == std::toupper(static_cast<unsigned char>(ch2));
					});
			}

			inline std::string join(const std::vector<std::string>& a_vec, const char* a_delimiter)
			{
				std::ostringstream os;
				auto               begin = a_vec.begin();
				auto               end = a_vec.end();

				if (begin != end) {
					std::copy(begin, std::prev(end), std::ostream_iterator<std::string>(os, a_delimiter));
					os << *std::prev(end);
				}

				return os.str();
			}

			template <class T>
			T lexical_cast(const std::string& a_str, bool a_hex = false)
			{
				if constexpr (std::is_floating_point_v<T>) {
					return static_cast<T>(std::stof(a_str));
				} else if constexpr (std::is_signed_v<T>) {
					return static_cast<T>(std::stoi(a_str));
				} else if constexpr (sizeof(T) == sizeof(std::uint64_t)) {
					return static_cast<T>(std::stoull(a_str));
				} else if (a_hex) {
					return static_cast<T>(std::stoul(a_str, nullptr, 16));
				} else {
					return static_cast<T>(std::stoul(a_str));
				}
			}

			inline std::string remove_non_alphanumeric(std::string& a_str)
			{
				std::ranges::replace_if(
					a_str, [](char c) { return !std::isalnum(static_cast<unsigned char>(c)); }, ' ');
				return trim_copy(a_str);
			}

			inline std::string remove_non_numeric(std::string& a_str)
			{
				std::ranges::replace_if(
					a_str, [](char c) { return !std::isdigit(static_cast<unsigned char>(c)); }, ' ');
				return trim_copy(a_str);
			}

			inline void replace_all(std::string& a_str, std::string_view a_search, std::string_view a_replace)
			{
				if (a_search.empty()) {
					return;
				}

				size_t pos = 0;
				while ((pos = a_str.find(a_search, pos)) != std::string::npos) {
					a_str.replace(pos, a_search.length(), a_replace);
					pos += a_replace.length();
				}
			}

			inline void replace_first_instance(std::string& a_str, std::string_view a_search, std::string_view a_replace)
			{
				if (a_search.empty()) {
					return;
				}

				if (auto pos = a_str.find(a_search); pos != std::string::npos) {
					a_str.replace(pos, a_search.length(), a_replace);
				}
			}

			inline std::vector<std::string> split(const std::string& a_str, const std::string& a_deliminator)
			{
				std::vector<std::string> list;
				std::string              strCopy = a_str;
				size_t                   pos = 0;
				std::string              token;
				while ((pos = strCopy.find(a_deliminator)) != std::string::npos) {
					token = strCopy.substr(0, pos);
					list.push_back(token);
					strCopy.erase(0, pos + a_deliminator.length());
				}
				list.push_back(strCopy);
				return list;
			}
		}

		template <typename First, typename... T>
		[[nodiscard]] bool is_in(First&& first, T&&... t)
		{
			return ((first == t) || ...);
		}
	}
}
