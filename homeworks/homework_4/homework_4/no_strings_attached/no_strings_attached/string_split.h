#pragma once

#include <string>
#include <vector>

namespace no_strings_attached {
namespace split {
std::vector<std::string> Split(const std::string& str,
                               const std::string& delimiter);
std::vector<std::string> Split(const std::string& str,
                               const std::string& delimiter,
                               int number_of_chunks_to_keep);

}  // namespace split
}  // namespace no_strings_attached
