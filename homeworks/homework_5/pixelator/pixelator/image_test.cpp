#include "image.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(Image_test, test1) {
    pixelator::Image empty_image{};
    bool empty = true;
    int row = 0;
    int col = 0;
    pixelator::Size s{row,col};  
    EXPECT_EQ(empty, empty_image.empty());
    EXPECT_EQ(row, empty_image.rows());
    EXPECT_EQ(col, empty_image.cols());
    EXPECT_EQ(s.row, empty_image.size().row);
    EXPECT_EQ(s.col, empty_image.size().col);
}

TEST(Image_test, test2) {
    const auto rows{42};
    const auto cols{23};
    pixelator::Image image{rows, cols};
    bool empty = false;
    int row = 42;
    int col = 23;
    pixelator::Size s{row,col};    
    EXPECT_EQ(empty, image.empty());
    EXPECT_EQ(row, image.rows());
    EXPECT_EQ(col, image.cols());
    EXPECT_EQ(s.row, image.size().row);
    EXPECT_EQ(s.col, image.size().col);
}

TEST(Image_test, test3) {
    const auto rows{42};
    const auto cols{23};
    pixelator::Image image{rows, cols};
    const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};

    bool x = true;
    image.at(4,2) = yellowish;

    EXPECT_EQ(x, image.at(4,2) == yellowish);

}

TEST(Image_test, test5) {
    const auto rows{42};
    const auto cols{23};
    pixelator::Image image{rows, cols};
    const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};

    bool x = true;
    image.at(4,2) = yellowish;

    const pixelator::Image image_copy{image};

    EXPECT_EQ(x, image_copy.at(4,2) == yellowish);

}       

TEST(Image_test, test6) {
    const auto rows{42};
    const auto cols{23};
    pixelator::Image image{rows, cols};
    const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};

    bool x = true;
    image.at(4,2) = yellowish;

    const pixelator::Image image_move{std::move(image)};

    EXPECT_EQ(x, image_move.at(4,2) == yellowish);

}    