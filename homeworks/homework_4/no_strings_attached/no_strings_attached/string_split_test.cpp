#include "no_strings_attached/string_split.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(Split_test, test1) {
    std::string str = "aaabaaba";
    std::string del = "aa";
    std::vector<std::string> vec = no_strings_attached::split::Split(str, del);
    std::vector<std::string> vec2{"", "ab", "ba"};
    EXPECT_EQ(vec, vec2);
}

TEST(Split_test, test2) {
    std::string str = "aaa baa ba";
    std::string del = " ";
    std::vector<std::string> vec = no_strings_attached::split::Split(str, del);
    std::vector<std::string> vec2{"aaa", "baa", "ba"};
    EXPECT_EQ(vec, vec2);
}

TEST(Split_overload_test, test1) {
    std::string str = "aaabaaba";
    std::string del = "aa";
    std::vector<std::string> vec =
        no_strings_attached::split::Split(str, del, 2);
    std::vector<std::string> vec2{"", "ab"};
    EXPECT_EQ(vec, vec2);
}

TEST(Split_overload_test, test2) {
    std::string str = "aaa baa ba";
    std::string del = " ";
    std::vector<std::string> vec =
        no_strings_attached::split::Split(str, del, 2);
    std::vector<std::string> vec2{"aaa", "baa"};
    EXPECT_EQ(vec, vec2);
}