#include "no_strings_attached/string_trim.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(TrimTest, test1) {
    std::string str = " hellloworld ";
    std::string res = no_strings_attached::trim::Trim(
        str, ' ', no_strings_attached::trim::Side::kLeft);
    std::string res2 = "hellloworld ";
    EXPECT_EQ(res, res2);
}

TEST(TrimTest, test2) {
    std::string str = " hellloworld ";
    std::string res = no_strings_attached::trim::Trim(
        str, ' ', no_strings_attached::trim::Side::kRight);
    std::string res2 = " hellloworld";
    EXPECT_EQ(res, res2);
}

TEST(TrimTest, test3) {
    std::string str = " hellloworld ";
    std::string res = no_strings_attached::trim::Trim(
        str, ' ', no_strings_attached::trim::Side::kBoth);
    std::string res2 = "hellloworld";
    EXPECT_EQ(res, res2);
}

TEST(TrimTest, test4) {
    std::string str = " hellloworld ";
    std::string res = no_strings_attached::trim::Trim(
        str, 'h', no_strings_attached::trim::Side::kLeft);
    std::string res2 = "ellloworld ";
    EXPECT_EQ(res, res2);
}