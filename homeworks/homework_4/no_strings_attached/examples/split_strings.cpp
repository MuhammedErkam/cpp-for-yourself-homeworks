#include <no_strings_attached/string_split.h>

#include <iostream>

int main() {
    std::string splitString;
    std::vector<std::string> result_vec{};
    std::vector<std::string> result_vec2{};
    std::cout << "Example program that splits strings." << std::endl;
    std::cout << "Please enter a string: " << std::endl;
    std::getline(std::cin, splitString);
    std::cout << "Your split string: ";

    result_vec = no_strings_attached::split::Split(splitString, " ");
    result_vec2 = no_strings_attached::split::Split(splitString, " ", 2);

    for (auto i = 0; i < result_vec.size(); i++) {
        if (i < result_vec.size() - 1) {
            std::cout << "'" << result_vec[i] << "' ";
        } else {
            std::cout << "'" << result_vec[i] << "'" << std::endl;
        }
    }

    for (auto i = 0; i < result_vec2.size(); i++) {
        if (i < result_vec2.size() - 1) {
            std::cout << "'" << result_vec2[i] << "' ";
        } else {
            std::cout << "'" << result_vec2[i] << "'" << std::endl;
        }
    }

    return 0;
}
