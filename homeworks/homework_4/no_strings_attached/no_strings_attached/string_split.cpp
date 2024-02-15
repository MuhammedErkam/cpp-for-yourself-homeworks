#include <no_strings_attached/string_split.h>

#include <iostream>

namespace no_strings_attached {
namespace split {

std::vector<std::string> Split(const std::string& str,
                               const std::string& delimiter) {
    std::vector<std::string> vec{};
    std::string::size_type n{0};
    auto cpos = 0;
    while (true) {
        n = str.find(delimiter, cpos);
        if (std::string::npos == n) {
            if (cpos <= str.size()) {
                if (str.substr(cpos) != "") {
                    vec.emplace_back(str.substr(cpos));
                }
            }
            break;
        } else {
            if (n == 0) {
                vec.emplace_back("");
                cpos += delimiter.size();
            } else {
                if (cpos == n) {
                    cpos = n + delimiter.size();
                    continue;
                }
                vec.emplace_back(str.substr(cpos, n - cpos));
                cpos = n + delimiter.size();
            }
        }
    }
    return vec;
}

std::vector<std::string> Split(const std::string& str,
                               const std::string& delimiter,
                               int number_of_chunks_to_keep) {
    std::vector<std::string> vec{};
    std::string::size_type n{0};
    auto cpos = 0;
    int chunk_counter = 0;
    while (true) {
        n = str.find(delimiter, cpos);
        if (chunk_counter == number_of_chunks_to_keep) { break; }
        if (std::string::npos == n) {
            if (cpos <= str.size()) {
                if (str.substr(cpos) != "") {
                    vec.emplace_back(str.substr(cpos));
                }
            }
            break;
        } else {
            if (n == 0) {
                vec.emplace_back("");
                cpos += delimiter.size();
            } else {
                if (cpos == n) {
                    cpos = n + delimiter.size();
                    continue;
                }
                vec.emplace_back(str.substr(cpos, n - cpos));
                cpos = n + delimiter.size();
            }
            chunk_counter++;
        }
    }
    return vec;
}
}  // namespace split
}  // namespace no_strings_attached