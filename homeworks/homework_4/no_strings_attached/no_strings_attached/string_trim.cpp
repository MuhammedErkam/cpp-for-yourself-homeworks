#include <no_strings_attached/string_trim.h>

#include <iostream>

namespace no_strings_attached {
namespace trim {
std::string Trim(const std::string& str, char char_to_trim, Side side) {
    std::string::size_type n{0};
    std::string result_str{};
    auto pos = 0, ppos = 0, cpos = 0;
    auto counter = 0;
    while (true) {
        counter++;
        n = str.find(char_to_trim, pos);
        if (n == std::string::npos) { break; }
        if (side == Side::kLeft) {
            if (counter == 1) {
                result_str = str.substr(n + 1);
                break;
            }
        } else if (side == Side::kRight) {
            if (counter == 2) {
                result_str = str.substr(0, n);
                break;
            }
        } else {
            if (counter == 1) { ppos = n; }
            if (counter == 2) {
                cpos = n;
                result_str = str.substr(ppos + 1, cpos - ppos - 1);
                break;
            }
        }

        pos++;
    }
    // std::cout << "result: " << result_str << "*qqqq" << std::endl;
    return result_str;
}
std::string Trim(const std::string& str) {
    std::string::size_type n{0};
    std::string result_str{};
    auto pos = 0, ppos = 0, cpos = 0;
    auto counter = 0;
    while (true) {
        counter++;
        n = str.find(" ", pos);
        if (n == std::string::npos) { break; }
        if (counter == 1) {
            ppos = n;
        } else if (counter == 2) {
            cpos = n;
            result_str = str.substr(ppos + 1, cpos - ppos - 1);
            break;
        }

        pos++;
    }
    return result_str;
}
}  // namespace trim
}  // namespace no_strings_attached
