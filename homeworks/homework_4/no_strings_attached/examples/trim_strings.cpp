#include <no_strings_attached/string_trim.h>

#include <iostream>

int main() {
    std::string trimString;
    std::string result_str{};
    std::cout << "Example program that trims strings." << std::endl;
    std::cout << "Please enter a string:" << std::endl;
    std::getline(std::cin, trimString);
    std::cout << "Your trimmed string:";

    result_str = no_strings_attached::trim::Trim(
        trimString, ' ', no_strings_attached::trim::Side::kBoth);

    std::cout << "'" << result_str << "'" << std::endl;

    return 0;
}
