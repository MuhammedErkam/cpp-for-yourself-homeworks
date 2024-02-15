#pragma once

#include <string>
#include <vector>

namespace no_strings_attached {
namespace trim {
enum class Side { kLeft, kRight, kBoth };
std::string Trim(const std::string& str, char char_to_trim, Side side);
std::string Trim(const std::string& str);
}  // namespace trim
}  // namespace no_strings_attached
